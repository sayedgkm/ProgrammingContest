 /// Bismillahir-Rahmanir-Rahim
#include <bits/stdc++.h>
#define        ll                              long long int
#define        FOR(x,y,z)                      for(int x=y;x<z;x++)
#define        pii                             pair<int,int>
#define        pll                             pair<ll,ll>
#define        CLR(a)                          memset(a,0,sizeof(a))
#define        SET(a)                          memset(a,-1,sizeof(a))
#define        N                               3002
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
vector<int> v[N][N];
vector<int> adj[N];
int level[N][N];
int n;
pii par[N][N];
int bfs(pii &last) {
    queue<pii> q;
    q.push(make_pair(0,3001));
    level[0][3001]=0;
    while(!q.empty()) {

        pii u= q.front();
        if(u.ff==n-1) {
            last = u;
            return level[u.ff][u.ss];
        }
        q.pop();
        for(auto it : adj[u.ff]) {
            if(binary_search(ALL(v[u.ss][u.ff]),it)) continue;
            if(level[it][u.ff]==-1) {
                level[it][u.ff]=level[u.ff][u.ss]+1;
                par[it][u.ff]= u;
                q.push(make_pair(it,u.ff));
            }
        }
    }
    return -1;
}
void dfs(pii last) {
    if(last.ss!=3001)
        dfs(par[last.ff][last.ss]);
    printf("%d ",1+last.ff);
}
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    n = nxt();
    int m = nxt();
    int q=nxt();
    for(int i = 0;i<m;i++){
        int a= nxt()-1;
        int b=nxt()-1;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    for(int i =0;i<q;i++) {
        int a = nxt()-1;
        int b= nxt()-1;
        int c= nxt()-1;
        v[a][b].pb(c);
    }
    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++) sort(ALL(v[i][j]));
    }
    SET(level);
    pii last;
    int res = bfs(last);
    if(res!=-1) {
        cout<<res<<endl;
        dfs(last);
    } else cout<<-1<<endl;
    return 0;
}

