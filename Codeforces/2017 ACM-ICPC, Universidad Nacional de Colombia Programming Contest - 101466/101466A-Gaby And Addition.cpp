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
#define        N                               1000100
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
inline ll lxt(){ll aaa;scanf("%lld",&aaa);return aaa;}
inline double dxt(){double aaa;scanf("%lf",&aaa);return aaa;}
template <class T> inline T bigmod(T p,T e,T m){T ret = 1;
for(; e > 0; e >>= 1){
    if(e & 1) ret = (ret * p) % m;p = (p * p) % m;
} return (T)ret;}
///******************************************START******************************************
int ar[N];

class node{
public:
 bool endmark;
 node *ar[11];
 node(){
  endmark = false;
  for (int i = 0; i < 11; i++) ar[i] = NULL;
    }
};
node *root;
void Insert(string word){
 int len = word.length();
 node *current =root;
 for (int i = 0; i < len; i++){
  int ascii = word[i] - 48;
         if (current->ar[ascii] == NULL){
    current->ar[ascii] = new node();
         }
     current= current->ar[ascii];
   }

}
ll  qmx(string word){

 int len = word.length();
 node *current = root;
 ll ans=0;
 for (int i = 0; i < len; i++){
  int ascii = word[i] - 48;
   ll mx=0;
   bool f=0;
   for(int j=0;j<=9;j++){
             if(current->ar[j]!=NULL){
                     f=1;
                  mx =max(mx,(ll)(ascii+j)%10);
             }
   }
   if(!f) return -5;
      for(int j=0;j<=9;j++){
           if((j+ascii)%10==mx){
                ans*=10;
                ans+=mx;
                current=current->ar[j];
                break;
           }
   }
 }
 return ans;
}
ll  qmn(string word){

 int len = word.length();
 node *current = root;
 ll ans=0;
 for (int i = 0; i < len; i++){
  int ascii = word[i] - 48;
   ll mx=9;
   bool f=0;
   for(int j=0;j<=9;j++){
             if(current->ar[j]!=NULL){
                  f=1;
                  mx =min(mx,(ll)(ascii+j)%10);
             }
   }
   if(!f) return LLONG_MAX;
      for(int j=0;j<=9;j++){
           if((j+ascii)%10==mx){
                ans*=10;
                ans+=mx;
                current=current->ar[j];
                break;
           }
   }
 }
 return ans;
}
string s[N];
int main(){
    #ifdef sayed
     // freopen("in.txt","r",stdin);
     //freopen("out.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);
   cin.tie(0);
    //cout<<LLONG_MAX<<endl;
    root =new node();
   int n;
 //  Insert("1");
   cin>>n;
   int m =0;
   FOR(i,0,n) {
      cin>>s[i];
      m =max(m,(int)s[i].size());
   }
     FOR(i,0,n){
        if(s[i].size()<m){
             reverse(ALL(s[i]));
              while(s[i].size()<m) s[i]+='0';
              reverse(ALL(s[i]));
        }

     }
     ll mx =0;
     ll mn = LLONG_MAX;
     string temp;
     FOR(i,0,m){
       temp+='0';
     }
   //  Insert(temp);
   //  Insert("11");

     FOR(i,0,n){
         mx = max(mx,qmx(s[i]));
          // cout<<"b"<<endl;
         mn = min(qmn(s[i]),mn);
         Insert(s[i]);
     }
    //  cout<<qmn("99")<<endl;
    cout<<mn<<" "<<mx<<endl;
return 0;
}