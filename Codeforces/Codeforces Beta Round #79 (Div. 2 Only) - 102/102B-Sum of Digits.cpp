#include<iostream>
#include<string>
using namespace std;
long long sum,counter=0,p,q=1;
 string s;
void rec()
{
  if(s.length()==1)
  {
      cout<<"0"<<endl;
      return;
  }
    if(counter==0)
    {
        for(long long i=0;i<s.length();i++)
            sum+=s[i]-'0';

    }
    else
    {
        p=sum;
        sum=0;
        while(p!=0)
        {

          sum+=p%10;  p/=10;
        }


    }

    if(sum>9)
    {
        counter++;
         rec();
    }
    if(sum<10&&q==1)
    {
       cout<<counter+1<<endl; q=0;
    }


}
int main()
{

    cin>>s;
  rec();
}