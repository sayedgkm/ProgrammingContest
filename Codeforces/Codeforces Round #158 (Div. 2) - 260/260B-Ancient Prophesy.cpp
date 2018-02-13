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
 map<string,int>mp;
 map<string,int>:: iterator it;
 int ar[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
 string s;
 void go(int x ){
     int check=1;
     int date=0;
     int month=0;
     int year=0;
     int i;
   for( i=x;check<=2;i++,check++){
       if(s[i]>='0'&&s[i]<='9'){
          date=date*10+s[i]-'0';
       } else return ;
    }
    if(s[i]!='-') {
       return;
    } else  {
       i++;
       check++;
    }
    for(;check<=5;i++,check++){
       if(s[i]>='0'&&s[i]<='9'){
          month=month*10+s[i]-'0';
       } else return ;
    }
    if(s[i]!='-') {
       return;
    } else  {
       i++;
       check++;
    }
    for(;check<=10;i++,check++){
       if(s[i]>='0'&&s[i]<='9'){
          year=year*10+s[i]-'0';
       } else return ;
    }
   // cout<<date<<" "<<year<<" "<<month<<endl;
   if(year>2015||year<2013) return ;
   if(month>12||month<1) return;
   if(ar[month]<date||date<1) return;
   string s;
   if(date<=9) s+='0';
   s+=NumberToString(date)+'-';
   if(month<=9) s+='0';
   s+=NumberToString(month)+'-'+NumberToString(year);
   mp[s]++;


 }
int main(){
     //freopen("out.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);

   cin>>s;
   for(int j=0,i=0;i<s.length()-9;i++,j++){
         go(j);
    }
    int mx=0;
  for(it=mp.begin();it!=mp.end();it++){
    mx=max(it->ss,mx);
  }
  for(it=mp.begin();it!=mp.end();it++){
     if(it->ss==mx) {
        cout<<it->ff<<endl;
        return 0;
     }
  }



return 0;
}