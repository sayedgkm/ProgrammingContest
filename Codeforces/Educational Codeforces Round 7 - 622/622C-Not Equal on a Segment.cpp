// ==========================================================================
//
//                   Bismillahir-Rahmanir-Rahim
//
// ==========================================================================
#include <bits/stdc++.h>
#define        ll                              long long
#define        f(x,y,z)                        for(int x=y;x<z;x++)
#define        take1(a);                       scanf("%d",&a);
#define        take2(a,b);                     scanf("%d%d",&a,&b);
#define        take3(a,b,c);                   scanf("%d%d%d",&a,&b,&c);
#define        take4(a,b,c,d);                 scanf("%d%d%d%d",&a,&b,&c,&d);
#define        pii                             pair<int,int>
#define        mem(a,x)                        memset(a,x,sizeof(a))
#define        N                               2000100
#define        M                               1000000007
#define        pi                              acos(-1.0)
#define        ff                              first
#define        ss                              second
#define        pb                              push_back
using namespace std;
int ar[N];pii tree[3*N];pii top;
pii mimx(pii x){
   top.ff=ar[x.ff]<ar[top.ff]?x.ff:top.ff;
  top.ss=ar[x.ss]>ar[top.ss]?x.ss:top.ss;
}
void segment_tree(int node,int low,int high){
     if(low==high){
        tree[node].ff=low;
        tree[node].ss=low;
         return;
     }
    int left=2*node;
    int right=2*node+1;
    int mid=(low+high)/2;
     segment_tree(left,low,mid);
     segment_tree(right,mid+1,high);
     tree[node].ff=ar[tree[left].ff]<ar[tree[right].ff]?tree[left].ff:tree[right].ff;
     tree[node].ss=ar[tree[left].ss]>ar[tree[right].ss]?tree[left].ss:tree[right].ss;
}
int query(int node,int low,int hi,int i,int j,int v){
       if(i>hi||j<low) return -1;
       if(low>=i&&hi<=j){
          if(ar[tree[node].ff]!=v) return tree[node].ff;
          if(ar[tree[node].ss]!=v) return tree[node].ss;
          return -1;
       }
 int mid=(low+hi)/2;
   int left=2*node;
   int right=left+1;
   int p=query(left,low,mid,i,j,v);
    int q=query(right,mid+1,hi,i,j,v);

    if(p==-1) return q;
    else return p;
}
int main()
{
 int n, m;
 cin >> n >> m;
 int pos = 0;
 f(i, 1, n+1)
   scanf("%d",&ar[i]);
  segment_tree(1,1,n);
 while(m--){
            ar[0]=1e8;
 ar[n+1]=0;
 top=pii(0,n+1);
        int l,r,q;
        take3(l,r,q);
      int ans= query(1,1,n,l,r,q);
     if(ans==-1)
          puts("-1");
     else printf("%d\n",ans);

     }
  }