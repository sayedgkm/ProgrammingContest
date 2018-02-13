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
#define        N                               3000010
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
struct vertex{
  int sum=0;
  int sf=0;
  int pf=0;

}tree[N];
string s;
void segment_tree(int node,int low,int high){
     if(low==high){
        if(s[low]==')') tree[node].pf++;
        else tree[node].sf++;
          return;
     }
    int left=2*node;
    int right=2*node+1;
    int mid=(low+high)/2;
     segment_tree(left,low,mid);
     segment_tree(right,mid+1,high);
     int p=min(tree[left].sf,tree[right].pf);
     tree[node].sum=tree[left].sum+tree[right].sum+p;
     tree[node].sf=tree[left].sf+tree[right].sf-p;
     tree[node].pf=tree[left].pf+tree[right].pf-p;
}

vertex query(int node,int low,int hi,int i,int j){
       if(i>hi||j<low){
        vertex temp;temp.sum=temp.pf=temp.sf=0;
        return temp;
       }
       if(low>=i&&hi<=j)
          return tree[node];
 int mid=(low+hi)/2;
   int left=2*node;
   int right=left+1;
  vertex x= query(left,low,mid,i,j);
  vertex y= query(right,mid+1,hi,i,j);
  vertex q;
    int p=min(x.sf,y.pf);
     q.sum=x.sum+y.sum+p;
     q.sf=x.sf+y.sf-p;
     q.pf=x.pf+y.pf-p;
   return q;

}
int main(){
     //freopen("out.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);

   string t;
   cin>>t;
   s+='0'+t;
   int len=s.length();
   segment_tree(1,1,len);
   int n=nxt();
   while(n--){

    int a=nxt(),b=nxt();
    vertex res=query(1,1,len,a,b);
    printf("%d\n",res.sum*2);

   }


return 0;
}