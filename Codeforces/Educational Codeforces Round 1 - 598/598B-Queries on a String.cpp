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
     //vector<char> p;
    string s;
     cin>>s;


       int n,a,b,c,dif;
       scanf("%d",&n);
       while(n--)
       {
           cin>>a>>b>>c;
           dif=abs(b-a)+1;
           dif=c%dif;
           a,b;a--;

       rotate(s.begin()+a,s.begin()+b-dif,s.begin()+b);

        
    }
cout<<s;
}