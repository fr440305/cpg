#include <stdio.h>

typedef struct avl_Node_T {
	struct avl_Node_T l;
	struct avl_Node_T r;
	struct avl_Node_T p;
	/* balance factor:
	 * nil.bf = -1;
	 * => leaf.bf = 0;
	 * n.bf = n.r.bf - n.l.bf
	 */
	int bf;
	int k; /* key */
	char* v; /* value */
} avl_Node;

typedef struct {
	Node root;
	unsigned int len; /* # of nodes */
} Avl;

void avlIni (Avl* tree) {
	tree->root = NULL;
	tree->len = 0;
}

Node* avl_find_node (Node* n, int key) {
	if (n == NULL || key == n->k) {
		return n;
	} else if (key < n->k) {
		return avl_find_node(n->l, key);
	} else {
		return avl_find_node(n->r, key);
	}
}

int avlFind (Avl tree, int key, char** val) {
	Node* res = avl_find_node(tree.root, key);
	if (res == NULL) {
		return 0; /* not found */
	} else {
		*val = res->v;
		return 1;
	}
}

/* If key already exists, then overwrite it. */
int avlAdd (Avl* tree, int key, char* val) {

}

int avlDel (Avl* tree, int key) {
}

int avlPrt (Avl tree) {
}

int main () {
	return 0;
}
