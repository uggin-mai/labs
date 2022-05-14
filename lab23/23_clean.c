#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct _node {
	int key;
    int q;
	struct _node ** sons;
} node;

node *make_node(int x) {
	node *n = malloc(sizeof(node));
	n->key = x;
    n->q = 0;
	n->sons = NULL;
	return n;
}

node * find_node(node *n, int father_key) {
    if (n->key == father_key) {
        return n;
    }
    if (n->q > 0) {
        for (int i = 0; i < n->q; ++i){
            node * son = find_node(n->sons[i], father_key);
            if (son != NULL) {
                return son;
            }
        }
        return NULL;
    } else {
        return NULL;
    }
}


void add_node(node * n, int father_key, int key) {
    if (find_node(n, key) == NULL) {
        node *parent = find_node(n, father_key);
        if (parent == NULL) {
            printf("Can't find specified parent\n");
            exit;
        }
        else {
            if (parent->q != 0) {
                parent->sons = (node **)realloc(parent->sons, sizeof(node *) * (parent->q + 1));
                parent->sons[parent->q] = make_node(key);
                parent->q++;
            } else if (parent->q == 0) {
                parent->sons = (node **)malloc(sizeof(node *));
                parent->sons[parent->q] = make_node(key);
                parent->q++;
            }
        }
    } else {
        printf("Already exists\n");
    }
}

int depth2(node *n, int level, int * leaf_levels, int leaf_count) {   
    if (n->q == 0) {


        leaf_levels[leaf_count] = level;
        leaf_count++;
        leaf_levels = (int *)realloc(leaf_levels, leaf_count * sizeof(int));


        return leaf_count;
    } else if (n->q > 0) {
        for (int i = 0; i < n->q; i++){
            leaf_count = depth2(n->sons[i], level + 1, leaf_levels, leaf_count);


        }
        return leaf_count; 
    } else {
        return -1;
    }
}

int leafs2(node * n, int level) {
    int *leaf_levels = (int *)malloc(1 * sizeof(int));
    int leaf_count = 0;
    if (n->q == 0) {
        return 1;
    } else if (n->q > 0) {
        for (int i = 0; i < n->q; i++){
            leaf_count = depth2(n->sons[i], level + 1, leaf_levels, leaf_count);
            //printf("leaf count - %d\n", leaf_count);
        }
    }

    for (int i = 0; i < leaf_count-1; i++){
        //printf("%d ", leaf_levels[i]);
    }

    for (int i = 0; i < leaf_count-2; i++){
        if (leaf_levels[i] != leaf_levels [i+1]) {
            return 0;
        }
    }


}


void free_node(node * n) {
    for (int i = 0; i < n->q; ++i){
        if (n->sons[i] != NULL) {
		    free_node(n->sons[i]);
        }
    }
    free(n->sons);
    n->sons = NULL;
	free(n);
}

void remove_element(node * n, int key) {
    if (n->key == key) {
        free_node(n);
    } else {
        for (int i = 0; i < n->q; ++i){
        if (n->sons[i]->key == key) {
		    free_node(n->sons[i]);
            for (int k = i; k < n->q - 1; k++) {
                n->sons[k] = n->sons[k+1];
            }
            n->q--;
        } else {
		    remove_element(n->sons[i], key);
        }
        }
    }
}

void print_tree_beauty(node *n, int deep) {
    for (int i = 0; i < deep; i++) {
        printf("\t");
    }
    printf("%d\n", n->key);
    if (n->q > 0) {
        for (int i = 0; i < n->q; i++){
            print_tree_beauty(n->sons[i], deep + 1);
        }

    }
}

void print_tree(node *n) {
	print_tree_beauty(n, 0);
}

bool isInt(const char*str) {
    while(*str)  {
        if((*str< '0' || *str > '9') && *str != '-' && *str != '.')
            return false;
        *str++;
    }
    return true;
}

int main() {
    printf("_________________________________________________________\n");
    printf("|                       Tree Editor                      |\n");
    printf("_________________________________________________________\n");
    printf("| Add Element - |1| Show tree - |2| Remove Element - |3| |\n");
    printf("|   Are leafs on the same depth? - |14|   Exit - |0|     |\n");
    printf("_________________________________________________________\n");
    

    char input[] = "";
    bool execute = true;
    bool isTreeCreated = false;
    int task = -1;
    node *n;
    
    while (execute) {
        char input[] = "";
        printf("\n");
        scanf("%s", input);
        if (isInt(input)) {
            if (!strcmp("0", input)) task = 0;
            if (!strcmp("1", input)) task = 1;
            if (!strcmp("2", input)) task = 2;
            if (!strcmp("3", input)) task = 3;
            if (!strcmp("14", input)) task = 14;
        } else {
            printf("Try something else :) ");
        }

        switch (task) {
            case 0:
                execute = false;
                if (isTreeCreated) {
                    free_node(n);
                }
                break;
            case 1:
                if (isTreeCreated) {
                    int keyp = 0;
                    int key = 0;
                    char p[] = "";
                    char e[] = "";
                    printf("Enter parent key\n");
                    scanf("%s", p);
                    if (!isInt(p)) {
                       printf("Try something else :) ");
                    } else {
                        keyp = atoi(p);
                        printf("Enter element key\n");
                        scanf("%s", e);
                        if (!isInt(e)) {
                        printf("Try something else :) ");
                        exit;
                        } else {
                            key = atoi(e);
                            add_node(n, keyp, key);
                        }
                    }
                } else {
                    int key = 0;
                    char e[] = "";
                    printf("Creating new tree...\n");
                    printf("Enter element key\n");
                    scanf("%s", e);
                    if (!isInt(e)) {
                        printf("Try something else :) ");
                        exit;
                        } else {
                            key = atoi(e);
                            n = make_node(key);
                            isTreeCreated = true;
                        }
                }
                break;
            case 2:
                if (isTreeCreated) {
                    print_tree(n);
                } else {
                    printf("Binary tree is not created\n");
                }
                break;
            case 3:
                if (isTreeCreated) {
                    int key = 0;
                    int rootkey = n->key;
                    char e[] = "";
                    printf("Enter element key\n");
                    scanf("%s", e);
                    key = atoi(e);
                    remove_element(n, key);
                    if (key == rootkey) isTreeCreated = false;
                } else {
                    printf("Binary tree is not created\n");
                }
                break;
            case 14:
                if (isTreeCreated) {
                    //printf("\n\n%i",leafs2(n,0));
                    /*
                    int result = leafs2(n,0);
                    if (result = 1) {
                        printf("Yes");
                    } else {
                        printf("No");
                    }
                    */
                } else {
                    printf("Binary tree is not created\n");
                }
                break;
            default:
                printf("Incorrect input");
                break;
        }
    }
	return 0;
}
