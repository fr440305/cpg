#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void arrangement_helper(char* alphabets, int* order, int len, int cap) {
	int i;
	int* map = (int*) calloc(cap, sizeof(int));

	if (len == cap) { /* base case */
		for (i = 0; i < len; i++) {
			printf("%c", alphabets[order[i]]);
		}
		printf("\n");
	} else {
		for (i = 0; i < len; i++)
			map[order[i]] = 1;
		for (i = 0; i < cap; i++) {
			if (map[i] == 0) {
				order[len] = i;
				arrangement_helper(alphabets, order, len+1, cap);
			}
		}
	}

	free(map);
}

void arrangement(char* str) {
	int table[256] = {0};
	char* new_str;
	int new_str_len = 0;
	int* order;
	int i, j;

	for (i = 0; str[i] != '\0'; i++) {
		if (table[str[i]] == 0) {
			table[str[i]] = 1;
			new_str_len++;
		}
	}
	new_str = (char*) malloc((new_str_len + 1) * sizeof(char));
	for (i = 0, j = 0; j < 256; j++) {
		if (table[j] == 1) {
			new_str[i] = (char)(j);
			i++;
		}
	}
	new_str[i] = '\0';
	order = (int*) malloc(new_str_len * sizeof(int));
	arrangement_helper(new_str, order, 0, new_str_len);

	free(new_str);
	free(order);
}

int main() {
	arrangement("aabbcc");
	return 0;
}

