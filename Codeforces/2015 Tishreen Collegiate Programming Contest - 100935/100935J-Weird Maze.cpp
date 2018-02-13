//==========================================================================
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
#define        N                               200010
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
   int x,y,cost,t;
   info() {
   }
   info(int a,int b,int c,int d) {
      x =a ;
      y = b;
      cost = c;
      t = d;

   }
   bool operator<(const info& ok) const{
       return ok.cost<cost;
   }
};
map<pii,vector<info> > adj;
int level[105][105][400];
void dijkstra(int sx,int sy,int t) {

     priority_queue<info> pq;
     FOR(i,0,105) FOR(j,0,105) FOR(k,0,400) level[i][j][k]=inf;
     level[sx][sy][t]=0;
       pq.push(info(sx,sy,0,t));
      // adj.clear();
     while(!pq.empty()) {

            info top = pq.top();
             pq.pop();
            int sz = adj[make_pair(top.x,top.y)].size();
            FOR(i,0,sz) {
                info temp = adj[make_pair(top.x,top.y)][i];
                if(temp.t+top.t<0) continue;
                if(temp.t+top.t>200) continue;
                if(level[top.x][top.y][top.t] + temp.cost<level[temp.x][temp.y][temp.t+top.t]) {
                    level[temp.x][temp.y][temp.t+top.t]= level[top.x][top.y][top.t] + temp.cost;
                    pq.push(info(temp.x,temp.y,level[temp.x][temp.y][temp.t+top.t],temp.t+top.t));
                }
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

    int test=nxt();
    int cs =1;
    while(test--) {

         int n=nxt();
         int m=nxt();
         int st=nxt();
         int ed=nxt();
         int p=nxt();
         while(p--) {
              int a=nxt();
              int b =nxt();
              info temp;
              temp.x =nxt();
              temp.y = nxt();
              temp.cost =nxt();
              temp.t =nxt();
              adj[make_pair(a,b)].pb(temp);

         }
       dijkstra(st,ed,100);
         printf("Case %d:\n",cs++);
         int q=nxt();
         while(q--) {
             int a =nxt();
             int b =nxt();
             int t= nxt();
             t += 100;
            if(level[a][b][t]>=inf) {
                 printf("No\n");
            } else printf("%d\n",level[a][b][t]);

         }
         adj.clear();
    }
return 0;
}