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
int main()
   {
     ll a,b,c,n;
     cin>>n;
     while(n--)
     {
         cin>>a;
         c=(a*(a+1))/2;
  // cout<<c<<endl;
         for(int i=0; ;i++)
         {
             if(pow(2,i)<=a){
                  b=pow(2,i);
                c-=2*b;

             }

                else break;


         }

         cout<<c<<endl;

     }

}