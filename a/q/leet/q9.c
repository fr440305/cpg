#include <stdbool.h>
#include <stdio.h>

bool isPalindrome(int x) {
	long ori = x, rev = 0;

	if (ori < 0)
		return false;
	while (x != 0) {
		rev *= 10;
		rev += x % 10;
		x /= 10;
	}

	return ori == rev;
}

int main() {
	printf("%d", isPalindrome(121));

	return 0;
}

