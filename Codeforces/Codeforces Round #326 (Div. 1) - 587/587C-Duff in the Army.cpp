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
inline long double dxt(){long double aaa;scanf("%lf",&aaa);return aaa;}
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
        cerr.write(names, comma - names) << " is " << arg1 <<endl;
        __f(comma+1, args...);
    }
#else
    #define debug(...)
#endif
///******************************************START******************************************
vector<int>adj[N];
int table[32][N];
vector<int> man[32][N];
int depth[N];
int parent[N];
void dfs(int s,int p,int d){
       parent[s]=p;
       depth[s]=d;
      for(int i=0;i<adj[s].size();i++){
         int t=adj[s][i];
         if(t==p) continue;
          dfs(t,s,d+1);
      }


}
vector<int> Merge(vector<int> a,vector<int> b) {
    vector<int> c;
    c.resize(a.size()+b.size());
    merge(ALL(a),ALL(b),c.begin());
    if(c.size()>10) c.resize(10);
    return c;
}
void lca_init(int n){
   SET(table);
   for(int i=0;i<n;i++){
      table[0][i]=parent[i];
    }
    for(int i=1;(1<<i)<n;i++){
         for(int j=0;j<n;j++){
            if(table[i-1][j]!=-1){
                man[i][j] = Merge(man[i-1][j],man[i-1][table[i-1][j]]);
                table[i][j]=table[i-1][table[i-1][j]];
            }
        }
    }

}
vector<int> lca_query(int p,int q){
    if(depth[q]>depth[p])
            swap(p,q);
    int log=1;
    vector<int>ans;
    while((1<<log)<depth[p]) log++;
    for(int i=log;i>=0;i--){
           if(depth[p]-(1<<i)>=depth[q]) {
                  ans = Merge(ans,man[i][p]);
                  p=table[i][p];

           }
        }
    if(p==q){
     ans = Merge(ans,man[0][p]);
     return ans;
    }
    for(int i=log;i>=0;i--){
        if(table[i][p]!=-1&&table[i][p]!=table[i][q]){
               ans = Merge(ans,man[i][p]);
               ans = Merge(ans,man[i][q]);
               p=table[i][p],q=table[i][q];
        }
    }
    ans = Merge(ans,man[0][p]);
    ans = Merge(ans,man[0][q]);
    p = parent[p];
    ans = Merge(ans,man[0][p]);
    return ans;

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
    int q = nxt();
    FOR(i,0,n-1) {
        int a = nxt();
        int b = nxt();
        a--;b--;
        adj[a].pb(b) ;
        adj[b].pb(a) ;

    }
    for(int i  = 1;i<=m;i++){
        int a = nxt();
        a--;
        man[0][a].pb(i);
    }
    for(int i = 0;i<n;i++) {
        sort(ALL(man[0][i]));
        if(man[0][i].size()>10) man[0][i].resize(10);
    }
    dfs(0,-1,1);
    lca_init(n);
    while(q--) {

        int  u = nxt();
        int v = nxt();
        u--;
        v--;
        int a = nxt();
        vector<int> res;
        res = lca_query(u,v);
        if(res.size()>a) res.resize(a);
        printf("%d",(int)res.size()) ;
        for(int i = 0;i<res.size();i++) {
            printf(" %d",res[i]);
        }
        printf("\n");
    }



    return 0;
}