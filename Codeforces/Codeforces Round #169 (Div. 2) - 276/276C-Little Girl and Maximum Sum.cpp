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
#define        N                               200010
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

int ar[N];
int tree[N];
void update(int idx,int n,int x)
{
    while(idx<=n)
    {
        tree[idx]+=x;
        idx+= idx&(-idx);
    }
}
int query(int idx){
     int sum=0;
     while(idx>0)
     {
         sum+=tree[idx];idx-=idx&(-idx);
     }
   return sum;
}
vector<int> v;
int main(){
     //freopen("out.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
   int n=nxt();
   int m=nxt();
   int mx=0;
   f(i,1,n+1)
   {
      ar[i]=nxt();
      mx=max(mx,ar[i]);
   }
    sort(ar+1,ar+n+1);
    for(int i=0;i<m;i++){
        int a=nxt();
        int b=nxt();
        update(a,n,1);
        update(b+1,n,-1);
    }
    for(int i=1;i<=n;i++) v.pb(query(i));
    v.pb(inf);
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    reverse(ar+1,ar+n+1);
    ll res=0;
    for(int i=1;i<=n;i++){
       res+=(ll)ar[i]*(ll)v[i];
    }
       printf("%I64d\n",res);
return 0;
}