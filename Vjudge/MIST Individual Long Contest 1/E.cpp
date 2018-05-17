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
int ar[20][20];
struct info{
    int v,c,t;
    info(int _v,int _c,int _t): v(_v),c(_c),t(_t){}
};
struct info1{
    ll cost,cur,city;
    info1(ll _cost,ll _cur,ll _city):cost(_cost),cur(_cur),city(_city){}
    bool operator<(const info1& other ) const {
        return cost>other.cost;
    }
};
vector<info> adj[N];
ll level[N][12];
void dj(int st) {
    priority_queue<info1> pq;
    pq.push(info1(0,st,0));
    for(int i = 0;i<N;i++) for(int j =0;j<12;j++) level[i][j] = (ll) 3e17;
    level[st][0] = 0;
    while(!pq.empty()) {

        info1 top = pq.top();
        int u = top.cur;
        int c1 =top.city;
        pq.pop();
        for(int i = 0;i<adj[u].size();i++) {
            int v = adj[u][i].v;
            ll cost = adj[u][i].c;
            int c2 =adj[u][i].t;
            debug(level[u][c1],c1,level[v][c2],u,v);
            if(level[u][c1]+cost+ar[c1][c2]<level[v][c2]){
                level[v][c2] = level[u][c1]+cost+ar[c1][c2];
                pq.push(info1(level[v][c2],v,c2));
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
    int n = nxt();
    int m = nxt();
    int t = nxt();
    int st = nxt();
    for(int i = 1;i<=t;i++) for(int j = 1;j<=t;j++) {

        ar[i][j] = nxt();
    }
    for(int i = 0;i<m;i++) {
        int a= nxt();
        int b= nxt(),c = nxt(),T = nxt();
        adj[a].pb(info(b,c,T));
        adj[b].pb(info(a,c,T));
    }
    dj(st);
    for(int i = 1;i<=n;i++) {
        ll ans = (ll)3e17;
        for(int j = 0;j<=10;j++){
            ans = min(ans,level[i][j]);
        }
        if(i>1) printf(" ");
        if(ans == (ll)3e17) {
            printf("-1");
        } else printf("%lld",ans);
    }
    printf("\n");

    return 0;
}
