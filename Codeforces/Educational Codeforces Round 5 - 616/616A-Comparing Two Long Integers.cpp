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
char a[N],b[N];
int main()
{
    string c,d;

  scanf("%s",a);
  scanf("%s",b);
  int lena=strlen(a);
  int lenb=strlen(b);
  int check=0;
  f(i,0,lena){
     if(a[i]!='0'){
        check=1;
     }
     if(check) c.push_back(a[i]);

  }
     check=0;
  f(i,0,lenb){
     if(b[i]!='0'){
        check=1;
     }
     if(check) d.push_back(b[i]);

  }
   if(c.size()>d.size())
     puts(">");
     else if(c.size()<d.size())
     puts("<");
   else{

      f(i,0,c.size()){
          if(c[i]>d[i])
          {

              puts(">");
              return 0;
          }
          if(c[i]<d[i])
          {

              puts("<");
              return 0;
          }


      }
      puts("=");

   }

return 0;
}