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
int main()
{
 string s;
 cin>>s;  int a=0,b=0,com=0;
   f(i,0,s.length()-1){
    if(i<=s.length()-3){
        if(s[i]=='A'&&s[i+1]=='B'&&s[i+2]=='A'){
             i+=2;com++;continue;
        }
       if(s[i]=='B'&&s[i+1]=='A'&&s[i+2]=='B'){
            com++; i+=2;continue;
        }
    }
    if(s[i]=='A'&&s[i+1]=='B') a++;
    if(s[i]=='B'&&s[i+1]=='A') b++;
 }
 if(com>=2){
    puts("YES");
 }
 else if(com==1&&(a>=1||b>=1)){
    puts("YES");
 }
 else if(a>=1&&b>=1){
     puts("YES");
    }
    else puts("NO");
return 0;
}