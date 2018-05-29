#include <stdio.h>
#include <stdlib.h>

typedef struct bst_Node {
	struct bst_Node* l; /* left */
	struct bst_Node* r; /* right */
	struct bst_Node* p; /* parent */
	int k; /* key */
	char* v; /* value */
} Node;

typedef struct bst_Tree {
	Node* root;
	unsigned int len;
} Bst;

void bst_Ini (Bst* tree) {
	tree->root = NULL;
	tree->len = 0;
}

int bst_Add (Bst* tree, int key, char* val) {
	Node* n = (Node*)malloc(sizeof(Node));
	Node* tr; /* trace: the insertion point */
	if (n == NULL || val == NULL) {
		return -1;
	}
	n->l = NULL;
	n->r = NULL;
	n->k = key;
	n->v = val;
	if (tree->root == NULL) {
		n->p = NULL;
		tree->root = n;
		tree->len += 1;
		return 0;
	}
	tr = tree->root;
	while (1) {
		if (key < tr->k) {
			if (tr->l == NULL) {
				/* insert */
				tr->l = n;
				n->p = tr;
				tree->len += 1;
				return 0;
			} else {
				tr = tr->l;
			}
		} else {
			if (tr->r == NULL) {
				tr->r = n;
				n->p = tr;
				tree->len += 1;
				return 0;
			} else {
				tr = tr->r;
			}
		}
	}
}

Node* bst_find_node (Node* n, int key) {
	if (n == NULL) {
		return NULL;
	}
	if (key == n->k) {
		return n;
	} else if (key > n->k) {
		/* maybe in right sub tree */
		return bst_find_node(n->r, key);
	} else {
		/* key > n->k */
		/* maybe in left sub tree */
		return bst_find_node(n->l, key);
	}
}

int bst_Find (Bst tree, int key, char** ret) {
	Node* res = bst_find_node(tree.root, key);
	if (res == NULL) {
		return 0;
	}
	*ret = res->v;
	return 1;
}

/* TODO */
int bst_Del (Bst* tree, int key) {
	Node* n;
	Node* leaf;
	if ((n = bst_find_node(tree->root)) == NULL) {
		return -1;
	}
	leaf = n;
	while (leaf->l != NULL || leaf->r != NULL) {
		leaf = leaf->l;
	}

	/*
	n->r->p = leaf;
	if (n->r->k < leaf->k) {
		leaf->l = n->r;
	} else {
		leaf->r = n->r;
	}
	*/
	return 0;
}

void bst_print_root (Node* n) {
	if (n == NULL) {
		printf(" NIL ");
		return;
	}
	printf("%d (", n->k);
	bst_print_root(n->l);
	bst_print_root(n->r);
	printf(")");
}

void bst_Print (Bst tree) {
	printf("Bst: ");
	bst_print_root(tree.root);
	printf("\n");
}

void bst_print_seq (Node* n) {
	if (n != NULL) {
		bst_print_seq(n->l);
		printf("%d ", n->k);
		bst_print_seq(n->r);
	}
}

void bst_PrintSeq (Bst tree) {
	printf("BstSeq: ");
	bst_print_seq(tree.root);
	printf("\n");
}

int main () {
	Bst* tree = (Bst*)malloc(sizeof(Bst));
	char* find;
	bst_Ini(tree);
	bst_Add(tree, 1, "one");
	bst_Add(tree, 0, "zero");
	bst_Add(tree, 3, "three");
	bst_Add(tree, 2, "two");
	bst_Add(tree, 5, "five");
	bst_Add(tree, 4, "four");
	bst_Add(tree, 7, "seven");
	bst_Add(tree, 6, "six");

	bst_Print(*tree);
	bst_PrintSeq(*tree);
	if (bst_Find(*tree, 34, &find)) {
		printf("    %s", find);
	} else {
		printf("    Not Found");
	}

	return 0;
}
