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
int b[500],g[500];
int main()
{
    int n;
    take1(n);
    while(n--){
        char c;int x,y;
        cin>>c>>x>>y;
        if(c=='F'){
            if(x==y)
                 g[x]++;
            else{

                f(i,x,y+1) g[i]++;
            }
        }
        else{
            if(x==y)
                 b[x]++;
            else{

                f(i,x,y+1) b[i]++;
            }

        }

    }
     ll ans=0;
        f(i,1,367)
          ans=max(ans,(ll)2*min(b[i],g[i]));
        cout<<ans<<endl;
      return 0;
}