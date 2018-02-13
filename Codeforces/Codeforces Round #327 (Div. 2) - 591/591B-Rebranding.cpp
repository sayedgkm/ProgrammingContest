#include <iostream>
#include <string>
#include <string.h>
#include <cstdio>
#define ll long long
#define f(x,y,z) for(int x=y;x<z;x++)
#define take1(a); scanf("%d",&a);
#define take2(a,b); scanf("%d%d",&a,&b);
#define take3(a,b,c); scanf("%d%d%d",&a,&b,&c);
#define take4(a,b,c,d); scanf("%d%d%d%d",&a,&b,&c,&d);
using namespace std;
struct abc{

    char x, y;



} p[200];
int main()
{
    for (int i = 'a'; i <= 'z'; i++)
    {
        p[i].x = i;   p[i].y = i;
    }
    int a, b;
    cin >> a >> b;
    string s;
    cin >> s;
    while (b--)
    {
        char m, n;
        cin >> m >> n;
        for (int i = 'a'; i <= 'z'; i++){
            if (p[i].y == m){
                p[i].y = n;

            }
            else if (p[i].y == n)
                p[i].y = m;
        }
    }
    for (int i = 0; i<a; i++)
    {
        if (s[i] == p[s[i]].x)
            cout << p[s[i]].y;
    }
    cout << endl;

}