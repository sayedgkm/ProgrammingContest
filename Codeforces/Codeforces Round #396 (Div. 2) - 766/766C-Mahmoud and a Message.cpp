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
#define        N                               100010
#define        M                               1000000007
#define        pi                              acos(-1.0)
#define        ff                              first
#define        ss                              second
#define        pb                              push_back
#define        inf                             (int)1e9
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
inline ll lxt(){ll aaa;scanf("%I64d",&aaa);return aaa;}
inline double dxt(){double aaa;scanf("%lf",&aaa);return aaa;}
template <class T> inline T bigmod(T p,T e,T m){T ret = 1;
for(; e > 0; e >>= 1){
    if(e & 1) ret = (ret * p) % m;p = (p * p) % m;
} return (T)ret;}
///******************************************START******************************************
int n; int ar[50];string s;
int dp[1005];
int mx=0;
ll go(int pos){
   if(pos>=n) {
      return 1;
   }
    if(dp[pos]!=-1) return dp[pos];
   int br[27]={0}; ll res=0,temp;
  for(int i=pos;i<n;i++){
       br[s[i]-'a']++; bool f=0;
         FOR(j,0,26){
            if(br[j]&&(i-pos+1)>ar[j]) f=1;
         }
      if(!f){ res=(res+go(i+1))%M;
         mx=max(mx,i-pos+1);

      } else break;
    }
    return  dp[pos]=res;
}
ll xo(int pos){
   if(pos>=n) {
      return 0;
   }
    if(dp[pos]!=-1) return dp[pos];
   int br[27]={0}; ll res=inf,temp;
  for(int i=pos;i<n;i++){
       br[s[i]-'a']++; bool f=0;
         FOR(j,0,26){
            if(br[j]&&(i-pos+1)>ar[j]) f=1;
         }
      if(!f){ res=xo(i+1)+1;
         mx=max(mx,i-pos+1);

      } else break;
    }
    return  dp[pos]=res;
}
int main(){
     //freopen("out.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
  SET(dp);
     n=nxt();
    cin>>s;
    FOR(i,0,26) ar[i]=nxt();
     ll ans=go(0);
     SET(dp);
     ll ans1=xo(0);
      cout<<ans<<endl;
      cout<<mx<<endl;
      cout<<ans1<<endl;

return 0;
}