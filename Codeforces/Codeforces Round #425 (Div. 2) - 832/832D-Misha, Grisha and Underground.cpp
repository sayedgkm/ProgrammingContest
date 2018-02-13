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
vector<int>adj[N];
int table[32][N];  ///for sparse  table
int depth[N];     ///depth of each node from root
int parent[N];
void dfs(int s,int p=-1,int d=0){
       parent[s]=p;
       depth[s]=d;
      for(int i=0;i<adj[s].size();i++){
         int t=adj[s][i];
         if(t==p) continue;
          dfs(t,s,d+1);
      }


}
void lca_init(int n){
   SET(table);
   for(int i=0;i<n;i++){
      table[0][i]=parent[i];
    }
    for(int i=1;(1<<i)<n;i++){
         for(int j=0;j<n;j++){
            table[i][j]=table[i-1][table[i-1][j]];
        }
    }

}
int lca_query(int p,int q){  ///p && q are two nodes.
        if(depth[q]>depth[p])
              swap(p,q);
        int log=1;
        while((1<<log)<depth[p]) log++;
    for(int i=log;i>=0;i--){
           if(depth[p]-(1<<i)>=depth[q])  ///making same level of p and q
                  p=table[i][p];

        }
    if(p==q)
          return p;
    for(int i=log;i>=0;i--){
        if(table[i][p]!=-1&&table[i][p]!=table[i][q])
               p=table[i][p],q=table[i][q];
    }
    return parent[p];

}
int dist(int a,int b){
    return depth[a]+depth[b]-2*depth[lca_query(a,b)];
}
int solve(int a,int b,int c) {

    int lc= lca_query(a,b);
    int lc1=lca_query(a,c);
    if(depth[lc1]<depth[lc]){

        return dist(lc,c);
    }
    if(lc==lc1) {
        lc = lca_query(b,c);
        return dist(lc,c);
    } else  {
      return dist(lc1,c);
    }
}
int main(){
    #ifdef sayed
     //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
    int n=nxt();
    int q=nxt();
    FOR(i,1,n) {
      int a=nxt();
       a--;
       adj[a].pb(i);
       adj[i].pb(a);
    }
    dfs(0);
//    debug(parent[0]);
//    debug(parent[1]);
//    debug(parent[2]);
    lca_init(n);
    while(q--) {

         int a=nxt();
         int b=nxt();
         int c=nxt();
           a--,b--,c--;
        printf("%d\n",max(max(solve(a,b,c),solve(a,c,b)),solve(b,c,a))+1);
    }
return 0;
}