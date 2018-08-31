 /// Bismillahir-Rahmanir-Rahim
#include <bits/stdc++.h>
#define        ll                              long long int
#define        FOR(x,y,z)                      for(int x=y;x<z;x++)
#define        pii                             pair<int,int>
#define        pll                             pair<ll,ll>
#define        CLR(a)                          memset(a,0,sizeof(a))
#define        SET(a)                          memset(a,-1,sizeof(a))
#define        N                               1000010
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
int n;
int ask(int x1,int y1,int x2,int y2) {
    if(x1<1||x1>n) return 0;
    if(y1<1||y1>n) return 0;
    if(x2<1||x2>n) return 0;
    if(y2<1||y2>n) return 0;
    printf("? %d %d %d %d\n",x1,y1,x2,y2);
    fflush(stdout);
    char s[100];
    scanf("%s",s);
    if(s[0]=='Y'){
        debug("asche");
        return true;
    }
    if(s[0]!='N') assert(false);
    return false;
}
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    n= nxt();
    vector<char > v;
    v.resize(2*(n-1));
    int last = 2*(n-1);
    int x,y;
    x = y = n;
    vector<pii> prev;
    while(abs(x-1)+abs(y-1)>=n) {
        if(ask(1,1,x-1,y)) {
            v[--last]='D';
            x--;
        } else {
            v[--last] = 'R';
            y--;
        }
    }
    last  = 0;
    x = 1,y =1;
    while(abs(x-n)+abs(y-n)>=n) {
        if(ask(x,y+1,n,n)) {
            v[last++] = 'R';
            y++;
        } else v[last++] = 'D',x++;
    }
    printf("! ");
    for(auto it : v) printf("%c",it);
    printf("\n");
    fflush(stdout);
    return 0;
}

