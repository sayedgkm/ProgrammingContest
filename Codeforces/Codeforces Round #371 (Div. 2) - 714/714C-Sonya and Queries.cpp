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

 map<string,int> mp;
string go(string s){
   string res;
   reverse(s.begin(),s.end());
   f(i,0,s.length()) {
      if((s[i]-48)%2==0) res+='0';
      else res+='1';
   }
   while(res.size()<=18) res+='0';
   return res;

}
class node{
public:
 bool endmark;
 node *ar[3];
 int cnt;
 node(){
  endmark = false;
  cnt=0;
  for (int i = 0; i < 3; i++){
                ar[i] = NULL;

  }
    }
};
node *root;
void Insert(string word,int q){

 int len = word.length();
 node *current =root;
 for (int i = 0; i < len; i++){
  int ascii = word[i] -48;
         if (current->ar[ascii] == NULL)
    current->ar[ascii] = new node();
     current= current->ar[ascii];
     if(q==1) current->cnt++;
     else current->cnt--;
   }
 current->endmark = true;
}
int query(string word){
    int mx=inf;
  int len = word.length();
 node *current =root;
 for (int i = 0; i < len; i++){
        int ascii = word[i] -48;
        if(current->ar[ascii] == NULL) return 0;
          current= current->ar[ascii];
     mx=min(mx,current->cnt);
   }
 return mx;
}
int main(){
     //freopen("out.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
   root=new node();
  int n=nxt();
  char s[5];
  char q[20];
  string x;
  while(n--){
    scanf("%s",s);
    scanf("%s",q);
    x=q;
    if(s[0]=='+'){
       Insert(go(x),1);
    } else if(s[0]=='-'){
      Insert(go(x),2);
    } else printf("%d\n",query(go(x)));

  }


return 0;
}