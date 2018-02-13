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
#define        pia                              acos(-1.0)
#define        ff                              first
#define        ss                              second
#define        pb                              push_back
#define        inf                             (int)1e9
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
int ar[N];

int main(){
     //freopen("out.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
   int n=nxt();
   for(int i=0;i<n;i++) ar[i]=nxt();
   if(n==1) {
    puts("-1");
    return 0;
   }
   sort(ar,ar+n);
   set<int>ans;
    if(n==2){

        int diff=ar[1]-ar[0];

        ans.insert(ar[0]-diff);
        if(!(diff%2)) ans.insert(ar[0]+diff/2);
        ans.insert(ar[1]+diff);
        cout<<ans.size()<<endl;
        for(auto it : ans)
             printf("%d ",it);
        return 0;
    }
    set<int>st;
    f(i,1,n) st.insert(ar[i]-ar[i-1]);
    if(st.size()>2) {
        puts("0");
        return 0;
    }
   if(st.size()==1) {
      int x=*st.begin();
      ans.insert(ar[0]-x);
      ans.insert(ar[n-1]+x);
   } else  {
       int x=*st.begin();
       int y=*--st.end();
        int c=0;
    for(int i=1;i<n;i++)  if(ar[i]-ar[i-1]==y) c++;
        if(c>1){ puts("0"); return 0;}
     if(x*2==y) {
        for(int i=1;i<n;i++) if(ar[i]-ar[i-1]==y) {
            ans.insert(ar[i-1]+y/2);
            break;
        }
     }
   }
  cout<<ans.size()<<endl;
        for(auto it : ans)
             printf("%d ",it);
return 0;
}