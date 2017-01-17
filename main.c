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
	char *char_cata = (char*) calloc (1, sizeof(char));
	char *leading_next = NULL;
	char *entire_next = NULL;
	int i, j;

	printf("\narrangement(%s, %s)\n", leading, entire);
	/* check the vaild of parameter*/
	if (leading == NULL) leading = (char *) calloc (1, sizeof(char));
	if (entire == NULL) {
		printf ("error - entire cannot be -1.");
		return (-1);
	}

	/*index() test */
	//char *s = "asd";
	//printf ("%s", strchr(s, 'w'));

	/*transform entire to char_cata; */
	//printf("\nentire - %s", entire);
	for (i = 0; i < strlen(entire); i++) {
		if (strchr(char_cata, entire[i]) == NULL) {
			/*entire[i] doesn't contains in char_cata */
			//printf("\nentire[i] - %c", entire[i]);
			//printf("\nstrlen(cata) - %d", (int)strlen(char_cata));
			char_cata = (char*) realloc (char_cata, (strlen(char_cata) + 2) * sizeof(char));
			char_cata[strlen(char_cata)] = entire[i];
		}
	}
	//printf ("\ncata - %s", char_cata);
	
	if (strlen(char_cata) != 1) {
		for (i = 0; i < strlen(char_cata); i++) {
			/* leading_next = leading + char_cata[i]; */
			leading_next = strdup(leading);
			leading_next = (char*) realloc (leading_next, sizeof(char) * (strlen(leading_next) + 3)); 
			leading_next[strlen(leading_next)] = char_cata[i];
			/*entire_next = char_cata - char_cata[i]; */
			entire_next = (char*) calloc (strlen (char_cata), sizeof(char));
			for (j = 0; j < strlen(char_cata); j++) {
				if (j < i) {
					entire_next[j] = char_cata[j];
				} else {
					entire_next[j] = char_cata[j+1];
				}
			}
			arrangement (leading_next, entire_next);
		}
	} else {
		printf ("%s%s\n", leading, entire);
	}

	return 0;
	
}

int main () {
	int arrangement (char *leading, char *entire);
	return arrangement(NULL, "ass");

	//return arrangement (NULL, "qwerty");
	
#if 0
ArrNode * arrangement (char * ori_string);
char *oristr;
printf("Input string:");
scanf("%s", oristr);
arrangement(oristr);
return 0;
#endif
	
}
