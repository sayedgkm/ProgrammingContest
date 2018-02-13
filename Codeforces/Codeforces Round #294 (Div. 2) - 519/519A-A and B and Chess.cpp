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
using namespace std;
int main()
{
 string s[100]; int wh=0,bl=0;
 f(i,0,8)
    {
       cin>>s[i];
       f(j,0,8)
       {
           if(s[i][j]=='Q')
            wh+=9;

           if(s[i][j]=='R')
            wh+=5;
            if(s[i][j]=='B')
            wh+=3;
            if(s[i][j]=='N')
            wh+=3;
            if(s[i][j]=='P')
            wh+=1;
            if(s[i][j]=='q')
            bl+=9;

           if(s[i][j]=='r')
            bl+=5;
            if(s[i][j]=='b')
            bl+=3;
            if(s[i][j]=='n')
            bl+=3;
            if(s[i][j]=='p')
            bl+=1;




       }


    }
      if(bl>wh)
        puts("Black");
      if(wh>bl)
        puts("White");
      if(bl==wh)
        puts("Draw");
}