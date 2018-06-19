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
int get(char c) {
    if(!isalpha(c)) return c-'0';
    if(c=='A') return 1;
    if(c=='T') return 10;
    if(c=='J') return 11;
    if(c=='Q') return 12;
    if(c=='K') return 13;
}
unsigned ll dp[14][14][14][14][5];
unsigned ll go(int one,int two,int three,int four,int last) {
    //debug(one,two,three,four,last);
    if(one+two+three+four==0) return 1;
    unsigned ll res = dp[one][two][three][four][last];
    if(res!=-1) return res;
    res = 0;
    if(last==2&&one) {
        res+=go(one-1,two,three,four,1)*(unsigned ll) (one-1);
    } else if(one) {
        res+=go(one-1,two,three,four,1)*(unsigned ll) (one);
    }
    if(last==3&&two) {
        res+=go(one+1,two-1,three,four,2)*(unsigned ll) (two-1)*2ULL;
    } else if(two) {
        res+=go(one+1,two-1,three,four,2)*(unsigned ll) (two)*2ULL;
    }

     if(last==4&&three) {
        res+=go(one,two+1,three-1,four,3)*(unsigned ll) (three-1)*3ULL;
    } else if(three) {
        res+=go(one,two+1,three-1,four,3)*(unsigned ll) (three)*3ULL;
    }
    if(four) res+=go(one,two,three+1,four-1,4)*(unsigned ll) (four)*4ULL;
    return res;
}
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    int test =nxt(); int cs = 1;
    SET(dp);
    while(test--) {
        int n = nxt();
        char c[2]; int oc[14] ={0};
        for(int i =0;i<n;i++) {
            scanf("%s",c);
            oc[get(c[0])]++;
        }
        int mark[5]={0};
        for(int i =1;i<=13;i++) mark[oc[i]]++;
        unsigned ll res= go(mark[1],mark[2],mark[3],mark[4],0);
        printf("Case %d: %llu\n",cs++,res);

    }

    return 0;
}

