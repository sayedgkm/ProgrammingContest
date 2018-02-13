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
#define        pia                              acos(-1.0)
#define        ff                              first
#define        ss                              second
#define        pb                              push_back
#define        inf                             (int)1e9
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
 int exam[N],day[N];
 int mark[N];
 int temp[N];
bool go(int mid,int m,int sum){
   int cnt=0; CLR(mark);
   CLR(temp);
      int x=-1;
   for(int i=mid;i>=1;i--){
       if(exam[i]==0||mark[exam[i]]) continue;
       mark[exam[i]]=1;
       cnt++;
       if((i-1-(m-cnt))<day[i]) return 0;
       if(x==-1) x=i;
   }
  if(cnt<m) return 0;
   if(x-m>=sum) return true;
  return false;
}
int main(){
     //freopen("out.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
   int n=nxt();
   int m=nxt();
   int sum=0;
   f(i,1,n+1) exam[i]=nxt();
   f(i,1,m+1) day[i]=nxt(),sum+=day[i];
   if(m>n){
     puts("-1");
     return 0;
   }
   int b=1,e=n;
   while(b<=e){

       int mid=(b+e)>>1;
       if(go(mid,m,sum)) e=mid-1;
       else b=mid+1;
    }
    if(b>n) puts("-1");
    else printf("%d\n",b);

return 0;
}