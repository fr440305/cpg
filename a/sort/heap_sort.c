#include <stdio.h>

void swap(int* arr, int i, int j) {
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

void build(int* arr, int len) {
    int top, left, right;
    /* bottom-up fixing: */
    for (top = len/2 - 1; top >= 0; --top) {
        left = 2 * top + 1;
        right = left + 1;
        if (left < len && arr[left] > arr[top])
            swap(arr, top, left);
        if (right < len && arr[right] > arr[top])
            swap(arr, top, right);
    }
}

void pop_all(int* arr, int len) {
    int top, left, right, max;

    while (len > 0) {
        /* pop the max element: */
        swap(arr, 0, len-1);
        len -= 1;
        /* top-down fixing: */
        top = max = 0;
        while (top < len) {
            left = 2 * top + 1;
            right = left + 1;
            if (left < len && arr[left] > arr[top])
                max = left;
            if (right < len && arr[right] > arr[max])
                max = right;
            if (max != left && max != right)
                break;
            swap(arr, top, max);
            top = max;
        }
    }
}

void heap_sort(int* arr, int len) {
    build(arr, len);
    pop_all(arr, len);
}

int main() {
    int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int i;

    heap_sort(arr, 9);
    for (i = 0; i < 9; i++)
        printf("%d ", arr[i]);

    return 0;
}
