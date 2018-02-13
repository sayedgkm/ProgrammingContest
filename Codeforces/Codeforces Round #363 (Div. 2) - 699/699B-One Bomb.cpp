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

char s[1005][1005];
ll sum[1005][1005];
ll sum1[1005][1005];
bool visited[1005][1005];
int main(){
     // freopen("out.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
   // cin.tie(0);
   int n=nxt();
   int m=nxt();
   f(i,0,n) scanf("%s",s[i]);
   for(int i=0;i<n;i++){
        int c=0;
      for(int j=0;j<m;j++){
        if(s[i][j]=='*') c++;
          visited[i][j]=true;
      }
    for(int j=0;j<m;j++) sum[i][j]=c;

   }
   for(int i=0;i<m;i++){
        int c=0;
      for(int j=0;j<n;j++){
        if(s[j][i]=='*'){ c++;

        }

      }

    for(int j=0;j<n;j++){
        sum1[j][i]=c;
      }

   }
  // cout<<sum[2][0]<<" "<<sum1[2][0]<<endl;
   int total=0;
   f(i,0,n) f(j,0,m) if(s[i][j]=='*') total++;
   f(i,0,n) f(j,0,m) {

      if(sum[i][j]+sum1[i][j]+(s[i][j]=='*'?-1:0)==total){
            puts("YES");
          cout<<i+1<<" "<<j+1<<endl;
         return 0;
      }
   }
  puts("NO");
return 0;
}