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
int ar[1005];vector<int> vc;
int main()
{
    string s,mini,temp;
    int n;
    cin>>n>>mini;
   temp= s=mini;
    f(i,0,n){
        f(j,0,10){
            f(k,0,n){
                if(temp[k]=='9')
                    temp[k]='0';
                else temp[k]+=1;
            }
            mini=min(temp,mini);
         }
         temp.clear();
         temp=s[n-1]+s.substr(0,n-1);
        mini=min(temp,mini);
        s=temp;
    }
    cout<<mini<<endl;
return 0;
}