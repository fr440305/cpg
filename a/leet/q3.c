#include <stdio.h>

int lengthOfLongestSubstring (char* s) {
        char* ptr = s;
        int len = 0;
        int ret = 0;
        int has[256] = {0};
        char after;
        while ((after = *(ptr + len)) != '\0') {
                if (!has[after]) {
                        has[after] = 1;
                        len += 1;
                        if (ret < len) {
                                ret = len;
                        }   
                } else {
                        has[*ptr] = 0;
                        ptr += 1;
                        len -= 1;
                }   
        }   
	return ret;
}

int main () {
	return 0;
}
