//==========================================================================
//
//                   Bismillahir-Rahmanir-Rahim
//
// ==========================================================================
#include <bits/stdc++.h>
#define        ll                              long long int
#define        FOR(x,y,z)                      for(int x=y;x<z;x++)
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
inline ll lxt(){ll aaa;scanf("%I64d",&aaa);return aaa;}
inline double dxt(){double aaa;scanf("%lf",&aaa);return aaa;}
template <class T> inline T bigmod(T p,T e,T m){T ret = 1;
for(; e > 0; e >>= 1){
    if(e & 1) ret = (ret * p) % m;p = (p * p) % m;
} return (T)ret;}
///******************************************START******************************************
const long long MOD[] = {1000000007LL, 2117566807LL};
const long long BASE[] = {1572872831LL, 1971536491LL};
class stringhash{
    public:
    long long base,mod;int len;
    long long ar[N],P[N],rar[N],RP[N];

   void GenerateFH(string s,ll b,ll m){
          base=b;
          mod=m;  len=s.length();
          P[0]=1; long long h=0;
          for(int i=1;i<=len;i++) P[i]=(P[i-1]*base)%mod;
          for(int i=0;i<len;i++){
              h=(h*base)+tolower(s[i]);
              h%=mod;
              ar[i]=h;
          }
   }
   long long Fhash(int x,int y){
        long long h=ar[y];
       if(x>0){
         h=(h-P[y-x+1]*ar[x-1])%mod;
         if(h<0) h+=mod;
       }
       return h;
   }

   void GenerateRH(string s,ll b,ll m){
          base=b;
          mod=m;  len=s.length();
          P[0]=1; long long h=0;
          for(int i=1;i<=len;i++) P[i]=(P[i-1]*base)%mod;
          for(int i=len-1;i>=0;i--){
              h=(h*base)+tolower(s[i]);
              h%=mod;
              ar[i]=h;
          }
   }
   long long Rhash(int x,int y){
        long long h=ar[x];
       if(y<len-1){
         h=(h-P[y-x+1]*ar[y+1])%mod;
         if(h<0) h+=mod;
       }
       return h;
   }


};
stringhash s1,s2;
map<int,int> mp;

 string s; int n;
 int dp[N],path[N];
bool go(int pos){
     if(pos>=n) return true;
     if(dp[pos]!=-1) return dp[pos];
    for(int i=pos;i<n;i++){
          if(mp[s1.Rhash(pos,i)]&&go(i+1)) {
              dp[i]=true;
              path[pos]=i+1;

              return true;
          }
    }
    return dp[pos]=false;
}
string a[N];
int main(){
     //freopen("out.txt","w",stdout);
     //freopen("in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
   cin.tie(0);

    cin>>n;

    cin>>s;
    int q;
    cin>>q;
    FOR(i,1,q+1){
        cin>>a[i];
        s1.GenerateFH(a[i],BASE[0],MOD[0]);
        mp[s1.ar[a[i].length()-1]]=i;
    }
     s1.GenerateRH(s,BASE[0],MOD[0]);
     SET(dp);SET(path);
     go(0);
     int x=0;
      int last=0;
     while(1){
        x=path[x];
          if(x==-1) break;
        ll hs=s1.Rhash(last,x-1);
          //cout<<last<<" "<<x-1<<endl;
        cout<<a[mp[hs]]<<" ";
         last=x;
     }

return 0;
}