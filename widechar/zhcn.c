#include <stdio.h>
#include <string.h>
#include <wchar.h>

int main() {
	wchar_t ni = L'你';
	char nihao[] = "你好啊.";

	printf("sizeof(wchar_t) == %lu\n%s len == %lu", sizeof(wchar_t), nihao, strlen(nihao));

	return 0;
}

