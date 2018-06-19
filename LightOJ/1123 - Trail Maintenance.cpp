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
struct E{
    int u,v,de;
}e[50000];

int pre[205];
int vis[205][205];
int cnt,n,w;

int Find(int x){
    return pre[x]==x?x:pre[x]=Find(pre[x]);
}

void Union(int x,int y){
    int fx=Find(x);
    int fy=Find(y);
    if(fx!=fy) pre[fx]=fy;
}

bool cmp(struct E a,struct E b){
    return a.de<b.de;
}

int  kruskal(){
    for(int i=1;i<=n;i++) pre[i]=i;
    int tmp=0;
    int conn=0;
    int ans=0;
    for(int i=0;i<cnt;i++){
        int a=Find(e[i].u);
        int b=Find(e[i].v);
        if(a==b){
            tmp=i;
            continue;
        }
        conn++;
        pre[a]=b;
        ans+=e[i].de;
    }
    if(tmp!=0) e[tmp]=e[--cnt];
    if(conn!=n-1) return -1;
    return ans;
}
int main(){
    int kase=0;
    int t = nxt();
    while(t--){
        kase++;
        scanf("%d%d",&n,&w);
        cnt=0;
        printf("Case %d:\n",kase);
        for(int i=0;i<w;i++){
            scanf("%d%d%d",&e[cnt].u,&e[cnt].v,&e[cnt].de);
            cnt++;
            sort(e,e+cnt,cmp);
            printf("%d\n",kruskal());
        }
    }
    return 0;
}

