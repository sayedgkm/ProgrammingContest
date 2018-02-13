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
inline ll lxt(){ll aaa;scanf("%lld",&aaa);return aaa;}
inline double dxt(){double aaa;scanf("%lf",&aaa);return aaa;}
template <class T> inline T bigmod(T p,T e,T m){T ret = 1;
for(; e > 0; e >>= 1){
    if(e & 1) ret = (ret * p) % m;p = (p * p) % m;
} return (T)ret;}
///******************************************START******************************************
int ar[12]={0};
bool valid(ll sum,ll koita,ll dig) {
//          if(koita%2==1) {
//               if(koita*dig>=sum&&(sum-dig*2)>=0)
//                    return true;
//                   if(dig==0) return true;
//                 // if(dig*2+9>=sum) return true;
//                 return false;
//          }
    if(dig==0) return true;
      if(koita*dig>=sum&&(sum-dig*2)>=0) return true;
      return false;

}
int main(){
    #ifdef sayed
     // freopen("in.txt","r",stdin);
     //freopen("out.txt","w",stdout);
    #endif
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
      int test = nxt();
      while(test--) {
          int n = nxt();
          ll sum =lxt();
          if(n==1)
          {
              if(sum<=9)
              {
                  printf("%lld\n",sum);
              }
              else
              {
                  puts("-1");
              }
              continue;
          }
          bool f;
            int one = 0;
            int j =9;
          for(int i =1;i<=n/2;i++) {

                f= 0;
              j = max(j,0);
            for( ;j>=0;j--) {
                    if(i==1&&j==0) break;
                if(valid(sum,n-(i-1)*2,j)) {
                      sum-=2*j;
                      f = 1;
                      ar[j]+=2;
                      break;
                }
            }
            if(!f) break;

          }
           //  cout<<sum<<endl;
          if(n%2==1&&f){
              if(sum>9){
                  f =0;
              } else{
                  f=1;
                ar[sum]++;
                  sum=0;
              }
          }
          if(sum) f=0;
          vector<int> a,b;
          if(!f) {
              printf("-1\n");
          } else{
                 int x  = -1;
                for(int i = 9;i>=0;i--) {
                     for(int j = 1;j<=ar[i]/2;j++){
                          a.pb(i);
                     }
                     if(ar[i]%2==1){
                          x=i;
                     }
                }
                if(x!=-1) a.pb(x);
               for(int i = 9;i>=0;i--) {
                     for(int j = 1;j<=ar[i]/2;j++){
                          b.pb(i);
                     }
                }

                for(int i = 0;i<a.size();i++) printf("%d",a[i]);
                for(int j =b.size()-1;j>=0;j--) printf("%d",b[j]);
                printf("\n");
          }
          CLR(ar);
       }
return 0;
}