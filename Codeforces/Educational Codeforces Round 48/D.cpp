 /// Bismillahir-Rahmanir-Rahim
#include <bits/stdc++.h>
#define        ll                              long long int
#define        FOR(x,y,z)                      for(int x=y;x<z;x++)
#define        pii                             pair<int,int>
#define        pll                             pair<ll,ll>
#define        CLR(a)                          memset(a,0,sizeof(a))
#define        SET(a)                          memset(a,-1,sizeof(a))
#define        N                               105
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
int ans[N][N];
int ar[N];
int br[N];
int tmp[N][N];
vector<int> r0;
int n,m;
vector<int> r1,c0,c1;
int build(int x) {

    for(int i =0;i<n;i++) {
        if(ison(ar[i],x)) r1.pb(i);
        else r0.pb(i);
    }
    for(int i =0;i<m;i++) {
        if(ison(br[i],x)) c1.pb(i);
        else c0.pb(i);
    }
    int diff =abs(r1.size()-c1.size());
    if(diff%2==0) {

        if(r1.size()>c1.size()) {
            if(c0.size()==0) return false;
            while(r1.size()!=c1.size()) {
                tmp[r1.back()][c0.back()] = 1;
                r1.pop_back();
            }

        } else {
            if(r0.size()==0) return false;

            while(r1.size()!=c1.size()) {
                tmp[r0.back()][c1.back()] = 1;
                c1.pop_back();
            }

        }


    } else {

        if(r1.size()>c1.size()) {
            if(c1.size()==0) return false;
            while(r1.size()!=c1.size()) {
                tmp[r1.back()][c1.back()] = 1;
                r1.pop_back();
            }

        } else if(c1.size()>r1.size()) {
            if(r1.size()==0) return false;

            while(r1.size()!=c1.size()) {
                tmp[r1.back()][c1.back()] = 1;
                c1.pop_back();
            }

        }


    }

    while(r1.size()) {

        tmp[r1.back()][c1.back()]=1;
        r1.pop_back();
        c1.pop_back();
    }
    for(int i = 0;i<n;i++) {
        for(int j =0;j<m;j++) {
            if(tmp[i][j]) ans[i][j] = biton(ans[i][j],x);
        }
     }
     CLR(tmp);
     return true;
}
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

     n= nxt();
     m = nxt();
    for(int i = 0;i<n;i++) ar[i] = nxt();
    for(int j = 0 ;j<m;j++) br[j] = nxt();
    for(int i =0;i<=30;i++) {
        int res =build(i);
        if(res==0){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    for(int i =0;i<n;i++){
        for(int j = 0;j<m;j++) {
            printf("%d ",ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}
