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
#define        inf                             9e9+100
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
int br[N];
vector<int> index[N];
vector<int> tree[4*N];
///Each of tree nodes keeps all value sorted from index low to high
void buildSegment_tree(int node,int low,int high) {
    if(low==high) {
        tree[node].pb(br[low]);
        return;
    }
    int left=2*node;
    int right=2*node+1;
    int mid=(low+high)/2;
    buildSegment_tree(left,low,mid);
    buildSegment_tree(right,mid+1,high);
    int sz=tree[left].size();
    int sz1=tree[right].size();
    tree[node].resize(sz+sz1);
    merge(tree[left].begin(),tree[left].begin()+sz,tree[right].begin(),tree[right].begin()+sz1,tree[node].begin());
}
int query(int node,int low,int hi,int i,int j,int val) {

    if(i>hi||j<low) return 0;
    if(low>=i&&hi<=j)
        return lower_bound(tree[node].begin(),tree[node].end(),val)-tree[node].begin();
    int mid=(low+hi)/2;
    int left=2*node;
    int right=left+1;
    int x= query(left,low,mid,i,j,val);
    int y= query(right,mid+1,hi,i,j,val);
    return x+y;
}
int main(){
     //freopen("out.txt","w",stdout);
     //freopen("in.txt","r",stdin);
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);'
   int n=nxt();
   int k=nxt();
   FOR(i,1,n+1) ar[i]=nxt(),index[ar[i]].pb(i);
   FOR(i,1,n+1) {
       int x=ar[i];
       int low=lower_bound(ALL(index[x]),i)-index[x].begin();
       low-=k;
       if(low<0) br[i]=-1;
       else br[i] =index[x][low];
    }
    buildSegment_tree(1,1,n);
    int q=nxt();
    int ans=0;
    FOR(i,0,q) {
       int a=nxt();
       int b=nxt();
       a=(a+ans)%n+1;
       b=(b+ans)%n+1;
       if(a>b) swap(a,b);
       ans=query(1,1,n,a,b,a);
       printf("%d\n",ans);
    }
return 0;
}