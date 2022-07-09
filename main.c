#include <stdio.h>
#include <locale.h>
#include <stdlib.h>


#define RA_1 2
#define RA_2 0
#define RA_3 1
#define RA_4 5
#define RA_5 1
#define RA_6 8
#define RA_7 9
#define RA_8 1
#define RA_9 5

typedef struct NODE {
    long digit;
    struct NODE *left;
    struct NODE *right;
    struct NODE *father;
} NODE;

typedef struct TREE {
    NODE *root;
} TREE;

TREE meu_ra;
void build_tree(TREE param_tree);
void build_node(NODE* n, int value);
void input_node(int value);
void pre_order_algo(NODE* root);


int main() {
    printf("Hello, World!\n");
    build_tree(meu_ra);
    input_node(RA_1);
    input_node(RA_2);
    input_node(RA_3);
    input_node(RA_4);
    input_node(RA_5);
    input_node(RA_6);
    input_node(RA_7);
    input_node(RA_8);
    input_node(RA_9);

    printf("Pre Order:\n");
    pre_order_algo(meu_ra.root);

    return 0;
}

void build_tree(TREE param_tree) {
    param_tree.root = NULL;
}

void build_node(NODE* n, int value) {
    if(!n) {
        printf("MEMORY ERROR\n");
        return;
    }
    n->left = NULL; n->right = NULL; n->father = NULL; n->digit = value;
}

void input_node(int value) {
    NODE* chain = meu_ra.root;
    NODE* father;
    NODE* next = (NODE*) malloc(sizeof(NODE));
    build_node(next, value);
    printf("Adding %ld", next->digit);

    if(chain == NULL){
        meu_ra.root = next;
        printf(" as root\n");
        return;
    }

    while (chain){
    father=chain;
    if(next->digit < chain->digit){
        chain = chain->left;
        if(!chain){
            printf(" to the left of %ld\n", father->digit);
            father->left = next;
            return;
        }
    } else{
        chain = chain->right;
        if(!chain){
            printf(" to the right of %ld\n", father->digit);
            father->right = next;
            return;
        }
    }
    }
}

void pre_order_algo(NODE* root) {
    if(root) {
        printf("%ld - ", root->digit);
        pre_order_algo(root->left);
        pre_order_algo(root->right);
    }
}
