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
#define        N                               200010
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
int ar[N];
///given two rectangles A and B,dimensions are A(a,b) and B(p,q)
/// this function returns true if rectangle B(p,q) can be fitted into A(a,b)

bool can_be_fitted(double a,double b,double p,double q) {

     if(a<b) swap(a,b);
     if(p<q) swap (p,q);
     if(p<=a&&q<=b) return true;
     double temp = ((2.0*p*q*a)+ (p*p-q*q)*sqrt(p*p+q*q-a*a))/(p*p+q*q);

     //debug(b)
    if(p>a&&(b+eps>temp||fabs(b-temp)<=eps)) return true;
    return false;
}
int main(){
    #ifdef sayed
     //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
   double a = dxt();
   double b = dxt();
   double c = dxt();
   double d  = dxt();
   if(can_be_fitted(a,b,c,d)){
            printf("Yes\n");
            return 0;
   }
   //debug("d");
   if(can_be_fitted(c,d,a,b)){
            printf("Yes\n");
            return 0;
   }

   printf("No\n");
return 0;
}