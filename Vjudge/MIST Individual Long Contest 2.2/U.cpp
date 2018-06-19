 /// Bismillahir-Rahmanir-Rahim
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
inline double dxt(){double aaa;scanf("%lf",&aaa);return aaa;}
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
        cerr.write(names, comma - names) << " is " << arg1 <<" | ";
        __f(comma+1, args...);
    }
#else
    #define debug(...)
#endif
///******************************************START******************************************
long n; // number of node in tree
vector<long> Edge[N+7];
long SubT[N+7]; // subtree size
long Par[N+7]; // parent of a node
long Level[N+7]; // level of a node

long nC; // number of chain
long ChainLdr[N+7]; // chainleadr of a node
                                          // for light edge chainldr is that node
long Chain[N+7];        // node v in is which chain
long nP=0;                        // number of position , obviously == N
long Pos[N+7];    // Pos of a node in chain/dfs order
vector<int> nodeList;
/* find subtree size and level */

long Explore( long u,long p,long l )
{
    SubT[u] = 1;
    Par[u] = p;
    Level[u] = l;
    long i;
    for( i=0;i<Edge[u].size();i++){
            long v = Edge[u][i];
            if( p==v ) continue;
            SubT[u] += Explore( v,u,l+1 );
    }
    return SubT[u];
}
/* if IsL make this node a chainledr of new chain */
void HeavyLight( long u,long k,bool IsL )
{
    if( IsL ){
        k = ++nC;
        ChainLdr[k] = u;
    }
    Chain[u] = k;
    if(nodeList.size()==0) nodeList.pb(0); /// 1 based index so 0 is dummy value
    nodeList.pb(u);
    Pos[u] = ++nP;
    //Update( nP,W[u] ); if query is need can b updated here
    long i,mx = -1; // max subtree size child is mx
    for( i=0;i<Edge[u].size();i++){
        long v = Edge[u][i];
        if( Par[u]==v ) continue;
        if( mx==-1 ) mx = v;
        else if( SubT[v] > SubT[mx] ) mx = v;
    }
    if( mx==-1 ) return;
    HeavyLight( mx,k,false );
    for( i=0;i<Edge[u].size();i++){
        long v = Edge[u][i];
        if( Par[u]==v || mx == v ) continue;
        HeavyLight( v,0,true );
    }
}

int ar[N];
struct info
{
    ll sum;
    ll lazy;

} tree[N*4];
void segment_tree(int node,int low,int high)
{
    if(low==high)
    {
        tree[node].sum=ar[nodeList[low]];
        return;
    }
    int left=2*node;
    int right=2*node+1;
    int mid=(low+high)/2;
    segment_tree(left,low,mid);
    segment_tree(right,mid+1,high);
    tree[node].sum=tree[left].sum+tree[right].sum;
}
void update(int node,int low,int hi,int i,int value){

   if(low==hi){
    tree[node].sum=value; return;
   }
   int mid=(low+hi)/2;
   int left=2*node;
   int right=left+1;
   if(i<=mid)
      update(left,low,mid,i,value);
   else
      update(right,mid+1,hi,i,value);
   tree[node].sum=tree[left].sum+tree[right].sum;
}
ll query(int node,int low,int hi,int i,int j){
    if(i>hi||j<low) return 0;
    if(low>=i&&hi<=j)
      return tree[node].sum;
    int mid=(low+hi)/2;
    int left=2*node;
    int right=left+1;
    ll x= query(left,low,mid,i,j);
    ll y= query(right,mid+1,hi,i,j);
    return x+y;
}
long LCA( long u,long v )
{
    while( Chain[u]!=Chain[v] ){
        if(Level[ChainLdr[Chain[u]]] < Level[ChainLdr[Chain[v]]] ){
            v = Par[ChainLdr[Chain[v]]];
        }
        else{
            u = Par[ChainLdr[Chain[u]]];
        }
    }
    if( Level[u]<Level[v] ) return u;
    else return v;
}

ll query(int u,int v,int n) {
    ll sum = 0;
    while(Chain[u]!=Chain[v]){
        if(Level[ChainLdr[Chain[u]]]<Level[ChainLdr[Chain[v]]]){
            int par1 = ChainLdr[Chain[v]];
            sum+=query(1,1,n,Pos[par1],Pos[v]);
            v = Par[ChainLdr[Chain[v]]];
        } else {
            int par1 = ChainLdr[Chain[u]];
            sum+=query(1,1,n,Pos[par1],Pos[u]);
            u = Par[ChainLdr[Chain[u]]];
        }
    }
    if( Level[u]<Level[v] ) sum+=query(1,1,n,Pos[u]+1,Pos[v]);
    else sum+=query(1,1,n,Pos[v]+1,Pos[u]);

    if(Level[v]<Level[u]) u = v;
    sum+=query(1,1,n,Pos[u],Pos[u]); /// skip this line if edge update is needed
    return sum;
}
void init() {
    nC = 0;
    nP = 0;
    nodeList.clear();
    for(int i =0;i<N;i++) {
        Pos[i] = Chain[i] = ChainLdr[i] = Level[i] = Par[i] = SubT[i] = 0;
        Edge[i].clear();
    }
    CLR(tree);
}
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    int test = nxt(); int cs = 1;
    while(test--) {
        int n= nxt();
        for(int i =0;i<n;i++) ar[i] = nxt();
        for(int i =0;i<n-1;i++){
            int a= nxt();
            int b= nxt();
            Edge[a].pb(b);
            Edge[b].pb(a);
        }
        Explore(0,0,0);
        HeavyLight(0,0,true);
        segment_tree(1,1,n);
        printf("Case %d:\n",cs++);
        int q= nxt();
        while(q--) {
            int t = nxt();
            if(t==0) {
               int a= nxt();
               int b= nxt();
               printf("%lld\n",query(a,b,n));
            } else {
                int pos = Pos[nxt()];
                int val = nxt();
                update(1,1,n,pos,val);
            }
        }
        init();
    }


    return 0;
}
