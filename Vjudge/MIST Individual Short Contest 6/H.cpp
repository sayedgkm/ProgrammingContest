 /// Bismillahir-Rahmanir-Rahim
#include <bits/stdc++.h>
#define        ll                              long long int
#define        FOR(x,y,z)                      for(int x=y;x<z;x++)
#define        pii                             pair<int,int>
#define        pll                             pair<ll,ll>
#define        CLR(a)                          memset(a,0,sizeof(a))
#define        SET(a)                          memset(a,-1,sizeof(a))
#define        N                               20010
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
vector<int> adj[2][N];
int par[2][N];
void go(int id,int u,string &tmp) {
    int cnt = 2;
    par[id][u]=u;
    for(int i = 0;i<tmp.size();i++) {
        if(tmp[i]=='1') {
            adj[id][u].pb(cnt);
            par[id][cnt] =u;
            u = cnt;
            cnt++;
        } else {
            u = par[id][u];
        }
    }

}
int sz[2][N];
vector<int> level[2][N];
int mx = 0;
void dfs(int id,int u,int l) {
    sz[id][u] = 1;
    mx = max(mx,l);
    for(int i = 0;i<adj[id][u].size();i++) {
        int v = adj[id][u][i];
        dfs(id,v,l+1);
        sz[id][u]+=sz[id][v];
    }
}
void dfs1(int id,int u,int l) {
    level[id][l].pb(sz[id][u]);
    for(int i = 0;i<adj[id][u].size();i++) {
        int v = adj[id][u][i];
        dfs1(id,v,l+1);
    }
}

int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
     freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    int test;
    cin>>test;int cs = 1;
    string s,t;
    getline(cin,s);
    while(test--) {
        mx =0;
        getline(cin,s);
        getline(cin,t);
        go(0,1,s);
        go(1,1,t);
        dfs(0,1,1);
        dfs(1,1,1);
        dfs1(0,1,1);
        dfs1(1,1,1);
        bool f= 0;
        for(int i =1;i<=mx;i++) {
            if(level[0][i].size()!=level[1][i].size()) {
                f = 1;
            }
            sort(ALL(level[0][i]));
            sort(ALL(level[1][i]));
        }
        if(f==0)
             for(int i =1;i<=mx;i++) {
                for(int j = 0;j<level[0][i].size();j++) {
                    int x = level[0][i][j];
                    int y = level[1][i][j];
                //    debug(i,x,y);
                    if(x!=y) {
                        f = 1;
                    }
                }
            }

        printf("Case %d: ",cs++);
        if(f) printf("Different\n");
        else printf("Same\n");
        for(int i =0;i<2;i++) {
            for(int j =0;j<N;j++) {
                adj[i][j].clear();
                level[i][j].clear();
                sz[i][j]=0;
                par[i][j]=0;
            }
        }

    }

    return 0;
}
