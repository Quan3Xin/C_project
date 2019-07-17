#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define STACKINITSIZE 100
#define STACKINCREASESIZE 20

typedef struct  {
    char job;
    int age;
    float height;
}Info;
typedef int ElemType;
typedef struct tree
{
    ElemType data;
    struct tree *lchild;
    struct tree *rchild;
    unsigned int isOut;

}TreeNode, *Tree;

typedef struct stack
{
    Tree *base;
    Tree *top;
    int stacksize;
}Sqstack;


void InitStack(Sqstack *s);
void Push(Sqstack s, Tree e);
void GetTop(Sqstack s, Tree e);
void StackEmpty(Sqstack s);


void CreateTree(Tree t);
void PreOrder(Tree t);
void PreOder1(Tree t);
void InOder(Tree t);
void PoserOder(Tree t);


int main()
{
    Info a;
    Info *prt = &a;
    
    prt->age = 4;
    printf("stars -->>%d\n",a.age);
    
    char *ef = "hello";
    char *af = "\"{hello}\"";
    for(int i = 0; i < 8; i++){
    
    
    }
    char *b = af;
    printf("af with b is -00>> %s\n", b);
    printf("af is -00>> %s\tlen is >%d\n",ef, strlen(ef));
    printf("ef is -00>> %s\tlen is >%d\n",af, strlen(af));



   
    
    return 0l;
}

void InitStack(Sqstack *s)
{
   s->base  = (Tree *)malloc(STACKINCREASESIZE *sizeof(Tree));

}
void Push(Sqstack s, Tree e);
void GetTop(Sqstack s, Tree e);
void StackEmpty(Sqstack s);

void PreOrder(Tree t);
void PreOder1(Tree t);
void InOder(Tree t);
void PoserOder(Tree t);
