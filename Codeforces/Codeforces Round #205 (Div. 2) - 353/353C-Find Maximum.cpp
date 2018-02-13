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
#define        inf                             (ll)1e15
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
string s;
int main(){
     //freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);
   cin.tie(0);
   int n;
   cin>>n;
   f(i,0,n) cin>>ar[i];
   cin>>s;
     int in=n-1;
   for(int i=s.length()-1;i>=0;i--){
      if(s[i]=='1'){
         in=i;
         break;
      }
    }
    for(int i=in;i>=0;i--){
         if(s[i]=='0') br[i]=ar[i];
        br[i]=br[i]+br[i+1];
    }
    int st=0,sum=0;
     f(i,0,in+1) sum+=ar[i];
     f(i,0,in+1) st+=ar[i]*(s[i]-'0');

     //cout<<sum<<" "<<st<<endl;
     int mx=st;
     int x;
     for(int i=in;i>=0;i--){

        if(s[i]=='1'){
           x=sum;
           x-=ar[i];
           x-=br[i];
         mx=max(mx,x);
        }

     }
     cout<<mx<<endl;

  //cout<<fixed<<setprecision(15)<<a<<endl;
  return 0;
}