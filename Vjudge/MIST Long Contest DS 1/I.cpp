#include <bits/stdc++.h>
#define        ll                              long long
#define        f(x,y,z)                        for(int x=y;x<z;x++)
#define        take1(a);                       scanf("%d",&a);
#define        take2(a,b);                     scanf("%d%d",&a,&b);
#define        take3(a,b,c);                   scanf("%d%d%d",&a,&b,&c);
#define        take4(a,b,c,d);                 scanf("%d%d%d%d",&a,&b,&c,&d);
#define        pii                             pair<int,int>
#define        mem(a,x)                        memset(a,x,sizeof(a))
#define        N                               100010
#define        M                               1000000007
#define        pi                              acos(-1.0)
#define        ff                              first
#define        ss                              second
#define        pb                              push_back
using namespace std;
struct pp{
  ll one,two,three,lazy;
}tree[N*3];
int convert(int node,int time){

    while(time--){
         int temp=tree[node].three;
              tree[node].three=tree[node].two;
              tree[node].two=tree[node].one;
              tree[node].one= temp;
    }
}
void segment_tree(int node,int low,int high){
     if(low==high){
        tree[node].one=0;
        tree[node].two=0;
        tree[node].three=1;
        tree[node].lazy=0;
        return;
     }
    int left=2*node;
    int right=2*node+1;
    int mid=(low+high)/2;
     segment_tree(left,low,mid);
     segment_tree(right,mid+1,high);
     tree[node].three=tree[left].three+tree[right].three;
}
void update(int node,int low,int hi,int i,int j){

    int left=node*2;
    int right=left+1;
    int mid=(low+hi)/2;
    if(tree[node].lazy){
              convert(node,tree[node].lazy%3);
            if(hi!=low){
             tree[left].lazy+=tree[node].lazy;
             tree[right].lazy+=tree[node].lazy;
            }
        tree[node].lazy=0;
    }
     if(low>j||hi<i) return;
    if(low>=i&&hi<=j){
            convert(node,1);
           if(hi!=low){
         tree[left].lazy++;
         tree[right].lazy++;
       }
       return ;
    }
     update(left,low,mid,i,j);
     update(right,mid+1,hi,i,j);
     tree[node].three=tree[left].three+tree[right].three;
     tree[node].one=tree[left].one+tree[right].one;
     tree[node].two=tree[left].two+tree[right].two;
}
int query(int node,int low,int hi,int i,int j){
      if(low>j||hi<i) return 0;
    int left=node*2;
    int right=left+1;
    int mid=(low+hi)/2;
    if(tree[node].lazy){
              convert(node,tree[node].lazy%3);
             if(hi!=low){
            tree[left].lazy+=tree[node].lazy;
            tree[right].lazy+=tree[node].lazy;
            }
        tree[node].lazy=0;
    }
    if(low>=i&&hi<=j){
       return tree[node].three;
    }
   int p=query(left,low,mid,i,j);
   int q= query(right,mid+1,hi,i,j);
    return p+q;
}
int main()
{

    int n,q;
    scanf("%d%d",&n,&q);
    segment_tree(1,1,n);
    while(q--){
        int xx;
        take1(xx);

        if(!xx){
            int x,y;
            take2(x,y);
            x++,y++;
            update(1,1,n,x,y);
        }
        else {
            int x,y;
            take2(x,y);
              x++,y++;
           int ans= query(1,1,n,x,y);
            printf("%d\n",ans);
        }

    }

      return 0;
}
