
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
string ss;
ll dp[20][2][205][205];
int a, b;
ll go(int pos,int isSmall, int f, int s){
     if(pos<0){
        return f%b==s%a;
     }
   if(dp[pos][isSmall][f][s]!=-1&& isSmall) return dp[pos][isSmall][f][s];
   ll res=0;
   int limit=isSmall?9:ss[pos]-'0';
   for(int i=0;i<=limit;i++){
        res+=go(pos-1,isSmall|i<(ss[pos]-'0'), ((f*10) + i)%a, (s*10+i)%b);
   }
  return  dp[pos][isSmall][f][s]=res;
}

int main(){
    #ifdef sayed
    freopen("out.txt","w",stdout);
    //freopen("in.txt","r",stdin);
    #endif
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);

    int test = nxt();
    while(test--)  {
        a = nxt();
        b= nxt();
        int q = nxt();
        if(b<a) swap(a,b);
        SET(dp);
        bool f = 0;
        while(q--) {
            ll  x = lxt();
            ll  y = lxt();
            ss = to_string(y);
            reverse(ALL(ss));
            ll ans = go((int)ss.size()-1, 0, 0, 0);
            x--;
            ss = to_string(x);
            reverse(ALL(ss));
            ans-=go((int)ss.size()-1,0,0,0);


            if(f) printf(" ");
             f= 1;

            printf("%lld",(y-x)-ans);

        }
        printf("\n");

    }


     return 0;
}

