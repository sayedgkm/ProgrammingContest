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
const int MAXN = 1<<18;
const int MAXL = 18;
int nnn, stp, mv, suffix[MAXN], tmp[MAXN];
int sum[MAXN], cnt[MAXN], sufRank[MAXL][MAXN];
char str[MAXN];

inline bool equal(const int &u, const int &v){
    if(!stp) return str[u] == str[v];
    if(sufRank[stp-1][u] != sufRank[stp-1][v]) return false;
    int a = u + mv < nnn ? sufRank[stp-1][u+mv] : -1;
    int b = v + mv < nnn ? sufRank[stp-1][v+mv] : -1;
    return a == b;
}

void update(){
    int i, rnk;
    for(i = 0; i < nnn; i++) sum[i] = 0;
    for(i = rnk = 0; i < nnn; i++) {
        suffix[i] = tmp[i];
        if(i && !equal(suffix[i], suffix[i-1])) {
            sufRank[stp][suffix[i]] = ++rnk;
            sum[rnk+1] = sum[rnk];
        }
        else sufRank[stp][suffix[i]] = rnk;
        sum[rnk+1]++;
    }
}

void Sort() {
    int i;
    for(i = 0; i < nnn; i++) cnt[i] = 0;
    memset(tmp, -1, sizeof tmp);
    for(i = 0; i < mv; i++){
        int idx = sufRank[stp - 1][nnn - i - 1];
        int x = sum[idx];
        tmp[x + cnt[idx]] = nnn - i - 1;
        cnt[idx]++;
    }
    for(i = 0; i < nnn; i++){
        int idx = suffix[i] - mv;
        if(idx < 0)continue;
        idx = sufRank[stp-1][idx];
        int x = sum[idx];
        tmp[x + cnt[idx]] = suffix[i] - mv;
        cnt[idx]++;
    }
    update();
    return;
}

inline bool cmp(const int &a, const int &b){
    if(str[a]!=str[b]) return str[a]<str[b];
    return false;
}

void SortSuffix() {
    int i;
    for(i = 0; i < nnn; i++) tmp[i] = i;
    sort(tmp, tmp + nnn, cmp);
    stp = 0;
    update();
    ++stp;
    for(mv = 1; mv < nnn; mv <<= 1) {
        Sort();
        stp++;
    }
    stp--;
    for(i = 0; i <= stp; i++) sufRank[i][nnn] = -1;
}

///Here u and v are unsorted suffix string positions
inline int lcp_(int u, int v) {
    if(u == v) return nnn - u;
    int ret, i;
    for(ret = 0, i = stp; i >= 0; i--) {
        if(sufRank[i][u] == sufRank[i][v]) {
            ret += 1<<i;
            u += 1<<i;
            v += 1<<i;
        }
    }
    return ret;
}
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    int test = nxt();
    int cs  = 1;
    while(test--) {
        scanf("%s",str);
        nnn = strlen(str);
        int len = nnn;
        SortSuffix();
        int p = nxt();
        int q =nxt();
        int ans = 0;
        for(int i = 0;i<len;i++) {
            int cur = len-suffix[i];
            if(cur<p) continue;
            int lcp = (i==0)?0:lcp_(suffix[i],suffix[i-1]);
            int tot = min(q-p+1,cur-p+1);
            lcp-=(p-1);
            tot-=max(lcp,0);
            //debug(tot,cur);
            ans+=max(tot,0);
        }
        printf("Case %d: %d\n",cs++,ans);
    }


    return 0;
}
