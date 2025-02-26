typedef struct s_fractal
{
    char *name;
    int (*draw_function)(t_data *data);
} t_fractal;

t_fractal fractals[] = {
    {"mandelbrot", ft_mandelbrot},
    {"newton", ft_newton},
    {"dragon", ft_dragon},
    {"sierpinski", ft_sierpinski},
    {"burning_ship", ft_burning_ship},
    {"julia_anime", ft_julia_anime},
    {"julia_anime_v2", ft_julia_anime_v2},
    {NULL, NULL}
};

int i = 0;
while (fractals[i].name != NULL)
{
    if (ft_strcmp(argv[1], fractals[i].name) == 0)
    {
        draw_fractal = fractals[i].draw_function;
        break;
    }
    i++;
}

if (draw_fractal == NULL)
{
    ft_printf("Error: Unknown fractal '%s'\n", argv[1]);
    show_menu();
    return (EXIT_FAILURE);
}
