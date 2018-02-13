//====================================
//======================================
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
#define        N                               100010
#define        M                               1000000007
#define        pi                              acos(-1.0)
#define        ff                              first
#define        ss                              second
#define        pb                              push_back
#define        inf                              (1e9)+1000
#define        eps                             1e-9
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
#ifdef sayed
     #define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template < typename Arg1 >
    void __f(const char* name, Arg1&& arg1){
        cerr << name << " is " << arg1 << std::endl;
    }
    template < typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names+1, ',');
        cerr.write(names, comma - names) << " is " << arg1 <<endl;
        __f(comma+1, args...);
    }
#else
    #define debug(...)
#endif
///******************************************START******************************************
ll ar[N];
int color[N];
ll dp[N];
struct info{
   ll sum;
   ll mx;
}tree[N*4];
void update(int node,int low,int hi,int i,ll value){

   if(low==hi){
    tree[node].sum=value; return;
   }
   int mid=(low+hi)/2;
   int left=2*node;
   int right=left+1;
   if(i<=mid)
      update(left,low,mid,i,value);
   else
      update(right,mid+1,hi,i,value);
   tree[node].sum=max(tree[left].sum,tree[right].sum);
}
ll query(int node,int low,int hi,int i,int j){
    if(i>hi||j<low) return 0;
    if(low>=i&&hi<=j)
      return tree[node].sum;
    int mid=(low+hi)/2;
    int left=2*node;
    int right=left+1;
    ll x= query(left,low,mid,i,j);
    ll y= query(right,mid+1,hi,i,j);
    return max(x,y);
}
bool isused[N];
ll go(ll a,ll b,int n) {
    for(int i = 0;i<=n;i++) {
        dp[i] = (ll) - 3e17;
    }
    ll ans = (ll)-3e17;
    pll mx1=make_pair((ll)-3e17,-1);
    pll mx2=make_pair((ll)-3e17,-1);
    for(int i = 1;i<=n;i++) {
        if(dp[color[i]]!=(ll)-3e17)
            dp[color[i]] = max(dp[color[i]],dp[color[i]]+ar[i]*a);
        dp[color[i]] = max(dp[color[i]],ar[i]*b);
        ll mx = (ll) - 3e18;
        if(color[i]!=mx1.ss) mx = max(mx,mx1.ff);
        if(color[i]!=mx2.ss) mx = max(mx,mx2.ff);
        if(mx!=(ll)-3e17)
            dp[color[i]] = max(dp[color[i]],mx+ar[i]*b);
        ans= max(dp[color[i]],ans);
        if(dp[color[i]]>=mx2.ff) {
            if(mx1.ss==color[i]){
                mx1.ff = max(mx1.ff,dp[color[i]]);

            } else {
                    mx2.ff = dp[color[i]];
                    mx2.ss = color[i];
            }

        }
        if(mx2.ff>=mx1.ff) swap(mx2,mx1);

    }
    return ans ;
}
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    int n = nxt();
    int q = nxt();
    for(int i = 1;i<=n;i++){
        ar[i] = lxt();
    }
    for(int i = 1;i<=n;i++){
        color[i] = nxt();
    }
    while(q--){
        ll a = lxt();
        ll b = lxt();
        printf("%lld\n",max(0LL,go(a,b,n)));
    }
    return 0;
}