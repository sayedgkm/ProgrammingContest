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
#define        N                     1000010
#define        M                     1000000007
#define        pi                    acos(-1.0)
using namespace std;
map<string,vector<string> > mp;
vector<string> v;
map<string,int> lef,ri,ans;
string ar[300];
int sum=0;
int main()
{
  take1(n);
  string a,c,b; int p=0;
  f(i,0,n){
    cin>>a>>c>>b;
    f(j,0,a.length()) if(a[j]>='A'&&a[j]<='Z') a[j]+=32;
    f(j,0,b.length()) if(b[j]>='A'&&b[j]<='Z') b[j]+=32;
    if(!ri[b])
      ar[p++]=b;
      if(!ri[a])
        ar[p++]=a;
      ri[a]=ri[b]=1;
     mp[b].push_back(a);
     mp[a].push_back(b);
  }
 for(int i=0;i<p;i++){
      for(int j=0;j<mp[ar[i]].size();j++){
          ans[mp[ar[i]][j]]=max(ans[ar[i]]+1,ans[mp[ar[i]][j]]);
        }
}
  int maxi=0;
  for(int i=0;i<p;i++){
        int qq=ans[ar[i]];
    maxi=max(ans[ar[i]],maxi);
  }

  cout<<maxi<<endl;
return 0;
}