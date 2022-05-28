#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>

int i, j, x = 1, y = 1, xm = 1, ym = 1;

int main()
{
	printf("test");
	struct winsize w;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

	for (;;)
	{
		for (i = 0; i < w.ws_row; i++)
		{
			for (j = 0; j < w.ws_col; j++)
			{
				if (i == y || j == x)
				{
					putchar('#');
				}
				else
				{
					putchar(' ');
				}
			}
			if (i < w.ws_row - 1)
			{
				printf("\n");
			}
		}
		fflush(stdout);
		if (y >= w.ws_row - 1)
		{
			ym = -1;
		}
		else if (y == 0)
		{
			ym = 1;
		}
		if (x >= w.ws_col - 1)
		{
			xm = -1;
		}
		else if (x == 0)
		{
			xm = 1;
		}
		x += xm;
		y += ym;
		usleep(100000);
	}
	return 0;

}
