// ==========================================================================
//
//                   Bismillahir-Rahmanir-Rahim
//
// ==========================================================================

#include <bits/stdc++.h>
#define ll long long
#define f(x,y,z) for(int x=y;x<z;x++)
#define take1(a); int a;scanf("%d",&a);
#define take2(a,b); int a;int b;scanf("%d%d",&a,&b);
#define take3(a,b,c); int a;int b;int c;scanf("%d%d%d",&a,&b,&c);
#define take4(a,b,c,d); int a;int b;int c;int d;scanf("%d%d%d%d",&a,&b,&c,&d);
using namespace std;
char p[1000+20][1000+20];int position[1000+20][1000+20],visited[1000+5][1000+5],ans;int m,n,k;
int result[1000000+100];
int fx[]={1,-1,0,0};
int fy[]={0,0,1,-1};
int dfs(int i,int j,int c){

         position[i][j]=c;
       f(k,0,4){
         int x=i+fx[k];
         int y=j+fy[k];
        // cout<<x<<" "<<y<<endl;
          if(p[x][y]=='*')++ans;
          else if(p[x][y]=='.'&&!visited[x][y]){
                visited[x][y]=true;
              dfs(x,y,c);
          }
       }


}
int main()
   {
        int pp=0;
     cin>>m>>n>>k;
     f(i,1,m+1) f(j,1,n+1) cin>>p[i][j];
     f(i,1,m+1) f(j,1,n+1){
             if(p[i][j]=='.'&&!visited[i][j]){ //cout<<i<<" "<<j<<endl;
                ans=0;visited[i][j]=1;
                dfs(i,j,pp);
                result[pp]=ans;
                pp++;
             }
             }
             while(k--)
             {
                 take2(x,y);
                 cout<<result[position[x][y]]<<endl;

             }


}