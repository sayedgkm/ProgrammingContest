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
#define        N                               1010
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
int ar[N][N];
ll two[N][N],five[N][N];
void cnt(int i,int j) {
    ll n=ar[i][j];
//    if(n==0) {
//        two[i][j]=(ll)-inf;
//       // five[i][j]=(ll)-inf;
//        return ;
//    }
    int c=0;
    while(n%2==0&&n) c++,n/=2;
     two[i][j]=c;
      c=0;n=ar[i][j];
    while(n%5==0&&n) c++,n/=5;
     five[i][j]=c;
}
ll dp[N][N],dp1[N][N];
int n;
ll go(int i,int j) {
     if(i>=n-1&&j>=n-1) {
            return two[i][j];
     }
      ll &res=dp[i][j];
      if(res!=-1) return res;
      res=inf;
     if(i<n-1) res=min(res,go(i+1,j)+two[i][j]);
     if(j<n-1) res=min(res,go(i,j+1)+two[i][j]);
     return res;
}
void print(int i,int j){
  if(i==n-1&&j==n-1) return ;
  if(i<n-1&&j<n-1) {
     if(dp[i+1][j]<dp[i][j+1]){
            printf("D");
         print(i+1,j);
     } else {
        printf("R");
         print(i,j+1);
     }

  } else if(i<n-1) {
       printf("D");
       print(i+1,j);
  }  else {
     printf("R");
     print(i,j+1);
  }
}
void print1(int i,int j){
  if(i==n-1&&j==n-1) return ;
  if(i<n-1&&j<n-1) {
     if(dp1[i+1][j]<dp1[i][j+1]){
            printf("D");
         print1(i+1,j);
     } else {
        printf("R");
         print1(i,j+1);
     }

  } else if(i<n-1) {
       printf("D");
       print1(i+1,j);
  }  else {
     printf("R");
     print1(i,j+1);
  }
}
ll go1(int i,int j) {
     if(i>=n-1&&j>=n-1) {
            return five[i][j];
     }
      ll &res=dp1[i][j];
      if(res!=-1) return res;
      res=inf;
     if(i<n-1) res=min(res,go1(i+1,j)+five[i][j]);
     if(j<n-1) res=min(res,go1(i,j+1)+five[i][j]);
     return res;
}
int main(){
     //freopen("out.txt","w",stdout);
     //freopen("in.txt","r",stdin);
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
     bool f=0;
     int x,y;
      n=nxt();
      FOR(i,0,n) {
       FOR(j,0,n) {
          ar[i][j]=nxt();
          cnt(i,j);
          if(ar[i][j]==0) f=1,x=i,y=j;
        }
      }
      //debug(two[1][2]);
      SET(dp);
      SET(dp1);
      ll ans=go(0,0);
      ll ans1=go1(0,0);
      ans=min(ans,ans1);
      if(f&&ans>1){
            puts("1");
            FOR(i,0,x) {
              printf("D");
            }
            FOR(i,0,n-1)  printf("R");
           FOR(i,x,n-1) printf("D");
           printf("\n");
      }
      else {
       printf("%lld\n",max(0LL,ans));
       if(ans1>ans) print(0,0);
       else print1(0,0);
       printf("\n");
    }
return 0;
}