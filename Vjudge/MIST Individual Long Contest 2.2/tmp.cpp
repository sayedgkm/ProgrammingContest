 /// Bismillahir-Rahmanir-Rahim
#include <bits/stdc++.h>
#define        ll                              long long int
#define        FOR(x,y,z)                      for(int x=y;x<z;x++)
#define        pii                             pair<int,int>
#define        pll                             pair<ll,ll>
#define        CLR(a)                          memset(a,0,sizeof(a))
#define        SET(a)                          memset(a,-1,sizeof(a))
#define        N                               101
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
vector<string> in[N];
map<string,int>mp;
string mp1[N];

#define gray 1
#define white 0
#define black 2
vector<int> adj[N]; int counter=1;
int disc[N],low[N]; ///disc[N] is discovery time;
vector<int> st;
int visited[N];
int cycle[N];
int sz[N];
int mark[N][N];
vector<int> tmp[N];
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
                    sz[u]++;
                    tmp[u].pb(x);
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
         disc[i]=low[i]=visited[i]=cycle[i]=sz[i]=0;
         dag[i].clear();
      }
   for(int i=0;i<=n;i++){
      if(!visited[i]) tarjan(i);
   } shrink(n);
}
void printdag(int u){

   for(int i=0;i<dag[u].size();i++){
     int v=dag[u][i];
    printf("%d %d\n",u,v);
    printdag(v);
   }
}
vector<int> top;
int dfs(int u,int f) {
    if(f&&visited[u]==1) return sz[u];
    visited[u] = 1;
    int res = 0;
    for(auto it : dag[u]) {
          res = max(res, dfs(it,f));
    }
    if(f) return sz[u]=sz[u]+res;
    top.pb(u);
}
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
     //freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    int n;
    while(1) {
        n = nxt();
        if(n==0) {
            break;
        }
        string s;
        getline(cin,s);
        int rnk = 0;
        for(int i = 0;i<n;i++) {
            getline(cin,s);
            stringstream ss(s);
            string tmp;
            while(getline(ss,tmp,' ')){
                in[i].pb(tmp);
            }
            mp[in[i][0]] = rnk++;
            mp1[rnk-1] = in[i][0];
        }
        for(int i =0;i<n;i++) {
            int u = mp[in[i][0]];
            for(int j = 1;j<in[i].size();j++) {
                int v = mp[in[i][j]];
                if(mark[u][v]) continue;
                mark[u][v]  = 1;
               // debug(u,v);
                adj[u].pb(v);
            }
        }
        createDag(n);
        //printdag(1);
        CLR(visited);int mx = inf;
        for(int i =0;i<rnk;i++) {
            if(!visited[cycle[i]]) {
                dfs(cycle[i],0);
            }
        }
        CLR(visited);
        for(int i =top.size()-1;i>=0;i--) {
            if(!visited[top[i]]){
                dfs(top[i],1);

            }
        }
        for(int i =0;i<n;i++)
            mx = min(sz[cycle[i]],mx);
        vector<string> ans;
        for(int i = 0;i<rnk;i++) {
            if(tmp[i].size()==mx) {
                for(auto it : tmp[i]) {
                    ans.pb(mp1[it]);
                }
                break;
            }
        }
        sort(ALL(ans));
        printf("%d\n",(int)ans.size());
        for(int i =0;i<ans.size();i++) {
            if(i) printf(" ");
            printf("%s",ans[i].c_str());
        }
        printf("\n");
        mp.clear();
        ans.clear();
        for(int i =0;i<N;i++) {
            adj[i].clear();
            tmp[i].clear();

        }
        CLR(mark);
        top.clear();

    }

    return 0;
}

