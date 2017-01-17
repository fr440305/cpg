#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#if 0
typedef struct _arr_node{
	char c;
	char * entire;
	struct _arr_node * prev;
	struct _arr_node ** children;
}ArrNode;


int printree (ArrNode *node) {
	int i;
	int children_quantity;
	ArrNode *father = node;

	if (strlen(node->entire) == 1) {
		children_quantity = 0;
	} else {
		for (children_quantity = 0; node->children[children_quantity] != NULL; children_quantity++);
	}

	if (strlen(node->entire) == 1) {
		/*leaf node*/
		printf("%c", father->entire[0]);
		while (father->prev != NULL) {
			printf("%c", father->c);
			father = father->prev;
		}
		printf("\n");
	} else {
		/*sub but not leaf*/
		for (i = 0; i < children_quantity; i++) { printree(node->children[i]); }
	}
	return 0;
}

ArrNode * construct_arrangement_tree (ArrNode * node) {
	int entire_len;
	int loop;
	int i;
	char * child_entire;

	if (strlen(node->entire) == 1) {
		return node;
	} else {
		entire_len = strlen(node->entire);
		node->children = (ArrNode **) calloc (entire_len + 1, sizeof(ArrNode*));
		/*make love */
		for (loop = 0; loop < entire_len; loop++) {
			child_entire = (char *)calloc (entire_len, sizeof(char));
			for (i = 0; i < entire_len; i++) {
				if (i < loop) {
					child_entire[i] = node->entire[i];
				} else if (i >= loop) {
					child_entire[i] = node->entire[i + 1];
				} else {
					printf("Excuse me??");
				}
			}
			node->children[loop] = (ArrNode*)calloc(1, sizeof(ArrNode));
			node->children[loop]->prev = node;
			node->children[loop]->c = node->entire[loop];
			node->children[loop]->entire = child_entire;
			//printf("%c, %s\n", node->children[loop]->c, node->children[loop]->entire);
			construct_arrangement_tree(node->children[loop]);
		}
	}
	return node;
}

ArrNode * arrangement (char * ori_string) {
	int printree (ArrNode *node);
	ArrNode * construct_arrangement_tree (ArrNode * node);
	ArrNode * node = (ArrNode*)calloc(1, sizeof(ArrNode));
	node->c = 0;
	node->prev = NULL;
	node->entire = ori_string;
	construct_arrangement_tree(node);
	printf("construct successfully\n");
	printree(node);
	free(node);
	return NULL;
}
#endif
int arrangement (char *leading, char *entire) {
	char *char_cata = NULL;
	char *leading_next = NULL;
	char *entire_next = NULL;
	int i;
	/*index() test */
	char *s = "asd";
	printf ("%s", strchr(s, 'w'));

	/*transform entire to char_cata; */
	for (i = 0; entire[i] != 0; i++) {
		char_cata = (char*) realloc (char_cata, sizeof(char) * (char_cata == NULL ? 0 : (strlen(char_cata)+1)) );
	}


	return 0;
	
}

int main () {
	int arrangement (char *leading, char *entire);
	return arrangement (NULL, NULL);
	
#if 0
ArrNode * arrangement (char * ori_string);
char *oristr;
printf("Input string:");
scanf("%s", oristr);
arrangement(oristr);
return 0;
#endif
	
}
