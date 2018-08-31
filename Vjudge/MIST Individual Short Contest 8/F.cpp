 /// Bismillahir-Rahmanir-Rahim
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
        cerr.write(names, comma - names) << " is " << arg1 <<" | ";
        __f(comma+1, args...);
    }
#else
    #define debug(...)
#endif
///******************************************START******************************************
int ar[N];
int br[N];
int dp[N][(1<<7)+1][7];
int ok[N][(1<<7)+1][7];
int cs = 1;
int n ;
int go(int pos,int mask,int last){
    if(pos==n) return 0;
    int res = inf;
    if(ison(mask,br[pos])) {
        if(br[pos]==last) res = min(res,dp[pos+1][mask][br[pos]]);
        else res = min(res,dp[pos+1][mask][last]+1);

    } else{
        res = min(res,dp[pos+1][biton(mask,br[pos])][br[pos]]);
        res = min(res,dp[pos+1][mask][last]+1);

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
    vector<int> tmp= {10, 20, 50, 100, 200, 500, 2000};
    for(int i = 0;i<tmp.size();i++) ar[tmp[i]] = i;
    int test = nxt();
    while(test--) {

        n = nxt();
        for(int i =0;i<n;i++) {
            int a= nxt();
            br[i] = ar[a];
        }
        for(int i = n;i>=0;i--) {
            for(int j = 0;j<128;j++) {
                for(int k = 0;k<7;k++){
                    dp[i][j][k] = go(i,j,k);
                }
            }
        }
        printf("%d\n",dp[0][0][0]);


    }

    return 0;
}
