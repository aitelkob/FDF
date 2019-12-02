#include "mlx.h"


int main()
{
	void	*ptr;
	void	*win;

	ptr =mlx_init();
	win = mlx_new_window(ptr,200,200,"fdf");
	mlx_loop(ptr);
}
