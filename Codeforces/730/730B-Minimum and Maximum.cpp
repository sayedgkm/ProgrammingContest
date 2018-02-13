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
#define        eps                              1e-9
using namespace std;
int dx[]={0,0,1,-1,-1,-1,1,1};
int dy[]={1,-1,0,0,-1,1,1,-1};
template < class T> inline T biton(T n,T pos){return n |((T)1<<pos);}
template < class T> inline T bitoff(T n,T pos){return n & ~((T)1<<pos);}
template < class T> inline T ison(T n,T pos){return (bool)(n & ((T)1<<pos));}
template < class T> inline T gcd(T a, T b){while(b){a%=b;swap(a,b);}return a;}
template <typename T> string NumberToString ( T Number ) { ostringstream ss; ss << Number; return ss.str(); }
inline int nxt(){int aaa;scanf("%d",&aaa);return aaa;}
inline ll lxt(){ll aaa;scanf("%I64d",&aaa);return aaa;}
inline double dxt(){double aaa;scanf("%lf",&aaa);return aaa;}
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
vector<int>mx,mn;
void go(int n){
   mx.clear();
   mn.clear(); char c;
  for(int i=1;i<=(n/2)*2;i+=2){
      cout<<"? "<<i<<" "<<i+1<<endl;
      cin>>c;
      if(c=='>'){ mx.pb(i),mn.pb(i+1); }
      else mx.pb(i+1),mn.pb(i);
  }
   if(n%2) {
      cout<<"? "<<mn.back()<<" "<<n<<endl;
      cin>>c;
      if(c=='>'){ mn.pop_back();mn.pb(n); }
      else mx.pb(n);
   }
  int mini,maxi;
  mini=mn[0];
  maxi=mx[0];
   for(int i=1;i<mx.size();i++){
      cout<<"? "<<mx[i]<<" "<<maxi<<endl;
      cin>>c;
      if(c=='>') maxi=mx[i];
   }
   for(int i=1;i<mn.size();i++){
      cout<<"? "<<mn[i]<<" "<<mini<<endl;
      cin>>c;
      if(c=='<') mini=mn[i];
   }
  cout<<"! "<<mini<<" "<<maxi<<endl;
}
int main(){
     //freopen("out.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
   int test;
   cin>>test;
   while(test--){
      char c;
      int n;
      cin>>n;
     if(n==1){
        puts("! 1 1");
     } else if(n==2){
        cout<<"? 1 2"<<endl;
        cin>>c;
        if(c=='>') cout<<"! 2 1\n";
        else cout<<"! 1 2\n";
     } else {
        go(n);
     }


   }

return 0;
}