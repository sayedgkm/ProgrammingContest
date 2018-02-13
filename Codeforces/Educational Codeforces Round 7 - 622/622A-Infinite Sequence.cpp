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
int main()
{
    ll n;
    cin>>n; ll q;
    double p=(-1+sqrt(2*n*4+1))/2.0;

    ll res=p;
    ll ans=res*(res+1)/2;
   //cout<<res<<endl;
    if(n==ans){
            res--;
        q=n-(res*(res+1))/2;
    }
    else q=n-ans;
    cout<<q<<endl;
      return 0;
}