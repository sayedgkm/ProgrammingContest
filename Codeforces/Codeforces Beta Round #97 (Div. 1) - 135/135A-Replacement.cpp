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
ll ar[N];
int main()
{
    int n;take1(n);ll mx=0,j;
    f(i,0,n) {take1(ar[i]);
    if(ar[i]>mx) mx=ar[i],j=i;
    }
    ar[j]==1?ar[j]=2:ar[j]=1;
    sort(ar,ar+n);
    f(i,0,n) cout<<ar[i]<<" ";
    puts("");
      return 0;
}