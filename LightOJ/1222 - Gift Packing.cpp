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
#define MAX 55          // Max number of vertices in one part
#define INF 100000000    // Just infinity

long long  cost[MAX][MAX];      // cost matrix
long long n,max_match;         // N workers and N jobs
long long lx[MAX], ly[MAX];    // Labels of X and Y parts
long long xy[MAX];             // xy[x] - vertex that is matched with x,
long long yx[MAX];             // yx[y] - vertex that is matched with y
bool S[MAX], T[MAX];     // Sets S and T in algorithm
long long slack[MAX];
long long slackx[MAX];         // slackx[y] such a vertex, that
                         // l(slackx[y]) + l(y) - w(slackx[y],y) = slack[y]
long long Prev[MAX];           // Array for memorizing alternating paths

void Init_Labels(){
    memset(lx, 0, sizeof(lx)); memset(ly, 0, sizeof(ly));
    long long x,y; for( x=0;x<n;x++ ) for( y=0;y<n;y++ ) lx[x] = max(lx[x], cost[x][y]);
}
void Update_Labels(){
    long long x, y, delta = INF;
    for( y=0;y<n;y++ ) if(!T[y]) delta = min(delta, slack[y]);
    for( x=0;x<n;x++ ) if(S[x]) lx[x] -= delta;
    for( y=0;y<n;y++ ) if(T[y]) ly[y] += delta;
    for( y=0;y<n;y++ ) if(!T[y]) slack[y] -= delta;
}
void Add_To_Tree(long long x, long long prevx) {
    S[x] = true; Prev[x] = prevx;
    long long y;
    for( y=0;y<n;y++ )
        if (lx[x] + ly[y] - cost[x][y] < slack[y]){
            slack[y] = lx[x] + ly[y] - cost[x][y]; slackx[y] = x;
        }
}
void Augment(){
    if (max_match == n) return;
    long long x, y, root; long long q[MAX], wr = 0, rd = 0;
    memset(S, false, sizeof(S)); memset(T, false, sizeof(T)); memset(Prev, -1, sizeof(Prev));
    for( x=0;x<n;x++ ) if (xy[x] == -1){ q[wr++] = root = x; Prev[x] = -2; S[x] = true; break; }
    for( y=0;y<n;y++ ){ slack[y] = lx[root] + ly[y] - cost[root][y]; slackx[y] = root; }
        while( true ){
        while (rd < wr){
            x = q[rd++];
            for( y=0;y<n;y++ ){
                if (cost[x][y] == lx[x] + ly[y] &&  !T[y]){
                    if (yx[y] == -1) break;
                    T[y] = true; q[wr++] = yx[y];
                    Add_To_Tree(yx[y], x);
                }
            } if (y < n) break;
        } if (y < n) break;
        Update_Labels();
        wr = rd = 0;
        for( y=0;y<n;y++ ){
            if (!T[y] &&  slack[y] == 0){
                if (yx[y] == -1){ x = slackx[y]; break;
                } else{
                    T[y] = true;
                    if (!S[yx[y]]){
                        q[wr++] = yx[y]; Add_To_Tree(yx[y], slackx[y]);
                    }
                }
            }
        } if (y < n) break;
    }
    if (y < n){ max_match++;
        for (long long cx = x, cy = y, ty; cx != -2; cx = Prev[cx], cy = ty){
            ty = xy[cx]; yx[cy] = cx; xy[cx] = cy;
        } Augment();
    }
}
long long Hungarian(){
    long long x,ret = 0; max_match = 0;
    memset(xy, -1, sizeof(xy)); memset(yx, -1, sizeof(yx));
    Init_Labels(); Augment();
    for( x=0;x<n;x++ ) ret += cost[x][xy[x]];
    return ret;
}

int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    int test= nxt();
    int cs = 1;
    while(test--) {
        n= nxt();
        CLR(cost);
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++) {
                cost[i][j] = lxt();
            }
        }
        printf("Case %d: %lld\n",cs++,Hungarian());
    }

    return 0;
}
