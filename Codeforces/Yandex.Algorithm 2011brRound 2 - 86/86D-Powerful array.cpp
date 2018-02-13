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
struct info{
    int l,r,id;
    int block_no;
}query[N];
int ar[N];ll cnt[N*10];
ll sum,ans[N];
int l=0,r=-1,k=450;
void add(int i) {
   int tmp = cnt[ar[i]];
    sum+=ar[i]*(tmp+tmp+1);
    cnt[ar[i]]++;
}
void remove(int i) {
    int tmp = cnt[ar[i]];
    sum-=ar[i]*(tmp+tmp-1);
    cnt[ar[i]]--;
}
bool cmp(info a,info b){
    if(a.block_no==b.block_no) return (a.block_no&1)?(a.r<b.r):(a.r>b.r);
    return (a.block_no)<(b.block_no);
}
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    int n = nxt();
    int q= nxt();
    FOR(I,0,n) ar[I] = lxt();
    FOR(i,0,q) query[i].l = (nxt()-1),query[i].r = (nxt()-1),query[i].id = i,query[i].block_no=query[i].l/k;
    sort(query,query+q,cmp);
    for(int i = 0;i<q;i++) {
        while(r<query[i].r) add(++r);
        while(r>query[i].r) remove(r--);
        while(l<query[i].l) remove(l++);
        while(l>query[i].l) add(--l);
        ans[query[i].id]= sum;
    }

    for(int i = 0;i<q;i++){
        printf("%lld\n",ans[i]);
    }


    return 0;
}