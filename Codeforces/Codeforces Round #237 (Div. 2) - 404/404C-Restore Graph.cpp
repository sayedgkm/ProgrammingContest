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

pii ar[N];
int deg[N];
vector<pii> v;
int main(){
     // freopen("out.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
   // cin.tie(0);
   int n=nxt(); int k=nxt();
   f(i,1,n+1) {
        ar[i].ff=nxt();
        ar[i].ss=i;
   }
   if(n==1){
    puts("0");
    return 0;
   }
   sort(ar+1,ar+n+1);
   if(ar[1].ff!=0||(ar[1].ff==0&&ar[2].ff==0)){
    puts("-1");
    return 0;
   }

   queue<int> q,q1,q2;
   q.push(ar[1].ss);
   int flag=0;
   for(int i=2;i<=n;i++){
        if(ar[i].ff-ar[i-1].ff!=1){
            puts("-1");
            return 0;
        }
      while(ar[i].ff==ar[i+1].ff){
            q1.push(ar[i].ss);
          i++;
      }
      q1.push(ar[i].ss);
      q2=q1;
      while(!q1.empty()){
         int x=q1.front();
         q1.pop();int y;
         while(1){
            if(q.empty()){
                puts("-1");return 0;
            }
              y=q.front();
            if(deg[y]<k) break;
            else q.pop();
         }
         v.pb(pii(y,x));deg[x]++,deg[y]++;
      }
      q=q2;

   }
   cout<<v.size()<<endl;
   for(auto it:v) printf("%d %d\n",it.ff,it.ss);

return 0;
}