#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <string.h>


#define SIMGEA  1

typedef struct binary_tree {
    int data;
    struct binary_tree *right;
    struct binary_tree *left;
}Node;

void show(void(*fp)(char *), char *str);

char *itobs(int , char*);
void show_bstr(const char *);

void insert(Node **tree, int val){
    Node *temp = NULL;
    if(!(*tree)){
        temp = (Node *)malloc(sizeof(Node));
        temp->left = temp->right = NULL;
        temp->data = val;
        *tree = temp;
        return ;
    }
    if(val < (*tree)->data){
        insert(&(*tree)->left, val);
    }else if(val > (*tree)->data){
        insert(&(*tree)->right, val);
    }

}
void printInorder(Node *tree)
{
    if(tree){
        printInorder(tree->left);
        printf("%d\n",tree->data);
        printInorder(tree->right);
    }
}
void printPostorder(Node *tree)
{
    if(tree){
        printPostorder(tree->right);
        printf("%d\n",tree->data);
        printPostorder(tree->left);
    }
}
void printPreoder(Node *tree)
{
    if(tree){
        printf("%d\n",tree->data);
        printPreoder(tree->right);
        printPreoder(tree->left);
    }
}
void delTree(Node *tree)
{
    if(tree) {
        delTree(tree->left);
        delTree(tree->right);
        free(tree);}

}


// 计算最大值
float max(double *a, int n)
{
    
 	double array=a[0];
 	for (int i=1;i<n;i++)
 	{
 		if (a[i]>array)
 		array=a[i];
	 }
	 return array;
}

int main()
{
    Node *root;
    root = NULL;
    insert(&root,9);
    insert(&root,9);
    insert(&root,10);
    insert(&root,19);
    insert(&root,4);
    insert(&root,18);
    insert(&root,4);
    printf("Pre order display\n");
    printPreoder(root);
    printf("Pre order display\n");
    printInorder(root);

    printf("Pre order display\n");
    printPostorder(root);
    delTree(root);
    char bin_str[CHAR_BIT * sizeof(int) +1];
    int number;
    puts("Enter integers and see them in binary.");
    puts("Non-numeric input terminates program.");
    while(scanf("%d", &number) == 1){
        itobs(number, bin_str);
        printf("%d\n", number);
        show_bstr(bin_str);
        printf("\n");
    }
    puts("Bye!");


    return 0;
}

char *itobs(int n, char* ps)
{
    int i;
    const static int size = CHAR_BIT * sizeof(int);
    printf("size is ->>>%d\n", size);

    for(i = size-1; i>= 0; i--, n >>= 1){
        ps[i] = (01 & n) + '0';
    }
    ps[size] = '\0';
    return ps;
}
void show_bstr(const char *str)
{
    int i = 0;
    while(str[i]){
        putchar(str[i]);
        if(++i % 4 == 0 && str[i]){
           printf(" ");    
        }
    }
}
