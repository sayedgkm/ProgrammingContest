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
vector<int> v[100];
vector<int> queen;
int cnt = 0;
vector<pii> given;
bool isValid(int r,int c) {
    for(int i = 0;i<queen.size();i++) {
        if(r==i||c==queen[i]) return false;
       if(r+c==i+queen[i]) return false;
        if(r-c==i-queen[i]) return false;
    }
    return true;
}
int Move(int r1,int c1,int r2,int c2) {
    if(r1==r2&&c1==c2) return 0;
    if(r1==r2||c1==c2||r1+c1==r2+c2||r1-c1==r2-c2) return 1;
    return 2;
}
void go(int pos){
    if(queen.size()==8) {
        v[cnt] = queen;
        cnt++;
        return;
    }
    for(int i =0;i<8;i++) {
        if(isValid(pos,i)) {
            queen.pb(i);
            go(pos+1);
            queen.pop_back();
        }
    }

}
int dp[9][(1<<9)+2];
int go(int x,int pos,int mask) {
    if(mask==(1<<8)-1){
        return 0;
    }
    int &res = dp[pos][mask];
    if(res!=-1) return res;
    res = inf;
    for(int i =0;i<given.size();i++) {
       if(ison(mask,i)) continue;
       res = min(res,go(x,pos+1,biton(mask,i))+Move(pos,v[x][pos],given[i].ff,given[i].ss));
    }

    return res;
}
int main(){
    #ifdef sayed
    freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    go(0);

    int test = nxt();
    int cs = 1;
    while(test--) {
        char t[8];
        int n = 8;
        for(int i = 0;i<n;i++) {
            scanf("%s",t);
            for(int j = 0;j<8;j++) {
                if(t[j]=='q') given.pb(make_pair(i,j));
            }
        }
//        printf("\n");
//        for(int i = 0;i<8;i++) {
//            for(int j = 0;j<8;j++) {
//                if(v[11][i]==j) printf("q");
//               else printf(".");
//            }
//            printf("\n");
//        }
        int res = inf;
        for(int i =0;i<cnt;i++) {
            SET(dp);
            res = min(res,go(i,0,0));
        }
        printf("Case %d: %d\n",cs++,res);


        given.clear();
    }

    return 0;
}
