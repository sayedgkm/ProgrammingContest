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
#define        N                               100010
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
string s;
struct info{
   int val[26];
   int lazy[26];
   int needupdate;
   info(){
      needupdate=-1;
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
          tree[node].val[s[low-1]-'a']=1;
         return;
     }
    int left=2*node;
    int right=2*node+1;
    int mid=(low+high)/2;
     segment_tree(left,low,mid);
     segment_tree(right,mid+1,high);
     tree[node]=add(tree[left],tree[right]);

}
void update(int node,int low,int hi,int i,int j,int t){
    int left=2*node;
    int right=left+1;
    int mid=(low+hi)/2;
      if(tree[node].needupdate!=-1){
          for(int i=0;i<26;i++){
             tree[node].val[i]=tree[node].lazy[i];
          }
        if(hi!=low){
                 int sz=mid-low+1;
                 if(tree[node].needupdate==1){
                  for(int i=0;i<26;i++){
                         int mn=min(sz,tree[node].lazy[i]);
                        tree[left].lazy[i]=mn;
                        sz-=mn;
                        tree[node].lazy[i]-=mn;

                    }
                 }  else {

                    for(int i=25;i>=0;i--){
                         int mn=min(sz,tree[node].lazy[i]);
                        tree[left].lazy[i]=mn;
                        sz-=mn;
                        tree[node].lazy[i]-=mn;

                    }

                 }
                sz=hi-mid;
                if(tree[node].needupdate==1){
                for(int i=0;i<26;i++){

                         int mn=min(sz,tree[node].lazy[i]);
                        tree[right].lazy[i]=mn;
                        sz-=mn;
                        tree[node].lazy[i]-=mn;


                }
             } else {

                for(int i=25;i>=0;i--){

                         int mn=min(sz,tree[node].lazy[i]);
                        tree[right].lazy[i]=mn;
                        sz-=mn;
                        tree[node].lazy[i]-=mn;


                }


             }
                tree[left].needupdate=tree[node].needupdate;
                tree[right].needupdate=tree[node].needupdate;
            }
        tree[node].needupdate=-1;
    }
      if(hi<i||j<low) return;
      if(low>=i&&hi<=j){
             int sz=hi-low+1;
        if(t==1) {
            for(int i=0;i<26;i++){
                 int mn=min(sz,temp.val[i]);
             tree[node].val[i]=mn;
             tree[node].lazy[i]=mn;
             sz-=mn;
             temp.val[i]-=mn;
          }
          tree[node].needupdate=1;
        } else {

          for(int i=25;i>=0;i--){
                 int mn=min(sz,temp.val[i]);
             tree[node].val[i]=mn;
             tree[node].lazy[i]=mn;
             sz-=mn;
             temp.val[i]-=mn;
          }
          tree[node].needupdate=0;


        }

        return ;
      }

      update(left,low,mid,i,j,t);
      update(right,mid+1,hi,i,j,t);
     tree[node]=add(tree[left],tree[right]);
}
info query(int node,int low,int hi,int i,int j,int t){  ///return sum index i to j
        int mid=(low+hi)/2;
        int left=2*node;
         int right=left+1;
      if(tree[node].needupdate!=-1){
          for(int i=0;i<26;i++){
             tree[node].val[i]=tree[node].lazy[i];
          }
        if(hi!=low){
                 int sz=mid-low+1;
                 if(tree[node].needupdate==1){
                  for(int i=0;i<26;i++){
                         int mn=min(sz,tree[node].lazy[i]);
                        tree[left].lazy[i]=mn;
                        sz-=mn;
                        tree[node].lazy[i]-=mn;

                    }
                 }  else {

                    for(int i=25;i>=0;i--){
                         int mn=min(sz,tree[node].lazy[i]);
                        tree[left].lazy[i]=mn;
                        sz-=mn;
                        tree[node].lazy[i]-=mn;

                    }

                 }
                sz=hi-mid;
                if(tree[node].needupdate==1){
                for(int i=0;i<26;i++){

                         int mn=min(sz,tree[node].lazy[i]);
                        tree[right].lazy[i]=mn;
                        sz-=mn;
                        tree[node].lazy[i]-=mn;


                }
             } else {

                for(int i=25;i>=0;i--){

                         int mn=min(sz,tree[node].lazy[i]);
                        tree[right].lazy[i]=mn;
                        sz-=mn;
                        tree[node].lazy[i]-=mn;


                }


             }
                tree[left].needupdate=tree[node].needupdate;
                tree[right].needupdate=tree[node].needupdate;
            }
        tree[node].needupdate=-1;
    }
       if(i>hi||j<low) {
         info t;
         return t;
       }
       if(low>=i&&hi<=j)
          return tree[node];

  info x= query(left,low,mid,i,j,t);
  info y= query(right,mid+1,hi,i,j,t);
   return add(x,y);

}
int querybyindex(int node,int low,int hi,int i){
        int mid=(low+hi)/2;
        int left=2*node;
         int right=left+1;
      if(tree[node].needupdate!=-1){
          for(int i=0;i<26;i++){
             tree[node].val[i]=tree[node].lazy[i];
          }
        if(hi!=low){
                 int sz=mid-low+1;
                 if(tree[node].needupdate==1){
                  for(int i=0;i<26;i++){
                         int mn=min(sz,tree[node].lazy[i]);
                        tree[left].lazy[i]=mn;
                        sz-=mn;
                        tree[node].lazy[i]-=mn;

                    }
                 }  else {

                    for(int i=25;i>=0;i--){
                         int mn=min(sz,tree[node].lazy[i]);
                        tree[left].lazy[i]=mn;
                        sz-=mn;
                        tree[node].lazy[i]-=mn;

                    }

                 }
                sz=hi-mid;
                if(tree[node].needupdate==1){
                for(int i=0;i<26;i++){

                         int mn=min(sz,tree[node].lazy[i]);
                        tree[right].lazy[i]=mn;
                        sz-=mn;
                        tree[node].lazy[i]-=mn;


                }
             } else {

                for(int i=25;i>=0;i--){

                         int mn=min(sz,tree[node].lazy[i]);
                        tree[right].lazy[i]=mn;
                        sz-=mn;
                        tree[node].lazy[i]-=mn;


                }


             }
                tree[left].needupdate=tree[node].needupdate;
                tree[right].needupdate=tree[node].needupdate;
            }
        tree[node].needupdate=-1;
    }
       if(i>hi||i<low) {
         return 0;
       }
       if(low==i&&hi==i){

          for(int j=0;j<26;j++)  {
                if(tree[node].val[j]) return j;
          }

       }
       int x=0,y=0;
  if(i<=mid){
    x = querybyindex(left,low,mid,i);
  }
  else{
    y = querybyindex(right,mid+1,hi,i);
  }
   return x+y;
}

int main(){
     //freopen("out.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
   int n=nxt();
   int k=nxt();
    cin>>s;
   segment_tree(1,1,n);
   while(k--){
     int a=nxt(),b=nxt(),c=nxt();
      temp=query(1,1,n,a,b,c);
      update(1,1,n,a,b,c);

   }
  for(int i=1;i<=n;i++){

     int c=querybyindex(1,1,n,i);
    printf("%c",c+'a');
 }

return 0;
}