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
char ar[1005][1005];int value[1005][1005],visited[1005][1005];int ans[N],an=0,vis[N];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int r,c;
int dfs(int i,int j,int index){
          value[i][j]=index;
          visited[i][j]=1; an++;
         for(int k=0;k<4;k++){
             int x=i+dx[k];
             int y=j+dy[k];
             if(x>=0&&x<r&&y>=0&&y<c&&!visited[x][y]&&ar[x][y]=='.')
                dfs(x,y,index);
             }

   return an;
}
int main()
{
 cin>>r>>c; int index=1,result;
  f(i,0,r) f(j,0,c) cin>>ar[i][j];
  f(i,0,r) f(j,0,c){
     if(ar[i][j]=='.'&&!visited[i][j]){
       result= dfs(i,j,index);
      // cout<<result<<endl;
        ans[index]=result;
        an=0;index++;
     }
    }
    int sum=0;
    f(i,0,r){
         f(j,0,c){
        sum=0;
       if(ar[i][j]=='.')
           printf(".");
       else{

        for(int k=0;k<4;k++){
             int x=i+dx[k];
             int y=j+dy[k];
             if(x>=0&&x<r&&y>=0&&y<c&&!vis[value[x][y]]){
                sum+=ans[value[x][y]];
                vis[value[x][y]]=1;
             }
             }
          printf("%d",(sum+1)%10);
          for(int k=0;k<4;k++){
             int x=i+dx[k];
             int y=j+dy[k];
             if(x>=0&&x<r&&y>=0&&y<c){

                vis[value[x][y]]=0;
             }
             }

       }


    }
    cout<<"\n";
}


return 0;
}