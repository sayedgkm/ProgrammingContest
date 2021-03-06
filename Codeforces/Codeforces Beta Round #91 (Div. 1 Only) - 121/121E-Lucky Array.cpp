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
int ar[N];
int mark[N];
vector<int> lucky;
int block;
int  Old[320][10010];
int segment[320];
void gen(int u) {
    if(u>10000) return ;
   mark[u]=1;
   lucky.pb(u);
   if(!mark[u*10+4]) gen(u*10+4);
   if(!mark[u*10+7]) gen(u*10+7);

}
int update(int a,int b,int d){
   int i=0;
   for(i=a;i<=b&&i%block;i++) {
      int id=i/block;
        int x=ar[i];
         Old[id][x]--;
         x+=d;
         ar[i]=x;
         Old[id][x]++;
    }
    for(;i+block-1<=b;i+=block) segment[i/block]+=d;
    for(;i<=b;i++) {

         int id=i/block;
         int x=ar[i];
         Old[id][x]--;
         x+=d;
         ar[i]=x;
         Old[id][x]++;
    }
}
int query(int a,int b){
     int i=0; int ans=0;
    for(i=a;i<=b&&(i%block);i++){
         int x=segment[i/block];
          x+=ar[i];
          ans+=mark[x];
    }
   for(;i+block-1<=b;i+=block) {
      FOR(j,0,lucky.size()) {
          int temp=lucky[j]-segment[i/block];
          if(temp>0) ans+=Old[i/block][temp];
      }
   }
   for(;i<=b;i++){

         int x=segment[i/block];
          x+=ar[i];
          ans+=mark[x];
    }
    return ans;
}
int main(){
     //freopen("out.txt","w",stdout);
     //freopen("in.txt","r",stdin);
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
    gen(4);
    gen(7);
    block=320;
    int n=nxt(); int m=nxt();
    FOR(i,0,n){
          ar[i]=nxt();
          Old[i/block][ar[i]]++;
     }
      while(m--){
       char c[10];
       scanf("%s",c);
       int a=nxt();
       int b=nxt();
       if(c[0]=='c') {
         printf("%d\n",query(--a,--b));
       } else {
          int d=nxt();
          update(--a,--b,d);
       }

    }
return 0;
}