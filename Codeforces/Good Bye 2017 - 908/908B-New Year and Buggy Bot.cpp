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
char s[55][55];
vector<char> v[100];
int sx,sy,ex,ey;
string st;
int n,m;
bool go(int x) {
    int tx = sx;
    int ty = sy;
    for(int i = 0;i<st.length();i++) {
        if(v[x][st[i]-'0']=='R'){
            tx++;
        }
        if(v[x][st[i]-'0']=='L'){
            tx--;
        }
         if(v[x][st[i]-'0']=='U'){
            ty++;
        }
         if(v[x][st[i]-'0']=='D'){
            ty--;
        }
        if(tx<0||ty<0||tx>=n||ty>=m) return 0 ;
        if(s[tx][ty]=='#') return 0;
        if(s[tx][ty]=='E') return 1;
    }
    return 0 ;


}
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
      char tmp[]={'D','L','R','U'};
    int x = 0;
     do {
        v[x].pb(tmp[0]);
        v[x].pb(tmp[1]);
        v[x].pb(tmp[2]);
        v[x].pb(tmp[3]);
        x++;
  } while ( next_permutation(tmp,tmp+4) );

     n = nxt();
     m = nxt();
    FOR(i,0,n) scanf("%s",s[i]);
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(s[i][j]=='S'){
                sx = i;
                sy = j;

            }
             if(s[i][j]=='E'){
                ex = i;
                ey = j;

            }
        }
    }
    cin>>st;
    int cnt = 0;
    for(int i = 0;i<x;i++){
        if(go(i)){
           cnt++;
        }
    }
    printf("%d\n",cnt);


    return 0;
}