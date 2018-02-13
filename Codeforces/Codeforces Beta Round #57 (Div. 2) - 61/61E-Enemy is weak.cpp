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
using namespace std;
int dx[]={0,0,1,-1,-1,-1,1,1};
int dy[]={1,-1,0,0,-1,1,1,-1};
template < class T> inline T biton(T n,T pos){return n |((T)1<<pos);}
template < class T> inline T bitoff(T n,T pos){return n & ~((T)1<<pos);}
template < class T> inline T on(T n,T pos){return (bool)(n & ((T)1<<pos));}
template < class T> inline T gcd(T a, T b){while(b){a%=b;swap(a,b);}return a;}
template <typename T> string NumberToString ( T Number ) { ostringstream ss; ss << Number; return ss.str(); }
inline int nxt(){int aaa;scanf("%d",&aaa);return aaa;}
inline ll lxt(){ll aaa;scanf("%I64d",&aaa);return aaa;}
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
int ar[N];
int br[N];
int BIT[2][N];
void update(int i,int n,int type,int val){

   while(i<=n){
      BIT[type][i]+=val;
      i+=i&(-i);
   }

}
ll query(int i,int type){
    ll sum=0;
   while(i>0){
      sum+=BIT[type][i];
      i-=i&(-i);
   }
  return sum;
}
int main(){
     //freopen("out.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
   int n=nxt(); int rnk=1;
   f(i,1,n+1){
       ar[i]=br[i]=nxt();
   }
   sort(br+1,br+n+1);
   f(i,1,n+1) ar[i]=lower_bound(br+1,br+1+n,ar[i])-br;

   for(int i=1;i<=n;i++) update(ar[i],n,1,1);
    ll ans=0;
   for(int i=1;i<=n;i++){
       ll left=query(ar[i]-1,0);
       left=i-1-left;
       ll right=query(ar[i]-1,1);
       update(ar[i],n,0,1);
       update(ar[i],n,1,-1);
      ans+=left*right;
   }
      printf("%I64d\n",ans);

return 0;
}