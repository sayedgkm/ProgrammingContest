// ==========================================================================
//
//                   Bismillahir-Rahmanir-Rahim
//
// ==========================================================================
#include <bits/stdc++.h>
#define        ll                              long long
#define        f(x,y,z)                        for(int x=y;x<z;x++)
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
#define        inf                             (int)1e9
using namespace std;
int dx[]={0,0,1,-1,-1,-1,1,1};
int dy[]={1,-1,0,0,-1,1,1,-1};
template < class T> inline T biton(T n,T pos){return n |((T)1<<pos);}
template < class T> inline T bitoff(T n,T pos){return n & ~((T)1<<pos);}
template < class T> inline T on(T n,T pos){return (bool)(n & ((T)1<<pos));}
template < class T> inline T gcd(T a, T b){while(b){a%=b;swap(a,b);}return a;}
template <typename T> string NumberToString ( T Number ) { ostringstream ss; ss << Number; return ss.str(); }
inline int nxt(){int aaa;scanf("%d",&aaa);return aaa;}
inline ll lxt(){ll aaa;scanf("%lld",&aaa);return aaa;}
template <class T> inline T bigmod(T p,T e,T m){T ret = 1;
for(; e > 0; e >>= 1){
    if(e & 1) ret = (ret * p) % m;p = (p * p) % m;
} return (T)ret;}
#define sayed
#ifdef sayed
     #define debug(args...) {cerr<<"Debug: "; dbg,args; cerr<<endl;}
#else
    #define debug(args...)  // Just strip off all debug tokens
#endif
struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;
///******************************************START******************************************
char s[20][20];
int ar[20][20];
int life[20];
int n;
int dp[1 << 16];
int go(int mask, int c){
    if (c == n) return 0;
    int cost = 0, mn = inf;
    if (dp[mask] != -1) return dp[mask];
    for (int i = 0; i<n; i++){
        if (on(mask, i) == 0) // i'th person k akhono mara hoini
        {
            int guli = 1;
            for (int j = 0; j<n; j++){
                if (on(mask, j))
                {
                    guli = max(guli, ar[j][i]);
                }
            }
            cost = (life[i] + guli - 1) / guli + go(biton(mask, i), c + 1);
            mn = min(cost, mn);
        }
    }

    return dp[mask] = mn;
}
int main()
{
    ///ios_base::sync_with_stdio(0); cin.tie(0);
    /// freopen("out.txt","w",stdout);
    int test = nxt(); int cs = 1;
    while (test--){
        SET(dp);
        n = nxt();
        f(i, 0, n) life[i] = nxt();
        f(i, 0, n)
            scanf("%s", s[i]);
        f(i, 0, n) f(j, 0, n) ar[i][j] = s[i][j] - 48;
        printf("Case %d: %d\n", cs++, go(0, 0));

    }

    return 0;
}

