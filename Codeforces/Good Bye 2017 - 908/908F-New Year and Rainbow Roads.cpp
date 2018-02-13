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
        cerr.write(names, comma - names) << " is " << arg1 <<endl;
        __f(comma+1, args...);
    }
#else
    #define debug(...)
#endif
///******************************************START******************************************
int ar[N];
int mark[N];
ll ans[N];
vector<pii> v;
vector<pii> go(int x) {
    vector<pii> res;
    for(int i = 0;i<v.size();i++) {
        if(v[i].ss==1) res.pb(v[i]);
        if(v[i].ss==x) res.pb(v[i]);
    }
    return res;
}
void get(vector<pii> gr,int x) {
     int last = -1;
     CLR(mark);
    for(int i = gr.size()-1;i>=0;i--) {
        if(gr[i].ss==1) {
            mark[i] = last;
            last = i;
        }
    }
    if(x) {
        while(1) {
            if(last==-1||mark[last]==-1) return ;
            int r= 0,b = 0;
            for(int i = last+1;i<mark[last];i++) {
                if(gr[i].ss==2) r = 1;
                if(gr[i].ss==3) b = 1;
            }
            if(r&&b) ans [mark[last]] = min(ans[mark[last]],(ll)2*(gr[mark[last]].ff-gr[last].ff));
            else if(r||b) ans [mark[last]] = min(ans[mark[last]],(ll)(gr[mark[last]].ff-gr[last].ff));
            last = mark[last];

        }

        return ;
    }
    if(last==-1) {
        ans[0]+=gr.back().ff-gr[0].ff;
        return;
    }

    ans[last]+=gr[last].ff - gr[0].ff;

    while(1) {
        if(mark[last]==-1) {
            ans[last+1]+=gr.back().ff-gr[last].ff;
            break;
        }
        ll mn = (ll)1e17;
        for(int i = last+1;i<=mark[last];i++)
            mn = min(mn,(ll)(gr[mark[last]].ff-gr[i].ff)+(gr[i-1].ff-gr[last].ff));
        if(mn<(ll)1e17)
            ans[mark[last]]+=mn;
        last = mark[last];

    }


}
vector<int> g;
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    ar['G'] = 1;
    ar['R'] = 2;
    ar['B'] = 3;
    int n = nxt();
    for(int i = 0;i<n;i++) {
        int a = nxt();
        char c[2];
        scanf("%s",c);
        if(c[0]=='G') g.pb(i);
        v.pb(make_pair(a,ar[c[0]]));
    }
    ll res = 0;
    for(int i = 1;i<g.size();i++) {
        ll ans = (ll)1e17;
        int last= g[i-1];
        int b = 0;
        int r = 0;
        for(int j = g[i-1]+1;j<=g[i];j++) {
            if(v[j].ss==2||v[j].ss==1) {
                ans = min(ans,(ll)(v[last].ff-v[g[i-1]].ff)+(ll)(v[g[i]].ff-v[j].ff));
                last = j;
                r = 1;
            }
        }
        ll ans1 = (ll)1e17;
        last= g[i-1];
         for(int j = g[i-1]+1;j<=g[i];j++) {
            if(v[j].ss==3||v[j].ss==1) {
                ans1 = min(ans1,(ll)(v[last].ff-v[g[i-1]].ff)+(ll)(v[g[i]].ff-v[j].ff));
                last = j;
                b = 1;
            }
        }
        debug(ans,ans1);
        ans+=ans1;
        if(ans>=(ll)1e17) ans = 0;
        ans +=v[g[i]].ff-v[g[i-1]].ff;
        if(r&&b) ans = min(ans,(ll)2*(v[g[i]].ff-v[g[i-1]].ff));
        else if(r||b) ans = min(ans,(ll)(v[g[i]].ff-v[g[i-1]].ff));
        res+=ans;
    }
    if(g.empty()) {
        int last  = -1;
        for(int i = 0;i<n;i++) {
            if(v[i].ss==2) {
                if(last!=-1) res+=v[i].ff-last;
                last = v[i].ff;
            }
        }
        last = -1;
        for(int i = 0;i<n;i++) {
            if(v[i].ss==3) {
                if(last!=-1) res+=v[i].ff-last;
                last = v[i].ff;
            }
        }
    } else {

        for(int i = 0;i<g[0];i++) {
            if(v[i].ss==2) {
                res+=v[g[0]].ff-v[i].ff;
                break;
            }
        }
        for(int i = 0;i<g[0];i++) {
            if(v[i].ss==3) {
                res+=v[g[0]].ff-v[i].ff;
                break;
            }
        }

        for(int i = n-1;i>g.back();i--) {
             if(v[i].ss==2) {
                res+=v[i].ff-v[g.back()].ff;
                break;
            }
        }
        for(int i = n-1;i>g.back();i--) {
             if(v[i].ss==3) {
                res+=v[i].ff-v[g.back()].ff;
                break;
            }
        }
    }

    cout<<res<<endl;

    return 0;
}