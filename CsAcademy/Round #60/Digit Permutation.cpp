

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
inline long double dxt(){long double aaa;scanf("%lf",&aaa);return aaa;}
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
int ans [N];
int mark[N];
int color[N];
vector<int>v[N];
vector<int> adj[N];
vector<int> top;
map<pii,int> mp;
void dfs(int u) {
    color[u] = 2;
    for(auto it : adj[u]) {
        if(!color[it]) dfs(it);
    }
    top.pb(u);
}
int st;
int cycle;
void f(int u){
    debug(u);
    if(ans[u]==-1) {
        ans [u] = st;st++;
    }
    color[u] = 2;
    for(auto it : adj[u]) {
        if(color[it]){  cycle = 1;
            continue;
        }
         f(it);
    }

}
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
     SET(ans);
     int n = nxt();
    int k = nxt();
    int m = nxt();
    bool flag = 0;
    FOR(i,0,n) {
        FOR(j,0,m) {
            int x = nxt();

            if(j==0) mark[x] = 1;
            v[i].pb(x);
        }
    }
    for(int i = 0 ;i<n-1;i++) {
            bool f =0;
        for(int j = 0;j<m;j++) {
            if(v[i][j]!=v[i+1][j]) {
                if(mp.count(make_pair(v[i][j],v[i+1][j]))==0) {
                    mp[make_pair(v[i][j],v[i+1][j])]=1;
                    adj[v[i][j]].pb(v[i+1][j]);
                    f=1;
                }
                break;
            }
        }
        if(f==0){
            cout<<-1<<endl;
            return 0;
        }
    }
    FOR(i,0,k) {
        if(!color[i]){
            dfs(i);
        }
    }
    reverse(ALL(top));
    st=1;
    assert(top.size()==k);
    CLR(color);
    flag = 1;
    for(int it : top) {
        if(!color[it]) {
            if(flag&&mark[it]==0) {
                ans[it]=0;
                flag=0;
            }
            f(it);
        }
    }
    if(cycle||flag){
        cout<<-1<<endl;
        return 0 ;
    }
    FOR(i,0,k) {
        if(i) printf(" ");
        printf("%d",ans[i]);
    }
    printf("\n");



    return 0;
}
