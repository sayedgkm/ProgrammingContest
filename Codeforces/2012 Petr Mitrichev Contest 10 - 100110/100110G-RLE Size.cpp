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
int n;
string s;
int dp[105][105][5];
ll go(int pos,int koita,int last){
     if(pos>n) return koita;
      if(dp[pos][koita][last]!=-1) return dp[pos][koita][last];
     ll res=0;
     if(last==0){
        if(s[pos]=='+') res=max(res,go(pos+1,koita,0));
        else if(s[pos]=='-') res=max(res,go(pos+1,koita+1,1));
        else {
            res=max(res,go(pos+1,koita,0));
            res=max(res,go(pos+1,koita+1,1));
        }
     } else {

       if(s[pos]=='+') res=max(res,go(pos+1,koita+1,0));
        else if(s[pos]=='-') res=max(res,go(pos+1,koita,1));
        else {
            res=max(res,go(pos+1,koita+1,0));
            res=max(res,go(pos+1,koita,1));
        }

     }

      return dp[pos][koita][last]=res;

}
ll go1(int pos,int koita,int last){
     if(pos>n){

       return koita;
     }
      if(dp[pos][koita][last]!=-1) return dp[pos][koita][last];
     ll res=inf;
     if(last==3){
         if(s[pos]=='+') res=min(res,go1(pos+1,koita+1,0));
        else if(s[pos]=='-') res=min(res,go1(pos+1,koita+1,1));
        else {
            res=min(res,go1(pos+1,koita+1,0));
            res=min(res,go1(pos+1,koita+1,1));
        }

     }
     else if(last==0){
        if(s[pos]=='+') res=min(res,go1(pos+1,koita,0));
        else if(s[pos]=='-') res=min(res,go1(pos+1,koita+1,1));
        else {
            res=min(res,go1(pos+1,koita,0));
            res=min(res,go1(pos+1,koita+1,1));
        }
     } else {

       if(s[pos]=='+') res=min(res,go1(pos+1,koita+1,0));
        else if(s[pos]=='-') res=min(res,go1(pos+1,koita,1));
        else {
            res=min(res,go1(pos+1,koita+1,0));
            res=min(res,go1(pos+1,koita,1));
        }

     }

      return dp[pos][koita][last]=res;

}
int main(){
     freopen("rle-size.out","w",stdout);
     freopen("rle-size.in","r",stdin);
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
   SET(dp);
   n=nxt();
   cin>>s;
   s='$'+s;

   int ans;
//   if(s[1]=='+') ans=go1(1,0,1);
//   else if(s[1]=='-') ans=go1(1,0,0);
    ans=go1(1,0,3);
     cout<<ans<<" ";
          SET(dp);
      cout<<max(go(1,0,1),go(1,0,0))<<endl;
return 0;
}