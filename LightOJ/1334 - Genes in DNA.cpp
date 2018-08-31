 /// Bismillahir-Rahmanir-Rahim
#include <bits/stdc++.h>
#define        ll                              long long int
#define        FOR(x,y,z)                      for(int x=y;x<z;x++)
#define        pii                             pair<int,int>
#define        pll                             pair<ll,ll>
#define        CLR(a)                          memset(a,0,sizeof(a))
#define        SET(a)                          memset(a,-1,sizeof(a))
#define        N                               50010
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
const long long MOD[] = {1000000007LL, 2117566807LL,1000000007LL,1000000037LL};
const long long BASE[] = {1572872831LL, 1971536491LL,1000003LL,31};
class stringhash{
    public:
    ll base,mod,len,ar[N],P[N];

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
};
stringhash s1,s2;

char s[N],t[N];
ll f1[N],f2[N];
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    int test =nxt();int cs =1;
    while(test--) {
        int n = nxt();
        scanf("%s",s);
        scanf("%s",t);
        s1.GenerateFH(s,BASE[0],MOD[0]);
        s2.GenerateFH(t,BASE[0],MOD[0]);
        int slen = strlen(s);
        int tlen = strlen(t);
        for(int i = 0;i<slen;i++) {

            if(s[i]!=t[0]) continue;
            int b = 1;
            int e = min(tlen-1,slen-i);
            while(b<=e) {

                int mid = (b+e)/2;
                if(s1.Fhash(i,i+mid-1)==s2.Fhash(0,0+mid-1)) {
                    b = mid+1;
                } else e= mid-1;
            }
            b--;
            f1[i]+=1;
            f1[i+b]-=1;
        }

        for(int i = slen-1;i>=0;i--) {
            if(s[i]!=t[tlen-1]) continue;
            int b= 1;
            int e= min(i+1,tlen-1);
            while(b<=e) {

                int mid = (b+e)/2;
                if(s1.Fhash(i-mid+1,i)==s2.Fhash(tlen-mid,tlen-1)) {
                    b = mid+1;
                } else e = mid-1;
            }
            b--;
           f2[i]+=1;
           if(i-b>=0)
            f2[i-b]-=1;
        }
        for(int i = 1;i<slen;i++) f1[i]+=f1[i-1];
        for(int i = slen-1;i>=0;i-- ) f2[i]+=f2[i+1];
        ll ans = 0;
        for(int i =0;i<slen-1;i++) {
            ans+=f1[i]*f2[i+1];
        }
        printf("Case %d: %lld\n",cs++,ans);
        CLR(f1);
        CLR(f2);

    }

    return 0;
}
