//====================================
//======================================
//
//                   Bismillahir-Rahmanir-Rahim
//
// ==========================================================================
#include <bits/stdc++.h>
#define        ll                              long long int
#define        FOR(x,y,z)                      for(int x=y;x<z;x++)
#define        pii                             pair<char,int>
#define        pll                             pair<ll,ll>
#define        CLR(a)                          memset(a,0,sizeof(a))
#define        SET(a)                          memset(a,-1,sizeof(a))
#define        N                               200010
#define        M                               1000000007
#define        pi                              acos(-1.0)
#define        ff                              first
#define        ss                              second
#define        pb                              push_back
#define        inf                              1e9
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
inline ll lxt(){ll aaa;scanf("%lld",&aaa);return aaa;}
inline double dxt(){double aaa;scanf("%lf",&aaa);return aaa;}
template <class T> inline T bigmod(T p,T e,T m){T ret = 1;
for(; e > 0; e >>= 1){
    if(e & 1) ret = (ret * p) % m;p = (p * p) % m;
} return (T)ret;}
///******************************************START******************************************
int ar[N];
int dp[N];

int main(){
    #ifdef sayed
     //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
   string s;
   cin>>s;
   s= '?'+ s;
   stack<pii>st;
   for(int i = 1;i<s.length();i++) {
       if(s[i]=='('||s[i]=='[') st.push(make_pair(s[i],i));
       else {
           if(s[i]==']') {
               if(!st.empty()&&st.top().ff=='[') {
                  pii x = st.top();
                  st.pop();
                  dp[i]=dp[x.ss-1]+(i-x.ss+1);
                 }
               else
                  st.push(make_pair(s[i],i));

           } else {

              if(!st.empty()&&st.top().ff=='(') {
                  pii x = st.top();
                   st.pop();
                  dp[i]=dp[x.ss-1]+(i-x.ss+1);
                 }
               else
                  st.push(make_pair(s[i],i));

           }

       }

   }
   for(int i =1;i<s.length();i++) {
       ar[i]+=ar[i-1]+(s[i]=='[');
    }
    int mx = 0;
    int sbstr= 0 ;
    int start=-1;
    for(int i =1;i<s.size();i++) {
        if(dp[i]) {
             int x = dp[i];
             if(ar[i]-ar[i-x]>mx) {
                 mx =ar[i]-ar[i-x];
                 start = i-x+1;
                 sbstr = x;
             }
        }
    }
    printf("%d\n",mx);
    for(int i = start,j=0;j<sbstr;i++,j++) printf("%c",s[i]);
    printf("\n");


return 0;
}