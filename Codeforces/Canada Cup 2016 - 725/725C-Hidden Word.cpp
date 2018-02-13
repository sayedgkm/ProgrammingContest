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
int ar[150];
char grid [5][15];
int main(){
     //freopen("out.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);

   string s;
   cin>>s;
   char c;
   for(int i=0;i<27;i++){
      if(ar[s[i]]==1){
        c=s[i];
        break;
      }
      ar[s[i]]++;
   }
   int x=-1,y=-1;
   for(int i=0;i<27;i++){

       if(s[i]==c){
          if(x==-1) x=i;
          else y=i;
       }

   }

    string s1,s2;
   for(int i=0;i<x;i++) s1+=s[i];
   for(int i=y+1;i<27;i++) s2+=s[i];
   if(y-x-1==0){

    puts("Impossible");
    return 0;
   }
   int diff=y-x-1;
     grid[1][13-diff/2]=c;
      x++;
     for(int i=13-diff/2+1;i<=13;i++){
         grid[1][i]=s[x++];
     }
       int temp=13;
     for(int i=x;i<y;i++){

        grid[2][temp]=s[i];
        temp--;
     }
     //reverse(s2.begin(),s2.end());
     s1=s2+s1;
        x=s1.length()-1;
     for(int i=13-diff/2-1;i>=1;i--){
          grid[1][i]=s1[x--];
     }

     for(int i=1; x>=0;x--){
        grid[2][i++]=s1[x];
     }
     for(int i=1;i<=2;i++){
         for(int j=1;j<=13;j++) printf("%c",grid[i][j]);
         puts("");
     }
return 0;
}