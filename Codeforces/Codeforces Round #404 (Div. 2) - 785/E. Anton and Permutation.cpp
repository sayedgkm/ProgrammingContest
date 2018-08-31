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
int ar[N];
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
ordered_set tr[N];
void add(int pos,int val,int n) {
    while(pos<=n) {
        tr[pos].insert(val);
        pos+=pos&-pos;
    }
}
void del(int pos,int val,int n) {
    while(pos<=n) {
        tr[pos].erase(tr[pos].find(val));
        pos+=pos&-pos;
    }
}
int query(int pos,int val) {
    int sum =0;
    while(pos>0) {
        sum+=tr[pos].order_of_key(val);
        pos-=pos&-pos;
    }
    return sum;
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
    for(int i = 1;i<=n;i++) ar[i]= i,add(i,i,n);
    ll ans = 0;
    while(q--) {
        int a= nxt();
        int b= nxt();
        if(a>b) swap(a,b);
        if(a!=b){
            if(b-a>1) {
                pii tmp ;
                tmp.ff=query(b-1,ar[b])-query(a,ar[b]);
                tmp.ss = (b-a-1-tmp.ff);
                ans+=tmp.ff;
                ans-=tmp.ss;
                tmp.ff=query(b-1,ar[a])-query(a,ar[a]);
                tmp.ss = (b-a-1-tmp.ff);
                ans-=tmp.ff;
                ans+=tmp.ss;
            }
            if(ar[a]<ar[b]) ans++;
            else ans--;
            del(a,ar[a],n);
            del(b,ar[b],n);
            swap(ar[a],ar[b]);
            add(a,ar[a],n);
            add(b,ar[b],n);
        }
        printf("%lld\n",ans);

    }


    return 0;
}

