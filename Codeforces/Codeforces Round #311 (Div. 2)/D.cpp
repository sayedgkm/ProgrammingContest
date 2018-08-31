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
int ar[N];
ll nc3(ll n) {
    return n*(n-1)*(n-2)/6LL;
}
ll nc2(ll n) {
    return n*(n-1)/2LL;
}
int mx = 0;
vector<int> component;
int level[N];
int color[N];
vector<int> adj[N];
int bfs(int u,int flag) {
    color[u] = 1;
    queue<int> q;
    q.push(u) ;
    int c= 1;
    if(flag) component.pb(u);
    while(!q.empty()) {
        u = q.front();
        q.pop();
        for(int i = 0 ;i<adj[u].size();i++) {
            int v  = adj[u][i];
            if(color[v]==0){
                if(flag==1) {
                    level[v]= level[u]+1;
                    component.pb(v);
                }
                if(color[u]==1) color[v] = 2;
                else color[v] = 1;
                q.push(v);
                c++;
            } else {
                if(color[v]==color[u]) return false;
            }
        }

    }
    mx = max(c,mx);
    return true;
}
vector<pii> v;
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    int n= nxt();
    int m= nxt();
    for(int i = 0;i<m;i++){
        int a= nxt();
        int b= nxt();
        adj[a].pb(b);
        adj[b].pb(a);
        v.pb(make_pair(a,b));
    }
    if(m==0) {
        printf("%d %lld\n",3,nc3(n));
        return 0;
    }
    for(int i = 1;i<=n;i++) {
        if(!color[i]){
            int ok = bfs(i,0);
            if(ok==0) {
                cout<<0<<" " <<1<<endl;
                return 0;
            }
        }
     }
     if(mx==2) {
        printf("%d %lld\n",2,(ll)v.size()*(ll)(n-2));
        return 0;
     }
     printf("1 ");
     CLR(color);
     ll sum = 0;
      for(int i = 1;i<=n;i++) {
        if(!color[i]){
            int c=0 ;
            component.clear();
            int ok = bfs(i,1);
            for(auto it : component) {
                color[it] = 0;
                if(level[it]%2==0) c++;
                level[it] = 0;
            }

            sum+=nc2(c);
            component.clear();
            c = 0;
            if(adj[i].size()) {
                int ok = bfs(adj[i][0],1);
                for(auto it : component) {
                   // debug(it,level[it]);
                    if(level[it]%2==0) c++;
                    level[it] = 0;
                }

            }

            sum+=nc2(c);
        }
     }

    cout<<sum<<endl;
    return 0;
}
