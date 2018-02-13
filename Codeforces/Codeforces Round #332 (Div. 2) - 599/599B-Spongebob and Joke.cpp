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
int ar[100000+10],br[100000+10],cr[100000+10],dr[100000+10];
int main()
   {
       take2(n,m);
     f(i,1,n+1){
       cin>>ar[i];
       cr[ar[i]]=i;
       dr[ar[i]]++;
     }
       f(i,1,m+1){
         cin>>br[i];
         //dr[i]=br[i];
       }


         int check=0;

         f(i,1,m+1)
         {
             //cout<<cr[br[i]]<<endl;
             if(cr[br[i]]==0)
             {

                 puts("Impossible");return 0;
             }


         }
               f(i,1,m+1)
                 if(dr[br[i]]>1) check=1;
         if(check){
             puts("Ambiguity"); return 0;
         }

              puts("Possible");
              f(i,1,m+1)
                cout<<cr[br[i]]<<" ";





}