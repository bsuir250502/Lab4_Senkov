#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib1.h"

#define STR_MAX 15

typedef struct line {
    char symbol;
    struct line *next;
} line_t;

typedef struct tree {
    line_t *line;
    int symbol_num;
    struct tree *left;
    struct tree *right;
} tree_t;

void str_input(char *information, char *input_text, int max_number_of_symbols);
void file_output(char *file_name);
tree_t *tree_filling(tree_t *tree);
tree_t *tree_creat(tree_t *tree, int elem_num);
tree_t *add_tree_elem(tree_t *n_elem, int elem_num);
int compare_elems(tree_t **tree, tree_t **elem, tree_t **n_elem, int elem_num);
int line_filling(line_t **line);
int check_line(line_t *line, int symbol_num);
tree_t *elems_reversal(tree_t *tree);
void revers(tree_t **tree, int symbol_num, line_t *line);
void see_tree(tree_t *tree);

int main(int argc, char **argv)
{
    if (argc > 1 && !strcmp(argv[1], "-h")) {
        file_output("README.txt");
        return 0;
    }
    tree_t *tree;
    tree = NULL;
    tree = tree_filling(tree);
    puts("\nReview of the tree (first order):");
    see_tree(tree);
    puts("\nReview of the tree (second order):");
    tree = elems_reversal(tree); 
    see_tree(tree);
    return 0;
}

tree_t *tree_filling(tree_t *tree)
{
    tree_t *elem, *n_elem;
    char add_elem[STR_MAX];
    int elem_num = 0;
    elem = NULL;
    n_elem = NULL;
    tree = tree_creat(tree, elem_num);
    elem_num ++;
    do {
        compare_elems(&tree, &elem, &n_elem, elem_num);
        str_input("\nFor add one more elem, press '+' , or put something:\n", add_elem, STR_MAX);
        elem_num ++;
    } while (!strcmp(add_elem, "+"));
    return tree;
}

tree_t *tree_creat(tree_t *tree, int elem_num)
{
    puts ("\n------------ Input of all info -------------\n"
          "* by-character input of line.\n"
          "* (for input stop press 's')\n"
          "\nput info in root of tree:");
    tree = add_tree_elem(tree, elem_num);
    puts("");
    return tree;
}

tree_t *add_tree_elem(tree_t *n_elem, int elem_num) 
{
    printf(" info for elem num %d): \n",elem_num + 1);
    n_elem = (tree_t *)malloc(sizeof(tree_t));
    do {
        n_elem->symbol_num = line_filling(&(n_elem->line));
    } while (!(check_line(n_elem->line, n_elem->symbol_num)));
    n_elem->left = NULL;
    n_elem->right = NULL;
    return n_elem;
}

int compare_elems(tree_t **tree, tree_t **elem, tree_t **n_elem, int elem_num)
{
    *elem = *tree;
        *n_elem = add_tree_elem(*n_elem, elem_num);
        while(1) {
            if ((*n_elem)->symbol_num < (*elem)->symbol_num) {
                if ((*elem)->left != NULL) {
                    (*elem) = (*elem)->left; 
                }  
                else {
                    (*elem)->left = (*n_elem);
                    break;
                }               
            } 
            else  {
                if ((*elem)->right != NULL) {
                    (*elem) = (*elem)->right;
                }  
                else {
                    (*elem)->right = (*n_elem);
                    break;
                }            
            }
        }
    return 1;
}

int line_filling(line_t **line) 
{
    int symbol_num = 0;
    *line = NULL;
    line_t *new_line = *line;
    while(1) { 
        *line = (line_t *)malloc(sizeof(*line));
        (*line)->symbol = getchar();
        (*line)->next = new_line;
        new_line = *line;
        symbol_num ++;
        if (getchar() == '\n') {
            if((*line)->symbol == 's') {
                puts("end of this line.");
                break; 
            }
        }
    }
    *line = (*line)->next;
    return (symbol_num - 1);
}

int check_line(line_t *line, int symbol_num)
{
    int i, j1, j2, j3, j4, j5, j6;
    j1 = j2 = j3 = j4 = j5 = j6 = 0;
    for (i = 1; i < symbol_num + 1; i++) {
        if (line->symbol == '(') {
            j1 = i;
        }
        if (line->symbol == ')') {
            j2 = i;
        }
        if (line->symbol == '[') {
            j3 = i;
        }
        if (line->symbol == ']') {
            j4 = i;
        }
        if (line->symbol == '{') {
            j5 = i;
        }
        if (line->symbol == '}') {
            j6 = i;
        }
        line = line->next;
    }
    if (j1 > j2 || j3 > j4 || j5 > j6 || (j1 != 0 && j2 == 0)||
       (j1 == 0 && j2 != 0)||(j3 == 0 && j4 != 0)||(j3 != 0 && j4 == 0)||
       (j5 == 0 && j6 != 0)||(j5 != 0 && j6 == 0)) {
        puts ("Wrong line. Try again.");
        return 0;
    }
    return 1;
}

tree_t *elems_reversal(tree_t *tree) 
{
    tree_t *rev_tree;
    line_t *elem;
    int num;
    rev_tree = tree;
    while (rev_tree->left) {
        rev_tree = rev_tree->left;
    }
    num = rev_tree->symbol_num;
    elem = rev_tree->line;
    rev_tree = tree;
        while (rev_tree->right) {
        rev_tree = rev_tree->right;
    }
    revers(&tree, rev_tree->symbol_num, rev_tree->line);
    revers(&tree, num, elem);
    return tree;
}

void revers(tree_t **tree, int symbol_num, line_t *line)
{   
    static int i = 0; 
    if (i != 0) {
        if ((*tree)->right) {
            revers(&((*tree)->right), symbol_num, line);
        }
        else {
            (*tree)->symbol_num = symbol_num;
            (*tree)->line = line; 
        } 
    }
    else { 
        if ((*tree)->left) {
            revers(&((*tree)->left), symbol_num, line);
        }
        else {
            (*tree)->symbol_num = symbol_num;
            (*tree)->line = line;
            i++;
            return ;
        }
    }
}

void see_tree(tree_t *tree) 
{
    line_t *see_elem;
    if (tree) {
        see_tree(tree->right);
    }
    if (tree) {
        see_elem = tree->line;
        while(see_elem) {
            printf("%c", see_elem->symbol);
            see_elem = see_elem->next;
        }
    }
    else {
        puts("");
    }
    if (tree) {
        see_tree(tree->left);
    }
}