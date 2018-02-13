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
#define        inf                             (int)1e9
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
map<pii,priority_queue<pii> > mp;
int ar[N],br[N],cr[N];
int main(){
     //freopen("out.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
   int n=nxt();
   double r=0;
   double mx=0;
   int index;
   f(i,0,n){
    ar[i]=nxt();
    br[i]=nxt();
    cr[i]=nxt();
     double temp=(double)min(ar[i],min(br[i],cr[i]));
     if((temp/2.0)>mx){
        mx=temp/2;
        index=i;
     }
   }
   int ans1=-1,ans2=-1;
   int temp[5];
   for(int i=0;i<n;i++){

      temp[0]=ar[i],temp[1]=br[i],temp[2]=cr[i];

          for(int x=0;x<3;x++){
            for(int y=0;y<3;y++){
            for(int z=0;z<3;z++){
                if(x!=y&&x!=z&&y!=z){
                    if(mp[pii(temp[x],temp[y])].size()){
                        pii ok=mp[pii(temp[x],temp[y])].top();
                         double xxx=min(temp[x],min(temp[y],temp[z]+ok.ff));
                        if((double)(xxx)/2.0>mx){
                            mx=(double)xxx/2.0;
                            ans1=ok.ss;
                            ans2=i;
                        }
                    }
                }

              }

            }

          }

          for(int x=0;x<3;x++){
            for(int y=0;y<3;y++){
            for(int z=0;z<3;z++){
                if(x!=y&&x!=z&&y!=z){
                      mp[pii(temp[x],temp[y])].push(pii(temp[z],i));
                    }
                }

              }

            }

          }
          if(ans1==-1) {
            puts("1");
            printf("%d\n",index+1);
          } else {
             puts("2");
             printf("%d %d\n",ans1+1,ans2+1);
          }



return 0;
}