//==========================================================================
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
#define        N                               100010
#define        M                               1000000007
#define        pi                              acos(-1.0)
#define        ff                              first
#define        ss                              second
#define        pb                              push_back
#define        inf                             (int)1e9
#define        eps                             1e-9
#define        debug(x)                        cerr << #x << " is " << x << endl;
#define        All(x)                          x.begin(),x.end()
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
///******************************************START******************************************
vector<char> v;
string s;

int main(){
     //freopen("out.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);

  cin>>s;int in;int x; int r=0,b=0,y=0,g=0;
  for(int i=0;i<s.length();i++){
     if(s[i]=='R'){
           x=in=i;
          break;
     }
  }
  while(in<s.length()){

      if(s[in]=='!') r++;
      in+=4;
  }
  in=x;
  while(in>=0){

      if(s[in]=='!') r++;
      in-=4;
  }
 for(int i=0;i<s.length();i++){
     if(s[i]=='B'){
           x=in=i;
          break;
     }
  }

  while(in<s.length()){

      if(s[in]=='!') b++;
      in+=4;
  }
  in=x;
  while(in>=0){

      if(s[in]=='!') b++;
      in-=4;
  }
  for(int i=0;i<s.length();i++){
     if(s[i]=='Y'){
           x=in=i;
          break;
     }
  }

  while(in<s.length()){

      if(s[in]=='!') y++;
      in+=4;
  }
  in=x;
  while(in>=0){

      if(s[in]=='!') y++;
      in-=4;
  }
  for(int i=0;i<s.length();i++){
     if(s[i]=='G'){
           x=in=i;
          break;
     }
  }
  while(in<s.length()){

      if(s[in]=='!') g++;
      in+=4;
  }
  in=x;
  while(in>=0){

      if(s[in]=='!') g++;
      in-=4;
  }
  cout<<r<<" "<<b<<" "<<y<<" "<<g<<endl;
return 0;
}