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
#define        N                               1000010
#define        M                               1000000007
#define        pi                              acos(-1.0)
#define        ff                              first
#define        ss                              second
#define        pb                              push_back
#define        inf                             (int)1e9
#define        eps                             1e-9
#define        debug(x)                        cerr << #x << " is " << x << endl;
#define        All(x)                          x.begin(),x.end()
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
ll tree[4*N];ll lazy[4*N];

void update(int node,int low,int hi,int i,int value){    /// update value in i'th index of array

   if(low==hi){
    tree[node]+=value; return;
   }
   int mid=(low+hi)/2;
   int left=2*node;
   int right=left+1;
   if(i<=mid)
      update(left,low,mid,i,value);
   else
      update(right,mid+1,hi,i,value);
   tree[node]=tree[left]+tree[right];
}
int query(int node,int low,int hi,int i,int j){  ///return sum index i to j
       if(i>hi||j<low) return 0;
       if(low>=i&&hi<=j)
          return tree[node];
 int mid=(low+hi)/2;
   int left=2*node;
   int right=left+1;
  int x= query(left,low,mid,i,j);
  int y= query(right,mid+1,hi,i,j);
   return x+y;

}
int main(){
     //freopen("out.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
    int n=nxt();
    int k=nxt();
    if(n-k<k) k=n-k;
    ll ans=2; ll now;
     now=1+k;
     update(1,1,n,1,1);
     update(1,1,n,now,1);
     printf("%I64d",ans);
    for(int i=2;i<=n;i++){

        ll temp;
        if(now+k<=n){

            temp=query(1,1,n,now+1,now+k-1);

        } else {
           if(now==n){
              temp=query(1,1,n,1,now+k-n-1);
           } else{
               temp=query(1,1,n,now+1,n);
               if(now+k-n!=1){
                   temp+=query(1,1,n,1,now+k-n-1);
               }

           }

        }
        ans+=temp+1;printf(" %I64d",ans);
        update(1,1,n,now,1);
        //cout<<now<<endl;
        now+=k;if(now>n) now-=n;
        update(1,1,n,now,1);
        //cout<<now<<endl;

    }
    printf("\n");

return 0;
}