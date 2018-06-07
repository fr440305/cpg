#include <stdio.h>


// 0 1 2 3 4 5
// 6 4 3 6 5 3

//     6
//  6     3
// 4 5   3

//
void swap(int* arr, int i, int j) {
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

void build(int* arr, int len) {
    int i;
    int left;
    int right;
    /* swim (bottom-up fixing) */
    for (i = len/2 - 1; i >= 0; --i) {
        left = 2 * i + 1;
        right = 2 * i + 2;
        if (left < len && arr[left] > arr[i])
            swap(arr, i, left);
        if (right < len && arr[right] > arr[i])
            swap(arr, i, right);
    }
}

void pop_and_fix(int* arr, int len) {
    int root, left, right, max;

    while (len > 0) {
        /* pop: */
        swap(arr, 0, len-1);
        len -= 1;
        /* fix: */
        root = 0;
        while (root < len) {
            max = root;
            left = 2 * root + 1;
            right = 2 * root + 2;
            if (left < len && arr[left] > arr[root])
                max = left;
            if (right < len && arr[right] > arr[max])
                max = right;
            if (max == left) {
                swap(arr, root, left);
                root = left;
            } else if (max == right) {
                swap(arr, root, right);
                root = right;
            } else {
                break;
            }
        }
    }
}

void heap_sort(int* arr, int len) {
    build(arr, len);
    pop_and_fix(arr, len);
}

int main() {
    int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int i;

    heap_sort(arr, 9);
    for (i = 0; i < 9; i++)
        printf("%d ", arr[i]);

    return 0;
}
