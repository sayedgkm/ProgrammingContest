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
#define        ff                    first
#define        ss                    second
#define        pb                    push_back
using namespace std;
int ar[1000];
int main()
{
    int n;
    cin>>n; int in=0;int c=0;
    f(i,0,n){
        cin>>ar[i];
        if(ar[i]==1){
            in=i;
        }
        if(ar[i]==0)
             c++;
    }
     if(c==n){

        puts("0");
        return 0;
     }
      c=0; vector<int> v;
      int check=0;
      for(int i=0;i<=in;i++){

           if(check){
             if(ar[i]==0)
                 c++;
             else {
                 v.pb(c+1);
                 c=0;

             }

           }
           if(ar[i]==1)
             check=1;
        }
       ll ans=1;
       for(int i=0;i<v.size();i++)
              ans*=v[i];
        cout<<ans<<endl;
   return 0;
}