/* wc.c
 * A wc clone with crippled functionality and ugly code. Refactor that shit, yo.
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
	bool wordc = false;
	bool linec = false;
	bool bytec = false;
	//bool charc = false; //fuck unicode and wchar_t and whatnot
	bool longlen = false;
	unsigned words = 0;
	unsigned lines = 0;
	unsigned bytes = 0;
	//unsigned characters = 0;
	unsigned longest = 0;
	unsigned curlen = 0;
	FILE *input;
	if (*argv[argc-1] != '-') {
		input = fopen(argv[argc-1], "r");
		if (!input)
			printf("wc: Could not open %s. Exiting.\n", argv[argc-1]);
	}
	else
		input = stdin;
		
	int i;
	for (i = 1; i < argc; ++i) {
		if (!strcmp(argv[i], "-w"))
			wordc = true;
		else if (!strcmp(argv[i], "-b"))
			bytec = true;
		else if (!strcmp(argv[i], "-l"))
			linec = true;
		else if (!strcmp(argv[i], "-L"))
			longlen = true;
	}
	if (!wordc && !linec && !bytec && !longlen)
		wordc = true; //default to word counting

	int c;
	bool inword = false;
	while ((c = getc(input)) != EOF) {
		++curlen;
		++bytes;
		if (c == ' ' || c == '\t' || c == '\n')
			inword = false;
		else {
			if (inword == false)
				++words;
			inword = true;
		}
		if (c == '\n') {
			++lines;
			if (curlen > longlen)
				longest = curlen;
			curlen = 0;
		}
	}
	if (wordc)
		printf("Words: %u\n", words);
	if (linec)
		printf("Lines: %u\n", lines);
	if (bytec)
		printf("Bytes: %u\n", bytes);
	if (longlen)
		printf("Longest line: %u\n", longest);
	return 0;
}
