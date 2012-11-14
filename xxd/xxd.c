/* xxd.c
 * Prints stdin in hexadecimal form.
 */

#include <stdio.h>

int main(void)
{
	int c;
	while ((c = getchar()) != EOF) {
		printf("%x", c);
	}
	printf("\n");
	return 0;
}
