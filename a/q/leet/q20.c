#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool isValid(char* s) {
	int stack[2048];
	int top = 0;
	int i;
	int table['}'+1] = {0};
	table['('] = 1; table[')'] = -1;
	table['['] = 2; table[']'] = -2;
	table['{'] = 3; table['}'] = -3;

	for(i = 0; s[i] != '\0'; i++)
		if (table[s[i]] > 0)
			stack[++top] = table[s[i]];
		else if (table[s[i]] < 0)
			if (top == 0 || stack[top] + table[s[i]] != 0)
				return false;
			else
				top -= 1;
		else
			return false;

	return top == 0;
}

int main() {
	printf("\n\n==%d", isValid("["));

	return 0;
}

