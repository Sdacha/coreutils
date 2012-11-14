/* cat.c
 * Prints either stdin or the file with the name specified as a command line argument to stdout.
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *input;
	if (argc == 1)
		input = stdin;
	else
		input = fopen(argv[1], "r");
	if (!input) {
		printf("cat: Failed to open %s\n", argv[1]);
		return EXIT_FAILURE;
	}
	int c;
	while ((c = fgetc(input)) != EOF) {
		putchar(c);
	}
	return 0;
}
