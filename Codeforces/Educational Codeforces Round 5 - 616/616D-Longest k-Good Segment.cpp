// ==========================================================================
//
//                   Bismillahir-Rahmanir-Rahim
//
// ==========================================================================
#include <bits/stdc++.h>
#define        ll                    long long
#define        f(x,y,z)              for(int x=y;x<z;x++)
#define        take1(a);             int a;scanf("%d",&a);
#define        take2(a,b);           int a;int b;scanf("%d%d",&a,&b);
#define        take3(a,b,c);         int a;int b;int c;scanf("%d%d%d",&a,&b,&c);
#define        take4(a,b,c,d);       int a;int b;int c;int d;scanf("%d%d%d%d",&a,&b,&c,&d);
#define        pii                   pair<int,int>
#define        mem(a,x)              memset(a,x,sizeof(a))
#define        N                     1000010
#define        M                     1000000007
#define        pi                    acos(-1.0)
using namespace std;
int vis[N],ar[N];
int main()
{
ios_base::sync_with_stdio(0); cin.tie(0);
   take2(n,limit);int counter=0,index=1,mx=0,f,s;
f(i,1,n+1){
  take1(p);
ar[i]=p;
//cout<<ar[i]<<endl;
}
f(i,1,n+1){
     vis[ar[i]]++;
     if(vis[ar[i]]==1) counter++;
    //cout<<ar[i]<<endl;
    if(counter>limit){
        while(counter>limit){
            if(vis[ar[index]]==1) counter--;
            vis[ar[index]]--;
            index++;
     }
}

     if(i-index+1>mx){
        mx=i-index+1;
        f=index;s=i;
     }

}
  printf("%d %d\n",f,s);

return 0;
}