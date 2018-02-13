#include<bits/stdc++.h>
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
vector<int> v[110];
int ans[110],visited[110];int color[101][101][101];
void bfs(int f,int cl){
      visited[f]=1;
        queue<int> q;
        q.push(f);
        while(!q.empty()){
               int first=q.front();q.pop();
               for(int i=0;i<v[first].size();i++){
                  if(!visited[v[first][i]]&&color[first][v[first][i]][cl]){
                    visited[v[first][i]]=1;
                    q.push(v[first][i]);
                  }

               }

        }
}
int main()
{
  int a,b;
  cin>>a>>b;
  while(b--){
    take3(x,y,z);
    v[x].push_back(y);
    v[y].push_back(x);
   color[x][y][z]=color[y][x][z]=1;
}
cin>>a;
  while(a--){
    take2(x,y);int ans=0;
    for(int i=1;i<=100;i++){
            f(j,0,105) visited[j]=0;
        bfs(x,i);
       if(visited[y]) ans++;
    }
    cout<<ans<<endl;
}

return 0;
}