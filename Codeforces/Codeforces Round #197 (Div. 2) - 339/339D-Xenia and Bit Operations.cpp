//==========================================================================
//
//                   Bismillahir-Rahmanir-Rahim
//
// ==========================================================================
#include <bits/stdc++.h>
#define        ll                              long long int
#define        f(x,y,z)                        for(int x=y;x<z;x++)
#define        pii                             pair<int,int>
#define        pll                             pair<ll,ll>
#define        CLR(a)                          memset(a,0,sizeof(a))
#define        SET(a)                          memset(a,-1,sizeof(a))
#define        N                               1000010
#define        M                               1000000007
#define        pi                              acos(-1.0)
#define        ff                              first
#define        ss                              second
#define        pb                              push_back
#define        inf                             (int)1e9
#define        eps                              1e-9
using namespace std;
int dx[]={0,0,1,-1,-1,-1,1,1};
int dy[]={1,-1,0,0,-1,1,1,-1};
template < class T> inline T biton(T n,T pos){return n |((T)1<<pos);}
template < class T> inline T bitoff(T n,T pos){return n & ~((T)1<<pos);}
template < class T> inline T ison(T n,T pos){return (bool)(n & ((T)1<<pos));}
template < class T> inline T gcd(T a, T b){while(b){a%=b;swap(a,b);}return a;}
template <typename T> string NumberToString ( T Number ) { ostringstream ss; ss << Number; return ss.str(); }
inline int nxt(){int aaa;scanf("%d",&aaa);return aaa;}
inline ll lxt(){ll aaa;scanf("%I64d",&aaa);return aaa;}
inline double dxt(){double aaa;scanf("%lf",&aaa);return aaa;}
template <class T> inline T bigmod(T p,T e,T m){T ret = 1;
for(; e > 0; e >>= 1){
    if(e & 1) ret = (ret * p) % m;p = (p * p) % m;
} return (T)ret;}
#define sayed
#ifdef sayed
     #define debug(args...) {cerr<<"Debug: "; dbg,args; cerr<<endl;}
#else
    #define debug(args...)  // Just strip off all debug tokens
#endif
struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;
///******************************************START******************************************
ll ar[N];
ll tree[4*N]; int check;
void segment(int node,int b,int e,int h){

      if(b==e){
         tree[node]=ar[b];
         return;
      }
    int mid=(b+e)>>1;
    int l=2*node;
    int r=l+1;
    segment(l,b,mid,h+1);
    segment(r,mid+1,e,h+1);
    ll Xor=tree[l]^tree[r];
    ll Or=tree[l]|tree[r];

    if(check%2==0){
        if(h%2==0) tree[node]=Or;
        else tree[node]=Xor;
    } else {
      if(h%2==1) tree[node]=Or;
        else tree[node]=Xor;
    }
}
void update(int node,int b,int e,int h,int i,int val){

      if(b==e){
           // cout<<b<<endl;
         tree[node]=val;
         return;
      }
    int mid=(b+e)>>1;
    int l=2*node;
    int r=l+1;
    if(i<=mid)
    update(l,b,mid,h+1,i,val);
    else update(r,mid+1,e,h+1,i,val);
    ll Xor=tree[l]^tree[r];
    ll Or=tree[l]|tree[r];

    if(check%2==0){
        if(h%2==0) tree[node]=Or;
        else tree[node]=Xor;
    } else {
      if(h%2==1) tree[node]=Or;
        else tree[node]=Xor;
    }

}
int main(){
     //freopen("out.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
     int n=nxt(),m=nxt();
     check=n;
      n=1<<n;
    for(int i=1;i<=n;i++) ar[i]=lxt();
    segment(1,1,n,1);
    while(m--){
        int x=nxt(),v=nxt();
        update(1,1,n,1,x,v);
        printf("%I64d\n",tree[1]);
    }
return 0;
}