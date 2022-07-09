#include <stdio.h>
#include <locale.h>
#include <stdlib.h>



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
    input_node(1);
    input_node(2);
    input_node(3);
    input_node(4);
    input_node(5);
    input_node(6);
    input_node(7);
    input_node(8);
    input_node(9);

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
