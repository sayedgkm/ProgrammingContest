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
int dp[305][305][305];
bool go(int x,int y,int z) {

  return (x^y^z)!=0;
}
int dp1[305][305];
bool go(int x,int y) {

     int c=0;
     if(!x) c++;
     if(!y) c++;
     if(c>=2) return false;
     if(dp1[x][y]!=-1) return dp1[x][y];
    bool flag = true;
    FOR(i,1,x+1) {
      flag&=go(x-i,y);
    }
    FOR(i,1,y+1) {
      flag&=go(x,y-i);
    }
   int mn =min(x,y);
   FOR(i,1,mn+1) {
      flag&=go(x-i,y-i);
   }
  return dp1[x][y]=flag^1;
}
int main(){
    #ifdef sayed
     //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);

   SET(dp1);
   int n=nxt();
   FOR(i,0,n) {
     ar[i]=nxt();
   }
   if(n==1){
     if(ar[0]==0) printf("BitAryo\n");
     else
    printf("BitLGM\n");
    return 0;
   }
   if(n==2){
      if(go(ar[0],ar[1])) {
         printf("BitLGM\n");
      } else {

       printf("BitAryo\n");
      }

   } else {
   if(go(ar[0],ar[1],ar[2])) {
         printf("BitLGM\n");
      } else {

       printf("BitAryo\n");
      }
   }
return 0;
}