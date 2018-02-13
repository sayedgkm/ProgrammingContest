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
 int n;   string s;
 int dp[N][5][5];
 int path[N][5][5];
 int path2[N][5][5];
ll go(int pos,int mod,int start){
     if(pos>=n){
         if(mod==0&&start) return 0;
         return -inf;
     }
     if(dp[pos][mod][start]!=-1) return dp[pos][mod][start];
   int res=-inf,res1=-inf;
   if(s[pos]!='0'||(s[pos]=='0'&&start))
    res=go(pos+1,(mod*10+s[pos]-48)%3,1)+1;
    res1=go(pos+1,mod,start);
   if(res>res1){
      //  cout<<pos<<" "<<mod<<" "<<start<<endl;
    path[pos][mod][start]=1;
   }
   return dp[pos][mod][start]=max(res,res1);

}
void print(int pos,int mod,int start){
     if(pos>=n) return;
    if(path[pos][mod][start]==1){
       cout<<s[pos];
       print(pos+1,(mod*10+s[pos]-48)%3,1);
       return;
    }
    print(pos+1,mod,start);
    return;
 }
int main()
{
#ifdef sayed
    // freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    SET(dp);
    SET(path);
   cin>>s;
   n=s.length();
   bool z=0;
   FOR(i,0,s.length()) if(s[i]=='0') z=1;
    int x=go(0,0,0);
   if(x<=0) {
      if(z) cout<<0<<endl;
      else cout<<-1<<endl;
      return 0;
   }
    vector<int>v;
  print(0,0,0);

    return 0;
}