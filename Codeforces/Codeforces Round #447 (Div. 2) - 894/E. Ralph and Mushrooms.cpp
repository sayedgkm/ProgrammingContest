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
#define gray 1
#define white 0
#define black 2
vector<int> adj[N]; int counter=1;
int disc[N],low[N]; ///disc[N] is discovery time;
vector<int> st;
int visited[N];
int cycle[N];
void tarjan(int u){
    disc[u]=low[u]=counter++;
    visited[u]=gray;
    st.pb(u);
    for(int i=0;i<adj[u].size();i++){
        int v=adj[u][i];
        if(visited[v]==white)
               tarjan(v);
        if(visited[v]==gray)   ///Back edge means gray to gray..so cycle found
              low[u]=min(low[u],low[v]);
         }
         if(low[u]==disc[u]){
            while(1){
                int x=st.back();
                st.pop_back();
                visited[x]=black;
                cycle[x]=u;
                if(x==u) break;
            }
    }

}
vector<int> dag[N];
void shrink(int node){
    for(int i=0;i<node;i++){
        for(int j=0;j<adj[i].size();j++){
            int t=adj[i][j];
            if(cycle[i]!=cycle[t]){
                dag[cycle[i]].pb(cycle[t]);
            }

        }

    }

}
void createDag(int n){
    counter=1; st.clear();
    for(int i=0;i<n;i++){
     disc[i]=low[i]=visited[i]=cycle[i]=0;
     dag[i].clear();
    }
    for(int i=0;i<n;i++){
      if(!visited[i]) tarjan(i);
    } shrink(n);
}
ll pre[N];
ll ar[N];
ll go(ll n) {
    ll tmp = sqrt(1+4*n*2LL);
    debug(tmp,4*n+1);
    tmp-=1;
    tmp/=2;
    return n*(tmp+1)-pre[tmp];
}
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    pre[0]=0;
    for(ll i = 1;i ;i++) {
        pre[i]= pre[i-1]+(i*i+i)/2;
        if(pre[i]>=1e9) break;
    }
    debug(go(10));
    int n= nxt();
    int m = nxt();
    for(int i = 0;i<m;i++) {
        int a= nxt()-1;
        int b= nxt()-1;
        adj[a].pb(b);
    }
    createDag(n);
    int s = nxt();

    return 0;
}

