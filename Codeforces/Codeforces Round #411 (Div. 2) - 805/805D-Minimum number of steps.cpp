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
int ar[N];
int dp[100][100100];
ll vis[100][100100];
 bool ok =false;

ll go(int pos,ll c,int x,ll a){

  if(pos<0) {

     if(c>=a) {
      return 1;
    }
    return (ll)-1;
 }
 if(c<=100000&&vis[pos][c]==x) return dp[pos][c];
  ll mx=0;
   if(c<a)
       mx=max(mx,go(pos-1,c*ar[pos],x,a));
       mx=max(mx,go(pos-1,c,x,a)*ar[pos]);
   if(c<=100000){
       vis[pos][c]=x;
      dp[pos][c]=mx;
   }
    return mx;
}
int main(){
     //freopen("out.txt","w",stdout);
     //freopen("in.txt","r",stdin);
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
   string s;
   cin>>s;
   ll ans=0;
   ll cnt=0;
   for(int i=s.length()-1;i>=0;i--){
        if(s[i]=='b') cnt++;
        else {
            ans+=cnt;
            cnt=(cnt*2)%M;
            if(ans>=M) ans-=M;
        }
      //  debug(ans);
   }
   cout<<ans%M<<endl;
return 0;
}