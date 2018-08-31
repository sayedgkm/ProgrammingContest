 /// Bismillahir-Rahmanir-Rahim
#include <bits/stdc++.h>
#define        ll                              long long int
#define        FOR(x,y,z)                      for(int x=y;x<z;x++)
#define        pii                             pair<int,int>
#define        pll                             pair<ll,ll>
#define        CLR(a)                          memset(a,0,sizeof(a))
#define        SET(a)                          memset(a,-1,sizeof(a))
#define        N                               500010
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
vector<pair<pii,int > > adj[N];
ll level[N];
int done[N];
vector<int> ans;
ll sum;
struct info{
    ll cost;
    ll cur;
    ll prev;
    ll id;
    info(ll cost,ll cur,ll prev,ll id) : cost(cost),cur(cur),prev(prev),id(id){}
    bool operator<(const info& other)const{
        if(cost==other.cost) {
            return prev>other.prev;
        }
        return cost>other.cost;
    }

};
void dj(int st) {
    for(int i = 0 ;i<N;i++) level[i] = (ll)3e18;
    level[st] = 0;
    priority_queue<info > pq;
    pq.push(info(0,st,0,0));
    while(!pq.empty()) {
        info  top = pq.top();
        pq.pop();
        if(done[top.cur]) continue;
        done[top.cur] = 1;
        ans.pb(top.id);
        sum+=top.prev;
        for(auto it : adj[top.cur]) {
           // debug(it.ff.ff,it.ff.ss);
            if(level[top.cur]+it.ff.ff<=level[it.ff.ss]) {
                level[it.ff.ss] =level[top.cur]+it.ff.ff;
                pq.push(info(level[it.ff.ss],it.ff.ss,it.ff.ff,it.ss));

            }

        }

    }

}

//struct info {
//    int u,v;
//    ll cost;
//    int id;
//    info(int u,int v,ll cost,int id ) : u(u),v(v),cost(cost),id(id) {}
//    bool operator<(const info & other) const {
//        return cost<other.cost;
//    }
//};
//vector<info> v;
//int par[N];
//int get(int x) {
//    if(par[x]==x) return x;
//    return par[x] = get(par[x]);
//}
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    int n = nxt();
    int m = nxt();
    for(int i = 0;i<m;i++) {
        int a= nxt();
        int b= nxt();
        int c = nxt();
        adj[a].pb(make_pair(make_pair(c,b),i));
        adj[b].pb(make_pair(make_pair(c,a),i));
    }

    int st = nxt();
    dj(st);
    for(int i =1;i<=n;i++)sort(ALL(adj[i]));

//    sort(ALL(v));ll sum = 0;
//    for(int i = 1;i<=n;i++) par[i] = i;
//    for(int i =0;i<v.size();i++) {
//        int x= v[i].u;
//        int y =v[i].v;
//        ll cost = v[i].cost;
//        int id = v[i].id;
//        if(get(x)==get(y)) continue;
//        debug(x,y,level[x],level[y],cost);
//        if(level[x]+cost==level[y]||level[y]+cost==level[x]) {
//            sum+=cost;
//            par[get(y)] = get(x);
//            ans.pb(id);
//        }
//
//
//    }
    ans.erase(ans.begin());
    printf("%lld\n",sum);
    for(auto it: ans) printf("%d ",it+1);
    printf("\n");
    return 0;
}
