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
#define        pii                   pair<ll,ll>
#define        mem(a,x)              memset(a,x,sizeof(a))
#define        N                     100010
#define        M                     1000000007
#define        pi                    acos(-1.0)
#define        ff                    first
#define        ss                    second
#define        pb                    push_back
using namespace std;
pii ar[N];ll sum[N];
int main()
{
    ll n,d;
    cin>>n>>d;
    f(i,1,n+1) {cin>>ar[i].ff>>ar[i].ss;

    }
    sort(ar+1,ar+n+1);
    f(i,1,n+1)
        sum[i]=sum[i-1]+ar[i].ss;
    int p=1;ll mx=0;
    f(i,1,n+1){
         while(ar[i].ff-ar[p].ff>=d){
                 p++;
          }
          //cout<<ar[i].ff-ar[p].ss<<endl;
      mx=max(mx,sum[i]-sum[p-1]);
      //cout<<i<<" "<<p<<endl;

    }
    cout<<mx<<endl;
   return 0;
}