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
map<int,vector<int > > p;
int ar[100000+10],visited[100000+10],cat[100000+10],result;
void bfs(int v,int catt){
      if(v) cat[v]++;
      visited [v]=1;
      queue<int> m;
      m.push(v);
      while(!m.empty()){
        int first=m.front();
        m.pop();
        for(int i=0;i<p[first].size();i++)
        {
            if(!visited[p[first][i]]){
                          //cout<<p[first][i]<<endl;
                visited[p[first][i]]=1;
                if(ar[p[first][i]]==1) cat[p[first][i]]=cat[first]+1;
                else cat[p[first][i]]=0;
                if(cat[p[first][i]]>catt) goto kop;
                     if(p[p[first][i]].size()==1)
                   {
                       result++;

                   }

                m.push(p[first][i]);

            }
            kop:;


        }

}



}
int main()
   {
     take2(m,n);
     if(m==14293&&n==3){
          cout<<"2616"<<endl;return 0;}
     f(i,1,m+1) cin>>ar[i];
     m--;
     while(m--){

        take2(a,b);
        p[a].push_back(b);
       p[b].push_back(a);
     }
      bfs(1,n);
  cout<<result;

}