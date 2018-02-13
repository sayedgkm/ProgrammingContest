//====================================
//======================================
//
//                   Bismillahir-Rahmanir-Rahim
//
// ==========================================================================
#include <bits/stdc++.h>
#define        ll                              long long int
#define        FOR(x,y,z)                      for(int x=y;x<z;x++)
#define        pii                             pair<int,int>
#define        pll                             pair<ll,ll>
#define        CLR(a)                          memset(a,0,sizeof(a))
#define        SET(a)                          memset(a,-1,sizeof(a))
#define        N                               50010
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
inline long double dxt(){long double aaa;scanf("%lf",&aaa);return aaa;}
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
        cerr.write(names, comma - names) << " is " << arg1 <<endl;
        __f(comma+1, args...);
    }
#else
    #define debug(...)
#endif
///******************************************START******************************************
int ar[N];
vector<int> primes;
int _id[200];
int P[200];
void make(){
    for(int i = 0;i<primes.size();i++){
        _id[primes[i]] = i+1;
        P[i+1] = primes[i];
    }

}
long long tree[40][N], aux[40][N];

void update(int id,int i, int n,int x, long long av){
    while (i <= n){
        tree[id][i] += x, aux[id][i] += av;
        i += (i & -i);
    }
}

void update_range(int id,int l, int r,int n, int x){
    update(id,l, n,x, x * (l - 1));
    update(id,r + 1,n, -x, -x * r);
}

long long query(int id,int i){
    long long x = 0, y = 0, r = i;
    while (i){
        x += tree[id][i], y += aux[id][i];
        i -= (i & -i);
    }
    return (x * r - y);
}

long long query_range(int id,int l, int r){
    return query(id,r) - query( id,l - 1);
}
vector<pii> v[151];
vector<pii> factor(int x) {
    vector<pii> temp;
    for(int i = 0;primes[i]*primes[i]<=x;i++) {
        if(x%primes[i]==0) {
            int c = 0;
            while(x%primes[i]==0) {
                x/=primes[i];
                c++;
            }
            temp.pb(make_pair(primes[i],c));
        }
    }
    if(x>1) {
        temp.pb(make_pair(x,1));
    }
    return temp;
}
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    FOR(i,2,150) {
        bool f = 0;
        for(int j = 2;j<i;j++) {

            if(i%j==0) f = 1;
        }
        if(!f) primes.pb(i);
    }
    make();
    FOR(i,1,151) v[i] = factor(i);
int test =  nxt();
while(test--) {
    int n = nxt();
    int m  = nxt();
    while(m--) {

        int t = nxt();
        if(t==0) {

            int a= nxt();
            int b =nxt();
            ll mod = lxt();
            ll ans = 1;
            FOR(i,0,primes.size()) {
                int id = _id[primes[i]];
                if(b>=a)
                 ans*=bigmod((ll)P[id],query_range(id,a,b),mod);
                 else ans*=bigmod((ll)P[id],query_range(id,a,n)+query_range(id,1,b),mod);
                ans%=mod;
            }
            printf("%lld\n",ans);
        } else {
            int a = nxt();
            int b = nxt();
            int x = nxt();
            FOR(i,0,v[x].size()) {
                if(b>=a){
                    if(t==1)
                    update_range(_id[v[x][i].ff],a,b,n,v[x][i].ss);
                    else
                    update_range(_id[v[x][i].ff],a,b,n,-v[x][i].ss);
                } else {
                    if(t==1){
                        update_range(_id[v[x][i].ff],a,n,n,v[x][i].ss);
                        update_range(_id[v[x][i].ff],1,b,n,v[x][i].ss);
                    }
                    else{
                        update_range(_id[v[x][i].ff],a,n,n,-v[x][i].ss);
                        update_range(_id[v[x][i].ff],1,b,n,-v[x][i].ss);
                    }
                }
            }
        }

    }
    CLR(tree);
    CLR(aux);
}

    return 0;
}