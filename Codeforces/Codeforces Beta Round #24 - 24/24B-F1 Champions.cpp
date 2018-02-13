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
#define pii pair<int,int>
#define mem(x,y) memset(x,y,sizeof(x));
using namespace std;
struct champion{

    string n;
    int position[100] ;
    int point;
}race[1005];
bool comp(champion x, champion y)
{
    if (x.point != y.point) return x.point > y.point;
    else for (int i = 1; i<50; i++)
    {
        if (x.position[i] != y.position[i])
            return x.position[i]>y.position[i];
    }
}
bool comp1(champion x, champion y)
{
    if (x.position[1] != y.position[1]) return x.position[1] > y.position[1];
    else    if (x.point!=y.point) return x.point>y.point;
    else for (int i = 1; i<50; i++)
    {
        if (x.position[i] != y.position[i])
            return x.position[i]>y.position[i];
    }
}


int main()
{
    int n, a, k = 0, j;;
    int ar[] = { 0, 25, 18, 15, 12, 10, 8, 6, 4, 2, 1 };
    cin >> n;
    while (n--)
    {

        cin >> a;
        getchar();
        for (int i = 1; i <= a; i++)
        {
            string s;
            cin >> s;
            for (j = 0; j<=k; j++)
            {
                if (race[j].n == s)
                    break;
            }
            if (j>k)
            {
                race[k].n = s;
                race[k].position[i]++;
                if (i <= 10)
                    race[k].point += ar[i]; k++;
            }
            else
            {
                race[j].position[i]++;
                if (i <= 10)
                    race[j].point += ar[i];

            }

        }


    }

    sort(race, race + k, comp);
    cout << race[0].n << endl;
    sort(race, race + k, comp1);

    //while (race[k].p == race[k + 1].p&&race[k].w == race[k + 1].w){ k++; }
    cout << race[0].n << endl;
    return 0;
}