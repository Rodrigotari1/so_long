/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtari-ca <rtari-ca@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 18:11:03 by rtari-ca          #+#    #+#             */
/*   Updated: 2024/11/09 18:11:06 by rtari-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>  // Include this header for NULL

int main(void)
{
    void    *mlx;
    void    *mlx_win;
    void    *img; // Pointer for the image

    // Initialize MiniLibX
    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");

    // Load the image (make sure the path is correct)
    img = mlx_xpm_file_to_image(mlx, "dog.xpm", &(int){0}, &(int){0});
    if (img == NULL)
    {
        return (1); // Exit if image loading fails
    }

    // Push the image to the window
    mlx_put_image_to_window(mlx, mlx_win, img, 0, 0);

    // Enter the event loop
    mlx_loop(mlx);

    return (0);
}

