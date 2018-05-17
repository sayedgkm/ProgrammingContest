 /// Bismillahir-Rahmanir-Rahim
#include <bits/stdc++.h>
#define        ll                              long long int
#define        FOR(x,y,z)                      for(int x=y;x<z;x++)
#define        pii                             pair<int,int>
#define        pll                             pair<ll,ll>
#define        CLR(a)                          memset(a,0,sizeof(a))
#define        SET(a)                          memset(a,-1,sizeof(a))
#define        N                               100010
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
}query[50005];
int ar[N];
int sum,ans[N];
int mark[N];
int tmp[N];
int l=0,r=-1,k=320;
void add(int i) {
    tmp[mark[ar[i]]]--;
    mark[ar[i]]++;
    tmp[mark[ar[i]]]++;
    sum = max(sum,mark[ar[i]]);
}
void del(int i) {
    tmp[mark[ar[i]]]--;
    if(tmp[mark[ar[i]]]==0&&mark[ar[i]]==sum) sum--;
    mark[ar[i]]--;
     tmp[mark[ar[i]]]++;

}
bool cmp(info a,info b){
    if(a.l/k==b.l/k)
        return a.r<b.r;
    return (a.l)<(b.l);
}
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    int test = nxt();
    int cs =1 ;
    while(test--) {

       int n, c, q;
        scanf("%d %d %d", &n, &c, &q);
        for(int i =0;i<n;i++) scanf("%d",ar+i);
        k = sqrt(n);
        for(int i =0;i<q;i++) {
            scanf("%d%d",&query[i].l,&query[i].r);
            query[i].l-=1;
            query[i].r-=1;
            query[i].id = i;
        }
        sort(query,query+q,cmp);
         sum = 0;
         l = 0,r = -1;
         for(int i = 0;i<q;i++) {
            while(r<query[i].r) add(++r);
            while(r>query[i].r) del(r--);
            while(l<query[i].l) del(l++);
            while(l>query[i].l) add(--l);
            ans[query[i].id]= sum;
        }
        printf("Case %d:\n",cs++);
        for(int i = 0;i<q;i++){
            printf("%d\n",ans[i]);
        }
        CLR(tmp);
        CLR(mark);
    }

    return 0;
}