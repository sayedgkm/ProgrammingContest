///Bismillahir-Rahmanir-Rahim
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
#define MAX_V 103
#define MAX_E MAX_V*MAX_V
long nV,nE,Match[MAX_V];
long Last[MAX_V], Next[MAX_E], To[MAX_E];
long eI;
long q[MAX_V], Pre[MAX_V], Base[MAX_V];
bool Hash[MAX_V], Blossom[MAX_V], Path[MAX_V];

void Insert(long u, long v) {
    To[eI] = v, Next[eI] = Last[u], Last[u] = eI++;
    To[eI] = u, Next[eI] = Last[v], Last[v] = eI++;
}

long Find_Base(long u, long v) {
    memset( Path,0,sizeof(Path));
    for (;;) {
        Path[u] = 1;
        if (Match[u] == -1) break;
        u = Base[Pre[Match[u]]];
    }
    while (Path[v] == 0) v = Base[Pre[Match[v]]];
    return v;
}

void Change_Blossom(long b, long u) {
    while (Base[u] != b) {
        long v = Match[u];
        Blossom[Base[u]] = Blossom[Base[v]] = 1;
        u = Pre[v];
        if (Base[u] != b) Pre[u] = v;
    }
}

long Contract(long u, long v) {
    memset( Blossom,0,sizeof(Blossom));
    long b = Find_Base(Base[u], Base[v]);
    Change_Blossom(b, u);
    Change_Blossom(b, v);
    if (Base[u] != b) Pre[u] = v;
    if (Base[v] != b) Pre[v] = u;
    return b;
}

void Augment(long u) {
    while (u != -1) {
        long v = Pre[u];
        long k = Match[v];
        Match[u] = v;
        Match[v] = u;
        u = k;
    }
}

long Bfs( long p ){
    memset( Pre,-1,sizeof(Pre));
    memset( Hash,0,sizeof(Hash));
    long i;
    for( i=1;i<=nV;i++ ) Base[i] = i;
    q[1] = p, Hash[p] = 1;
    for (long head=1, rear=1; head<=rear; head++) {
        long u = q[head];
        for (long e=Last[u]; e!=-1; e=Next[e]) {
            long v = To[e];
            if (Base[u]!=Base[v] and v!=Match[u]) {
                if (v==p or (Match[v]!=-1 and Pre[Match[v]]!=-1)) {
                    long b = Contract(u, v);
                    for( i=1;i<=nV;i++ ) if (Blossom[Base[i]]==1) {
                        Base[i] = b;
                        if (!Hash[i]) {
                            Hash[i] = 1;
                            q[++rear] = i;
                        }
                    }
                } else if (Pre[v]==-1) {
                    Pre[v] = u;
                    if (Match[v]==-1) {
                        Augment(v);
                        return 1;
                    }
                    else {
                        q[++rear] = Match[v];
                        Hash[Match[v]] = 1;
                    }
                }
            }
        }
    }
    return 0;
}

long Edmonds_Blossom(){
    long i,Ans = 0;
    memset( Match,-1,sizeof(Match));
    for( i=1;i<=nV;i++ ) if (Match[i] == -1) Ans += Bfs(i);
    return Ans;
}
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    int test = nxt();
    while(test--) {
        eI = 0;
        memset( Last,-1,sizeof(Last));
        int n= nxt();
        int m = nxt();
        nV= n;
        for(int i = 0;i<m;i++) {
            int a= nxt();
            int b = nxt();
            Insert(a,b);
        }
        if(nV%2) {
            printf("NO\n");
            continue;
        }
        int res = Edmonds_Blossom();
        if(res==nV/2) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}
