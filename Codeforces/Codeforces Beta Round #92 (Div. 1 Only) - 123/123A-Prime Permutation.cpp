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
#define        N                               1001010
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
vector<int>primes;
bool mark[N];
void sieve(int n) {
    primes.push_back(2);
    for(int i=3; i*i<=n; i+=2)
     for(int j = i*i; j <= n; j += i * 2)
            mark[j] = 1;
    for (int i = 3; i <= n; i += 2)
        if (!mark[i]) primes.push_back(i);
    }
int ar[50];
set<int> two;
set<int> ::iterator it;
vector<int> other;
char ans[1010];
int main(){
     //freopen("out.txt","w",stdout);
     //freopen("in.txt","r",stdin);
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
   sieve(101100);

   string s;
   cin>>s;
    FOR(i,0,s.length()) ar[s[i]-'a']++;

  for(int i=0;primes[i]<=s.length();i++){
       if(primes[i]*2<=s.length()){
             int p=primes[i];
            for(int j=1; ;j++){
                  if(p*j<=s.length()){
                        two.insert(p*j);
                  } else break;
            }
       } else other.pb(primes[i]);
  }
    int mx=0;
    int temp;
  FOR(i,0,26){
      if(ar[i]>=mx){
         mx=ar[i];
         temp=i;

      }
  }
     bool f=0;
    for(it=two.begin();it!=two.end();it++){
        int pos=*it;
        ans[pos]=temp+'a';
        ar[temp]--;
        if(ar[temp]<0) f=1;
    }
   if(f) {
     puts("NO");
     return 0;
   }
   puts("YES");
   FOR(i,1,s.length()+1){
       if(ans[i]) printf("%c",ans[i]);
       else {

        FOR(j,0,26) {
              if(ar[j]){
                printf("%c",j+'a');
                ar[j]--;
                break;
              }
        }
       }
   }
return 0;
}