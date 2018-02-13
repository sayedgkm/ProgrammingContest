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
char c[200];
string s[200]; int n,m;
int get(char a){
   if(a>='0'&&a<='9') return 0;
   else if(a>='a'&&a<='z') return 1;
   else return 2;
}
int dp[100][10];
int go(int pos,int mask){
    //cout<<pos<<" "<<mask<<endl;
     if(pos>n){
         if(__builtin_popcount(mask)==3)
             return 0;
             return inf;
     }
     if(dp[pos][mask]!=-1) return dp[pos][mask];
      int res=inf;
     for(int i=1;i<=m;i++){

      if(ison(mask,0)==0){
        if(get(s[pos][i])==0)
             res=min(res,go(pos+1,biton(mask,0))+min(i-1,m-i+1));
       }
       if(ison(mask,1)==0){
        if(get(s[pos][i])==1)
             res=min(res,go(pos+1,biton(mask,1))+min(i-1,m-i+1));
       }
      if(ison(mask,2)==0){
        if(get(s[pos][i])==2)
             res=min(res,go(pos+1,biton(mask,2))+min(i-1,m-i+1));
       }
       res=min(res,go(pos+1,mask));
     }
    // cout<<res<<endl;
  return dp[pos][mask]=res;
}
int main(){
     //freopen("out.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);

     n=nxt();
      m=nxt(); SET(dp);
   for(int i=1;i<=n;i++){
       scanf("%s",c);
       s[i]=c;
       s[i]='&'+s[i];
       //cout<<s[i]<<endl;
   }
  // cout<<s[1][1]<<endl;
  cout<<go(1,0)<<endl;
return 0;
}