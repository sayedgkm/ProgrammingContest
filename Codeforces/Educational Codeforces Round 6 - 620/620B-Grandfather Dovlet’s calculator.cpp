// ==========================================================================
//
//                   Bismillahir-Rahmanir-Rahim
//
// ==========================================================================
#include <bits/stdc++.h>
#define        ll                    long long
#define        f(x,y,z)              for(int x=y;x<z;x++)
#define        take1(a);             int a;scanf("%d",&a);
#define        take2(a,b);           int a;int b;scanf("%d%d",&a,&b);
#define        take3(a,b,c);         int a;int b;int c;scanf("%d%d%d",&a,&b,&c);
#define        take4(a,b,c,d);       int a;int b;int c;int d;scanf("%d%d%d%d",&a,&b,&c,&d);
#define        pii                   pair<int,int>
#define        mem(a,x)              memset(a,x,sizeof(a))
#define        N                     1000010
#define        M                     1000000007
#define        pi                    acos(-1.0)
#define        ff                    first
#define        ss                    second
#define        pb                    push_back
using namespace std;
int ar[]={6,2,5,5,4,5,6,3,7,6,0};
int main()
{
    ll a,b,p;
    cin>>a>>b; ll ans=0;
    f(i,a,b+1){
        p=i;
       while(p){
         ans+=ar[p%10];
           p/=10;
        }

    }
    cout<<ans<<endl;

   return 0;
}