 /// Bismillahir-Rahmanir-Rahim
#include <bits/stdc++.h>
#define        ll                              long long int
#define        FOR(x,y,z)                      for(int x=y;x<z;x++)
#define        pii                             pair<int,int>
#define        pll                             pair<ll,ll>
#define        CLR(a)                          memset(a,0,sizeof(a))
#define        SET(a)                          memset(a,-1,sizeof(a))
#define        N                               1000010
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
vector<int> adj[N];
int sz[N];
int branch[N];
int where[N];
int b;
int color[N];
void dfs(int u,int l) {
    color[u] = 1;
    where[u] = l;
    sz[b]++;
    branch[u] = b;
    for(auto it :adj[u]) {
        if(color[it]==0) dfs(it,l+1);
    }
}
vector<int> tree[N];
void update(int id,int ind,int x,int limit) {
    while(ind<=limit) {
        tree[id][ind]+=x;
        ind+=ind&-ind;
    }
}
int query(int id,int ind) {
    int sum = 0;
    while(ind>0) {
        sum+=tree[id][ind];
        ind-=ind&-ind;
    }
    return sum;
}
void update1(int u,int v,int bb,int x) {
    if(v>sz[bb]) v= sz[bb];
    if(u>v) return;

    update(bb,u,x,sz[bb]);
    update(bb,v+1,-x,sz[bb]);
}
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    int n=nxt();
    int q= nxt();
    for(int i = 0;i<n-1;i++) {
        int a= nxt();
        int b= nxt();
        adj[a].pb(b);
        adj[b].pb(a);
    }
    color[1]=1;
    b=1;
    for(int i =0;i<adj[1].size();i++) {
        int x = adj[1][i];
        b++;
        dfs(x,1);
    }
    tree[1].resize(n+1);
    sz[1] = n;
    for(int i = 2;i<=b;i++) tree[i].resize(sz[i]+1);
    while(q--) {

        int t = nxt();
        if(t==0) {
            int v = nxt();
            int x= nxt();
            int d =nxt();
            int chain = branch[v];
            int ind = where[v];
            if(v==1){
                update1(1,d+1,1,x);
                continue;
            }
            if(ind-d>=1) {
                update1(ind-d,ind+d,chain,x);
            } else {
                debug(d-ind+1,ind+d);
                update1(d-ind+1,ind+d,chain,x);
                update1(1,d-ind+1,1,x);
            }

        } else {
            int v = nxt();
            if(v==1) {
                printf("%d\n",query(1,1));
            } else {
                printf("%d\n",query(branch[v],where[v])+query(1,where[v]+1));
            }
        }
    }


    return 0;
}

