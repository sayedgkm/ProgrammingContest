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
     ll a,b,c,result,temp;
     cin>>c>>a>>b;
    if(a>0&&b>0||a<0&&b<0)
    {
        a=abs(a);
        b=abs(b);
        if(b<a)
            swap(a,b);
            a--;
        result=b/c-a/c;

    }
    else
        result=1+abs(a/c)+abs(b/c);
cout<<result;
}