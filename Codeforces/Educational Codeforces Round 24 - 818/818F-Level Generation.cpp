//==========================================================================
//
//                   Bismillahir-Rahmanir-Rahim
//
// ==========================================================================
#include <bits/stdc++.h>
#define        ll                              long long int
#define        FOR(x,y,z)                      for(int x=y;x<z;x++)
#define        pii                             pair<int,int>
#define        pll                             pair<ll,ll>
#define        CLR(a)                          memset(a,0,sizeof(a))
#define        SET(a)                          memset(a,-1,sizeof(a))
#define        N                               5000010
#define        M                               1000000007
#define        pi                              acos(-1.0)
#define        ff                              first
#define        ss                              second
#define        pb                              push_back
#define        inf                             9e9+100
#define        eps                             1e-9
#define        debug(x)                        cerr << #x << " is " << x << endl;
#define        ALL(x)                          x.begin(),x.end()
using namespace std;
int dx[]={0,0,1,-1,-1,-1,1,1};
int dy[]={1,-1,0,0,-1,1,1,-1};
template < class T> inline T biton(T n,T pos){return n |((T)1<<pos);}
template < class T> inline T bitoff(T n,T pos){return n & ~((T)1<<pos);}
template < class T> inline T ison(T n,T pos){return (bool)(n & ((T)1<<pos));}
template < class T> inline T gcd(T a, T b){while(b){a%=b;swap(a,b);}return a;}
template <typename T> string NumberToString ( T Number ) { ostringstream ss; ss << Number; return ss.str(); }
inline int nxt(){int aaa;scanf("%d",&aaa);return aaa;}
inline ll lxt(){ll aaa;scanf("%lld",&aaa);return aaa;}
inline double dxt(){double aaa;scanf("%lf",&aaa);return aaa;}
template <class T> inline T bigmod(T p,T e,T m){T ret = 1;
for(; e > 0; e >>= 1){
    if(e & 1) ret = (ret * p) % m;p = (p * p) % m;
} return (T)ret;}
///******************************************START******************************************
int ar[N];
ll dp[N];
ll p[N];
int a,b;
ll ans;
void gen(int n,ll t){
   int sq=sqrt(n);
   FOR(i,2,sq+1){
      if(ar[i]==0) {
         for(int j=i;j<=n;j+=i) if(ar[j]==0) ar[j]=i;
      }
   }
   p[0]=1;
   p[1]=t;
   int c=0;
   FOR(i,2,b+1) {
       p[i]=(p[i-1]*t)%M;
       ll x=ar[i];
       if(x==0) x=i;
       dp[i]=dp[i/x] + (((ll)i/x)*(x*(x-1))/2)%M;
       dp[i]%=M;
       if(i>=a) {
         ans+=(p[c]*dp[i])%M;
         ans%=M;
          c++;
       }
   }
}
 stack<int> st;
 char s[20];
int main(){
     //freopen("out.txt","w",stdout);
     //freopen("in.txt","r",stdin);
      //ios_base::sync_with_stdio(false);
      //cin.tie(0);
    int q=nxt();
    while(q--) {
         ll n=lxt();
         if(n==1||n==2||n==3) {
             printf("%d\n",n-1);
             continue;
         }
         int edge=n-1;
       ll b=1;
       ll e=n;
       while(b<=e){
          ll mid = (b+e)/2;
            ll baki = n-mid;
             baki=(baki*(baki-1))/2;
             if(mid<baki) b=mid+1;
             else e=mid-1;
//             debug(b);
//             debug(e);
        }

        ll baki = n- b;
        baki=(baki*(baki-1))/2;
        ll ans2= baki+b;
        if(baki<b) b--;
         n-=b;
         n=(n*(n-1))/2;
         ll ans1=min((ll)n,b)+b;
        printf("%lld\n",max(ans1,ans2));
     }
return 0;
}