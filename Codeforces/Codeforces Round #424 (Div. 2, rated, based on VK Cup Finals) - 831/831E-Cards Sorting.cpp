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
int ar[N];
vector<int> v;
bool comp (pii x,pii y) {
    if(x.ff<y.ff) return x.ss<y.ss;
    return x.ff<y.ff;
}
int tree[N];
void update(int i,int n,int val) {

    while(i<=n) {
         tree[i]+=val;
         i+=(i)&(-i);

    }

}
int query(int n) {
   ll sum=0;
   while(n) {
      sum+=tree[n];
      n-=(n)&(-n);
   }
  return sum;
}
vector<int> index[N];
bool mark[N];
int main(){
     //freopen("out.txt","w",stdout);
     //freopen("in.txt","r",stdin);
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
      int n=nxt();
      FOR(i,0,n) {
         int a=nxt();
          if(!mark[a]) v.pb(a);
          mark[a]=1;
         update(i+1,n,1);
         index[a].pb(i+1);
      }
      sort(ALL(v));
      vector<int>serial;
        int last=0;
      FOR(i,0,v.size()) {
           int el=v[i];
           int l=lower_bound(ALL(index[el]),last)-index[el].begin();
           FOR(j,l,index[el].size()) {
              serial.pb(index[el][j]);
           }
           FOR(j,0,l) {
               serial.pb(index[el][j]);
           }
           last=serial.back();
      }
      ll ans=0;
    last=0;
      FOR(i,0,n) {
          int x=serial[i];
         if(last<=x) {
             ans+=query(x-1)-query(last)+1;
             update(x,n,-1);
         } else {
            ans+=query(x-1);
            ans+=query(n);
            ans-=query(last);
            ans+=1;
            update(x,n,-1);
         }
         last=x;
//         debug(x);
//         debug(ans);
         //debug(v[i].ss);
         //debug(ans);
      }
      cout<<ans<<endl;
return 0;
}