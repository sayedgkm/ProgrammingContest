#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
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
#include <algorithm>
using namespace std;
#define ll long long
#define f(x,y,z) for(int x=y;x<z;x++)
#define take1(a); scanf("%d",&a);
#define take2(a,b); scanf("%d%d",&a,&b);
#define take3(a,b,c); scanf("%d%d%d",&a,&b,&c);
#define take4(a,b,c,d); scanf("%d%d%d%d",&a,&b,&c,&d);
int main()
{

    string s;
    cin >> s;
    s = "00" + s;
    int num;
    int len = s.length();
    f(i, 0, len)
        f(j, i + 1, len)
        f(k, j + 1, len)
    {
            num = (s[i] - '0')*1e2 + (s[j] - '0')*1e1 + s[k] - '0'; if (num % 8 == 0) { puts("YES"); printf("%d", num); return 0; }
        }

    puts("NO");




    return 0;
}