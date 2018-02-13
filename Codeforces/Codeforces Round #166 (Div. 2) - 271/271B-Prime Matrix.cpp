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
#define        N                               100010
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
 int prime[1000000 + 100];
 int v[N];
void seive(int n)
{   int sq;
 sq = sqrt(n);
 for(int i=3;i<=sq;i+=2)
  for (int j = i*i; j <= n; j += i * 2)
  prime[j] = 1;
  int last;
 for(int i=100003;i>=1;i--){
        if(!prime[i]&&i%2) last=i;
        v[i]=last-i;
 }
 v[2]=0;
 v[1]=1;
}
int ar[500][500];
int main(){
     //freopen("out.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
   seive(100100);
   //cout<<v[7]<<" "<<v[2]<<endl;
   int n=nxt();int m=nxt(); int res=inf;
   for(int i=0;i<n;i++){
        int sum=0;
     for(int j=0;j<m;j++){
        int a=nxt();
        sum+=v[a];
        ar[i][j]=v[a];
     }
     res=min(sum,res);
  }
  for(int i=0;i<m;i++){
        int sum=0;
     for(int j=0;j<n;j++){
        sum+=ar[j][i];
     }
     res=min(sum,res);
}
   printf("%d\n",res);

return 0;
}