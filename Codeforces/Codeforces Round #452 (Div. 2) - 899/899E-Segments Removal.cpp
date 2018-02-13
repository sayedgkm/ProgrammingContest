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

struct info {
    int len , start;
    info(int _start,int _len) {
        len = _len;
        start = _start;
    }
    bool operator<( const info& x) const {
        if(x.len==len) {
            return start<x.start;
        } else {
            return len>x.len;
        }
    }
};
set<info> st;
int ar[N],len[N];
set<int> normal;
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    int n = nxt();
    FOR(i,0,n) {
        ar[i] = nxt();
    }
    int s = 0;
    int cnt = 1;
    FOR(i,1,n) {
        if(ar[i]!=ar[i-1]){
            st.insert(info(s,cnt));
            normal.insert(s);
            len[s] = cnt;

            s = i;
            cnt = 1;
        } else {
            cnt++;
        }
    }
    if(cnt) {
        st.insert(info(s,cnt));
         normal.insert(s);
            len[s] = cnt;
    }
    int ans = 0;
    debug(normal.size(),st.size());
    while(st.size()) {
        auto it = st.begin();
        info tmp = *it;
        st.erase(tmp);
        ans++;
        int index = tmp.start;
        if(st.empty()) break;
        if(normal.size()<=2) {
            continue;
        }
        normal.erase(normal.find(index));
        debug(index,(int)st.size(),normal.size());


        int first = *normal.begin();
        int last = *--normal.end();
        if(index>last) continue;
        if(index<=first) continue;

        auto it1 = normal.lower_bound(index);
        auto it2 = it1;
        it2--;

        int b = (*it1);
        int a = (*it2);
            debug(a,b);
            if(ar[a]==ar[b]) {
                normal.erase(it1);
                st.erase(st.find(info(a,len[a])));
                st.erase(st.find(info(b,len[b])));
                len[a]+=len[b];
                st.insert(info(a,len[a]));
            }


    }
    cout<<ans<<endl;
    return 0;
}