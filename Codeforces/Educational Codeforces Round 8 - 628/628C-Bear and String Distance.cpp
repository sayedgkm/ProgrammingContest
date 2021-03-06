// ==========================================================================
//
//                   Bismillahir-Rahmanir-Rahim
//
// ==========================================================================
#include <bits/stdc++.h>
#define        ll                              long long
#define        f(x,y,z)                        for(int x=y;x<z;x++)
#define        take1(a);                       scanf("%d",&a);
#define        take2(a,b);                     scanf("%d%d",&a,&b);
#define        take3(a,b,c);                   scanf("%d%d%d",&a,&b,&c);
#define        take4(a,b,c,d);                 scanf("%d%d%d%d",&a,&b,&c,&d);
#define        pii                             pair<int,int>
#define        mem(a,x)                        memset(a,x,sizeof(a))
#define        N                               1000010
#define        M                               1000000007
#define        pi                              acos(-1.0)
#define        ff                              first
#define        ss                              second
#define        pb                              push_back
using namespace std;
char go(char a,int value){
     if(!value) return a;
     if(abs(a-'a')>=value)
           return a-value;
     if(abs(a-'z')>=value)
        return a+value;
      if(abs(a-'a')>abs(a-'z')){
        return 'a';
      }
      else return 'z';
}
int main()
{
    int n,value;string s,ans;
    cin>>n>>value;
    cin>>s;
    f(i,0,s.length()){
       ans+=go(s[i],value);
       value-=abs(s[i]-ans[i]);
    }
    if(value!=0){
        puts("-1");
    }
    else cout<<ans<<endl;
      return 0;
}