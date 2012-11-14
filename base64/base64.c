/* base64.c 
 * Replacement of the base64 GNU-coreutil-program.
 *
 * CURRENTLY DEFECTIVE!
 * Output is *almost* correct as it is. However, it is not technically correct. It is misaligned and some other shit,
 * can't give a better explanations, because if I knew what was going on, I'd fix it.
 * 
 * TODO:	Find a better name for charvals.
 *			Write decoder.
 * 			Allow user select files for output/input?
 */

#include <stdio.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
	const char charvals[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
							'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
							'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd',
							'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
							'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x',
							'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7',
							'8', '9', '+', '/', '='};
	FILE *input;
	input = stdin;
	FILE *out;
	out = stdout;
	int padchars = -1;
	for (;;) {
		char tmp[3];
		int i;
		unsigned bits;
		for (i = 2; i >= 0; --i) {
			int tmpchr;
			if ((tmpchr = fgetc(input)) == EOF) {
				if (i == 2) {
					padchars = 0;
				} else if (i == 1) {
					tmp[1] = tmp[0] = '\0';
					padchars = 2;
				} else {
					tmp[1] = '\0';
					padchars = 1;
				}
				break;
			} else {
				//if (tmpchr == '\n')
				//	printf("read newline!\n");
				tmp[i] = (char)tmpchr;
			}
		}
		bits = *(unsigned*)tmp;
		fprintf(out, "%c%c%c%c", charvals[(uint8_t)(bits >> 18)],
								 charvals[(uint8_t)(bits << 14 >> 26)],
								 charvals[(uint8_t)(bits << 21 >> 27)],
								 charvals[(uint8_t)(bits << 26 >> 26)]);
		if (padchars != -1) {
			for (; padchars > 0; --padchars)
				fputc('=', out);
			fputc('\n', out);
			break;
		}
	}
	return 0;
}
