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
#define        pi                              acos(-1.0)
#define        ff                              first
#define        ss                              second
#define        pb                              push_back
#define        inf                             (int)1e9
#define NMAX   1000
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

string go(int n){
  string s;
  while(n){
    int p=n%2;
       p=p+'0';
    s+=p;
    n/=2;
  }
 while(s.size()!=30) s+='0';
  reverse(s.begin(),s.end());
  return s;
}
ll go(string s){
  ll p=0;
  for(int i=0;i<s.length();i++) p=(p*2)+(s[i]-48);
  return p;

}
class node{
public:
 bool endmark;
 node *ar[2];
 int cnt[2];
 node(){
  endmark = false;
  for (int i = 0; i < 2; i++){
                ar[i] = NULL;
                cnt[i]=0;
  }
    }
};
node *root;
void Insert(string word){

 int len = word.length();
 node *current =root;
 for (int i = 0; i < len; i++){
  int ascii = word[i] - '0';
         if (current->ar[ascii] == NULL)
    current->ar[ascii] = new node();
    current->cnt[ascii]++;
     current= current->ar[ascii];
   }
 current->endmark = true;
}
void del(string word){

 int len = word.length();
 node *current = root;
 for (int i = 0; i < len; i++){
  int ascii = word[i] - '0';
  current->cnt[ascii]--;
  current = current->ar[ascii];
 }
}
string query(string s){
   string m;
    node *curr =root;
   for(int i=0;i<s.length();i++){
        int c=s[i]-'0';
        if(c==1){
            if(curr->cnt[0]){
                m+='1';
                curr=curr->ar[0];
            } else {
               m+='0';
                curr=curr->ar[1];
            }

        } else {
           if(curr->cnt[1]){
                m+='1';
                curr=curr->ar[1];
            } else {
               m+='0';
                curr=curr->ar[0];
            }
        }

    }
    return m;
}

void del(node *cur)
{
 for (int i = 0; i<10; i++)
 if (cur->ar[i]){
  del(cur->ar[i]);
       delete(cur);
  return;
 }
}

int main(){
 root = new node();
  Insert(go(0));
   int n=nxt();
   while(n--){
     char a;int b;
     cin>>a;
     b=nxt();
     string x=go(b);
     if(a=='+'){
        Insert(x);
     } else if(a=='-'){
        del(x);
     } else {

      string s=query(x);
     // cout<<s<<endl;
      printf("%I64d\n",go(s));
     }
   }
return 0;
}