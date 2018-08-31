//==========================================================================
//
//                   Bismillahir-Rahmanir-Rahim
//
// ==========================================================================
#include <bits/stdc++.h>
#define        ll                              long long int
#define        f(x,y,z)                        for(int x=y;x<z;x++)
#define        pii                             pair<int,int>
#define        pll                             pair<ll,ll>
#define        CLR(a)                          memset(a,0,sizeof(a))
#define        SET(a)                          memset(a,-1,sizeof(a))
#define        N                               1010
#define        M                               1000000007
#define        pi                              acos(-1.0)
#define        ff                              first
#define        ss                              second
#define        pb                              push_back
#define        inf                             (int)1e9
using namespace std;
int dx[]={0,0,1,-1,-1,-1,1,1};
int dy[]={1,-1,0,0,-1,1,1,-1};
template < class T> inline T biton(T n,T pos){return n |((T)1<<pos);}
template < class T> inline T bitoff(T n,T pos){return n & ~((T)1<<pos);}
template < class T> inline T on(T n,T pos){return (bool)(n & ((T)1<<pos));}
template < class T> inline T gcd(T a, T b){while(b){a%=b;swap(a,b);}return a;}
template <typename T> string NumberToString ( T Number ) { ostringstream ss; ss << Number; return ss.str(); }
inline int nxt(){int aaa;scanf("%d",&aaa);return aaa;}
inline ll lxt(){ll aaa;scanf("%I64d",&aaa);return aaa;}
template <class T> inline T bigmod(T p,T e,T m){T ret = 1;
for(; e > 0; e >>= 1){
    if(e & 1) ret = (ret * p) % m;p = (p * p) % m;
} return (T)ret;}
#define sayed
#ifdef sayed
     #define debug(args...) {cerr<<"Debug: "; dbg,args; cerr<<endl;}
#else
    #define debug(args...)  // Just strip off all debug tokens
#endif
struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;
///******************************************START******************************************


#define gray 1
#define white 0
#define black 2
vector<int> adj[N],adj1[N];
int visited[N];
int counter=1;
int disc[N],low[N]; ///dfs[N] is discovery time;
vector<int> st;
int cycle[N]; int scc=0;
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
                    scc++;
                while(1){

                    int x=st.back();
                    st.pop_back();
                    visited[x]=black;
                     cycle[x]=scc;

                    if(x==u) break;
                }

        }

}
vector<int> dag[N];
void shrink(int node){
   for(int i=1;i<=node;i++){
         for(int j=0;j<adj[i].size();j++){
            int t=adj[i][j];
            if(cycle[i]!=cycle[t]){
                dag[cycle[i]].pb(cycle[t]);
            }

         }

   }

}
void createDag(int n){
     for(int i=0;i<N;i++){
        low[i]=visited[i]=cycle[i]=disc[i]=0;
     }
     counter=1;
     scc=0;
     for(int i=1;i<=n;i++) if(!visited[i]) tarjan(i);
     shrink(n);
        //cout<<scc<<" scc "<<endl;
    // for(int i=1;i<=scc;i++) {
         //for(int j=0;j<dag[i].size();j++) cout<<i<<" dag "<<dag[i][j]<<endl;
    // }
 }
void bfs(int m,int color){
     visited[m]=color;
     queue<int>q;
     q.push(m);
     while(!q.empty()){
       int u=q.front(); q.pop();
        for(int i=0;i<dag[u].size();i++){
            int v=dag[u][i];
           if(visited[v]!=color){
              visited[v]=color;
              adj1[m].pb(v);
                q.push(v);
           }

         }

     }
 }
 int Left[N],Right[N];
 bool tryK(int u,int color){
    if(visited[u]==color) return false;
    visited[u]=color;
    for(int i=0;i<adj1[u].size();i++){
        int v=adj1[u][i];
        if(Right[v]==-1||tryK(Right[v],color)){     /// if Right[v]==-1 then v unmatched
            Right[v]=u;
            Left[u]=v;
            return true;
        }

    }
  return false;
 }
 int kuhn(int n){
     SET(Left);
     SET(Right);
     CLR(visited);
    int res=0;
    for(int i=1;i<=n;i++)
         if(tryK(i,i)) res++;   ///trying to match every nodes of left side

    return res;
 }

 int main(){
     //freopen("out.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
   int test=nxt();
    int cs=1;
   while(test--){

    int n=nxt(),m=nxt();
      while(m--){
            int a=nxt(),b=nxt();
            adj[a].pb(b);
      }
    createDag(n);
    for(int i=1;i<=scc;i++) bfs(i,i);
     printf("Case %d: %d\n",cs++,scc-kuhn(scc));
     f(i,0,N){
      adj[i].clear();
      adj1[i].clear();
      dag[i].clear();
     }
     CLR(visited);
   }

return 0;
}
