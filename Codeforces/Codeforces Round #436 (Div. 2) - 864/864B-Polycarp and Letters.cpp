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
#define        inf                              1e9
#define        eps                             1e-9
#define        debug(x)                        cerr << #x << " is " << x << endl;
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
///******************************************START******************************************
int ar[N];
string s;
     int n;
     bool issmall(char a) {
        if(a>='a'&&a<='z') return true;
        return false;
     }
int go() {
   int mx = 0;
  FOR(i,0,n) {
      int mark[300] = {0};
      int j = i;
      int c = 0;
      while(j<n&&issmall(s[j])){
            if(mark[s[j]]==0) c++;
            mark[s[j]]= 1;
            j++;
      }
      mx = max(mx,c);

  }
  return mx;

}
int main(){
    #ifdef sayed
     //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);

     cin>>n;

     cin>>s;
     int b = 0;
     int e = s.size();
    cout<<go()<<endl;

return 0;
}