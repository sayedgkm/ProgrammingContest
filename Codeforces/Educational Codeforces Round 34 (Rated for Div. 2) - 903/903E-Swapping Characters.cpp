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
int ar[N];
vector<string> v;
map<string ,int> mp;
bool isok() {
    string s = v[0];
    for(int i = 1;i<v.size();i++) {

        int mark[30]={0};
        string t = v[i];
       // debug(s,t);
        vector<int> diff;
        bool f = 0;
        for(int  j = 0;j<t.size();j++) {
            //debug(j);
            if(s[j]!=t[j]) {
                diff.pb(j);
            }
            mark[t[j]-'a']++;
            if(mark[t[j]-'a']>1) f = 1;

        }

        if(diff.size()==0){
            if(f==0) {
                return 0;
            }
        }
        if(diff.size()>2||diff.size()==1) {
            return 0;
        } else if(diff.size()==2)
        if(s[diff[0]]!=t[diff[1]]||s[diff[1]]!=t[diff[0]]) return 0 ;


    }
    return 1;
}
    int mark[N]={0};
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    FOR(i,0,n) {
        string s;
        cin>>s;
        if(mp.count(s)) continue;
        mp[s] =1;
        v.pb(s);
    }
    if(v.size()==1) {
        swap(v[0][0],v[0][1]);
        cout<<v[0]<<endl;
        return 0;
    }
    vector<int> diff;
    bool f= 0;
    for(int i = 1;i<v.size();i++) {
        for(int j = 0;j<m;j++) {
            //debug(j);
            if(v[0][j]!=v[i][j]) {
                if(mark[j]) continue;
                mark[j] = 1;
                diff.pb(j);
            }
            if(diff.size()>5) break;
        }
        if(diff.size()>5)  break;

    }
    debug(diff.size());
    for(int i = 0;i<diff.size();i++) {
        for(int j = 0;j<diff.size();j++) {
            if(i==j) continue;
            swap(v[0][diff[i]],v[0][diff[j]]);
            if(isok()) {
                cout<<v[0]<<endl;
                return 0;
            }
            swap(v[0][diff[i]],v[0][diff[j]]);
        }

    }
        CLR(mark);

        for(int i = 0;i<m;i++) {
            mark[v[0][i]]++;
            if(mark[v[0][i]]>1)  f = 1;
        }
        if(f&&isok()) {
            cout<<v[0]<<endl;
            return 0;
        }

    cout<<-1<<endl;
    return 0;
}