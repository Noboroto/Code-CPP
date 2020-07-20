#include <bits/stdc++.h>

using namespace std;

void Init ()
{
    const string FileINP = "GAME25" + (string)".INP";
    const string FileOUT = "GAME25" + (string)".OUT";
    freopen (FileINP.c_str(), "r", stdin);
    freopen (FileOUT.c_str(), "w", stdout);
}

int t = 0;
bool a[5][5] , A, B;

int main ()
{
    char s;
    Init();
    while (true)
    {
        s =  getchar();
        if (s < '0' || '9' < s) break;
        t = t * 10 + (s - '0'); 
    } 
    while (t > 0)
    {
        A = false;
        B = false;
        for (int i = 0; i < 5; ++i)
        {
            for (int j = 0; j < 5; ++j)
            {
                s = getchar ();
                while (s != 'A' && s != 'B')
                {
                    s = getchar ();
                }
                if (A && B) continue;
                a[i][j] = (s == 'A');
                if (i > 1 && j > 1)
                {
                    A = A || (a[i][j] && a[i - 1][j - 1] && a[i - 2][j - 2]);
                    B = B || (!a[i][j] && !a[i - 1][j - 1] && !a[i - 2][j - 2]);
                }
                if (i > 1 && j < 3)
                {
                    A = A || (a[i][j] && a[i - 1][j + 1] && a[i - 2][j + 2]);
                    B = B || (!a[i][j] && !a[i - 1][j + 1] && !a[i - 2][j + 2]);
                }
                if (j > 1) 
                {
                    A = A || (a[i][j] && a[i][j - 1] && a[i][j - 2]);
                    B = B || (!a[i][j] && !a[i][j - 1] && !a[i][j - 2]);
                }
                if (i > 1)
                {
                    A = A || (a[i][j] && a[i - 1][j] && a[i - 2][j]);
                    B = B || (!a[i][j] && !a[i - 1][j] && !a[i - 2][j]);
                }
            }
        }    
        if (A && B) printf ("draw");
        else if (A) printf ("A wins");
        else printf ("B wins");
        printf ("\n");
        t--;
    }
    return 0;
}