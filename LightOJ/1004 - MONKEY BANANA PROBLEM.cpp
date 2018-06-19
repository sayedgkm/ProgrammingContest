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
using namespace std;

int ar[505][505],n;ll ans [505][505];
void bfs(int i,int j,int cases)
{
      ans[i][j]=ar[i][j];int x,y;
      queue <pii> p;
      p.push(pii(i,j));
      while(!p.empty())
      {
          pii fst=p.front();p.pop();
          if(fst.first<n)
          {
              x=fst.first+1;
              y=fst.second;
              if(ar[x][y])
              {
                  if(ans[fst.first][fst.second]+ar[x][y]>ans[x][y]){
                      ans[x][y]=ans[fst.first][fst.second]+ar[x][y];p.push(pii(x,y));
                  }

              }
              x=fst.first+1;
              y=fst.second+1;
              if(ar[x][y])
              {
                  if(ans[fst.first][fst.second]+ar[x][y]>ans[x][y]){
                      ans[x][y]=ans[fst.first][fst.second]+ar[x][y];p.push(pii(x,y));
                  }

              }

          }
          else
          {
              x=fst.first+1;
              y=fst.second;
              if(ar[x][y])
              {
                  if(ans[fst.first][fst.second]+ar[x][y]>ans[x][y]){
                      ans[x][y]=ans[fst.first][fst.second]+ar[x][y];p.push(pii(x,y));
                  }

              }
              x=fst.first+1;
              y=fst.second-1;
              if(ar[x][y])
              {
                  if(ans[fst.first][fst.second]+ar[x][y]>ans[x][y]){
                      ans[x][y]=ans[fst.first][fst.second]+ar[x][y];p.push(pii(x,y));
                  }

              }


          }

      }
printf("Case %d: %lld\n",cases,ans[2*n-1][1]);

}
int main()
   {
        int b=1;
     take1(test);
     while(test--){

       cin>>n;
    for(int i=1;i<=n;i++){
               for(int j=1;j<=i;j++)
                   scanf("%d",&ar[i][j]);
        }

        int q=n-1;
       for(int i=n+1;i<=(2*n)-1;i++){
           // cout<<"t"<<i<<endl;
             for(int j=1;j<=q;j++){
                scanf("%d",&ar[i][j]);

             }
           q--;
       }

        bfs(1,1,b++);
        mem(ar,0);
        mem(ans,0);
     }


}


