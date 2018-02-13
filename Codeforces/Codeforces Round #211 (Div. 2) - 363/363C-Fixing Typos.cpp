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
int check[N] = { 0 };
int main()
{
 string s;
 cin >> s;
 vector<char> v;
 char p = s[0]; int c = 0;
 f(i, 0, s.length()){
  if(i>1){
            int si=v.size();
            if(v[si-1]==s[i]&&v[si-2]==s[i]) continue;
            if(v[si-1]==s[i]&&v[si-2]==v[si-3]) continue;
            }
            v.pb(s[i]);
 }
  f(i,0,v.size())
     cout<<v[i];


 return 0;
}