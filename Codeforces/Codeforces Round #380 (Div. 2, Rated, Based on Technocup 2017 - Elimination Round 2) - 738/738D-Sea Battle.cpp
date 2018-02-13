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
vector<int>v;
int main(){
     //freopen("out.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
   int n=nxt(),a=nxt(),b=nxt();
   int k=nxt();

   string s;
   cin>>s;
   int j=0; int c=0;
   for(int i=0;i<n;i++){
        if(s[i]=='0') c++;
     if(c==b&&a){
        int j=i;
        while(c){
            s[j]='?';
            c--;
            j--;
        }
        a--;
     }
     if(s[i]=='1') c=0;
   }
   c=0;
   for(int i=s.length()-1;i>=0;i--){
        if(s[i]=='?'){
            c++;
        }

        if(c==b){
            j=i;
            while(c){

                s[j]='0';
                j++;
                c--;
            }
            break;
        }

   }
   //cout<<s<<endl;
         c=0;
  for(int i=0;i<n;i++){
       if(s[i]=='0') c++;
       else c=0;
       if(c==b) v.pb(i+1);
       if(c==b) c=0;
  }
    printf("%d\n",v.size());
    for(int i=0;i<v.size();i++){
        if(i) printf(" ");
        printf("%d",v[i]);
    }

return 0;
}