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
vector<int>primes;
bool mark[N];
void sieve(int n) {
    primes.push_back(2);
    for(int i=3; i*i<=n; i+=2)
     for(int j = i*i; j <= n; j += i * 2)
            mark[j] = 1;
    for (int i = 3; i <= n; i += 2)
        if (!mark[i]) primes.push_back(i);
    }
    map<int,int>mp[N];
void save(int x) {
   int n=ar[x];
   for(int i=0;primes[i]*primes[i]<=n;i++) {
      int c=0;
      if(n%primes[i]==0) {
         while(n%primes[i]==0) {
            n/=primes[i];
            c++;
         }
         mp[x][primes[i]]=c;
      }
    }
    if(n>1) mp[x][n]=1;
    mp[x][1]++;
}
 map<int,int>check;
  map<int,int>:: iterator it;
bool ok(int n){

   for(it =mp[n].begin();it!=mp[n].end();it++){
        int l=it->ff;
        int r=it->ss;
        if(check[l]<r) return false;
    }
    return true;
}
int main(){
     //freopen("out.txt","w",stdout);
     //freopen("in.txt","r",stdin);
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
   sieve(N-1);
    int n=nxt();
    int k=nxt();
    FOR(i,0,n){
       ar[i]=nxt();
       save(i);
    }
    ar[n]=k;
    save(n);
    ll ans=0;
    int i=-1,j=0;
    while(i<n) {
        if(ok(n)) {
            ans+=n-i;
            for(it=mp[j].begin();it!=mp[j].end();it++) {
                check[it->ff]-=it->ss;
            }
            j++;
        } else {
           i++;
          for(it=mp[i].begin();it!=mp[i].end();it++) {
                check[it->ff]+=it->ss;
            }
        }
//        debug(i);
//        debug(j);
    }
    cout<<ans<<endl;
return 0;
}