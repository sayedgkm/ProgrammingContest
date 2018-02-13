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
#define        N                               500010
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
 string s;
 int dp[N][30];
 int ar[N][30];
 int k,n;
 int ok(char a) {
    return a-'A'+1;
 }
 int go(int pos,int prev){
     if(pos>=n) return 0;

   if(dp[pos][prev]!=-1) return dp[pos][prev];
   int x,y=inf;
   int temp=ok(s[pos]);
   for(int i=max(temp-2,1);i<=min(26,temp+2);i++){
         if(i>k) continue;
        if(prev==i) continue;
        if(i==temp) x=go(pos+1,i);
        else x=go(pos+1,i)+1;

        if(x<y){
           ar[pos][prev]=i;
           y=x;
        } //else ar[pos][prev]=0;
    }
    return dp[pos][prev]=y;
 }
 void print(int pos,int prev){

    while(pos<n){

        printf("%c",ar[pos][prev]+64);
        prev=ar[pos][prev];
        pos++;
    }
 }
int main(){
     //freopen("out.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
   SET(dp);
    n=nxt();
     k=nxt();
   cin>>s;
  cout<<go(0,0)<<endl;
  print(0,0);
  printf("\n");

return 0;
}