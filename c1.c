#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10

typedef struct SeqList{
    int* elem;
    int length;
    int size;
}SeqList, *PSeqList;

void InitList(PSeqList pList, int initSize) {
    pList->elem = (int* )malloc(initSize * sizeof(int));
    pList->size = initSize;
    pList->length = 0;
}


//静态链表的构建

typedef struct {
    int data;
    int cursor;
}Component, StaticList[MAXSIZE];

void initial(StaticList space, int *av) {
    int k;
    space[0].cursor = -1;
    for(k = 1; k < MAXSIZE - 1; k++) {
        space[k].cursor = k + 1;
    }
    space[MAXSIZE - 1].cursor = -1;
    *av = 1;
}

int getNode(StaticList space, int *av) {
    int i;
    i = *av;
    *av = space[*av].cursor;
    return i;
}

void freeNode(StaticList space, int *av, int k) {
    space[k].cursor = *av;
    *av = k;
}

/*构建完成*/


/*多项式相加或多项式相乘*/

typedef struct PolyNode {
    int coef;
    int exp;
    struct PolyNode* next;
}Polynode, *Polylist;        //多项式的结点构建

Polylist PolyCreate() {
    Polynode *head, *rear, *s;
    int co, ex, num;
    head = (Polynode* )malloc(sizeof(Polynode));
    rear = head;
    scanf("%d", &num);
    for(int i = 0; i < num; i++) {
        s = (Polynode* )malloc(sizeof(Polynode));
        scanf("%d %d", &s->coef, &s->exp);
        rear->next = s;
        rear = s;
    }
    rear->next = NULL;
    return head;
}

//加和多项式函数
void sumPoly(Polylist polya, Polylist polyb) {
    Polynode* p1, *p2, *temp, *tail;
    int sum;
    p1 = polya->next;
    p2 = polyb->next;
    tail = polya;
    while(p1 && p2) {
        if(p1->exp < p2->exp) {
            tail->next = p1;
            tail = p1;
            p1 = p1->next;
        }

        else if(p1->exp == p2->exp) {
            sum = p1->coef + p2->coef;
            if(sum == 0) {
                temp = p1;
                p1 = p1->next;
                free(temp);
            }
            else {
                p1->coef = sum;
                tail->next = p1;
                tail = p1;
                p1 = p1->next;
            }
            p2 = p2->next;
        }

        else {
            tail->next = p2;
            tail = p2;
            p2 = p2->next;
        }
    }

    while(p1 != NULL) {
        tail->next = p1;
        tail = tail->next;
        p1 = p1->next;
    }

    while(p2 != NULL) {
        tail->next = p2;
        tail = tail->next;
        p2 = p2->next;
    }
    tail->next = NULL;
}



//打印我的得到的加和多项式
void printPoly(Polylist poly) {
    Polynode* temp = poly->next;
    while(temp) {
        printf("%dx^%d", temp->coef, temp->exp);
        if (temp->next != NULL)
            printf(" + ");
        temp = temp->next;
    }
    printf("\n");
}


//释放多项式函数
void freePoly(Polylist poly) {
    Polynode* temp = poly->next;
    Polynode* s;
    while(temp != NULL) {
        s = temp;
        temp = temp->next;
        free(s);
    }
}

/*多项式加和部分代码构建完成*/

int main(void) { 
    Polylist polya, polyb;
    polya = PolyCreate();
    polyb = PolyCreate();
    printPoly(polya);
    printPoly(polyb);
    sumPoly(polya, polyb);
    printPoly(polya);
    freePoly(polya);
    freePoly(polyb);
    return 0;
}