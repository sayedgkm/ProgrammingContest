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
vector<int> v[5];
map<int,int> mp,mp1;
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    int n= nxt();
    for(int i = 0;i<n;i++) ar[i] = nxt();
    sort(ar,ar+n);
    int mn = ar[0];
    int mx = ar[n-1];
    if(abs(mx-mn)<=1){
        printf("%d\n",n);
        for(int i = 0;i<n;i++) {
            printf("%d ",ar[i]);
        }
        printf("\n");
        return 0;
    }
    int mark[5] ={0};
    for(int i = 0;i<n;i++){
        if(ar[i]==mn) mark[0]++;
        else if(ar[i]==mx) mark[2]++;
        else mark[1]++;
        mp[ar[i]]++;
    }
    while(mark[0]&&mark[2]){
        mark[0]--;
        mark[2]--;
        mark[1]+=2;
    }
    int other = mn+1;
    while(mark[0]--) v[0].pb(mn);
    while(mark[1]--) v[0].pb(other);
    while(mark[2]--) v[0].pb(mx);
    sort(ALL(v[0]));
    int c = 0;
    set<int> st;
    for(int it : v[0]) st.insert(it),mp1[it]++;
    for(auto it : st){
        c+=min(mp1[it],mp[it]);
    }
    printf("%d\n",c);
    for(auto it : v[0]) {
        printf("%d ",it);
    }


//    mark[5] ={0};
//    for(int i = 0;i<n;i++){
//        if(ar[i]==mn) mark[0]++;
//        else if(ar[i]==mx) mark[2]++;
//        else mark[1]++;
//    }
//    while(1) {
//        mark[0]--;
//        mark[2]--;
//        mar
//    }


    return 0;
}
