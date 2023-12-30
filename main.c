#include "minilibx-linux/mlx.h"
#include "libft/libft.h"
#include <X11/keysym.h>

#define EXIT_FAILURE 1
#define EXIT_SUCCESS 0
#define WINDOW_WIDTH 420
#define WINDOW_HEIGHT 420

typedef struct s_img
{
    void *img_ptr;
    char *addr;
    int endian;
    int bits_per_pixel;
    int size_line;
} t_img;

typedef struct s_data
{
    void *mlx_ptr;
    void *win_ptr;
    t_img *img;
} t_data;


int main(void)
{
    t_data *mlxd = malloc(sizeof(t_data));
    mlxd->mlx_ptr = mlx_init();
    if (NULL == mlxd->mlx_ptr)
        exit(EXIT_FAILURE);
    mlxd->win_ptr = mlx_new_window(mlxd->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "So long");
    if  (NULL == mlxd->win_ptr)
        exit(EXIT_FAILURE);
    mlx_loop(mlxd->mlx_ptr);
    return (EXIT_SUCCESS);
}