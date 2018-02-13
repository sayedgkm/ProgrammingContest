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
ll rema[1000000+10],remb[1000000+10],a,b;
ll bigmod(ll m,ll p){
      if(p==0)
         return 1;
      if(p%2==0)
      {
          ll ret=bigmod(m,p/2);
             return (ret%b*ret%b)%b;

      }
    else
         return (m%b*bigmod(m,p-1)%b)%b;

}
int main()
   {

     string s;
      cin>>s;
      cin>>a>>b;
      ll j=s.length();
      ll len=j;
      --j;  ll p=0,pos,m=1;
      f(i,0,len){
           if(i>0)
          rema[i]=(rema[i-1]*10+(s[i]-'0'))%a;
          else
            rema[i]=(s[i]-'0')%a;
            remb[j]=(remb[j+1]+(s[j]-'0')*m)%b;
            j--;
            m=(m%b*10)%b;
      }

      int check=0;
      f(i,0,len-1)
      {
          if(!rema[i]&&!remb[i+1]&&s[i+1]!='0')
          {
              pos=i;check=5; break;}
        }

        if(check==0)
            puts("NO");
        else{
                puts("YES");
            f(i,0,len)
        {
            cout<<s[i];
            if(i==pos)
                cout<<"\n";

        }
        }
}