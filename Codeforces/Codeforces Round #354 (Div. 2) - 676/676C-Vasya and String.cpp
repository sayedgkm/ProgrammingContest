// ==========================================================================
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

int main()
{
 ///ios_base::sync_with_stdio(0); cin.tie(0);
 /// freopen("out.txt","w",stdout);
 int n, k;
 n = nxt(), k = nxt();
 string s;
 cin >> s;
 int res = 0;
 int temp = k; int c = 0;
 int x = 0, y = 0;
 for (int i = 0; i<s.length(); i++){

  if (s[i] == 'b'){
   if (temp) {
    temp--;
   }
   else {
    while (1){
    if (s[x] =='b'){
     x++;
     break;
    }
    x++;
    }
   }
  }
  res = max(res, i - x + 1);
 }
 x = 0;
 temp = k;
 for (int i = 0; i<s.length(); i++){

  if (s[i] == 'a'){
   if (temp) {
    temp--;
   }
   else {
    while (1){
     if (s[x] == 'a'){
      x++;
      break;
     }
     x++;
    }
   }
  }
  res = max(res, i - x + 1);
 }
 cout << res << endl;

 return 0;
}