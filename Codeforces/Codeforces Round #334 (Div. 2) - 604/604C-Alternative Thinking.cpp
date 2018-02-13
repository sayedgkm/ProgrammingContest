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
     take1(n); int counter=0; int check=0;
     string s,p,q;
     cin>>s;
     char m='1',y='0';
     f(i,0,n)
     {
         if(s[i]==m){p.push_back(s[i]);
               if(s[i]=='0')
                     m='1';
                else
                    m='0';
             }
            if(s[i]==y)
            {
                q.push_back(s[i]);
                if(s[i]=='0')
                     y='1';
                else
                    y='0';
            }
     }
  //  cout<<p<<endl<<q<<endl;
   int lenp=p.length();
   int lenq=q.length();
     cout<<min(n,max(lenp,lenq)+2)<<endl;

}