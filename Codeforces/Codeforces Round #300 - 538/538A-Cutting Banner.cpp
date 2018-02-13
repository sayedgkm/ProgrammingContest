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
     string s,s1;
     s1="CODEFORCES";
     cin>>s; int p=0,counter=0;
     if(s.length()<11){
        puts("NO");return 0;
     }
     f(i,0,s.length())
         {
              if(s1[p]!=s[i]) break;
              counter++;p++;
          }
    f(i,s.length()-10+counter,s.length()){
          if(s1[p]!=s[i]){ puts("NO");return 0;}p++;
    }
            puts("YES");

}