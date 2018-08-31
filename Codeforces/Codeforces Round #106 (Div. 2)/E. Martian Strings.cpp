 /// Bismillahir-Rahmanir-Rahim
#include <bits/stdc++.h>
#define        ll                              long long int
#define        FOR(x,y,z)                      for(int x=y;x<z;x++)
#define        pii                             pair<int,int>
#define        pll                             pair<ll,ll>
#define        CLR(a)                          memset(a,0,sizeof(a))
#define        SET(a)                          memset(a,-1,sizeof(a))
#define        N                               100110
#define        M                               1000000007
#define        pi                              acos(-1.0)
#define        ff                              first
#define        ss                              second
#define        pb                              push_back
#define        inf                              (1e9)+1000
#define        eps                             1e-9
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
#ifdef sayed
     #define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template < typename Arg1 >
    void __f(const char* name, Arg1&& arg1){
        cerr << name << " is " << arg1 << std::endl;
    }
    template < typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names+1, ',');
        cerr.write(names, comma - names) << " is " << arg1 <<" | ";
        __f(comma+1, args...);
    }
#else
    #define debug(...)
#endif
///******************************************START******************************************
const long long MOD[] = {1000000007LL, 2117566807LL,1000000007LL,1000000037LL};
const long long BASE[] = {1572872831LL, 1971536491LL,1000003LL,31};
class stringhash{
    public:
    ll base,mod,len,ar[N],P[N];

   void GenerateFH(string &s,ll b,ll m){
          base=b;
          mod=m;  len=s.length();
          P[0]=1; long long h=0;
          for(int i=1;i<=len;i++) P[i]=((ll)P[i-1]*(ll)base)%mod;
          for(int i=0;i<len;i++){
              h=(h*base)+s[i];
              h%=mod;
              ar[i]=h;
          }
   }
   int Fhash(int x,int y){
        ll h=ar[y];
       if(x>0){
         h=(h-(ll)P[y-x+1]*(ll)ar[x-1])%mod;
         if(h<0) h+=mod;
       }
       return h;
   }

   void GenerateRH(string s,ll b,ll m){
          base=b;
          mod=m;  len=s.length();
          P[0]=1; ll h=0;
          for(int i=1;i<=len;i++) P[i]=((ll)P[i-1]*(ll)base)%mod;
          for(int i=len-1;i>=0;i--){
              h=(h*base)+s[i];
              h%=mod;
              ar[i]=h;
          }
   }
   ll Rhash(int x,int y){
        long long h=ar[x];
       if(y<len-1){
         h=(h-(ll)P[y-x+1]*(ll)ar[y+1])%mod;
         if(h<0) h+=mod;
       }
       return h;
   }


};
stringhash s1,s2;
int ar[N];
string s,t;
int prefix[1005];
void Generate_prefix() {
    int i= 1,j=0;
    prefix[0] = 0;
    while(i<t.length()) {
        if(t[i]==t[j]) prefix[i]= j+1,i++,j++;
        else {
            while(j&&t[j]!=t[i]) j = prefix[j-1];
            if(t[j]==t[i]) prefix[i]= j+1,i++,j++;
            else prefix[i] = 0,i++;
        }
    }
}
bool ok(int m) {
    CLR(ar);
    int n =s.length();
    Generate_prefix();
    int i = 0;int j = 0;
    while(i<s.length()) {
        if(t[j]==s[i]) i++,j++;
        else {
            while(j&&t[j]!=s[i]) j = prefix[j-1];
            if(t[j]==s[i]) i++,j++;
            else i++;
        }
        if(j==t.length()) return true;
        ar[i] = j;

    }
    for(int i = 1;i<n;i++) ar[i] = max(ar[i],ar[i-1]);
    CLR(prefix);
    prefix[m-1]=m-1;
     i = m-2;
     j = m-1;
    while(i>=0) {
        while(j<m-1&&t[i]!=t[j]) j = prefix[j+1];
        if(t[j]==t[i]) prefix[i]= j-1,i--,j--;
        else prefix[i] = m-1,i--;
    }
    i = n-1;
    j = m-1;
    while(i>=0) {
        if(j<ar[i]) return true;
        while(j<m-1&&s[i]!=t[j]) j = prefix[j+1];
        if(s[i]==t[j]) i--,j--;
        else i--;
        if(i<0) return false;


    }
    return false;
}
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>s;
    s1.GenerateFH(s,BASE[0],MOD[0]);
    int q;
    cin>>q;
    int cnt = 0;
    for(int i = 0;i<q;i++){
        cin>>t;
        if(t.length()==1) continue;
        s2.GenerateFH(t,BASE[0],MOD[0]);
        if(ok(t.length())) cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}
