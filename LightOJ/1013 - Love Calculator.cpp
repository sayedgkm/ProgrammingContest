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
template < class T> inline T biton(T n,T pos){return n |((T)1<<pos);}
template < class T> inline T bitoff(T n,T pos){return n & ~((T)1<<pos);}
template < class T> inline T on(T n,T pos){return (bool)(n & ((T)1<<pos));}
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
ll dp[50][50]; string x, y;
ll dp1[50][50][50];
int lcs(int a, int b){

    for (int i = 1; i <= a; i++) for (int j = 1; j <= b; j++){
        if (x[i - 1] == y[j - 1]){
            dp[i][j] = 1 + dp[i - 1][j - 1];
        }
        else {
            if (dp[i - 1][j] > dp[i][j - 1]){
                dp[i][j] = dp[i - 1][j];
            }
            else {
                dp[i][j] = dp[i][j-1];
            }

        }
    }
    return dp[a][b];
}
ll go(int i,int j,int l){
   if(i==x.length()&&j==y.length()) {
        return l==0;
   }
   if(dp1[i][j][l]!=-1) return dp1[i][j][l];
   ll p=0,q=0;
   if(x[i]==y[j]){
      p=go(i+1,j+1,l-1);
   }
     else {
        if(i<x.length())
             p+=go(i+1,j,l-1);
         if(j<y.length())
           p+=go(i,j+1,l-1);
      }
    return dp1[i][j][l]=p;

}
int main(){
     // freopen("out.txt","w",stdout);
     int test=nxt();int cs=1;
     while(test--){
            CLR(dp);
        cin>>x>>y;
        int lc=x.length()+y.length()-lcs(x.length(),y.length());
          SET(dp1);
       printf("Case %d: %d %lld\n",cs++,lc,go(0,0,lc));
     }

return 0;
}


