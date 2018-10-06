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
int ar[N];
vector<int> v;
vector<pii> edge;
int cnt[N];
int mark[N];
set<int> st;
int get(int x) {
    for(int i = x-1;i>=1;i--) {
        if(st.find(i)==st.end()&&!mark[i]) {
            mark[i] = 1;
            return i;
        }
    }
    return -1;
}
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    int n = nxt();
    for(int i = 1;i<n;i++) {
        int a= nxt();
        int b= nxt();
        if(a>b) swap(a,b);
        if(b!=n) {
            cout<<"NO"<<endl;
            return 0;
        }
        if(a==b&&b==n){
            cout<<"NO"<<endl;
            return 0;
        }
        st.insert(a);
        cnt[a]++;
        if(cnt[a]==0)
            v.pb(a);
    }
    for(int i = n-1;i>=1;i--) {
        vector<int> ok;
        if(cnt[i]) {
            ok.pb(i);
            cnt[i]--;
            while(cnt[i]--) {
                int val = get(i);
                if(val==-1) {
                    printf("NO\n");
                    return 0;
                }
                ok.pb(val);
            }
            sort(ALL(ok));
            for(int i = 1;i<ok.size();i++) {
                edge.pb(make_pair(ok[i],ok[i-1]));
            }
            edge.pb(make_pair(n,ok[0]));
        }

    }
    if(edge.size()!=n-1){
        printf("NO\n");
            return 0;
    }
    printf("YES\n");
    for(auto it : edge) {
        printf("%d %d\n",it.ff,it.ss);
    }

    return 0;
}
