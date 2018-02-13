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
#define        inf                             1e19
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
struct tree{
  int left,right,val;
}node[N];
map<int,int> mp,mark;
 int ans;
void dfs(int u,int x,int y){

     if(node[u].val<x&&node[u].val>=y) mark[node[u].val]=1;
     if(node[u].left!=-1) dfs(node[u].left,min(x,node[u].val),y);
     if(node[u].right!=-1) dfs(node[u].right,x,max(y,node[u].val));
}
int main(){
     //freopen("out.txt","w",stdout);
     //freopen("in.txt","r",stdin);
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
    int n=nxt();
    FOR(i,1,n+1) {
      int a=nxt();
      int l=nxt();
      int r=nxt();
      node[i].val=a;
      node[i].left=l;
      node[i].right=r;
      mp[l]=mp[r]=1;
    }
     int root=-1;
    FOR(i,1,n+1)  if(mp.count(i)==0) {root=i; break;}
    dfs(root,INT_MAX,-1);
    FOR(i,1,n+1) if(mark.count(node[i].val)) ans++;
    cout<<n-ans<<endl;
return 0;
}