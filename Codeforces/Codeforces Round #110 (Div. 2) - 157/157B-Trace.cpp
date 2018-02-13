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
int ar[105];
int main()
{
    int n;
    cin>>n;
    f(i,1,n+1){
     cin>>ar[i];
    }
    sort(ar+1,ar+n+1);
    double ans=0;
    for(int i=n;i>=1;i-=2){
            double p=(double)ar[i];
           double q=(double)ar[i-1];
           //cout<<p<<" "<<q<<endl;
            ans+=pi*(p*p-q*q);
    }
    printf("%.10lf\n",ans);
      return 0;
}