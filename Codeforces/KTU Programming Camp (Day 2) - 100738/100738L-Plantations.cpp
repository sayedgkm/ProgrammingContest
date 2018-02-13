//====================================
//======================================
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
#define        inf                              1e9
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
ll ar[N][N];
ll sumL[N][N];
ll sumR[N][N];
ll w;
bool possible(int sz,int n) {

   for(int i = 1;i+sz-1<=n;i++) {
     for(int j = 1;j+sz-1<=n;j++) {
        ll S = sumL[i+sz-1][j+sz-1];
        //cout<<S<<endl;

        S-=sumL[i-1][j-1];
        //cout<<S<<endl;
         ll tj = j+sz-1;
        S+=sumR[i+sz-1][j]-sumR[i-1][tj+1];
        //cout<<S<<endl;
        if(sz%2==1) {
            S-=ar[i+(sz)/2][j+sz/2];
        }
       // debug(S);
       if(S<=w) return true;

    }
  }
   return false;
}
void print(int n,ll xr[][N]) {
  for(int i = 1;i<=n;i++){
    for(int j  = 1;j<= n;j++){

        cout<<xr[i][j];
    }
    cout<<endl;
  }
}
int main(){
    #ifdef sayed
     //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
   int test = nxt();
   while(test--) {
    int n = nxt();
     w = lxt();
    for(int i = 1;i<=n;i++) {

        for(int j = 1;j<=n;j++) ar[i][j] = lxt();
    }
    for(int i = 1;i<=n;i++){

        for(int j = 1;j<=n;j++) {

            sumL[i][j] += sumL[i-1][j-1]+ar[i][j];
            sumR[i][j]+=sumR[i-1][j+1]+ar[i][j];
        }
    }
   // print(n,sumL);
    int b = 0;
    int e = n;
   // debug(possible(2,n));
    while(b<=e) {
        int mid = (b+e)/2;
        if(possible(mid,n))  b = mid+1;
        else e = mid-1;
    }
     printf("%d\n",b-1);
     CLR(sumL);
      CLR(sumR);
   }
return 0;
}