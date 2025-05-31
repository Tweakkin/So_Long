#include "so_long.h"

int main(void)
{
	int yah, yah1;
	//creating connection identifier
    void *con_iden = mlx_init();
	//setting up the window
    void *Window = mlx_new_window(con_iden, 1000, 1000, "PACMANNNN");
    //create an image
	void *img = mlx_xpm_file_to_image(con_iden, "./dd.xpm", &yah, &yah1);
	//putting the image in window
	mlx_put_image_to_window(con_iden, Window, img, 0, 0);
	// Window stays open
    mlx_loop(con_iden);
    return (0);
}