#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
int main()
{
string s;int a,m;
cin>>m>>a;
cin>>s;
for(int i=1;i<=a;i++)
{
    for(int j=0;j<m-1;j++)
    {
        if(s[j]=='B'&&s[j+1]=='G')
        {
           // cout<<s[j] <<" "<<s[j+1]<<endl;
            swap(s[j],s[j+1]);
           // cout<<s[j] <<" "<<s[j+1]<<endl;
        j++;
        }
    }

    }
    cout<<s<<endl;
return 0;
}