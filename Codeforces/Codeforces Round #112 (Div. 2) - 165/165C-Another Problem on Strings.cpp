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

int main(){
     //freopen("out.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
   int k=nxt();
   string s;
   cin>>s;
   ll cnt=0;
   int left,right; ll ans=0;
   if(!k){

      f(i,0,s.length()) {
         if(s[i]=='1'){

            ans+=(cnt*(cnt+1))/(ll)2;
            cnt=0;
            continue;
         }  else cnt++;
      }
      if(cnt) ans+=(cnt*(cnt+1))/(ll)2;
     cout<<ans<<endl;
     return 0;
   }
   for(int i=0,j=0;i<s.length();i++){
         if(s[i]=='1') cnt++;
          left=0;
          right=0;
          if(cnt>k){
              while(cnt>k){
                if(s[j]=='1') cnt--;
                   j++;
              }


          }
          if(cnt==k){
          //cout<<i<<" "<<j<<endl;
            while(1){

                    i++;
                if(i==s.length()||s[i]=='1'){
                    i--;
                    break;
                }  else right++;
             }
            while(1){

                if(s[j]=='1'){
                    //j--;
                    break;
                }  else left++;
                j++;
             }
            ans+=(ll)(left+1)*(ll)(right+1);

              //cout<<left<<"l "<<right<<endl;
          }


   }
  cout<<ans<<endl;
return 0;
}