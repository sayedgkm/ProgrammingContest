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
#define        N                               2000010
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
pii ar[N] ;
map<int,int> mp;
map<int,int> :: iterator it;


struct info{
  ll sum;
  ll lazy;

}tree[N*4];
void segment_tree(int node,int low,int high){
     if(low==high){
        tree[node].sum=0; return;
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
     tree[node].sum+=(hi-low+1)*tree[node].lazy;
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
           tree[node].sum+=(hi-low+1)*value;
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
   tree[node].sum=tree[left].sum+tree[right].sum;
}
void update(int node,int low,int hi,int i,int value){
    int left=2*node;
    int right=left+1;
      if(tree[node].lazy)propagate(node,low,hi);

      if(low>=i&&hi<=i){
           tree[node].sum=value;
        return ;
      }
   int mid=(low+hi)/2;
   if(i<=mid)
      update(left,low,mid,i,value);
    else
      update(right,mid+1,hi,i,value);
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
ll query(int node,int low,int hi,int i){
       int left=2*node;
      int right=left+1;
       if(tree[node].lazy)propagate(node,low,hi);

       if(low>=i&&hi<=i)
          return tree[node].sum;
   int mid=(low+hi)/2;
   if(i<=mid)
 return query(left,low,mid,i);
  else
return   query(right,mid+1,hi,i);


}

int main(){
    #ifdef sayed
     //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
    int rnk = 1;
    int n = nxt() ;
    FOR(i,0,n) {
        ar[i].ff = nxt();
        ar[i].ss = nxt() ;
        mp[ar[i].ff]= 0;
        mp[ar[i].ss] =0;
        mp[ar[i].ss+1] =0;
        mp[ar[i].ss-1] =0;
        mp[ar[i].ff+1] =0;
        mp[ar[i].ff-1] =0;
    }
    for(it =  mp.begin();it!=mp.end();it++) {
        it->ss = rnk++;

    }

     int mn = inf;
     int mx  = 0 ;
    for(int i = 0;i<n;i++) {
         int l = mp[ar[i].ff];
         int r = mp[ar[i].ss];
         update(1,1,rnk,l,r,1);
    }
  FOR(i,1,rnk+1) {
     int x = query(1,1,rnk,i) ;
     if(x>=2) update(1,1,rnk,i,1);
     else update(1,1,rnk,i,0) ;
  }
      for(int i = 0;i<n;i++) {
         int l = mp[ar[i].ff];
         int r = mp[ar[i].ss];
      //   update(1,1,rnk,l,r,-1);
         int x = query(1,1,rnk,l,r);
         if(x==(r-l+1)){
            cout<<i+1<<endl;
            return 0 ;
         }
        //update(1,1,rnk,l,r,1);
    }
    cout<<-1<<endl;
return 0;
}