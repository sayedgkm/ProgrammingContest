//==========================================================================
//
//                   Bismillahir-Rahmanir-Rahim
//
// ==========================================================================
#include <bits/stdc++.h>
#define        ll                              long long int
#define        f(x,y,z)                        for(int x=y;x<z;x++)
#define        pii                             pair<int,int>
#define        pll                             pair<ll,ll>
#define        CLR(a)                          memset(a,0,sizeof(a))
#define        SET(a)                          memset(a,-1,sizeof(a))
#define        N                               100010
#define        M                               1000000007
#define        pi                              acos(-1.0)
#define        ff                              first
#define        ss                              second
#define        pb                              push_back
#define        inf                             (int)1e9
using namespace std;
int dx[]={0,0,1,-1,-1,-1,1,1};
int dy[]={1,-1,0,0,-1,1,1,-1};
template < class T> inline T biton(T n,T pos){return n |((T)1<<pos);}
template < class T> inline T bitoff(T n,T pos){return n & ~((T)1<<pos);}
template < class T> inline T on(T n,T pos){return (bool)(n & ((T)1<<pos));}
template < class T> inline T gcd(T a, T b){while(b){a%=b;swap(a,b);}return a;}
template <typename T> string NumberToString ( T Number ) { ostringstream ss; ss << Number; return ss.str(); }
inline int nxt(){int aaa;scanf("%d",&aaa);return aaa;}
inline ll lxt(){ll aaa;scanf("%I64d",&aaa);return aaa;}
template <class T> inline T bigmod(T p,T e,T m){T ret = 1;
for(; e > 0; e >>= 1){
    if(e & 1) ret = (ret * p) % m;p = (p * p) % m;
} return (T)ret;}
#define sayed
#ifdef sayed
     #define debug(args...) {cerr<<"Debug: "; dbg,args; cerr<<endl;}
#else
    #define debug(args...)  // Just strip off all debug tokens
#endif
struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;
///******************************************START******************************************
 void rook(int r1,int c1,int r2,int c2){
    if(r1==r2||c1==c2) printf("1 ");
    else printf("2 ");
 }
 void bishop(int r1,int c1,int r2,int c2){
    int w1=0;
    int w2=0;
    if((r1%2==0&&c1%2==0)|| (r1%2==1&&c1%2==1)) w1=1;
    if((r2%2==0&&c2%2==0)|| (r2%2==1&&c2%2==1)) w2=1;
    if(w1!=w2){
        printf("0 ");
        return ;
    }
    if(abs(r1-r2)==abs(c1-c2)) printf("1 ");
    else printf("2 ");
 }
 void king(int r1,int c1,int r2,int c2){
   printf("%d\n",max(abs(r1-r2),abs(c1-c2)));
 }
int main(){
     //freopen("out.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
   int a=nxt();
   int b=nxt();
   int c=nxt();
   int d=nxt();
   rook(a,b,c,d);
   bishop(a,b,c,d);
   king(a,b,c,d);


return 0;
}