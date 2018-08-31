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

 struct info{

  int pr, sf, mx, total;

 }tree[N*3];

 int ar[N];
 info go(info a,info b){

    info temp;
    temp.total=a.total+b.total;
    temp.mx=max(a.mx,max(b.mx,temp.total));
    temp.mx=max(temp.mx,a.sf+b.pr);

    temp.sf=max(b.sf,b.total+a.sf);
    temp.pr=max(a.pr,a.total+b.pr);
    return temp;

 }
 void segment_tree(int node,int low,int high){
     if(low==high){
        tree[node].mx=tree[node].sf=tree[node].pr=tree[node].total=ar[low]; return;
     }
    int left=2*node;
    int right=2*node+1;
    int mid=(low+high)/2;
     segment_tree(left,low,mid);
     segment_tree(right,mid+1,high);
     tree[node]=go(tree[left],tree[right]);
}
info query(int node,int low,int hi,int i,int j){
    //cout<<low<<" "<<hi<<endl;
       if(low>=i&&hi<=j){
            //cout<<tree[node].mx<<endl;
          return tree[node];
       }
 int mid=(low+hi)/2;
   int left=2*node;
   int right=left+1;
   info x,y;
   if(j<=mid) return query(left,low,mid,i,j);
   else if(i>mid)  return query(right,mid+1,hi,i,j);
   else return go(query(left,low,mid,i,j),query(right,mid+1,hi,i,j));
 }
int main(){
     //freopen("out.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
   int n=nxt();
   f(i,1,n+1)ar[i]=nxt();
   segment_tree(1,1,n);
   int m=nxt();
   while(m--){
      int a=nxt(),b=nxt();
     info f=query(1,1,n,a,b);
     printf("%d\n",f.mx);
   }

return 0;
}
