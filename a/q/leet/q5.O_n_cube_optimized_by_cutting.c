#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* longestPalindrome (char* s) {
	char* ret = NULL;
	char* sub; /* substring */
	int sz = strlen(s), lo, hi;
	int i; /* iterator */
	int len = 0; /* the length of arbitary substring */
	int max = 0; /* the maximun value of encountered @len */
	int find = 1; /* flag */

	for (lo = 0; s[lo] != '\0'; lo++) {
		if ((hi = lo + max) >= sz)
			break;
		for (; s[hi] != '\0'; hi++) {
			find = 1;
			len = hi - lo + 1;
			sub = s + lo;
			for (i = 0; i < len; i++) {
				if (sub[i] != sub[len-1-i]) { /* not palin */
					find = 0;
					break;
				}
			}
			/* is palin: */
			if (find == 1 && len > max) {
				max = len;
				ret = sub;
			}
		}
	}

	return strncpy((char*) calloc(max + 1, sizeof(char)), ret, max);
}

int main () {
	printf("%s", longestPalindrome("aaaaa"));

	return 0;
}

