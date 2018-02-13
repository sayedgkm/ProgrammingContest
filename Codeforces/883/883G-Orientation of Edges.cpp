//====================================
//======================================
//
//                   Bismillahir-Rahmanir-Rahim
//
// ==========================================================================
#include <bits/stdc++.h>
#define        ll                              long long int
#define        FOR(x,y,z)                      for(int x=y;x<z;x++)
#define        pii                             pair<int,int>
#define        pll                             pair<ll,ll>
#define        CLR(a)                          memset(a,0,sizeof(a))
#define        SET(a)                          memset(a,-1,sizeof(a))
#define        N                               2000010
#define        M                               1000000007
#define        pi                              acos(-1.0)
#define        ff                              first
#define        ss                              second
#define        pb                              push_back
#define        inf                              1e9
#define        eps                             1e-9
#define        debug(x)                        cerr << #x << " is " << x << endl;
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
///******************************************START******************************************
int ar[N];
struct info{
 int v,t,ind;

  info(int _v,int _t,int _ind) {
     v = _v;
     t =_t;
     ind = _ind;
  }
};
vector<info> adj[N];
vector<pii>  vv;
int mxcnt=0,mncnt=0;
int mxarr[N],mnarr[N];
int col[N];
void dfs(int u){
    if(col[u])return;
    col[u]=1;
    mxcnt++;
    for(int i=0;i<adj[u].size();i++){
        int v,t,ind;
        v=adj[u][i].v;
        if(col[v])continue;
        t=adj[u][i].t;
        ind=adj[u][i].ind;
        if(t==1){
            dfs(v);
        }
        else{
            int x=vv[ind].ff;
            int y=vv[ind].ss;
         //   cout<<x<<" "<<y<<" "<<ind<<" "<<u<<" "<<v<<endl;
            if(x==u && y==v)mxarr[ind]=1;
            else mxarr[ind]=-1;
            dfs(v);
        }
    }
}
void dfs2(int u){
    if(col[u])return;
    col[u]=1;
    mxcnt++;
    for(int i=0;i<adj[u].size();i++){
        int v,t,ind;
        v=adj[u][i].v;
        if(col[v])continue;
        t=adj[u][i].t;
        ind=adj[u][i].ind;
        if(t==1){
            dfs2(v);
        }
        else{
            int x=vv[ind].ff;
            int y=vv[ind].ss;
            if(x==u && y==v)mxarr[ind]=-1;
            else mxarr[ind]=1;
        }
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
   int m = nxt();
   int s = nxt();
   int id = 0;
   FOR(i,0,m){
      int t = nxt();
      int a = nxt();
      int b = nxt();
       if(t==2) {
          vv.pb(make_pair(a,b));
              adj[a].pb(info(b,t,id));
              adj[b].pb(info(a,t,id));
              id++;
       } else {
         adj[a].pb(info(b,t,m));
       }

   }
   dfs(s);
   printf("%d\n",mxcnt);
   for(int i=0;i<id;i++){
    if(mxarr[i]==1)printf("+");
    else printf("-");
   // if(i<id-1)printf(" ");
   }
   printf("\n");
    CLR(col); mxcnt=0;CLR(mxarr);
    dfs2(s);
    dfs2(s);
   printf("%d\n",mxcnt);
   for(int i=0;i<id;i++){
    if(mxarr[i]==1)printf("+");
    else printf("-");
   // if(i<id-1)printf(" ");
   }
   printf("\n");
return 0;
}