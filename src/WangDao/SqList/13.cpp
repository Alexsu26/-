/*
主要利用一个大小为n的数组，若有大于n的元素值，则一定会有
小于n的元素值不在数组中；
*/
#include <iostream>
#include <cstring>
using namespace std;

int FindMin(int a[], int n)
{
    int i, *b;
    b = (int *)malloc(n*sizeof(int *));
    memset(b,0,sizeof(int));

    for(i=0; i<n; i++)
        if(a[i] > 0 && a[i] <= n)
            b[a[i] - 1] = 1;
    for(i=0; i<n; i++)
        if(!b[i])
            break;
    return i+1;
}

int main()
{
    int a[] = {1,2,3,7,5};
    cout << FindMin(a, 5);

    return 0;
}