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
char ar[505][505]; int x,y; int visited[505][505],s,counter=0,a,b,c;
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
void dfs(int row,int clm)
{
  if(counter>=s-c) return;
    counter++;
  ar[row][clm]='d';
    f(i,0,4){
      int x=row+dx[i];
      int y=clm+dy[i];
      if(x<0||y<0||x>=a||y>=b) continue;
      if(ar[x][y]=='.')
         dfs(x,y);

    }


}

int main()
   {
     cin>>a>>b>>c;
     f(i,0,a) {f(k,0,b) {cin>>ar[i][k];
          if(ar[i][k]=='.')
          {
              s++;x=i;y=k;
          }
     }
 }
     dfs(x,y);

  f(i,0,a){ f(j,0,b){
         if(ar[i][j]=='d') cout<<'.';
           else if(ar[i][j]=='.') cout<<'X';
           else cout<<ar[i][j];
       }
       cout<<"\n";
  }

}