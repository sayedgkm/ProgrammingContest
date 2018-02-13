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
int srow,sclm,erow,eclm,m,n;int visited[505][505],ans;string s[505];
int dx[]={1,-1,0,0};
int dy[]={0,0,-1,1};
void dfs(int row,int clm)
{

        visited[row][clm]=1;
    f(i,0,4){
     int x=row+dx[i];
      int y=clm+dy[i];
       if(x<0||x>m-1||y<0||y>n-1) continue;
         if(x==erow-1&&y==eclm-1&&visited[x][y]){
            ans=1;return;
         }
          if(x==erow-1&&y==eclm-1&&ans==0)
             dfs(x,y);
         else if(!visited[x][y]&&s[x][y]=='.')
                  dfs(x,y);
    }
}
int main()
   {
      cin>>m>>n;
      f(i,0,m){
         cin>>s[i];
         f(j,0,n)
            if(s[i][j]=='X')
                visited[i][j]=1;
      }
         cin>>srow>>sclm>>erow>>eclm;
           dfs(srow-1,sclm-1);
           if(ans)
               puts("YES");
           else
            puts("NO");
}