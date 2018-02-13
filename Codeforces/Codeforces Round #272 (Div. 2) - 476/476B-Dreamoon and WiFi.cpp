//==========================================================================
//
//                   Bismillahir-Rahmanir-Rahim
//
// ==========================================================================
#include <bits/stdc++.h>
#define        ll                              long long
#define        f(x,y,z)                        for(int x=y;x<z;x++)
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
inline int lxt(){ll aaa;scanf("%lld",&aaa);return aaa;}
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
ll fact[15];
ll ncr(ll n,ll r){
   ll temp=fact[n-r]*fact[r];
   temp=fact[n]/temp;
   return temp;
}
int main(){
     // freopen("out.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
   // cin.tie(0);
   fact[0]=fact[1]=1;
   for(int i=2;i<=11;i++) fact[i]=fact[i-1]*(ll)i;
   string s1,s2;
   cin>>s1>>s2;
   int pos1=0;
   f(i,0,s1.length())
     pos1=pos1+(s1[i]=='+'?1:-1);
    int q=0,pos2=0;
    f(i,0,s2.length()){
       if(s2[i]=='?') q++;
       else {
        pos2+=(s2[i]=='+'?1:-1);
       }
    }
    int dist=pos1-pos2;
    if((q+abs(dist))%2!=0||q<abs(dist)) {
        puts("0.000000000");
        return 0;
    }
    int Plus=0;
    int temp=q;
 if(dist>=0){
    Plus+=dist;
    q-=dist;
    Plus+=q/2;
 } else  {
    q-=abs(dist);
    Plus+=q/2;
}
 double ans=(double)ncr(temp,Plus)/(double)(1<<temp);
 printf("%0.9lf\n",ans);

return 0;
}