// ==========================================================================
//
//                   Bismillahir-Rahmanir-Rahim
//
// ==========================================================================
#include <bits/stdc++.h>
#define        ll                              long long
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
template < class T> inline T gcd(T a, T b){while(b){a%=b;swap(a,b);}return a;}
template <typename T> string NumberToString ( T Number ) { ostringstream ss; ss << Number; return ss.str(); }
inline int nxt(){int aaa;scanf("%d",&aaa);return aaa;}
inline ll lxt(){ll aaa;scanf("%lld",&aaa);return aaa;}
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
ll s[N], s1[N];
ll sum[N];
ll ar[N];
int main()
{
 // freopen("out.txt","w",stdout);
 int n = nxt();
 f(i, 0, n){
  ar[i] = lxt();
  if (i)
   sum[i] += ar[i] + sum[i - 1];
  else sum[i] = ar[i];
 }
 if (sum[n - 1] % 3 != 0||n<3){
  puts("0");
  return 0;
 }
 ll check = sum[n - 1] / 3;
 f(i, 0, n - 2){
  if (sum[i]== check)
   s[i] = 1;
 }
 f(i, 1, n - 1){
  if (sum[i]== 2 * check)
   s1[i] = 1;
 }
 for (int i = n - 3; i >= 0; i--){
  s1[i] += s1[i+1];
 }
 ll res = 0;
 for (int i = 0; i<n-2; i++){
  if (s[i] == 1){
   res += s1[i + 1];
  }

 }
 cout << res << endl;

 return 0;
}