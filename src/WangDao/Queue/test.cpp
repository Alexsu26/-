#include <iostream>
#include <queue>
#include <stack>
using namespace std;
void PrintQueue(queue<int> queue)
{
    while(!queue.empty())
    {
        cout << queue.front() << " ";
        queue.pop();
    }
    cout << "\n";
}

double Pnx( int n , double x)
{
    if( n == 0 )
        return 1;
    else if( n== 1)
        return 2*x;
    else
    {
        double p1 = 2 * x * Pnx(n-1,x);
        double p2 = 2 * (n-1) * Pnx(n-2, x);
        return p1 - p2;
    }
}

double p(int n, double x)
{
    struct stack
    {
        int n;
        double value;
    }st[10];
    int top = -1, i;
    double fv1 = 1, fv2 = 2*x;
    for(i = n; i>=2; i--)
    {
        top++;
        st[top].n = i;
    }
    while( top >= 0)
    {
        st[top].value =2*x*fv2 - 2*(st[top].n - 1) * fv1;
        fv1 = fv2;
        fv2 = st[top].value;
        top--;
    }
    if(n==0) return fv1;
    return fv2;
}
double p_test(int n, double x)
{
    int value[10];
    int top = 2;
    value[0] = 1, value[1] = 2*x;
    while( top <= n)
    {
        value[top] = 2*x*value[top-1] - 2*(top-1)*value[top-2];
        top++;
    }
    return value[top-1];
}
int main()
{
    cout << Pnx(5,4) << "\n";
    // PrintQueue(Q);
    cout << p(5,4) << "\n";
    cout << p_test(5,4);
    return 0;
}