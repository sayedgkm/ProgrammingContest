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
template < class T> inline T ison(T n,T pos){return (bool)(n & ((T)1<<pos));}
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

 vector<int> adj[N];
 int visited[N];
 int Left[N],Right[N];
 bool tryK(int u,int col){
    if(visited[u]==col) return false;
    visited[u]=col;
    for(int i=0;i<adj[u].size();i++){
        int v=adj[u][i];
        if(Right[v]==-1||tryK(Right[v],col)){     /// if Right[v]==-1 then v unmatched
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
    int res=0;  CLR(visited);
    for(int i=1;i<=n;i++)
        if(tryK(i,i)) res++;   ///trying to match every nodes of left side

    return res;
 }

 struct info{
    int time;
    int x1,x2,y1,y2;

 }ar[505];
 void make(int i,int j){

      //cout<<ar[i].time+abs(ar[i].x1-ar[i].x2)+abs(ar[i].y1-ar[i].y2)<<" "<<ar[j].time<<endl;
        if((ar[i].time+abs(ar[i].x1-ar[i].x2)+abs(ar[i].y1-ar[i].y2)
           +abs(ar[i].x2-ar[j].x1)+abs(ar[i].y2-ar[j].y1))<ar[j].time)
             adj[i+1].pb(j+1);



 }
int main(){
     //freopen("out.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
   int test=nxt();
   int cs=1;
   while(test--){

      int n=nxt();
      f(i,0,n){
        int h,m;
        scanf("%d:%d",&h,&m);
        info temp;
        temp.time=h*60+m;
        temp.x1=nxt(),temp.y1=nxt(),temp.x2=nxt(),temp.y2=nxt();
          ar[i]=temp;
       }
       for(int i=0;i<n;i++){

           for(int j=0;j<n;j++) {
               if(i==j) continue;
                make(i,j);
           }

       }
       //f(i,0,n) f(j,0,adj[i].size()) cout<<i<< " "<<adj[i][j]<<endl;
       int match=kuhn(n);
       printf("Case %d: %d\n",cs++,n-match);
       f(i,0,N) adj[i].clear();


   }

return 0;
}
