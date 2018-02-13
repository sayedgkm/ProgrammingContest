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
int ar[100000+5],br[100000+5];
int c[]={0,9,99,999,9999,99999,999999,9999999,99999999,999999999,9999999999};
ll M=1e9+7;
ll pow1(ll p,ll length)
{
    ll res=1;
    f(i,0,length)
      res*=p;
    return res;

}
int main()
   {
     take2(n,k);
     f(i,0,n/k) cin>>ar[i];
     f(i,0,n/k) cin>>br[i];
    ll total=1,counter,cut,high,low;

     f(i,0,n/k) {
           counter=(c[k]/ar[i])+1;
           if(br[i]==0){
           high=(((pow1(10,k-1)-1))/ar[i])+1;
           //cout<<high<<endl;
           counter-=high;}
           else{
           low=((br[i]*pow1(10,k-1))-1)/ar[i];
           high=(((br[i]+1)*pow1(10,k-1))-1)/ar[i];
          // cout<<((br[i]*pow1(10,k-1))-1)<<endl;
           counter-=(high-low);
           }
          // cout<<counter<<endl;
           total=total*counter%M;
     }
     cout<<total<<endl;

}