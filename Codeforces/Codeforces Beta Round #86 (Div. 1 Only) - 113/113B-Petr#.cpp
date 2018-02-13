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
#define        N                               2010
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
const long long MOD[] = {1000000007LL, 2117566807LL,1000000007LL};
const long long BASE[] = {1572872831LL, 1971536491LL,1000003LL};
class stringhash{
    public:
    ll base,mod,len,ar[N],P[N];

   void GenerateFH(string s,ll b,ll m){
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
stringhash ss[3];
stringhash sst[3];
stringhash sed[3];
int ar[N],n;
 map<ll,int> mp;
int main(){
    #ifdef sayed
     // freopen("in.txt","r",stdin);
     //freopen("out.txt","w",stdout);
    #endif
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
    string s;
    string st,ed;  int ans=0;
   vector<pair<ll,ll > > v;
    cin>>s>>st>>ed;
     ss[0].GenerateFH(s,BASE[0],MOD[0]);
     ss[1].GenerateFH(s,BASE[1],MOD[1]);
     sst[0].GenerateFH(st,BASE[0],MOD[0]);
     sst[1].GenerateFH(st,BASE[1],MOD[1]);
     sed[0].GenerateFH(ed,BASE[0],MOD[0]);
     sed[1].GenerateFH(ed,BASE[1],MOD[1]);

    for(int i=0;i+st.length()-1<s.length();i++){
          if(ss[0].Fhash(i,i+st.length()-1)!=sst[0].Fhash(0,st.length()-1)) continue;
          if(ss[1].Fhash(i,i+st.length()-1)!=sst[1].Fhash(0,st.length()-1)) continue;

        for(int j=i+max(st.length(),ed.length())-ed.length();j+ed.length()-1<s.length();j++){
             // debug(j);
             if(ss[0].Fhash(j,j+ed.length()-1)==sed[0].Fhash(0,ed.length()-1)&&
                 ss[1].Fhash(j,j+ed.length()-1)==sed[1].Fhash(0,ed.length()-1))
                 {

                    ll hs=ss[0].Fhash(i,j+ed.length()-1);
                    ll hs1=ss[1].Fhash(i,j+ed.length()-1);
                    v.pb({hs,hs1});

             }
        }
    }
    sort(ALL(v));
    ans=v.size()?1:0;
    v.resize(unique(ALL(v))-v.begin());
    cout<<v.size()<<endl;

return 0;
}