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
template < class T> inline T gcd(T a, T b){return a%b ? gcd(b,a%b) : b;}
using namespace std;
map<ll,ll> x,y;
map<ll,ll>:: iterator it;
map<pii,ll> com;
map<pii,ll>:: iterator it1;
int main()
{
    int n;
    cin>>n;
    while(n--){
        ll a,b;
        scanf("%I64d%I64d",&a,&b);
        x[a]++;
        y[b]++;
        com[pii(a,b)]++;

    }
    ll ans=0;
    for(it=x.begin();it!=x.end();it++){
            ll p=it->ss;
        ans+=(p*(p-1))/2;
    }
    for(it=y.begin();it!=y.end();it++){
            ll p=it->ss;
        ans+=(p*(p-1))/2;
    }
    for(it1=com.begin();it1!=com.end();it1++){
            ll p=it1->ss;
        ans-=(p*(p-1))/2;
    }
    cout<<ans<<endl;
      return 0;
}