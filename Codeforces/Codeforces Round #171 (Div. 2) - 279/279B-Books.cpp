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
ll ar[N],sum[N];
int main()
{
    ll n,time;
    cin>>n>>time;
    f(i,1,n+1){
      cin>>ar[i];
      sum[i]=sum[i-1]+ar[i];
    }
    int p=1;
    int mx=0;ll m=0;
    f(i,1,n+1){
        m=sum[i]-sum[p-1];
        while(m>time){
            p++;
            m=sum[i]-sum[p-1];
        }
    //cout<<i<<" "<<p<<" "<<m<<endl;
       mx=max(mx,i-p+1);
    }
    cout<<mx<<endl;
      return 0;
}