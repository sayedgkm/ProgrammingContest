// ==========================================================================
//
//                   Bismillahir-Rahmanir-Rahim
//
// ==========================================================================

#include <bits/stdc++.h>
#define ll long long
#define f(x,y,z) for(int x=y;x<z;x++)
#define take1(a); scanf("%d",&a);
#define take2(a,b); scanf("%d%d",&a,&b);
#define take3(a,b,c); scanf("%d%d%d",&a,&b,&c);
#define take4(a,b,c,d); scanf("%d%d%d%d",&a,&b,&c,&d);
using namespace std;
int aa[200],cc[200][200];
int main()
   {
  int n;
  take1(n);
  string p;
  while(n--)
  {
      cin>>p; int counter=0;
          int ar[200]={0};
      f(i,0,p.length())
            ar[p[i]]++;
            //cout<<ar[98]<<endl;
            int a,b;
      f(i,0,200)
         {
             if(ar[i]!=0) {
                counter++;
                if(counter==1)
                a=i;
               if(counter==2)
                    b=i;
             }


         }
        // cout<<a<<endl<<b<<endl;
         if(counter==1)
            aa[a]+=p.length();
         if(counter==2){
            cc[a][b]+=p.length();

         }

  }
 // cout<<cc[97][98]<<endl;
int  maxi=0,len; string k;
  for(int i='a';i<='z';i++)
        for(int j=i+1;j<='z';j++)
          maxi=max(maxi,cc[i][j]+aa[i]+aa[j]);

    cout<<maxi<<endl;
}