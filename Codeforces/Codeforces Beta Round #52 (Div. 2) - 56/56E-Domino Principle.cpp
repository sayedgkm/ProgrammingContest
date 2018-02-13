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
#define        inf                             1e9
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
pair<int,pii> ar[N];
int ans[N];
int n;

struct info{
  ll sum;
  ll lazy;

}tree[N*4];
void propagate(int node,int low,int hi){
    int left=2*node;
    int right=left+1;
    int mid =(low+hi)/2;
     tree[node].sum+=tree[node].lazy;
            if(hi!=low){
               tree[left].lazy+=tree[node].lazy;
               tree[right].lazy+=tree[node].lazy;
            }
           tree[node].lazy=0;
    tree[node].lazy=0;
}
void update(int node,int low,int hi,int i,int j,int value){
    int left=2*node;
    int right=left+1;
      if(tree[node].lazy)propagate(node,low,hi);
      if(hi<i||j<low) return;
      if(low>=i&&hi<=j){
           tree[node].sum+=value;
            if(hi!=low){
               tree[left].lazy+=value;
               tree[right].lazy+=value;
            }
           tree[node].lazy=0;
        return ;
      }
   int mid=(low+hi)/2;
      update(left,low,mid,i,j,value);
      update(right,mid+1,hi,i,j,value);
   tree[node].sum=max(tree[left].sum,tree[right].sum);
}
void updateind(int node,int low,int hi,int i,int value){
    int left=2*node;
    int right=left+1;
      if(tree[node].lazy)propagate(node,low,hi);
      if(low>=i&&hi<=i){
          tree[node].sum=value;
          return;

      }
   int mid=(low+hi)/2;
   if(i<=mid)
      updateind(left,low,mid,i,value);
     else
        updateind(right,mid+1,hi,i,value);
   tree[node].sum=max(tree[left].sum,tree[right].sum);
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
  return max(x,y);

}
int nextInd(int val){
   int b=1;
   int e=n;
  // debug(val);
   while(b<=e) {
     int mid=(b+e)/2;
     if(ar[mid].ff<val) b=mid+1;
     else e=mid-1;

   }
   //debug(b);
   return b-1;
}
int main(){
     //freopen("out.txt","w",stdout);
     //freopen("in.txt","r",stdin);
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
      n=nxt();
    FOR(i,1,n+1) {
         int a=nxt();
         int b=nxt();
           ar[i]=make_pair(a,pii(b,i));
    }
    sort(ar+1,ar+n+1);
    ans[ar[n].ss.ss]=1;
    updateind(1,1,n,n,1);
    for(int i=n-1;i>=1;i--) {
          //  debug(query(1,1,n,1,n));
        int h=ar[i].ff;
        int x=ar[i].ss.ff;
        int index=ar[i].ss.ss;
          update(1,1,n,i+1,n,1);
         int l=nextInd(h+x);
         int lol;
           if(l==i) {
             lol=1;
           } else {
               lol=query(1,1,n,i+1,l);
           }
//           debug(lol);
//           debug(l);
//           debug(index);
         ans[index]=lol;
         updateind(1,1,n,i,lol);
         //debug("*************");
    }
    FOR(i,1,n+1){
       printf("%d ",ans[i]);
    }
return 0;
}