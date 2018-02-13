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
 string s;
 vector<int>v;
 bool go(int i,int j){
     int p[100]={0};
     for(int k=i;k<=j;k++){

        if(s[k]=='?') continue;
        if(p[s[k]]) return false;
        p[s[k]]++;
     }
     for(int k='A';k<='Z';k++) {

        if(p[k]==0) v.pb(k);
     }
    return true;
 }
int main(){
     //freopen("out.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
   cin>>s;
   if(s.size()<26) {
      puts("-1");
      return 0;

   }
   s='0'+s;
    int i,j=1; int f=0;
   for(i=26;i<s.length();i++,j++){
      if(go(j,i)){
            f=1;
         break;
      }

    }
    if(!f) {

        puts("-1");
        return 0;
    }
      int p=0;
    for(int k=j;k<=i;k++){
        if(s[k]=='?'){

             s[k]=v[p];
             p++;
        }

    }
    char c='A';
    for(int k=1;k<s.length();k++)
    {
         if(s[k]=='?') printf("%c",c);
         else
          printf("%c",s[k]);
    }
    puts("");

return 0;
}