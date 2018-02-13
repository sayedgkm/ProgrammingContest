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
struct matrix{
  ll mat[2][2];
}base,ans;
matrix mul(matrix a,matrix b){
     matrix c;
    for(int i=0;i<2;i++)
     for(int j=0;j<2;j++){
         c.mat[i][j]=0;
         for(int k=0;k<2;k++)
              c.mat[i][j]=(c.mat[i][j]+(a.mat[i][k]%M*b.mat[k][j]%M)%M)%M;
     }
     return c;
}
matrix bigmod(ll n){
     if(n==1) return base;
     if(n%2==0){
        matrix ret=bigmod(n/2);
        return mul(ret,ret);
     } else  {
        matrix ret=bigmod(n-1);
        return mul(base,ret);
     }

}
int main(){
     // freopen("out.txt","w",stdout);
  ll x,n,a,b;
  cin>>a>>b>>n>>x;
   base.mat[0][0]=a;  base.mat[0][1]=b;
   base.mat[1][0]=0;  base.mat[1][1]=1;
  matrix ans=bigmod(n);
  cout<<(ans.mat[0][0]*x+ans.mat[0][1])%M<<endl;
return 0;
}