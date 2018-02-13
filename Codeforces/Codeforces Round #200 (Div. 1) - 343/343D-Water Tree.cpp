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
#define        N                               500010
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
int ar[N];
int par[N];
int st[N];
int ed [N];
int t = 1;
vector<int>adj[N];
void dfs(int u,int p = -1) {
    st[u] = t++;
    par[u] = p;
    for(int i =0;i<adj[u].size();i++) {
        int v = adj[u][i];
        if(v==p) continue;
        dfs(v,u);
    }
    ed [u] = t;
}

struct info{
  ll sum;
  ll lazy;

}tree[N*4];
void segment_tree(int node,int low,int high){
     if(low==high){
        tree[node].sum=ar[low]; return;
     }
    int left=2*node;
    int right=2*node+1;
    int mid=(low+high)/2;
     segment_tree(left,low,mid);
     segment_tree(right,mid+1,high);
     tree[node].sum=tree[left].sum+tree[right].sum;
}
void propagate(int node,int low,int hi){
    int left=2*node;
    int right=left+1;
    int mid =(low+hi)/2;
     tree[node].sum=(hi-low+1)*tree[node].lazy;
            if(hi!=low){
               tree[left].lazy=tree[node].lazy;
               tree[right].lazy=tree[node].lazy;
            }

    tree[node].lazy=0;
}
void update(int node,int low,int hi,int i,int j,int value){
    int left=2*node;
    int right=left+1;
      if(tree[node].lazy)propagate(node,low,hi);
      if(hi<i||j<low) return;
      if(low>=i&&hi<=j){
           tree[node].sum=(hi-low+1)*value;
            if(hi!=low){
               tree[left].lazy=value;
               tree[right].lazy=value;
            }
           tree[node].lazy=0;
        return ;
      }
   int mid=(low+hi)/2;
      update(left,low,mid,i,j,value);
      update(right,mid+1,hi,i,j,value);
   tree[node].sum=tree[left].sum+tree[right].sum;
}
ll query(int node,int low,int hi,int i,int j){
       int left=2*node;
      int right=left+1;
       if(tree[node].lazy)propagate(node,low,hi);
    if(hi<i||j<low) return 0;
  if(low>=i&&hi<=j)
          return tree[node].sum;
  int mid=(low+hi)/2;
  ll x= query(left,low,mid,i,j);
  ll y= query(right,mid+1,hi,i,j);
  return x+y;

}
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    int n = nxt();
    FOR(i,0,n-1) {
        int a= nxt();
        int b = nxt();
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(1);
    debug(ed[1]);
    int q = nxt();
    while(q--) {
        int t = nxt();
        int v = nxt();
        int a = st[v];
        int b = ed[v]-1;
        if(t==1) {
            int x = query(1,1,n,a,b);
            int zero = b-a+1-x;
            if(zero>0&&v!=1) {
                int p = par[v];
                update(1,1,n,st[p],st[p],0);
            }
            update(1,1,n,a,b,1);
        } else if(t==2) {
            update(1,1,n,st[v],st[v],0);

        } else {
            int q = query(1,1,n,a,b);
            debug(q);
            debug(a,b);
            int zero = b-a+1-q;
            if(zero>0) printf("0\n");
            else printf("1\n");
        }
    }

    return 0;
}