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
int ar[15],w[1000+10];ll le,ri;
int main()
   {
     string a;int res=0,m;
     cin>>a>>m;
     f(i,0,a.length())
         if(a[i]=='1')
               ar[res++]=i+1;
               if(!res){
                puts("NO");return 0;
               }
              int check=0,check1,xx=0;
              loop:;
              le=ar[xx];
                check=le;
                w[0]=ar[xx];
                xx++;
                ri=0;


     f(i,1,m){
         if(i%2==0){
                check1=0;
             f(j,0,res)
            {
               if(ar[j]!=check&&le+ar[j]>ri)
               {
                   check=ar[j];
                   check1=1;
                   w[i]=ar[j];
                   le+=ar[j];
                   break;
               }

          }
          if(check1==0)
          {
             if(xx==res) {puts("NO");return 0;}
       else goto loop;
          }

         }
         else
         {

              check1=0;
             f(j,0,res)
            {
               if(ar[j]!=check&&ri+ar[j]>le)
               {
                   check=ar[j];
                   check1=1;
                   w[i]=ar[j];
                   ri+=ar[j];
                   break;
               }

          }
          if(check1==0)
          {
                   if(xx==res) {puts("NO");return 0;}
       else goto loop;

          }




         }

     }
     puts("YES");
     f(i,0,m)
       cout<<w[i]<<" ";
}