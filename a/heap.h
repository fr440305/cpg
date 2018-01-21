#ifndef _HEAP_H_ 
#define _HEAP_H_

#define _HEAP_H_DEBUG_

/* max heap */
typedef struct heap_T {
	int len;
	int cap;
	int* arr;
} Heap;

int heap_Ini (Heap* h, int* arr, int len);

void heap_Add (Heap* h, int key);

int heap_Del (Heap* h);

void heap_Print (Heap h);

#endif

