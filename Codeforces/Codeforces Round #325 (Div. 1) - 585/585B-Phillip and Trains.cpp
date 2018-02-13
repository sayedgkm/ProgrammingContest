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
char p[5][110];int visited[5][110],check=false;
using namespace std;
void dfs(int row,int clm,int n)
{
    if(visited[row][clm]||p[row][clm]!='.') return;
       visited[row][clm]=1;
        //cout<<row<<" "<<clm<<endl;
    if(clm>n){
        check=true;
        return;
    }

        if(p[row][clm+1]=='.'&&p[row][clm+2]=='.'&&p[row][clm+3]=='.')
           dfs(row,clm+3,n);
         if(row>0&&p[row][clm+1]=='.'&&p[row-1][clm+1]=='.'&&p[row-1][clm+2]=='.'&&p[row-1][clm+3]=='.')
            dfs(row-1,clm+3,n);
        if(row<2&&p[row][clm+1]=='.'&&p[row+1][clm+1]=='.'&&p[row+1][clm+2]=='.'&&p[row+1][clm+3]=='.')
            dfs(row+1,clm+3,n);


}
int main()
   {
     take1(n);int row;
     while(n--){
        take2(clm,train);
        f(i,0,3)
          { cin>>p[i];
           p[i][clm]='.';
           p[i][clm+1]='.';
           p[i][clm+2]='.';
           p[i][clm+3]='.';
           if(p[i][0]=='s'){ row=i;p[i][0]='.';}
        }
        check=false;
        dfs(row,0,clm);
        if(check)
        puts("YES");else puts("NO");
        memset(visited,false,sizeof(visited));

     }

}