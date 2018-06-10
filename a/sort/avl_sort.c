#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "sort.h"


struct AvlNode_ {
	int b; /* balance factor */
	int h; /* the height of the tree */
	int k; /* key */
	struct AvlNode_ *l, *r, *u; /* left, right, up */
};

typedef struct {
	struct AvlNode_* root;
	int len;
} AvlTree;

static void avl_tree_print(AvlTree* t);

AvlTree* avl_tree_new() {
	return (AvlTree*) calloc(1, sizeof(AvlTree));
}

/* rotate the node */
static struct AvlNode_* avl_node_left_rotate(struct AvlNode_* node) {
/*
	assert(node != NULL);
	assert(node->l == NULL);
	assert(node->u != NULL);

	node->r->u = node->u;
	if (node->u->l == node) {
		node->u->l = node->r;
	} else if (node->u->r == node) {
		node->u->r = node->r;
	}

	node->r->l = node;
	node->u = node->r;
	node = node->r;
	node->l->u = node;
*/
	return node;
}

static struct AvlNode_* avl_node_right_rotate(struct AvlNode_* node) {
	return node;
}

/* Add an element into the AVL tree @t, and fix the heap
 * to make @t still satisfies the AVL property.
 * @t : the avl tree
 * @key : the key that needs to be added */
static void avl_tree_add(AvlTree* t, int key) {
	struct AvlNode_* new = (struct AvlNode_*) calloc(1, sizeof(struct AvlNode_));
	struct AvlNode_* pos = t->root;
	struct AvlNode_** next = &t->root;
	int lh, rh;

	while (*next != NULL) {
		pos = *next;
		if (key <= pos->k)
			next = &pos->l;
		else
			next = &pos->r;
	}
	new->k = key;
	new->u = pos;
	*next = new;
	/* bottom-up fixing: */

	for (pos = new; pos != NULL; pos = pos->u) {
		printf("pos{k: %d, b: %d, *u: %lu}\n", pos->k, pos->b, (unsigned long)pos->u);
		lh = (pos->l) ? pos->l->h : -1;
		rh = (pos->r) ? pos->r->h : -1;
		pos->h = (lh > rh) ? lh+1 : rh+1;
		pos->b = lh - rh;
		/* check and fix */
		if (pos->b == 2 || pos->b == -2) { /* unbalance */
			if (pos->b == 2) { /* @pos is left-heavy, '/' or '<' */
				if (pos->l->b == 1) { /* '/' */
					printf("pos[bf]:%d[%d] '/'\n", pos->k, pos->b);
					//pos = avl_node_right_rotate(pos);
				} else if (pos->l->b == -1) { /* '<' */
					printf("pos[bf]:%d[%d] '<'\n", pos->k, pos->b);
					//pos = avl_node_left_rotate(pos->l);
					//pos = avl_node_right_rotate(pos);
				}
			} else if (pos->b == -2) { /* '\' or '>' */
				if (pos->r->b == 1) { /* '>' */
					printf("pos[bf]:%d[%d] '>'\n", pos->k, pos->b);
					//pos = avl_node_right_rotate(pos->r);
					//pos = avl_node_left_rotate(pos);
				} else if (pos->r->b == -1) { /* '\' */
					printf("pos[bf]:%d[%d] '\\'\n", pos->k, pos->b);
					//pos = avl_node_left_rotate(pos);
					pos->r->u = pos->u;
					//printf("1, pos.u.l == %lu\n", (unsigned long)pos->u->l);
					if (pos->u->l == pos) {
						printf("1.1\n");
						pos->u->l = pos->r;
					} else if (pos->u->r == pos) {
						printf("1.2\n");
						pos->u->r = pos->r;
					}
					printf("2\n");
					printf("pos 的右孩子被 pos 的父亲领养\n");
					pos->r->l = pos;
					pos->u = pos->r;
					printf("pos 变成了他曾经右孩子的左孩子\n");
				}
			}
		}
	}
}

/* In-orderly traverse the tree @t, and store the
 * result into @arr. Note that the capacity of @arr
 * should be the length of the tree (@t->len).
 * @t : the avl tree
 * @arr : the pointer of the space for storing the result */
static void avl_tree_inorder_seralize(AvlTree* t, int* arr) {
}

static void avl_node_destory(struct AvlNode_* node) {
	if (node->l != NULL)
		avl_node_destory(node->l);
	if (node->r != NULL)
		avl_node_destory(node->r);

	free(node);
}

/* Release the whole tree @t */
static void avl_tree_destory(AvlTree* t) {
	avl_node_destory(t->root);
	free(t);
}

void avl_sort(int* arr, int len) {
	AvlTree* t = avl_tree_new();
	int i;

	for (i = 0; i < len; i++)
		avl_tree_add(t, arr[i]);

	avl_tree_inorder_seralize(t, arr);
	avl_tree_destory(t);
}

#define AVL_SORT_DEBUG_

#ifdef AVL_SORT_DEBUG_

void avl_node_print(struct AvlNode_* n) {
	printf("%d[%d] (", n->k, n->b);
	if (n->l != NULL)
		avl_node_print(n->l);
	printf(", ");
	if (n->r != NULL)
		avl_node_print(n->r);
	printf(") ");
}

static void avl_tree_print(AvlTree* t) {
	if (t->root == NULL)
		printf("()");
	else
		avl_node_print(t->root);
	printf("\n");
}


int main() {
	AvlTree* t = avl_tree_new();
	avl_tree_add(t, 1);
	avl_tree_add(t, 2);
	avl_tree_add(t, 3);
	avl_tree_add(t, 4);

	avl_tree_print(t);
	avl_tree_destory(t);
}

#endif

