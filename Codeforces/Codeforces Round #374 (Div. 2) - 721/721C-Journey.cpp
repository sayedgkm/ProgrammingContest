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
#define        N                               5005
#define        M                               1000000007
#define        pi                              acos(-1.0)
#define        ff                              first
#define        ss                              second
#define        pb                              push_back
#define        inf                             (int)1e9
#define        eps                              1e-9
using namespace std;
int dx[]={0,0,1,-1,-1,-1,1,1};
int dy[]={1,-1,0,0,-1,1,1,-1};
template < class T> inline T biton(T n,T pos){return n |((T)1<<pos);}
template < class T> inline T bitoff(T n,T pos){return n & ~((T)1<<pos);}
template < class T> inline T ison(T n,T pos){return (bool)(n & ((T)1<<pos));}
template < class T> inline T gcd(T a, T b){while(b){a%=b;swap(a,b);}return a;}
template <typename T> string NumberToString ( T Number ) { ostringstream ss; ss << Number; return ss.str(); }
inline int nxt(){int aaa;scanf("%d",&aaa);return aaa;}
inline ll lxt(){ll aaa;scanf("%I64d",&aaa);return aaa;}
inline double dxt(){double aaa;scanf("%lf",&aaa);return aaa;}
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
vector<pii> adj[N];
int dist[N][N];
 int path[N][N];
 struct node {
    int u; int cost; int len;
 };
bool operator < (node a,node b){
    return a.cost>b.cost;
}
void dijkstra(ll n){
      priority_queue<node> pq;
      for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
              dist[i][j]=INT_MAX;
              path[i][j]=-1;
        }
      }

      dist[1][1]=0;
      node temp;
      temp.cost=0;
      temp.len=1;
      temp.u=1;
      pq.push(temp);
      while(!pq.empty()){
         node top=pq.top();
           pq.pop();
         for(int i=0;i<adj[top.u].size();i++){
                ll v=adj[top.u][i].ff;
                ll cost=adj[top.u][i].ss;
              //  cout<<dist[top.u][top.len]<<" "<<dist[v][top.len+1]<<endl;
                if(dist[top.u][top.len]+cost<dist[v][top.len+1]){
                    dist[v][top.len+1]=dist[top.u][top.len]+cost;
                    path[v][top.len+1]=top.u;

                    node temp;
                    temp.cost=dist[v][top.len+1];
                    temp.u=v;
                    temp.len=top.len+1;
                    pq.push(temp);
                }

         }

      }


 }
 void print(int v,int len){

       if(v==-1) return ;
       print(path[v][len],len-1);
       printf("%d ",v);

 }
int main(){
     //freopen("out.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
   int n=nxt(),m=nxt(),t=nxt();
     for(int i=0;i<m;i++){
            int a=nxt(),b=nxt(),c=nxt();
          adj[a].pb({b,c});
     }
      dijkstra(n);

      int ans;
      for(int i=1;i<=n;i++){
       //  cout<<dist[n][i]<<endl;
        if(dist[n][i]<=t){
            ans=i;
        }

      }
      printf("%d\n",ans);
      print(n,ans);
      puts("");

return 0;
}