/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jari <marvin@42.ma>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 05:27:31 by sel-jari          #+#    #+#             */
/*   Updated: 2025/03/28 05:27:32 by sel-jari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>

# define WIDTH 800
# define HEIGHT 800

typedef struct s_image
{
	void	*img_ptr;
	int		bpp;
	int		size_line;
	int		endian;
	char	*pixel_addr;
}				t_image;

typedef struct s_fractal
{
	char	*fractal_type;
	void	*mlx_init;
	void	*mlx_win;
	t_image	img;
	double	shift_x;
	double	shift_y;
	double	colors_shift;
	double	zoom;
	int		iterations_defintion;
	int		ac;
	double	julia_x;
	double	julia_y;
}				t_fractal;

typedef struct s_complex
{
	double	x;
	double	y;
}				t_complex;

double		str_to_double(char *str);
t_complex	ft_absolut(t_complex z);
t_complex	sum_complex(t_complex z, t_complex c);
t_complex	power_complex(t_complex z);
double		scale(double unscalednum,
				double minallowed, double maxallowed, double max);
int			ft_strlen(char *str);
int			is_valid_double(char *str);
void		events_init(t_fractal *fractal);
void		fractal_render(t_fractal *fractal);
void		fractal_init(t_fractal *fractal);
void		events_handler(t_fractal *fractal);
void		putstr_fd(char *s, int fd);
void		fractal_help(void);
void		ft_putstr_fd(char *s, int fd);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
#endif
