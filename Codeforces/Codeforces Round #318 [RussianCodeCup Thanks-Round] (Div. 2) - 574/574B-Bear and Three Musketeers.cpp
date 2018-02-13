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
map<int,vector<int> > graph; ll ar[4005][4005];
/*void dfs(int a)
{
         visited[a]=1;
        f(i,0,graph[a].size())
          {
              if(!visited[graph[a][i]])
              {
                  counter[fraph[a][i]]=counter[a]+1;
                  if(counter[graph[a][i]]>2&&graph[a][i].size()==1)
                  result=min(result,counter[])
                    dfs(graph[a][i]);
              }


          }




}*/
int main()
   {
     take2(n,m)
    while(m--){

        take2(a,b);
        ar[a][b]=1;
        ar[b][a]=1;
        graph[a].push_back(b);
        graph[b].push_back(a);

    }
    ll result=1e16,temp;
    f(i,1,n+1)
       f(j,i+1,n+1)
       {
           if(ar[i][j])
           {

               f(k,j+1,n+1)
                 if(ar[j][k]&&ar[i][k]){
                        //cout<<i<<" "<<j<<" "<<k<<"p"<<result<<endl;
                        temp=graph[i].size()+graph[j].size()+graph[k].size()-6;
                            result=min(result,temp);
            }
        }

}
if(result!=1e16)
 cout<<result<<endl;
 else puts("-1");

}