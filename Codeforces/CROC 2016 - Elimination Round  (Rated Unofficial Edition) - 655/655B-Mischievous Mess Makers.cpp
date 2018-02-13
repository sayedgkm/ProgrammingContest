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
int ar[N];
int nxt(){
  int a;
  scanf("%d",&a);
  return a;
}
int main()
{
    int n=nxt();
    int k=nxt();
    k=min(n/2,k);
    for(int i=1;i<=n;i++) ar[i]=i;
    int j=n;
    for(int i=1;i<=k;i++){
        swap(ar[i],ar[j]);j--;
    }
    ll ans=0;
    int i=1;
    for(;i<=k;i++)
          ans+=(n-i);
    for(;i<=n;i++)
        ans+=min(k,n-i);
    cout<<ans<<endl;
          return 0;
}