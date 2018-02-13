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
map <char,char> mp;

int main()
{

    stack<char> st;

      string s;
      cin>>s;  int open=0,close=0;
      f(i,0,s.length()){
        if(s[i]=='<'||s[i]=='('||s[i]=='{'||s[i]=='['){
              st.push(s[i]);

        }
        else{


            if(st.empty())
          {

              puts("Impossible");
              return 0;
          }
            char m=st.top();
            if(s[i]==')'&&m=='('){
                 st.pop();
            }
            else if(s[i]=='}'&&m=='{'){
                 st.pop();
            }
            else if (s[i]=='>'&&m=='<'){
                 st.pop();
            }
            else if(s[i]==']'&&m=='['){
                 st.pop();
            }
                 else
                    {
                        close++;
                        st.pop();
                    }
        }
      }
      if(st.empty())
        cout<<close<<endl;
      else
         puts("Impossible");
return 0;
}