#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* convert(char* s, int numRows) {
	int len = strlen(s);
	char* ret = (char*)malloc((len + 1) * sizeof(char));
	int row, lo, i, k = 0;
	int d = 2 * numRows - 2;

	if (numRows == 1)
		return s;

	for (row = 0; row < numRows; row++)
		for (lo = 0; lo < len; lo += d)
			for (i = 0; i < d; i++)
				if (s[lo+i] == '\0')
					i = d, lo = len; /* terminate */
				else if ((i <= d/2 && i == row) || (i > d/2 && d-i == row))
					ret[k++] = s[lo+i];

	ret[k] = '\0';
	return ret;
}

int main() {
	printf("%s\n", convert("PAYPALISHIRING", 3));

	return 0;
}

