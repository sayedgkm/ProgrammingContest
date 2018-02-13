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
int n,m;
bool cycle = 0;
char s[1003][1003];
string t = "DIMA";
int dp[1003][1003][4];
int vis[1003][1003][4];
int now = 1;
int dfs(int i,int j,int khuj){
  // debug(i,j,khuj);
    if(cycle) return 0;
    if(dp[i][j][khuj]!=-1) return dp[i][j][khuj];
    vis[i][j][khuj] = now;
    int res = 0;
    for(int k = 0;k<4;k++) {
        int nx = i+dx[k];
        int ny = j+dy[k];
        if(nx<0||nx>=n||ny<0||ny>=m) continue;
        int nkhuj = khuj+1;
        if(nkhuj==4) nkhuj = 0;
        if(s[nx][ny]!=t[nkhuj]) continue;
        if(vis[nx][ny][nkhuj]==now&&nkhuj==0){
            cycle = true;
            return 0;
        }

        res = max(res,dfs(nx,ny,nkhuj)+1);
    }
    vis[i][j][khuj] = now-5;
    return dp[i][j][khuj]=res;
}
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    n = nxt();
    m =nxt();
    for(int i = 0;i<n;i++) scanf("%s",s[i]);
    int res = 0;
    SET(dp);
    for(int i = 0;i<n;i++) {
        for(int j = 0;j<m;j++) {
            if(s[i][j]=='D') {
                now++;
               // debug(i,j);
                res = max(res,dfs(i,j,0)+1);
            }
            if(cycle){
                //debug(i,j);
                printf("Poor Inna!\n");
                return 0;
            }
        }
    }
    res/=4;
    if(res) printf("%d\n",res);
    else printf("Poor Dima!\n");

    return 0;
}