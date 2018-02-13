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
int ar[N];
int main()
{
   string a,b;
   cin>>a>>b;
   int lena=a.length();
   int lenb=b.length();
   ar[0]=b[0]-48;
   f(i,1,lenb)
       ar[i]=ar[i-1]+(b[i]-'0');
       ll ans=0,temp=0;
       int diff=lenb-lena;
     f(i,0,lena){

              if(i==0)
                 temp=ar[diff];
             else temp=ar[i+diff]-ar[i-1];
             ans+=abs((a[i]-'0')*(diff+1)-temp);

     }
       cout<<ans<<endl;
return 0;
}