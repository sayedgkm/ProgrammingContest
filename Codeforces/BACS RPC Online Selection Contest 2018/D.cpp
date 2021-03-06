 /// Bismillahir-Rahmanir-Rahim
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
#define        inf                              (1e9)+1000
#define        eps                             1e-9
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
#ifdef sayed
     #define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template < typename Arg1 >
    void __f(const char* name, Arg1&& arg1){
        cerr << name << " is " << arg1 << std::endl;
    }
    template < typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names+1, ',');
        cerr.write(names, comma - names) << " is " << arg1 <<" | ";
        __f(comma+1, args...);
    }
#else
    #define debug(...)
#endif
///******************************************START******************************************
int ar[N];
char s[N];

const long long MOD[] = {1000000007LL, 2117566807LL,1000000007LL,1000000037LL};
const long long BASE[] = {1572872831LL, 1971536491LL,1000003LL,31};
class stringhash{
    public:
    ll base,mod,len,ar[N],P[N],br[N];

   void GenerateFH(string s,ll b,ll m){
          base=b;
          mod=m;  len=s.length();
          P[0]=1; long long h=0;
          for(int i=1;i<=len;i++) P[i]=((ll)P[i-1]*(ll)base)%mod;
          for(int i=0;i<len;i++){
              h=(h*base)+s[i];
              h%=mod;
              ar[i]=h;
          }
   }
   int Fhash(int x,int y){
        ll h=ar[y];
       if(x>0){
         h=(h-(ll)P[y-x+1]*(ll)ar[x-1])%mod;
         if(h<0) h+=mod;
       }
       return h;
   }

   void GenerateRH(string s,ll b,ll m){
          base=b;
          mod=m;  len=s.length();
          P[0]=1; ll h=0;
          for(int i=1;i<=len;i++) P[i]=((ll)P[i-1]*(ll)base)%mod;
          for(int i=len-1;i>=0;i--){
              h=(h*base)+s[i];
              h%=mod;
              br[i]=h;
          }
   }
   ll Rhash(int x,int y){
        long long h=br[x];
       if(y<len-1){
         h=(h-(ll)P[y-x+1]*(ll)br[y+1])%mod;
         if(h<0) h+=mod;
       }
       return h;
   }


};
stringhash s1,s2;
int len ;
ll go(int i,int k) {
    int lo=k/2;
    int hi =len;
    while(lo<=hi){
        int mid = (lo+hi)/2;
        if(mid+i>=len) {
            hi= mid-1;
            continue;
        }
        if(i-mid<0){
            hi = mid-1;
            continue;
        }
        if(s1.Fhash(i-mid,i-1)==s1.Rhash(i+1,i+mid)){
            hi = mid-1;
        } else lo = mid+1;
    }
    return lo;
}
ll even(int i,int k) {
    int lo=(k+1)/2;
    int hi =len;
    while(lo<=hi){
        int mid = (lo+hi)/2;
        if(mid+i-1>=len) {
            hi= mid-1;
            continue;
        }
        if(i-mid<0){
            hi = mid-1;
            continue;
        }
        if(s1.Fhash(i-mid,i-1)==s1.Rhash(i,i+mid-1)){
            hi = mid-1;
        } else lo = mid+1;
    }
    return lo;
}
int check(int i,int x,int t,int k) {
    if(t==0) {
        int l = i-x;
        int r = i+x;

        if(l<0||r>=len) return false;
        if(s1.Fhash(l,r)==s1.Rhash(l,r)&&(r-l+1)>=k) return true;
        return false;
    } else {
        int l = i - x;
        int r = i+x-1;
        if(l<0||r>=len) return false;
        if(s1.Fhash(l,r)==s1.Rhash(l,r)&&(r-l+1)>=k) return true;
        return false;
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
    int cs = 1;
    while(test--) {
        int k = nxt();
        scanf("%s",s);
        len  = strlen(s);
        ll tot = len*(len-1);
        tot/=2;
        tot+=len;

        s1.GenerateFH(s,BASE[0],MOD[0]);
        s1.GenerateRH(s,BASE[0],MOD[0]);
        ll last = -1;

        for(int i =0;i<len;i++) {
            int x = go(i,k);
            int y = even(i,k);
            int l,r;
            if(check(i,x,0,k)&&check(i,y,1,k)) {
                l = i-x;
                r = i+x-1;
            } else if(check(i,x,0,k)) {
                l = i-x;
                r = i+x;
            } else if(check(i,y,1,k)){
                l = i-x;
                 r = i+x-1;
            } else continue;
            if(last>l) continue;
            else{
                debug(l,r);
                debug(len-r);
                debug(l-last);
                tot-=(len-r)*(l-last);
                last = l;
            }
        }

        printf("Case %d: %lld\n",cs++,tot);
    }

    return 0;
}
