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
int ar[1000000];
int main()
   {
       take2(a,b)  int maxi=0,temp,ans=0;
       f(i,0,a) {cin>>ar[i];maxi=max(maxi,ar[i]);}
       if(b>=a){
        cout<<maxi<<endl;return 0;
       }
       temp=(a-b)*2;
       //cout<<temp<<endl;
       for(int i=0,j=temp-1;i<temp;i++,j--){

           ans=max(ans,ar[i]+ar[j]);
       }
       cout<<max(maxi,ans)<<endl;

}