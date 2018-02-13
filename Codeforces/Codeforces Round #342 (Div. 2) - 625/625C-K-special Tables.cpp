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
int ar[505][505];
int main()
{
    int n,a;
    cin>>n>>a;
    int number=n*n-(n-a+1)*n; ll sum=0;
    f(i,0,n){
        f(j,a-1,n)
           ar[i][j]=++number;
        sum+=ar[i][a-1];
    }
           number=0;
        f(i,0,n) f(j,0,a-1)
          ar[i][j]=++number;
          cout<<sum<<endl;
          f(i,0,n){ f(j,0,n) cout<<ar[i][j]<<" ";
          puts("");}

}