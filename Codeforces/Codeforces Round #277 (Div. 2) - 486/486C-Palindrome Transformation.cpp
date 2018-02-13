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
int go(char a,char b){
    int temp=max(a,b);
    a=min(a,b);
    b=temp;
  int x=abs(a-b);
  int y=abs(a-'a'+('z'-b))+1;
  return min(x,y);
}

int main(){
     //freopen("out.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
   int n,p;
   cin>>n>>p;
   string s;
   cin>>s;
   s='a'+s;
   int res=0;
   for(int i=1;i<=n/2;i++){
     res+=go(s[i],s[n-i+1]);
    }
    int temp=n/2;
     int x,y;
    if(p<=temp){
            x=y=p;
        for(int i=p;i>=1;i--)
            if(go(s[i],s[n-i+1])!=0) x=i;
         for(int i=p;i<=temp;i++)
            if(go(s[i],s[n-i+1])!=0) y=i;
    } else  {
          x=y=p;
         for(int i=p;i>temp;i--)
                 if(go(s[i],s[n-i+1])!=0) x=i;
         for(int i=p;i<=n;i++)
            if(go(s[i],s[n-i+1])!=0) y=i;
    }
    res+=min(abs(p-x),abs(p-y))+abs(x-y);
    cout<<res<<endl;

return 0;
}