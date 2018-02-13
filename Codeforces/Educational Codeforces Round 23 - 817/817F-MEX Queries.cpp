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
#define        N                               300010
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
map<ll,int> mp;
map<ll,int> :: iterator it;
map<ll,ll> ans;
vector<pair<int,pll > > v;

struct info{
  ll sum;
  ll lazy;

}tree[N*4];
void propagate(int node,int low,int hi){
    int left=2*node;
    int right=left+1;
    int mid =(low+hi)/2;
    int t = tree[node].lazy;
     tree[node].lazy = 0;

     if(t==1) {
        tree[node].sum = (hi-low+1);
        //debug(tree[node].sum);
        if(low!=hi){
            tree[left].lazy = 1;
            tree[right].lazy = 1;

        }
     } else if(t == 2){
          tree[node].sum = 0;
        if(low!=hi){
            tree[left].lazy = 2;
            tree[right].lazy = 2;

        }
     } else {
          tree[node].sum = (hi-low+1)-tree[node].sum;

          if(low!=hi){
          if(tree[left].lazy==0){
             tree[left].lazy = 3;

           } else if (tree[left].lazy==1){
             tree[left].lazy = 2;

           }  else if(tree[left].lazy==3){
              tree[left].lazy = 0 ;
            } else {
             tree[left].lazy = 1;

           }

           if(tree[right].lazy==0){
             tree[right].lazy = 3;

           } else if (tree[right].lazy==1){
             tree[right].lazy = 2;

           } else if(tree[right].lazy==3){
              tree[right].lazy = 0 ;
            } else {
             tree[right].lazy = 1;

           }
        }
     }
}
void update(int node,int low,int hi,int i,int j,int value){
    int left=2*node;
    int right=left+1;
      if(tree[node].lazy)propagate(node,low,hi);
      if(hi<i||j<low) return;
      if(low>=i&&hi<=j){
            tree[node].lazy = value;
             propagate(node,low,hi);

        return ;
      }
   int mid=(low+hi)/2;
      update(left,low,mid,i,j,value);
      update(right,mid+1,hi,i,j,value);
   tree[node].sum=tree[left].sum+tree[right].sum;
}
ll query(int node,int low,int hi){
     int left=2*node;
     int right=left+1;
     int mid=(low+hi)/2;
     if(tree[node].lazy)propagate(node,low,hi);
     if(tree[left].lazy) propagate(left,low,mid);
     if(tree[right].lazy) propagate(right,mid+1,hi);
     if(hi==low) return low;
     int sum = tree[left].sum;
     if(sum==mid-low+1)
     return  query(right,mid+1,hi);
     else return query(left,low,mid);

}
//ll query(int node,int low,int hi,int i,int j){
//       int left=2*node;
//      int right=left+1;
//       if(tree[node].lazy)propagate(node,low,hi);
//    if(hi<i||j<low) return 0;
//       if(low>=i&&hi<=j)
//          return tree[node].sum;
//   int mid=(low+hi)/2;
//  ll x= query(left,low,mid,i,j);
//  ll y= query(right,mid+1,hi,i,j);
//  return x+y;
//
//}
ll query(int node,int low,int hi,int i){
      int left=2*node;
      int right=left+1;
      if(tree[node].lazy)propagate(node,low,hi);

      if(low>=i&&hi<=i)
          return tree[node].sum;
   int mid=(low+hi)/2;
  if(i<=mid) return query(left,low,mid,i);
   return  query(right,mid+1,hi,i);


}

int main(){
    #ifdef sayed
     //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
    int n = nxt();
    ll mx = 0;
    FOR(i,0,n) {
        int t = nxt();
     ll a = lxt();
     ll b = lxt();
     v.pb(make_pair(t,make_pair(a,b)));
      mp[a] = mp[b] = 0;
      mp[b+1] =0;
      mx = max({mx,a,b});
    }
     mx ++;
     mp[1] =0;
     mp[mx] =0;
     int rnk = 1;
      for(it = mp.begin();it!=mp.end();it++) {
          it->ss = rnk;
          ans [rnk] = it->ff;
          rnk++;
      }
      for(int i = 0;i<n;i++) {
           update(1,1,rnk,mp[v[i].ss.ff],mp[v[i].ss.ss],v[i].ff);
          int b = query(1,1,rnk);
           printf("%lld\n",ans[b]);
      }

return 0;
}