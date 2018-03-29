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
ll ar[N];
ll ri[N];
ll br[N];
ll sol[N];
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    int n = nxt();
    ll m= lxt();
    for(int i = 0;i<n;i++) ar[i] = lxt();
    for(int i = 0;i<n;i++) br[i] = lxt();
    ll down= 1;
    ll up = 0;
    for(int i = 0;i<n;i++) {
        if(ar[i]==0) {
            down*=m;
        }
        down%=M;
        if(br[i] == 0) down*=m;
        down%=M;
    }
    ll dan = 1;
    for(int i = n-1;i>=0;i--) {
        if(ar[i]==0) {
            dan*=m;
        }
        dan%=M;
        if(br[i] == 0) dan*=m;
        dan%=M;
        ri[i] = dan;
    }
    ri[n] = 1;
    sol[n] = 0;

    for(int i = n-1;i>=0;i--) {
        if(ar[i]&&br[i]) {
            if(ar[i]<br[i]) sol[i]=0;
            if(ar[i]>br[i]) {
                sol[i]= ri[i+1];
            }
            if(ar[i]==br[i]) sol[i]= sol[i+1];

        } else if(ar[i]&&br[i]==0) {
            up=((ar[i]-1)*ri[i+1])%M;
            sol[i] = up;
            sol[i]+=sol[i+1];
        } else if(ar[i]==0&&br[i]) {
            up= ((m-br[i])*ri[i+1])%M;
            sol[i] = up;
            sol[i]+=sol[i+1];
        } else {
            ll gun = m-1;
            gun = (gun*gun+gun)/2;
            gun%=M;
            gun*=ri[i+1];
            gun%=M;
            gun+=(m*sol[i+1]);
            sol[i] = gun;
        }
        sol[i]%=M;
    }
    up =sol[0];
    debug(up,down);
    down = bigmod(down,(ll)M-2,(ll)M);
    up= up*down;
    up%=M;
    printf("%lld\n",up);


    return 0;
}
