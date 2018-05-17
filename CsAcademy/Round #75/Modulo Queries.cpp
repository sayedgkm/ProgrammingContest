 /// Bismillahir-Rahmanir-Rahim
#include <bits/stdc++.h>
#define        ll                              long long int
#define        FOR(x,y,z)                      for(int x=y;x<z;x++)
#define        pii                             pair<int,int>
#define        pll                             pair<ll,ll>
#define        CLR(a)                          memset(a,0,sizeof(a))
#define        SET(a)                          memset(a,-1,sizeof(a))
#define        N                               200010
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
        cerr.write(names, comma - names) << " is " << arg1 <<" | ";
        __f(comma+1, args...);
    }
#else
    #define debug(...)
#endif
///******************************************START******************************************
const int block=1000;
vector<int> v[200+10];
const int mx = (4*(int)1e4)+5;
int ar[mx+5];
int br[2*mx+5];
int ans[305][mx+5];
int get_ans(int l,int r,int mod) {
    int i = l;
    int res = 0;
    for(;i<=r&&i%block;i++) {
        res = max(res,ar[i]%mod);
    }
    for(;i+block-1<=r;i+=block) {
        res = max(res,ans[i/block][mod]);
    }
    for(;i<=r;i++) {
         res = max(res,ar[i]%mod);
    }
    return res;
}
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    int n= nxt();
    int m = nxt();
    for(int i = 0;i<n;i++) {
        ar[i] = nxt();
        v[i/block].pb(ar[i]);
    }
    for(int i= 0;i<=(n-1)/block;i++) {
        CLR(br);
        for(auto it : v[i]) br[it] = it;
        for(int i = 1;i < 2*mx; i++) if(br[i]==0) br[i] = br[i-1];
        for(int j = 2;j<mx;j++) {
            for(int k = j;k<2*mx;k+=j) {
                ans[i][j] = max(ans[i][j],br[k-1]%j);
            }
        }

    }

    while(m--) {
        int a= nxt();
        int b= nxt();
        a--,b--;
        int mod = nxt();
        if(mod==1) {
            printf("0\n");
            continue;
        }
        printf("%d\n",get_ans(a,b,mod));
    }


    return 0;
}
