#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib1.h"

#define STR_MAX 256

typedef struct line {
    char symbol;
    struct line *next;
} line_t;

typedef struct tree {
   1 line_t *line;
    struct tree *left;
    struct tree *right;
} tree_t;

int int_input(char *information, int min, int max, FILE *file);
void file_output(char *file_name);
void help(int argc, char **argv);
tree_t *creat_tree(tree_t *tree);
int line_filling(tree_t *leaf);

int main(int argc, char **argv)
{
    tree_t *tree;
    tree = NULL;
    tree = creat_tree(tree);
    help(argc,argv);  
    return 0;
}

tree_t *creat_tree(tree_t *tree)
{
    tree = (tree_t *)malloc(sizeof(tree_t));
    puts("Enter info in root of tree");
    line_filling(tree);
    tree->left = NULL;
    tree->right = NULL;
    return tree;
}

int line_filling(tree_t *leaf) 
{
    puts("Symbols input( enter 's'):");
    do {
        leaf->line->symbol = getchar();    
    } while(leaf->line->symbol != 's');
    return 1;
}

void help(int argc, char **argv)
{
    if (argc > 1 && !strcmp(argv[1], "-h")) {
        file_output("README.txt");
        exit(0);
    }
}
