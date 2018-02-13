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
string a,b;
bool fun(int r,int c){

     for(int j=1;j<=c;j++)
     {
           bool check=true;int p=0;
         for(int i=1;i<=r;i++)
         {
             if(a[p*c+j]!='X')
                check=false;
             p++;
         }
         if(check) return true;
     }


  return false;

}
int main()
{
    vector<pii> ans;
    take1(test)
        while(test--){
  cin>>b;
     a='0'+b;
     if(fun(1,12))
        ans.push_back(pii(1,12));
     if(fun(2,6)) ans.push_back(pii(2,6));
     if(fun(3,4))
        ans.push_back(pii(3,4));
     if(fun(4,3)) ans.push_back(pii(4,3));
     if(fun(6,2))
        ans.push_back(pii(6,2));
     if(fun(12,1)) ans.push_back(pii(12,1));
    cout<<ans.size()<<" ";
    f(i,0,ans.size())
       cout<<ans[i].first<<"x"<<ans[i].second<<" ";
       cout<<endl;
       ans.clear();a.clear();
    }
return 0;
}