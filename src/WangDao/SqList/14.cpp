/*
基本思路是每次循环只改变最小项，缩短三者之间的距离
*/
#include <iostream>
using namespace std;
int abs_(int x)
{
    if(x>0)
        return x;
    else
        return -x;
}
bool MinOfTrip(int x, int y, int z)
{
    if(x<=y && x<=z)
        return true;
    else
        return false;
}

int FindMinOfTrip(int a[], int m, int b[], int n, int c[], int k)
{
    int min = 1000000;
    int i=0,j=0,l=0;
    while(i<m && j<n && l<k && min>0)
    {
        int d = abs_(a[i] - b[j]) + abs_(a[i] - c[l]) + abs_(b[j] - c[l]);
        if(d < min)
            min = d;
        if(MinOfTrip(a[i],b[j],c[l]))
            i++;
        else if(MinOfTrip(b[j],a[i],c[l]))
            j++;
        else 
            l++;
    }
    return min;
}

int main()
{
    int a[] = {-1,0,9};
    int b[] = {-25,-10,10,11};
    int c[] = {2,9,10,31,40};

    cout << FindMinOfTrip(a,3,b,4,c,5);

}