#ifndef _sort_funcs_h_
#define _sort_funcs_h_

void knuth_shuffle(int* arr, int len);

/* insertion_sort.c */
void linear_insertion_sort(int* arr, int len);
void binary_insertion_sort(int* arr, int len);

/* merge_sort_myself.c */
void merge_sort_recursive(int* arr, int len);
void merge_sort_loop(int* arr, int len);

/* merge_sort_alog4.c */
void merge_sort_top_down(int* arr, int len); /* with recursive */
void merge_sort_bottom_up(int* arr, int len); /* with loop */

void heap_sort(int* arr, int len);

/* sort by building a binary search tree with AVL rotating operations */
void avl_sort(int* arr, int len);

#endif
