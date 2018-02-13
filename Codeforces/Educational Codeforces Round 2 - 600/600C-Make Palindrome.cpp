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
int ar[50];
int main()
{
    string s;
    cin>>s; int check=0;
     f(i,0,s.length()) {ar[s[i]-'a']++;
     }
     //cout<<ar[0]<<ar[1]<<ar[2]<<endl;
     f(i,0,26){
         if(ar[i]%2!=0){

                 for(int j=25;j>=0;j--){
                       if(ar[j]%2!=0){
                             ar[i]++;
                           ar[j]--;
                           break;

                       }
                 }

         }

     }
     poop:;
    // cout<<ar[0]<<ar[1]<<ar[2]<<ar[3]<<endl;
  //cout<<check<<endl;
  f(i,0,26){
         if(!ar[i]) continue;
           f(j,0,ar[i]/2){
            cout<<(char)(i+'a');
           }


  }

     f(i,0,25)
       if(ar[i]%2==1)
          cout<<(char)(i+'a');
   for(int i=26;i>=0;i--)
   {
       if(!ar[i]) continue;
           f(j,0,ar[i]/2) {
           cout<<(char)(i+'a');

       }

   }
     cout<<endl;
}