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
int ar[N];pii tree[3*N];
pii go(pii a,pii b){
   vector<int>v;
   v.pb(a.ff);
   v.pb(a.ss);
   v.pb(b.ff);
   v.pb(b.ss);
   sort(v.begin(),v.end());
   return pii(v[3],v[2]);
}
void segment_tree(int node,int low,int high){
     if(low==high){
        tree[node].ff=ar[low];
        tree[node].ss=0;
        return;
     }
    int left=2*node;
    int right=2*node+1;
    int mid=(low+high)/2;
     segment_tree(left,low,mid);
     segment_tree(right,mid+1,high);
     pii x=go(tree[left],tree[right]);
     tree[node].ff=x.ff;
     tree[node].ss=x.ss;
}
void update(int node,int low,int hi,int i,int value){

   if(low==hi){
    tree[node].ff=value; return;
   }
   int mid=(low+hi)/2;
   int left=2*node;
   int right=left+1;
   if(i<=mid)
      update(left,low,mid,i,value);
   else
      update(right,mid+1,hi,i,value);
   pii x=go(tree[left],tree[right]);
     tree[node].ff=x.ff;
     tree[node].ss=x.ss;
}
pii query(int node,int low,int hi,int i,int j){
       if(i>hi||j<low) return pii(0,0);
       if(low>=i&&hi<=j)
          return pii(tree[node]);
 int mid=(low+hi)/2;
   int left=2*node;
   int right=left+1;
  pii x= query(left,low,mid,i,j);
  pii y= query(right,mid+1,hi,i,j);
   return pii(go(x,y));

}

int main(){
     //freopen("out.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
   int n=nxt();
   f(i,1,n+1) ar[i]=nxt();
   segment_tree(1,1,n);
   int m=nxt();
   char s;
   while(m--){
      cin>>s;
      int a=nxt();
      int b=nxt();
      if(s=='Q'){
            pii x=query(1,1,n,a,b);
        printf("%d\n",x.ff+x.ss);
      } else update(1,1,n,a,b);
}

return 0;
}

