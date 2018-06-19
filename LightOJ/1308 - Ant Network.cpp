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
#define  gray  1
#define  white 0
#define  black 2
vector<int> adj[N];
int disc[N],low[N],color[N],visited[N];
int counter=1;
int root;
int point[N];
void init(){
    counter =1 ;
    for(int i = 0;i<N;i++) {
        adj[i].clear();
        disc[i] = low[i]= color[i]= visited[i] = point[i] = 0;
    }
}
int artpoint(int s,int p) {
    disc[s]=low[s]=counter++;  ///discovery time and lowest back edge extension
    color[s]=gray;
    int child=0; ///only for root.
    for(int i=0; i<adj[s].size(); i++) {
        int t=adj[s][i];
        if(t==p)  ///don't go to parent
            continue;
        if(color[t]==white) {   ///Tree Edge
            child++;
            artpoint(t,s);
            if(s==root&&child>1) {  ///for root articulation point is different case
                if(!visited[s])
                    point[s] = 1;
                visited[s]=1;
            }
            if(disc[s]<=low[t]&&s!=root) {
                if(!visited[s])
                    point[s] = 1;
                visited[s]=1;
            }
            low[s]=min(low[s],low[t]);
        } else if(color[t]==gray) {         ///Back Edge
            low[s]=min(low[s],disc[t]);
        }
    }

}
unsigned ll cnt = 0;
int cutReach = 0;
set<int> st;
void dfs(int u) {
    cnt++;
    visited[u] =1 ;
    for(int i = 0;i<adj[u].size();i++){
        if(point[adj[u][i]]==1) {
            st.insert(adj[u][i]);
        }
        if(visited[adj[u][i]]==0&&point[adj[u][i]]==0)
            dfs(adj[u][i]);

    }
}
ll nc2(ll n) {
    return (n*n-n)/2LL;
}
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    int test = nxt();int cs =1;
    while(test--) {
        int n= nxt();
        int m  = nxt();
        for(int i =0;i<m;i++) {
            int a= nxt();
            int b= nxt();
            adj[a].pb(b);
            adj[b].pb(a);
        }
        for(int i = 0;i<n;i++) if(!color[i]){
            root= i;
            artpoint(i,-1);

        }
        unsigned ll ans = 1;
        CLR(visited);
        int c= 0;
        for(int i = 0;i<n;i++) {
            cnt = 0;cutReach = 0;
            st.clear();
            if(!(visited[i]==1||point[i]==1)){
                dfs(i);
                cutReach = st.size();
                if(cutReach==0) ans+=nc2(cnt)-1,c++;
                else if(cutReach==1)
                    ans*=cnt;
                else {
                    continue;
                }
                c++;
            }

        }

        printf("Case %d: %d %llu\n",cs++,c,ans);
        init();

    }

    return 0;
}

