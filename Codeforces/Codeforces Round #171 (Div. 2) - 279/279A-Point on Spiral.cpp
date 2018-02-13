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
#define        N                               2000010
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
pair<pii,int>ar[N];
int suma[N],sumb[N];
char s[N];
map<pii,int> mp;
int main(){
    #ifdef sayed
     //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
    int x=0;
    int y=0;
    int turn=-1;
    int c=1;
    int check=0;
   while(1) {
     if(check%2==0) {

        int nx = x+c;
        int ny = y;
         turn++;
        for(int i = x+1;i<=nx;i++) {
              mp[make_pair(i,ny)]=turn;
        }
        x=nx;
        y=ny;
        turn++;
        nx=x;
        ny =y+c;
        for(int i = y+1;i<=ny;i++) {
            mp[make_pair(nx,i)]=turn;

        }

        c++;
        x=nx;
        y =ny;
     } else {

          int nx,ny;
          nx=x-c;
          ny = y;
          turn++;
          for(int i = x-1;i>=nx;i--) {
              mp[make_pair(i,ny)]=turn;
          }
         x=nx;
         y=ny;

         nx=x;
         turn++;
         ny = y-c;
         for(int i = y-1;i>=ny;i--){
            mp[make_pair(nx,i)]=turn;

         }
        c++;
        x=nx;
        y=ny;


     }
      check++;
      if(abs(x)>=105&&abs(y)>=105) break;
   }
    int a=nxt();
    int b=nxt();
    cout<<mp[make_pair(a,b)]<<endl;

return 0;
}