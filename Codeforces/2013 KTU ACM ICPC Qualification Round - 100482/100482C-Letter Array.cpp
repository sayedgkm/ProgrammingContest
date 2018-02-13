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
#define        eps                              1e-9
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
string s;
struct info{
   int val[26];
   int lazy[26];
   bool needupdate;
   info(){
      needupdate=false;
      for(int i=0;i<26;i++){
        lazy[i]=val[i]=0;
      }
   }
   void print(){
       cout<<"********"<<endl;
      for(int i=0;i<26;i++) cout<<val[i]<<" ";
      cout<<endl;
   }
}tree[N*4];
info add(info a,info b){
   info temp;
   for(int i=0;i<26;i++) temp.val[i]=a.val[i]+b.val[i];
   return temp;
}
info temp;
void segment_tree(int node,int low,int high){
     if(low==high){
          tree[node].val[s[low-1]-'A']=1;
         return;
     }
    int left=2*node;
    int right=2*node+1;
    int mid=(low+high)/2;
     segment_tree(left,low,mid);
     segment_tree(right,mid+1,high);
     tree[node]=add(tree[left],tree[right]);

}
void update(int node,int low,int hi,int i,int j){
    int left=2*node;
    int right=left+1;
    int mid=(low+hi)/2;
      if(tree[node].needupdate){
          for(int i=0;i<26;i++){
             tree[node].val[i]=tree[node].lazy[i];
          }
        if(hi!=low){
                 int sz=mid-low+1;
                for(int i=0;i<26;i++){
                         int mn=min(sz,tree[node].lazy[i]);
                        tree[left].lazy[i]=mn;
                        sz-=mn;
                        tree[node].lazy[i]-=mn;

                    }
                sz=hi-mid;
                for(int i=0;i<26;i++){

                         int mn=min(sz,tree[node].lazy[i]);
                        tree[right].lazy[i]=mn;
                        sz-=mn;
                        tree[node].lazy[i]-=mn;


                }
                tree[left].needupdate=true;
                tree[right].needupdate=true;
            }
        tree[node].needupdate=false;
    }
      if(hi<i||j<low) return;
      if(low>=i&&hi<=j){
             int sz=hi-low+1;
             info x=temp;
            for(int i=0;i<26;i++){
                 int mn=min(sz,temp.val[i]);
             tree[node].val[i]=mn;
             tree[node].lazy[i]=mn;
             sz-=mn;
             temp.val[i]-=mn;
          }

        tree[node].needupdate=true;
        return ;
      }

      update(left,low,mid,i,j);
      update(right,mid+1,hi,i,j);
     tree[node]=add(tree[left],tree[right]);
}
info query(int node,int low,int hi,int i,int j){  ///return sum index i to j
        int mid=(low+hi)/2;
        int left=2*node;
         int right=left+1;
       if(tree[node].needupdate){
          for(int i=0;i<26;i++){
             tree[node].val[i]=tree[node].lazy[i];
          }
        if(hi!=low){
                 int sz=mid-low+1;
                for(int i=0;i<26;i++){
                         int mn=min(sz,tree[node].lazy[i]);
                        tree[left].lazy[i]=mn;
                        sz-=mn;
                        tree[node].lazy[i]-=mn;

                    }
                sz=hi-mid;
                for(int i=0;i<26;i++){

                         int mn=min(sz,tree[node].lazy[i]);
                        tree[right].lazy[i]=mn;
                        sz-=mn;
                        tree[node].lazy[i]-=mn;


                }
                tree[left].needupdate=true;
                tree[right].needupdate=true;
            }
        tree[node].needupdate=false;
    }
       if(i>hi||j<low) {
         info t;
         return t;
       }
       if(low>=i&&hi<=j)
          return tree[node];

  info x= query(left,low,mid,i,j);
  info y= query(right,mid+1,hi,i,j);
   return add(x,y);

}
int main(){
     //freopen("out.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
   int test=nxt();
   int cs=1;
   while(test--){
        CLR(tree);
      cin>>s; int n=s.size(); printf("Case #%d:\n",cs++);
      segment_tree(1,1,n);
     int q=nxt();
     while(q--){
        char c[2];
        scanf("%s",c);
        int i=nxt();
        int j=nxt();
        ++i,++j;
       if(c[0]=='g'){

         temp=query(1,1,n,i,j);
         for(int i=0;i<26;i++){
                 if(i) printf(" ");
             printf("%d",temp.val[i]);
         }
         printf("\n");
       } else {
          temp=query(1,1,n,i,j);
          update(1,1,n,i,j);

       }

     }


}

return 0;
}