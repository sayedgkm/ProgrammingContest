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
#define        N                               5005
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

bitset<N> dp[14][N];
bitset<N>isp[N];
int ans[N];
int main(){
    #ifdef sayed
     //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
   string s;
   cin>>s;
   int n= s.length();
   FOR(i,0,n) {
      isp[i][i]=true;
      isp[i+1][i]=true;
   }
   for(int i =n-1;i>=0;i--) {
     FOR(j,i+1,n) {
       if(isp[i+1][j-1]&&s[i]==s[j]){
         isp[i][j] =true;
       }
     }

   }
   FOR(k,1,14) {

     FOR(i,0,n) {
       FOR(j,i+k-1,n) {
          if(isp[i][j]){
             int t=j-i+1;
               t/=2;
              if(k==1) {
                 dp[k][i][j]=1;
                 ans[k]++;
              } else {
                 if(dp[k-1][i][i+t-1]&&dp[k-1][j-t+1][j]) {
                     dp[k][i][j]=1;
                     ans[k]++;
                 }
              }
          }
       }
     }


   }
   FOR(i,1,s.length()+1) printf("%d ",ans[i]);
return 0;
}