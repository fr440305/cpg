#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int arrangement (char *leading, char *entire) {
	char *char_cata = (char*) calloc (1, sizeof(char));
	char *leading_next = NULL;
	char *entire_next = NULL;
	int i, j;

	/* check the vaild of parameter*/
	//printf("\narrangement(%s, %s)\n", leading, entire);
	if (leading == NULL) leading = (char *) calloc (1, sizeof(char));
	if (entire == NULL) {
		printf ("error - entire cannot be NULL. Ni3 Shi4 Sha2 Dou1 Mei2 Shu1 Ba0?");
		return (-1);
	}

	/*transform entire to char_cata; */
	for (i = 0; i < strlen(entire); i++) {
		if (strchr(char_cata, entire[i]) == NULL) {
			/*entire[i] doesn't contains in char_cata */
			char_cata = (char*) realloc (char_cata, (strlen(char_cata) + 2) * sizeof(char));
			char_cata[strlen(char_cata)] = entire[i];
		}
	}
	
	if (strlen(char_cata) != 1) {
		for (i = 0; i < strlen(char_cata); i++) {
			/* leading_next = leading + char_cata[i]; */
			leading_next = strdup(leading);
			leading_next = (char*) realloc (leading_next, sizeof(char) * (strlen(leading_next) + 3)); 
			leading_next[strlen(leading_next)] = char_cata[i];
			/*entire_next = entire - char_cata[i]; */
			entire_next = (char*) calloc (strlen (entire), sizeof(char));
			for (j = 0; entire[j] != char_cata[i]; j++) entire_next[j] = entire[j];
			for (j++; j < strlen(entire); j++) entire_next[j - 1] = entire[j];
			/* recursive */
			arrangement (leading_next, entire_next);
		}
	} else {
		printf ("%s%s\n", leading, entire);
	}

	return 0;
	
}

int main () {
	int arrangement (char *leading, char *entire);
	char * str;
	printf("Input string:");
	scanf ("%s", str);
	printf("\n");
	return arrangement(NULL, str);
}
