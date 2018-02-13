#include<bits/stdc++.h>
#define ll long long
using namespace std;

 double ans=0;
 vector<int>v;
 map<int,int>mp;
void dfs(long long u){
    if(u>=1000000000) return;
    v.push_back(u);
    mp[u]=1;
    if(mp[u*10+4]==0) dfs(u*10+4);
    if(mp[u*10+7]==0) dfs(u*10+7);

}
int main(){

   dfs(4);
   dfs(7);
   v.push_back(0);
   v.push_back(1000000009);
   sort(v.begin(),v.end());
   long long  tot=0;
   int a,b,c,d;
   cin>>a>>b>>c>>d;
   int k;
   cin>>k;;
    for(int i=1;i<v.size();i++){
          if(i+k-1>=v.size()) break;
          if(v[i]>=a&&v[i+k-1]<=d){
                ll l,r;
                 if(v[i]>b)
                 l=min(max(0,b-v[i-1]+1),b-a+1);
                 else l=min(v[i]-v[i-1],v[i]-a+1);
                if(v[i+k-1]<c)
                 r=min(max(0,v[i+k]-c),d-c+1);
                else r=min(d-v[i+k-1]+1,v[i+k]-v[i+k-1]);
                 //cout<<l<<" "<<r<<endl;
                tot+=l*r;
          }
    }
     for(int i=1;i<v.size();i++){
          if(i+k-1>=v.size()) break;
          if(v[i]>=c&&v[i+k-1]<=b){
                ll l,r;
                 if(v[i]>d)
                   l=min(max(0,d-v[i-1]),d-c+1);
                   else l=min(v[i]-v[i-1],v[i]-c+1);
                   if(v[i+k-1]<a)
                   r=min(max(0,v[i+k]-a),b-a+1);
                else r=min(b-v[i+k-1]+1,v[i+k]-v[i+k-1]);
                tot+=l*r;
                if(k==1&&v[i]>=c&&v[i]<=d&&v[i]>=a&&v[i]<=b) tot--;
          }
    }
    cout<<setprecision(20)<<fixed<<(double) tot/((ll)(b-a+1)*(ll)(d-c+1))<<endl;
return 0;
}