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
#define        N                               51
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
 struct bio{
   int age,height,type;
 }man[N],woman[N];
  vector<int> adj[N];
 int visited[N];
 int Right[N];
 bool tryK(int u,int color){
    if(visited[u]==color) return false;
    visited[u]=color;
    for(int i=0;i<adj[u].size();i++){
        int v=adj[u][i];
        if(Right[v]==-1||tryK(Right[v],color)){     /// if Right[v]==-1 then v unmatched
            Right[v]=u;
            return true;
        }

    }
  return false;
 }
 int kuhn(int n){
    SET(Right);
    CLR(visited);
    int res=0;
    for(int i=1;i<=n;i++){
        if(tryK(i,i)) res++;   ///trying to match every nodes of left side
    }
    return res;
 }
int main(){
     //freopen("out.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
   int test=nxt();
   int cs=1;
   while(test--){

       int m=nxt(),w=nxt();
       for(int i=1;i<=m;i++) man[i].height=nxt(),man[i].age=nxt(),man[i].type=nxt();
       for(int i=1;i<=w;i++) woman[i].height=nxt(),woman[i].age=nxt(),woman[i].type=nxt();
       for(int i=1;i<=m;i++){
            for(int j=1;j<=w;j++){
              if(man[i].type==woman[j].type&&abs(man[i].age-woman[j].age)<=5&&abs(man[i].height-woman[j].height)<=12)
                adj[i].pb(j);
           }
       }
      printf("Case %d: %d\n",cs++,kuhn(m));
      f(i,0,N)  adj[i].clear();
   }

return 0;
}
