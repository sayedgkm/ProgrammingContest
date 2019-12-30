///Bismillahir-Rahmanir-Rahim
#include <bits/stdc++.h>
#define        ll                              long long int
#define        FOR(x,y,z)                      for(int x=y;x<z;x++)
#define        pii                             pair<int,int>
#define        pll                             pair<ll,ll>
#define        CLR(a)                          memset(a,0,sizeof(a))
#define        SET(a)                          memset(a,-1,sizeof(a))
#define        N                               3005
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
int ar[N][N];
ll g[20000000];
vector<int> GetMinimumValues(vector<int> &input,int k) { /// size of window is k
    vector<int> minimums;
    deque<int> dq;
    for(int i = 0;i<input.size();i++) {
        while(dq.size()&&i-dq.front()+1>k) dq.pop_front();
        while(dq.size()&&input[dq.back()]>=input[i]) dq.pop_back();
        dq.push_back(i);
        if(i>=k-1) {
            debug(dq.front());
            minimums.push_back(input[dq.front()]);
        }
    }
    return minimums;
}
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
//    vector<int> temp = {1,2,18};
//
//    auto v = GetMinimumValues(temp,2);

    ll n = lxt();
    ll m = lxt();
    ll a= lxt();
    ll b= lxt();
    g[0] = lxt();
    ll x= lxt();
    ll y = lxt();
    ll z= lxt();

    for(int i = 1;i<20000000;i++) {
        g[i] = (g[i-1]*x + y) %z;
    }
    for(int i = 1;i<=n;i++) {
        for(int j = 1;j<=m;j++) {
            ar[i-1][j-1] = g[((i-1)*m+j-1)];
        }
    }
    vector< vector<int> > answer(n);
    for(int i = 0;i<n;i++) {
        vector<int> v;
        for(int j = 0;j<m;j++){
            v.push_back(ar[i][j]);
        }
        answer[i] = GetMinimumValues(v,b);
    }
    ll sum = 0;
    for(int j = 0;j<answer[0].size();j++) {
        vector<int> v;
        for(int i = 0;i<n;i++) {
            v.push_back(answer[i][j]);
        }
        vector<int> vertical = GetMinimumValues(v,a);
        for(auto it : vertical) {
            debug(it);
            sum+=(ll)it;
        }
    }

    cout<<sum<<endl;
    return 0;
}
