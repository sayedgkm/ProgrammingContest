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
#define        N                               600010
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
 char x[N];
 class node{
public:
 bool endmark;
 node *ar[3];
 node(){
  endmark = false;
  for (int i = 0; i < 3; i++) ar[i] = NULL;
    }
};
node *root;
void Insert(string word){

 int len = word.length();
 node *current =root;
 for (int i = 0; i < len; i++){
  int ascii = word[i] - 'a';
         if (current->ar[ascii] == NULL)
    current->ar[ascii] = new node();
     current= current->ar[ascii];
   }
 current->endmark = true;
}
string s;
bool Search(node *current,int pos,int skip){
     if(pos==s.length()){
        if(skip==1){

           return current->endmark;
        }
        return false;
     }
     bool ans=false;
     int ascii=s[pos]-'a';
 for (int i = 0; i < 3; i++){
  if(current->ar[i]!=NULL){
          if(ascii==i)
            ans=ans|Search(current->ar[i],pos+1,skip);
            else if(skip==0)
              ans=ans|Search(current->ar[i],pos+1,skip+1);
  }
 }
 return ans;
}

int main(){
     //freopen("out.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
   root=new node();
   int n=nxt();
   int m=nxt();

   while(n--){
     scanf("%s",x);
     s=x;
     Insert(s);

   }
   while(m--){
      scanf("%s",x);
        s=x;
     if(Search(root,0,0)) puts("YES");
     else puts("NO");
   }

return 0;
}