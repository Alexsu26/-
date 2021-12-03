#include <iostream>

using namespace std;

typedef int Elemtype;

typedef struct LNode
{
    int data;
    LNode* next;
}LNode;

void build_L(int a[], int len, LNode* L)
{
    LNode *p = L;
    for(int i=0; i<len; i++)
    {
        LNode *temp = new LNode();
        temp->data = a[i];
        temp->next = NULL;
        p->next = temp;
        p = p->next;
    }
    p->next = NULL;
}

void Print_No_Head(LNode *L)
{
    LNode *p = L;
    if( p != NULL )
        cout << p->data << " ";
    if( p->next != NULL )
        Print_No_Head(p->next);
}

void Print_Head(LNode *L)
{
    LNode *p = L->next;
    while( p != NULL )
    {
        cout << p->data << " ";
        p = p->next;
    }
}



void ReSortLL(LNode *L)

{

LNode *rL = L->next;

LNode *p, *r, *head;

while( rL->next != NULL )

{

p = rL->next;

head = p;

while( p->next != NULL )

{

r = p->next;

p->next = r->next;

r->next = head;

head = r;

}

rL->next = head;

rL = rL->next;

}

}







int main()
{
    int a[] = {1,2,3,4,5,6,7};
    LNode *L = new LNode();
    L->next = NULL;
    build_L(a, 7, L);
    Print_Head(L);
    cout << "\n";
    
    // int b[] = {5,7,11,13};
    // LNode *L2 = new LNode();
    // L2->next = NULL;
    // build_L(b, 4, L2);
    // Print_Head(L2);
    // cout << "\n";
    
    //打印
    // Print_No_Head(L->next);
    // cout << "\n";
    // Print_Head(L);
    // cout << "\n";

    //测试代码
    ReSortLL(L);

    
    Print_Head(L);
    return 0;
}