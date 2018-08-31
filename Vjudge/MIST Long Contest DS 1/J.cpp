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
 int ar[N];vector<int> tree[4*N];
 vector<int> v;
void segment_tree(int node,int low,int high){
     if(low==high){
        tree[node].pb(ar[low]); return;
     }
    int left=2*node;
    int right=2*node+1;
    int mid=(low+high)/2;
     segment_tree(left,low,mid);
     segment_tree(right,mid+1,high);
     int sz=tree[left].size();
     int sz1=tree[right].size();
     tree[node].resize(sz+sz1);
     merge(tree[left].begin(),tree[left].begin()+sz,tree[right].begin(),tree[right].begin()+sz1,tree[node].begin());
}
int query(int node,int low,int hi,int i,int j,int val){
       if(i>hi||j<low) return 0;
       if(low>=i&&hi<=j)
          return upper_bound(tree[node].begin(),tree[node].end(),val)-tree[node].begin();
 int mid=(low+hi)/2;
   int left=2*node;
   int right=left+1;
  int x= query(left,low,mid,i,j,val);
  int y= query(right,mid+1,hi,i,j,val);
   return x+y;

}
int main(){
     //freopen("out.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);

   int n=nxt();
   int m=nxt();
   for(int i=1;i<=n;i++) ar[i]=nxt(),v.pb(ar[i]);
   segment_tree(1,1,n);
   sort(v.begin(),v.end());
   while(m--){

    int i=nxt(),j=nxt(),k=nxt();
     int b=-inf-10,e=inf+10;
     while(b<=e){
         int mid=(b+e)>>1;
        int q=query(1,1,n,i,j,mid);

            if(q<k) b=mid+1;
            else e=mid-1;


     }
    /// cout<<b<<endl;
    // int in=upper_bound(v.begin(),v.end(),b)-v.begin();
     printf("%d\n",b);
  }

return 0;
}
