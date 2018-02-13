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
        cerr.write(names, comma - names) << " is " << arg1 <<endl;
        __f(comma+1, args...);
    }
#else
    #define debug(...)
#endif
///******************************************START******************************************
int ar[N];
vector<int> v[2],deg[2];
int dp[2][N];
int n;
void go(int player,int pos) {
    int x = 1-player;
    for(int i = 0;i<v[x].size();i++) {
        int Npos = pos;
        Npos-=v[x][i];
        if(Npos<=0) {
            Npos= n+Npos;
        }
        if(dp[x][Npos]!=-1) continue;
        if(dp[player][pos]==0){
            dp[x][Npos] = 1;
            go(x,Npos);
        } else {
            deg[x][Npos]--;
            if(deg[x][Npos]==0) {
                dp[x][Npos] = 0;
                go(x,Npos);
            }
        }
    }
}
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    n= nxt();
    int k = nxt();
    v[0].resize(k);
    for(int i = 0;i<k;i++) v[0][i] = nxt();
    k = nxt();
    v[1].resize(k);
    for(int i = 0;i<k;i++) v[1][i] = nxt();
    for(int i = 0;i<2;i++) {
        deg[i].resize(n+1);
        for(int j = 1;j<=n;j++) {
            deg[i][j] = v[i].size();
        }
    }
    SET(dp);
    dp[0][1] = 0;
    dp[1][1] = 0;
    go(0,1);
    go(1,1);
    for(int i = 0;i<2;i++) {
        for(int j = 2;j<=n;j++) {
            if(j>2) printf(" ");
            if(dp[i][j]==0) printf("Lose");
            else if(dp[i][j]==1) printf("Win");
            else printf("Loop");
        }
        printf("\n");
    }

    return 0;
}