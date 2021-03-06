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
#define        N                               200010
#define        M                               1000000007
#define        pia                              acos(-1.0)
#define        ff                              first
#define        ss                              second
#define        pb                              push_back
#define        inf                             (int)1e9
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
set<int> st;
set<int> ::iterator it;
int ar[N];
int color[N];
int ok[N];
vector<int> adj[N];
int visited[N];
int visited1[N];
int mx=0;
int cnt=0;
void dfs(int u){
  cnt++;
  visited[u]=1;
  ok[ar[u]]++;
  mx=max(mx,ok[ar[u]]);
  for(int i=0;i<adj[u].size();i++){
        if(!visited[adj[u][i]])
               dfs(adj[u][i]);
  }
  //ok[ar[u]]--;

}
void dfs1(int u){

  visited1[u]=1;
  ok[ar[u]]=0;
  for(int i=0;i<adj[u].size();i++){

    if(!visited1[adj[u][i]]) dfs1(adj[u][i]);
  }

}
int main(){
     //freopen("out.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);

   int n=nxt();
   int m=nxt();
   int k=nxt();
   for(int i=1;i<=n;i++)
            ar[i]=nxt();


  for(int i=0;i<m;i++){

      int a=nxt(),b=nxt();
      adj[a].pb(b);
      adj[b].pb(a);
      st.insert(a);
      st.insert(b);

  }
  int res=0;
  for(it=st.begin();it!=st.end();it++){

      mx=0;cnt=0;
      if(!visited[*it]){
          dfs(*it);
        //  cout<<*it<<endl;
          //cout<<cnt<<" "<<mx<<endl;
        res+=cnt-mx;
        dfs1(*it);
      }

  }

cout<<res<<endl;
return 0;
}