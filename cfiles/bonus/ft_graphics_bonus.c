/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphics_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarini <tarini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 19:07:31 by tarini            #+#    #+#             */
/*   Updated: 2025/02/21 19:07:33 by tarini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void ft_myMlxPixelPut(t_img *data, int x, int y, int color)
{
    if (x < 0 || x >= ULTRA_WIDTH || y < 0 || y >= ULTRA_HEIGHT)
        return ;
    *(unsigned int*)(data->addr + (y * data->line_length + x * ((int)(data->bits_per_pixel * 0.125)))) = color;
}

int ft_get_color_dark_raibow(int x, int y, int iterations)
{
    int r, g, b;
    float cx = ULTRA_WIDTH / 2.0f;
    float cy = ULTRA_HEIGHT / 2.0f;
    float dx = x - cx;
    float dy = y - cy;
    float dist = sqrtf(dx * dx + dy * dy);
    float t = dist / (sqrtf(cx * cx + cy * cy));
    float iter_t = (float)iterations / MAX_ITER;
    float angle = (t + iter_t) * 360.0f;
    r = (int)(sin(angle * M_PI / 180.0f) * 127 + 128);
    g = (int)(sin((angle + 120) * M_PI / 180.0f) * 127 + 128);
    b = (int)(sin((angle + 240) * M_PI / 180.0f) * 127 + 128);
    float brightness = powf(1.0f - powf(t, 0.8f), 0.5f) * powf(iter_t, 0.5f);
    r *= brightness;
    g *= brightness;
    b *= brightness;
    if (iterations == MAX_ITER)
        return 0x000000;
    return (r << 16) | (g << 8) | b;
}

int ft_get_color_light_raimbow(int x, int y, int iterations)
{
    int r, g, b;
    float cx = ULTRA_WIDTH / 2.0f;
    float cy = ULTRA_HEIGHT / 2.0f;
    float dx = x - cx;
    float dy = y - cy;
    float dist = sqrtf(dx * dx + dy * dy);
    float t = dist / (sqrtf(cx * cx + cy * cy));
    float iter_t = (float)iterations / MAX_ITER;
    float angle = (t + iter_t * 2.0f) * 360.0f;
    r = (int)(sin(angle * M_PI / 180.0f) * 127 + 128);
    g = (int)(sin((angle + 120) * M_PI / 180.0f) * 127 + 128);
    b = (int)(sin((angle + 240) * M_PI / 180.0f) * 127 + 128);
    float brightness = powf(1.0f - powf(t, 0.6f), 0.8f) * powf(iter_t, 0.7f);
    brightness = fmaxf(brightness, 0.4f);
    r = fminf(r * brightness + 50, 255);
    g = fminf(g * brightness + 50, 255);
    b = fminf(b * brightness + 50, 255);
    if (iterations == MAX_ITER)
        return 0x000000;
    return (r << 16) | (g << 8) | b;
}
