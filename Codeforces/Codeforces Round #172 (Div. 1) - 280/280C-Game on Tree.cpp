#include<bits/stdc++.h>
using namespace std;
 double ans=0;
 vector<int> adj[100010];
void dfs(int u,double d,int p){

    ans+=1.0/d;
    for(int i=0;i<adj[u].size();i++){
          int v=adj[u][i];
           if(v==p) continue;
           dfs(v,d+1,u);
    }


}
int main(){

   int n;
   cin>>n;
   for(int i=0;i<n-1;i++){
      int a,b;
      cin>>a>>b;
      adj[a].push_back(b);
      adj[b].push_back(a);

   }
   dfs(1,1,-1);
   cout<<setprecision(20)<<ans<<endl;

}