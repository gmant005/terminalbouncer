#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>

int i, j, x = 1, y = 1, xm = 1, ym = 1, F = 0;

int main(int argc, char *argv[])
{
	struct winsize w;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	while ((++argv)[0]) // this will get any flags/arguments.
    {
            if (argv[0][0] == '-' )
            {
                    switch (argv[0][1])  {

                            default:
                                    printf("Unknown option -%c screensaver -h for help\n\n", argv[0][1]); // if you put an invalid argument
                                    exit(0);
                                    break;
                            case 'H':
                            case 'h':
                                    printf("Function:\n    Just make a # bounce around.\nUsage: uwu <args>\n    -h Displays this menu.\n    -f Full lines.\n"); // the help menu
                                    exit(0);
                                    break;
                            case 'F':
                            case 'f':
                                    F = 1;
                                    break;
                    }
            }
    }

	for (;;)
	{
		system("clear");
		for (i = 0; i < w.ws_row; i++)
		{
			for (j = 0; j < w.ws_col; j++)
			{
				if (F == 1)
				{
					if (i == y || j == x)
					{
						putchar('#');
					}
					else
					{
						putchar(' ');
					}
				} else {
					if (i == y && j == x)
					{
						putchar('#');
					}
					else
					{
						putchar(' ');
					}
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
