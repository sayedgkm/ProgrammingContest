 /// Bismillahir-Rahmanir-Rahim
#include <bits/stdc++.h>
#define        ll                              long long int
#define        FOR(x,y,z)                      for(int x=y;x<z;x++)
#define        pii                             pair<int,int>
#define        pll                             pair<ll,ll>
#define        CLR(a)                          memset(a,0,sizeof(a))
#define        SET(a)                          memset(a,-1,sizeof(a))
#define        N                               205
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

multiset<int> adj[N];
vector<int> euler_cycle; /// 0 based node
multiset<pii> st;
map<pii,int> mp;
map<pii,int> extra;
int deg[N];
int vis[N];
void find_cycle(int u) {
    vis[u] = 1;
    while(adj[u].size()) {
        int it = *adj[u].begin();
        if(mp[make_pair(u,it)]==0) {
            adj[u].erase(adj[u].find(it));
            adj[it].erase(adj[it].find(u));
            continue;
        }
        mp[make_pair(u,it)]--;
        mp[make_pair(it,u)]--;
        find_cycle(it);
    }
    euler_cycle.pb(u);
}
vector<pii> edge;
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    int test = nxt();
    while(test--) {
        int n= nxt();
        int m = nxt();
        int cnt = 0;
        for(int i = 0;i<m;i++) {
            int a= nxt();
            int b = nxt();
            a--,b--;
            adj[a].insert(b);
            adj[b].insert(a);
            edge.pb(make_pair(a,b));
            mp[make_pair(a,b)]++;
            mp[make_pair(b,a)]++;
            deg[a]++;
            deg[b]++;
        }
        vector<int> odd;

        for(int i =0;i<n;i++){
            if(deg[i]%2) odd.pb(i);
            else cnt++;
        }
        for(int i = 0;i+2-1<odd.size();i+=2) {
            int a = odd[i];
            int b= odd[i+1];
            mp[make_pair(a,b)]++;
            mp[make_pair(b,a)]++;
            adj[a].insert(b);
            adj[b].insert(a);
        }
        printf("%d\n",cnt);
        for(int i =0;i<n;i++) {
            if(!vis[i]) find_cycle(i);
        }
        reverse(ALL(euler_cycle));
        for(int i =0 ;i+2-1<euler_cycle.size();i++){
            int a= euler_cycle[i];
            int b = euler_cycle[i+1];
            debug(a,b);
            extra[make_pair(a,b)] = 1;
        }
        for(int i = 0;i<edge.size();i++) {
            if(extra.count(make_pair(edge[i].ff,edge[i].ss))){
                printf("%d %d\n",edge[i].ff+1,edge[i].ss+1);
            } else {
                printf("%d %d\n",edge[i].ss+1,edge[i].ff+1);
            }
        }
        for(int i= 0;i<N;i++) adj[i].clear();
        CLR(deg);
        st.clear();
        extra.clear();
        euler_cycle.clear();
        mp.clear();
        CLR(vis);
        edge.clear();

    }


    return 0;
}
