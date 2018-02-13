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
int deg[N];
vector<pii> edge;
priority_queue<pii> q;
vector<pii> v;
vector<int> adj[N];
int main(){
    #ifdef sayed
     //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
   int  n = nxt();
   bool flag = 0;
   ll sum = 0;
   FOR(i,1,n+1) {
     ar[i] = nxt();
     sum+=ar[i];
     v.push_back(make_pair(ar[i],i));
     if(ar[i]<=0) flag = 1;

   }
   if(sum!=2*(n-1)) {

             printf("-1\n");
             return 0 ;

   }
   sort(ALL(v));
   reverse(ALL(v));
   //for(int i = 0;i<v.size();i++) cout<<v[i].ss<<endl;
      int j = 1;
      for(int i = 0;i<n;i++) {
          pii a= v[i];
          while(a.ff--&&j<n) {
                edge.pb(make_pair(a.ss,v[j].ss));
                //debug(a.ss);
               // debug(v[j].ss);
                v[j].ff--;
                j++;

          }
      }
       for(int i= 0;i<edge.size();i++) {
           deg[edge[i].ff]++;
           deg[edge[i].ss]++;
       }
       for(int i = 1;i<=n;i++) {
          if(ar[i]!=deg[i]) {
             printf("-1\n");
             return 0 ;
          }
       }
       if(edge.size()!=n-1) {
             printf("-1\n");
             return 0 ;
          }
      FOR(i,0,edge.size()) printf("%d %d\n",edge[i].ff,edge[i].ss);


return 0;
}