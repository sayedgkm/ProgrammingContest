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
#define        All(x)                          x.begin(),x.end()
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
ll ar[105][105];
int main(){
     //freopen("out.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
   ll n,m,k,x,y; ll mn=(ll)inf*inf,mx=0,sg=0;
   n=lxt(),m=lxt(),k=lxt(),x=lxt(),y=lxt();
   if(n==1){
      ll temp=k/m;
      ll rem=k%m;
      mn=mx=sg=temp;
      if(rem) mx++;
      for(int i=1;i<=rem;i++){
          if(i==y) sg++;
      }
      cout<<mx<<" "<<mn<<" "<<sg<<endl;
      return 0;
   } else {

         for(int i=1;i<=n&&k;i++){
            for(int j=1;j<=m&&k;j++){
                ar[i][j]=1;
                k--;
            }
         }
         ll temp=k/((n-1)*m);
         ll rem=k%((n-1)*m);
         if(temp%2==0){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    if(i==1||i==n) ar[i][j]+=temp/2LL;
                    else ar[i][j]+=temp;
                }
            }
            for(int i=n-1;i>=1&&rem;i--){
                for(int j=1;j<=m&&rem;j++){
                    ar[i][j]++;
                    rem--;
                }
            }
         } else {
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    if(i==1) ar[i][j]+=(temp+1)/2LL;
                    else if(i==n) ar[i][j]+=(temp+1)/2LL-1;
                    else ar[i][j]+=temp;
                }
            }
            for(int i=2;i<=n&&rem;i++){
                for(int j=1;j<=m&&rem;j++){
                    ar[i][j]++;
                    rem--;
                }
            }
         }
       }
       FOR(i,1,n+1) FOR(j,1,m+1) {
         mx=max(ar[i][j],mx);
         mn=min(ar[i][j],mn);
         if(i==x&&j==y) sg=ar[i][j];
       }
   cout<<mx<<" "<<mn<<" "<<sg<<endl;



return 0;
}