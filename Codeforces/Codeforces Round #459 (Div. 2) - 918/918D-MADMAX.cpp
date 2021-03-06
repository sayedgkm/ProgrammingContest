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
int ar[N];
vector<pii> adj[105];
int dp[105][105][27][2];
int vis[105][105][27][2];
int cs = 0;
int go(int x,int y,int val,int flag) {

    if(vis[x][y][val][flag]==cs) return dp[x][y][val][flag];
    vis[x][y][val][flag] = cs;
    if(flag==0) {
        int res = -10;
        FOR(i,0,adj[x].size()) {
            if(adj[x][i].ss>=val) {
                res = max(res,go(adj[x][i].ff,y,adj[x][i].ss,1));
            }
        }
        return dp[x][y][val][flag]= res;
    } else {
        int res = 10;
        FOR(i,0,adj[y].size()) {
            if(adj[y][i].ss>=val) {
                res = min(res,go(x,adj[y][i].ff,adj[y][i].ss,0));
            }
        }
        return  dp[x][y][val][flag]=res;

    }

}
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    int n = nxt(); int m = nxt();
    for(int i = 0;i<m;i++) {
        int a = nxt();
        int b =nxt();
        char c[2];scanf("%s",c);
        int ascii = c[0]-'a';
        adj[a].pb(make_pair(b,ascii));
    }
    //cout<<go(1,1,0,0)<<endl;
    ++cs;
    for(int i = 1;i<=n;i++) {
        for(int j = 1;j<=n;j++) {
                //++cs;
            if(go(i,j,0,0)==10) printf("A");
            else printf("B");
        }
        printf("\n");

    }


    return 0;
}