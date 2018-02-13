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
#define        pii                             pair<ll,ll>
#define        mem(a,x)                        memset(a,x,sizeof(a))
#define        N                               1000010
#define        M                               1000000007
#define        pi                              acos(-1.0)
#define        ff                              first
#define        ss                              second
#define        pb                              push_back
using namespace std;
int dx[]={0,0,1,-1,-1,-1,1,1};
int dy[]={1,-1,0,0,-1,1,1,-1};
template < class T> inline T gcd(T a, T b){while(b){a%=b;swap(a,b);}return a;}
template <class T> inline T bigmod(T p,T e,T m){
    ll ret = 1;
    for(; e > 0; e >>= 1){
        if(e & 1) ret = (ret * p) % m;
        p = (p * p) % m;
    } return (T)ret;
}
inline int nxt(){
  int aaa;
  scanf("%d",&aaa);
  return aaa;
}
ll ar[N];
int val[10];
int main()
{
    int n=nxt(),k=nxt(),q=nxt();
    f(i,1,n+1) scanf("%I64d",&ar[i]);
      vector<pii> v;
    while(q--){
        int a=nxt();
        if(a==1){
           int b=nxt();
            if(v.size()<k)
             v.pb(pii(ar[b],b));
             else{   if(ar[b]>v[v.size()-1].ff)
                    v[v.size()-1]=pii(ar[b],b);
             }
               sort(v.begin(),v.end());
                 reverse(v.begin(),v.end());
            } else if(a==2) {

             ll b;scanf("%I64d",&b);
             int flag=0;
             f(i,0,v.size()){
                if(v[i].ss==b){
                    flag=1;
                    break;
                }
             }
               if(flag) puts("YES");
               else puts("NO");
            }

    }



      return 0;
}