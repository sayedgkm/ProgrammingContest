//==========================================================================
//
//                   Bismillahir-Rahmanir-Rahim
//
// ==========================================================================
#include <bits/stdc++.h>
#define        ll                              long long int
#define        f(x,y,z)                        for(int x=y;x<z;x++)
#define        pii                             pair<int,int>
#define        pll                             pair<ll,ll>
#define        CLR(a)                          memset(a,0,sizeof(a))
#define        SET(a)                          memset(a,-1,sizeof(a))
#define        N                               101010
#define        M                               1000000007
#define        pi                              acos(-1.0)
#define        ff                              first
#define        ss                              second
#define        pb                              push_back
#define        inf                             (int)1e9
#define        eps                              1e-9
using namespace std;
int dx[]={0,0,1,-1,-1,-1,1,1};
int dy[]={1,-1,0,0,-1,1,1,-1};
template < class T> inline T biton(T n,T pos){return n |((T)1<<pos);}
template < class T> inline T bitoff(T n,T pos){return n & ~((T)1<<pos);}
template < class T> inline T ison(T n,T pos){return (bool)(n & ((T)1<<pos));}
template < class T> inline T gcd(T a, T b){while(b){a%=b;swap(a,b);}return a;}
template <typename T> string NumberToString ( T Number ) { ostringstream ss; ss << Number; return ss.str(); }
inline int nxt(){int aaa;scanf("%d",&aaa);return aaa;}
inline ll lxt(){ll aaa;scanf("%I64d",&aaa);return aaa;}
inline double dxt(){double aaa;scanf("%lf",&aaa);return aaa;}
template <class T> inline T bigmod(T p,T e,T m){T ret = 1;
for(; e > 0; e >>= 1){
    if(e & 1) ret = (ret * p) % m;p = (p * p) % m;
} return (T)ret;}
#define sayed
#ifdef sayed
     #define debug(args...) {cerr<<"Debug: "; dbg,args; cerr<<endl;}
#else
    #define debug(args...)  // Just strip off all debug tokens
#endif
struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;
///******************************************START******************************************
int ans[N];
int ar[N];
vector<int> v;
ll prime[N+10];
void p()
{
 int sq;
 sq = sqrt(N);
 for(int i=3;i<=sq;i+=2)
  for (int j = i*i; j <= N; j += i * 2)
   prime[j] = 1;
 int li = 0;
 prime[li++] = 2;
 for (int i = 3; i <= N; i += 2)
 if (!prime[i])
  prime[li++] = i;

}
void nod(ll n){
    for(ll i=0;prime[i]*prime[i]<=n;i++){
          if(n%prime[i]==0){

        while(n%prime[i]==0){
                n/=prime[i];

        }
       ans[prime[i]]++;
    }
 }
  if(n>1)
      ans[n]++;

}
int main(){
     //freopen("out.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
   p();
    int n=nxt(); int res=1;
    for(int i=0;i<n;i++) ar[i]=nxt();
    sort(ar,ar+n);
    for(int i=0;i<n;i++){
        int a=ar[i];
        nod(a);
         int mx=0;
        for(int i=1;i<v.size();i++){
            mx=max(mx,ans[v[i]]);
        }
        for(int i=1;i<v.size();i++){
            ans[v[i]]=(mx+1);
        }
        v.clear();
    }
    for(int i=0;i<N;i++){
        res=max(res,ans[i]);
    }
     printf("%d\n",res);
return 0;
}