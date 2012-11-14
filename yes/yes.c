/* yes.c
 * Prints yes or argv[1..] to stdout
 */

#include <stdio.h>

int main(int argc, char *argv[])
{
	if (argc < 2)
		for(;;)
			printf("yes\n");
	for(;;) {
		int i;
		for(i = 1; i < argc - 1; ++i)
			printf("%s ", argv[i]);
		printf("%s\n", argv[i]); //No trailing blank
	}
}
