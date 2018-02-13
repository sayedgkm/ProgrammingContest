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
  take1(n);map<string,string> mp;map<string,int>y;
  pair<string,string> s[10000];
  while(n--){

     string a,b;
     cin>>a>>b;
       y[b]++;
       mp[a]=b;
     }
   map<string,string>::iterator it; int id=0;
   for(it=mp.begin();it!=mp.end();it++){
       //cout<<"b"<<endl;
        string res=it->first;
        if(!y[res]){
            s[id].first=res;
            while(1){
                if(mp[res].empty()){
                    s[id].second=res;
                    break;
                }
                res=mp[res];

            }
             id++;
        }

   }
   cout<<id<<endl;
   f(i,0,id){
     cout<<s[i].first<<" "<<s[i].second<<endl;
   }
return 0;
}