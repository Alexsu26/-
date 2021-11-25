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

void Divide_A(LNode *A, LNode *B)


{


LNode *p = A->next;


LNode *pb = B;


while( p != NULL )


{


pb->next = p->next;

if(p->next != NULL)
	p->next = p->next->next;

pb = pb->next;

p = p->next;


}


}




int main()
{
    int a[] = {1,2,3,4,5};
    LNode *L = new LNode();
    L->next = NULL;
    build_L(a, 5, L);
    //打印
    // Print_No_Head(L->next);
    // cout << "\n";
    // Print_Head(L);
    // cout << "\n";

    //测试代码
    
    LNode *L2 = new LNode();
    L2->next = NULL;
    
    Divide_A(L, L2);

    Print_Head(L);
    Print_Head(L2);
    return 0;
}