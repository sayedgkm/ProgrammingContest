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
 int ar[N];
string s;
 void go1(){

   vector<int>v;
   int x=0;

   for(int i=1;i<s.length();i++){

        if(s[i]=='C'){
            v.pb(x);
            x=0;
            continue;
        }
        x=x*10+s[i]-'0';
        //cout<<x<<endl;

   }
   v.pb(x);
   int p=v[1];
   vector<int> ans;
   while(p){

      ans.pb(p%26);
      p/=26;
      if(ans.back()==0) p--;

   }

   reverse(ans.begin(),ans.end());
  for(int i=0;i<ans.size();i++){
    if(ans[i]==0) printf("Z");
    else printf("%c",64+ans[i]);
  }
      printf("%d\n",v[0]);
 }
 void go2(){
     //puts("b");
       int x=0;
       string temp; int f=0;
     for(int i=0;i<s.length();i++){
            if(s[i]>='0'&&s[i]<='9')
                f=1;
          if(!f){

            temp+=s[i];
          }
     else {
        x=x*10+s[i]-'0';
     }


     }
   int y=0;
   reverse(temp.begin(),temp.end());
     int l=1;
   f(i,0,temp.length()){

      y+=(temp[i]-64)*l;
      l=l*26;
   }
 printf("R%dC%d\n",x,y);
 }
int main(){
     //freopen("out.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);

    int n=nxt();

    while(n--){

        cin>>s;
        if(s[0]=='R'&&s[1]>='0'&&s[1]<='9'){
            for(int i=2;i<s.length();i++){
                if(s[i]=='C'){
                        go1();
                goto xxxx;
                }
            }
            go2();
            xxxx:;
        }
      else go2();

    }

return 0;
}