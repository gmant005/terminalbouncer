// C program to build the outline
// boundary using draw()
#include <sys/ioctl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
// might need to make cross compatible.
int i, j, x=0, y=0, xm=1, ym=1;
void draw(int height, int width)
{
	for (i=0; i < height; i++)
	{
//                if(i < height-1)
//                {
//                        printf("\n");
//                }

		for (j=0; j < width; j++)
		{
			if (i != y && j != x)
			{
				printf(" ");
			} else
			{
				printf("#");
			}
		}
		if(i < height-1)
		{
			printf("\n");
		}
	}
}
int main()
{
	printf("\e[?25l");
	for(;;)
	{
		struct winsize w;
		ioctl(0,TIOCGWINSZ, &w);
		printf("\e[1;1H\e[2J");
		draw(w.ws_row, w.ws_col);
//		printf("e");
		if (y >= w.ws_row-1)
		{
			ym=-1;
		} else if (y == 0)
		{
			ym=1;
		}
		if (x >= w.ws_col-1)
		{
			xm=-1;
		} else if (x == 0)
		{
			xm=1;
		}
		x=x+xm;
		y=y+ym;
//	        printf ("lines %d\n", w.ws_row);
//	        printf ("columns %d\n", w.ws_col);
	usleep(100000);
	}
    	return 0;
}

