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
inline ll lxt(){ll aaa;scanf("%I64d",&aaa);return aaa;}
inline double dxt(){double aaa;scanf("%lf",&aaa);return aaa;}
template <class T> inline T bigmod(T p,T e,T m){T ret = 1;
for(; e > 0; e >>= 1){
    if(e & 1) ret = (ret * p) % m;p = (p * p) % m;
} return (T)ret;}
///******************************************START******************************************


int ans[N];
map<string,int> mp;
int main(){
     //freopen("out.txt","w",stdout);
    // freopen("out.txt","r",stdin);
  int n=nxt();
  string s;
  cin>>s;
  int mx=1; int c=1;
  ans[0]=1;
  FOR(i,1,s.length()){
      if(s[i]==s[i-1]) c++;
      else {
        c=1;
      }
      mx=max(c,mx);
      ans[i]=c;
  }
  vector<string> res;
  FOR(i,0,s.length()){
     if(ans[i]==mx){

        int c=mx; int j=i;
        string t;
        while(c) {
            t+=s[j];
     j--;
            c--;
        }
        reverse(ALL(t));
        if(mp[t]==0)  res.pb(t);
        mp[t]=1;
     }
  }
  cout<<res.size()<<endl;
  FOR(i,0,res.size()) cout<<res[i]<<endl;
return 0;
}