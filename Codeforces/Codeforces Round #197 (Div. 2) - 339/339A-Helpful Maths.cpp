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
int main()
{
    char s[1000];
    int ar[1000],i,j;
    int q=0;
    gets(s);
    for(i=0;i<strlen(s);i++){
        if(s[i]!='+'){
             ar[q]=s[i]-'0';
             q++;
        }
    }
    sort(ar,ar+q);
    for(i=0;i<q;i++){
        if(i!=q-1)
             printf("%d+",ar[i]);
        else
            printf("%d\n",ar[i]);
    }
      return 0;
}