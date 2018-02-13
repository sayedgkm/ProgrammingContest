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
#define        N                               200010
#define        M                               1000000007
#define        pi                              acos(-1.0)
#define        ff                              first
#define        ss                              second
#define        pb                              push_back
#define        inf                             9e9+100
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
inline ll lxt(){ll aaa;scanf("%lld",&aaa);return aaa;}
inline double dxt(){double aaa;scanf("%lf",&aaa);return aaa;}
template <class T> inline T bigmod(T p,T e,T m){T ret = 1;
for(; e > 0; e >>= 1){
    if(e & 1) ret = (ret * p) % m;p = (p * p) % m;
} return (T)ret;}
///******************************************START******************************************
int ar[105][105],br[105][105],com[105][105];
vector<int>row,clm;
int main(){
     //freopen("out.txt","w",stdout);
     //freopen("in.txt","r",stdin);
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
   int n=nxt();
   int m=nxt();
   FOR(i,0,n) FOR(j,0,m) ar[i][j]=nxt(),br[i][j]=ar[i][j];
   FOR(i,0,n) sort(br[i],br[i]+m);
   bool f=0;
   if(n<m) {

   FOR(i,0,n) {
       int x=br[i][0];
       while(x) row.pb(i),x--;
       FOR(j,0,m) com[i][j]+=br[i][0];
   }

   FOR(i,0,m){
      int x=max(0,ar[0][i]-com[0][i]);
      int y=x;
      while(x) clm.pb(i),x--;
      FOR(j,0,n) {
         com[j][i]+=y;
         if(com[j][i]!=ar[j][i]) f=1;
      }
   }
 } else {

    FOR(i,0,m) {
       int mn=505;
       FOR(j,0,n) {
          mn=min(mn,ar[j][i]);
       }
       int x=mn;
       while(x) clm.pb(i),x--;
       FOR(j,0,n) com[j][i]+=mn;
    }

    FOR(i,0,n){
      int x=max(0,ar[i][0]-com[i][0]);
      int y=x;
    //  debug(y);
      while(x) row.pb(i),x--;
      FOR(j,0,m) {
         com[i][j]+=y;
         if(com[i][j]!=ar[i][j]) f=1;
      }
   }

 }
   if(f) puts("-1");
   else{
      printf("%d\n",(int)row.size()+clm.size());
      FOR(i,0,row.size()) printf("row %d\n",row[i]+1);
      FOR(i,0,clm.size()) printf("col %d\n",clm[i]+1);

   }


return 0;
}