///Bismillahir-Rahmanir-Rahim
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
ll ar[N];
vector<int> adj[N];
vector<int> v;
vector<long long> cost;
int st[N],ed[N];
int t = 1;
ll level[N];
void dfs(int u,int p =-1) {
    v.push_back(u);
    cost.pb(ar[u]);
    st[u] = t++;
    for(auto it:adj[u] ) {
        if(it==p) continue;
        level[it] = level[u]+1;
        dfs(it,u);
    }

    ed[u] = t-1;
}
ll tree[N];
void update(int idx,int n,int x)
{
    while(idx<=n)
    {
        tree[idx]+=x;
        idx+= idx&(-idx);
    }
}
ll query(int idx){
     ll sum=0;
     while(idx>0)
     {
         sum+=tree[idx];idx-=idx&(-idx);
     }
   return sum;
}
ll sum(int i,int j) {
    return query(j)-query(i-1);
}
ll mx = 0;
ll totSum = 0;
void dfsAgain(int u,int p,ll res) {
        mx = max(res,mx);
        for(auto it : adj[u]) {
            if(it==p) continue;
            ll temp= res;
            ll sub = sum(st[it],ed[it]);
            ll add = totSum-sub;
            temp-=sub;
            temp+=add;
            dfsAgain(it,u,temp);
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
    for(int i =1;i<=n;i++)  ar[i] = lxt(),totSum+=ar[i];
    for(int i = 0;i<n-1;i++) {
        int a= nxt();
        int b = nxt();
        adj[a].pb(b);
        adj[b].pb(a);
    }
    v.pb(0);
    cost.pb(0);
    dfs(1);
    mx = 0;
    long long res = 0;
    for(int i =1;i<=n;i++) {
        res+=level[i]*ar[i];
    }
    for(int i = 1;i<=n;i++) {
        update(i,n,cost[i]);
    }
    dfsAgain(1,-1,res);
    cout<<mx<<endl;

    return 0;
}
