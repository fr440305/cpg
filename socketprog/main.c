#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>

int main (int ArgN, char **ArgList) {
	int i;
	printf ("%d\n", i);
	printf ("%d\n", ArgN);
	for (i = 0; i < ArgN; i++) {
		printf ("%s;\n", ArgList[i]);
	}
	return 0;
}
