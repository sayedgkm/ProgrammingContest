// ==========================================================================
//
//                   Bismillahir-Rahmanir-Rahim
//
// ==========================================================================
#include <bits/stdc++.h>
#define        ll                              long long
#define        f(x,y,z)                        for(int x=y;x<z;x++)
#define        take1(a);                       scanf("%d",&a);
#define        take2(a,b);                     scanf("%d%d",&a,&b);
#define        take3(a,b,c);                   scanf("%d%d%d",&a,&b,&c);
#define        take4(a,b,c,d);                 scanf("%d%d%d%d",&a,&b,&c,&d);
#define        pii                             pair<int,int>
#define        mem(a,x)                        memset(a,x,sizeof(a))
#define        N                               1000010
#define        M                               1000000007
#define        pi                              acos(-1.0)
#define        ff                              first
#define        ss                              second
#define        pb                              push_back
using namespace std;
ll C[1000];
ll b(int n, int k)
{
    memset(C, 0, sizeof(C));

    C[0] = 1;

    for (int i = 1; i <= n; i++)
    {

        for (int j = min(i, k); j > 0; j--)
                C[j] = C[j] + C[j-1];
    }
    return C[k];
}
int main()
{
    int n;
    cin>>n;
    cout<<b(n,5)+b(n,6)+b(n,7)<<endl;
      return 0;
}