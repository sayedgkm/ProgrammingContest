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

int tree[105][105];
int limit=105;
int n;
void update(int x,int y, int value) {

    for(int i=x; i<=limit; i+=i&(-i))
        for(int j=y; j<=limit; j+=j&(-j))
            tree[i][j]+=value;
}
int query(int x,int y) {
    int sum=0;
    for(int i=x; i>0; i-=i&(-i))
        for(int j=y; j>0; j-=j&(-j))
            sum+=tree[i][j];
    return sum;
}



struct point {
   int x,y;
   int s;
}ar[N];
struct info{
   int t,x1,y1,x2,y2;
    int id;
}br[N];
bool cmp(info a,info b){
  return a.t<b.t;
}
int mod;
void go(){

 FOR(i,0,n){
      update(ar[i].x,ar[i].y,-ar[i].s);
      ar[i].s++;
      ar[i].s%=mod;
      update(ar[i].x,ar[i].y,ar[i].s);
 }

}
int ans[N];
int main(){
    #ifdef sayed
     //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
         n=nxt();
       int q=nxt();
       int c=nxt();
        mod=c+1;
        //debug(mod);
       FOR(i,0,n) {
          ar[i].x=nxt();
          ar[i].y=nxt();
          ar[i].s=nxt();
          update(ar[i].x,ar[i].y,ar[i].s);
          //debug(query(5,5));
       }
       FOR(i,0,q){
          br[i].t=nxt();
          br[i].t%=mod;
          br[i].x1=nxt();
          br[i].y1=nxt();
          br[i].x2=nxt();
          br[i].y2=nxt();
          br[i].id=i;
       }
       sort(br,br+q,cmp);
      // debug(query(5,5));
       int Time=1;
      FOR(i,0,q){

         int need = br[i].t;
         //debug(need);
         while(Time<=need){
            go();
            Time++;
         }
         //debug(query(5,5));
         ans[br[i].id]=query(br[i].x2,br[i].y2)+query(br[i].x1-1,br[i].y1-1)-query(br[i].x2,br[i].y1-1)-query(br[i].x1-1,br[i].y2);
        //debug(ans[br[i].id]);

        // mat[x2][y2]+mat[x1-1][y1-1]-mat[x2][y1-1]-mat[x1-1][y2];

      }
       FOR(i,0,q) {
         printf("%d\n",ans[i]);
       }
return 0;
}