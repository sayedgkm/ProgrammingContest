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
using namespace std;
int main()
{
  int ar[505][505]={0};
  int c=1;
  int a,b,x,y;
  cin>>a>>b>>x>>y;
  string s;
  cin>>s;
  cout<<"1 ";
  ar[x][y]=1;
  f(i,0,s.length()-1){
      if(s[i]=='U')
             if(x>1) x--;
      if(s[i]=='R')
          if(y<b) y++;
      if(s[i]=='L')
           if(y>1) y--;
      if(s[i]=='D')
           if(x<a) x++;
      if(ar[x][y]) cout<<"0 ";
      else{
        cout<<"1 ";c++;
      }
      ar[x][y]=1;
  }
  cout<<a*b-c<<endl;
return 0;
}