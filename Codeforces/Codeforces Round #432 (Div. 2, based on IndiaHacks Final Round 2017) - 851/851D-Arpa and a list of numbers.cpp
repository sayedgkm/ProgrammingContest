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
#define        N                               2000000
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
ll sum[N];
ll cnt[N];
ll koita(int a,int b) {
    if(a>b) return 0;
   return cnt[b] - cnt[a-1];
}
ll go(int a,int b) {
    if(a>b) return 0 ;
   return sum[b]-sum[a-1];
}
int mark[N];
int main(){
    #ifdef sayed
     //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
      int  n  = nxt();
      ll x  = lxt();
      ll y  = lxt();
      FOR(i,0,n) {
          int a = nxt();
          assert(a<=1000000);
          cnt[a]++;
          sum[a] +=a;
      }
      FOR(i,1,N) sum[i] += sum[i-1],cnt[i] += cnt[i-1];
       ll ans = LLONG_MAX;
       ll diff = x/y;
      for(int i = 2;i<N;i++) {
            ll temp = 0;
            if( mark[i]) continue;
            for(int j = i;j<N;j+=i) {
                ll cur = j;
                mark[j] = 1;
                ll past = j - i;
                ll bam= max(cur-diff,past+1);
                ll change = koita(bam,cur-1)*cur-go(bam,cur-1);
                ll del= koita(past+1,bam-1);
                temp+=change*y+del*x;
                if(temp>ans) break;

            }
            ans = min(ans,temp);

      }
     cout<<ans<<endl;

return 0;
}