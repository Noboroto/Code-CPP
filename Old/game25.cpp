#include <cstdio>
using namespace std;

#define pii pair<int, int> 
#define TASK "GAME25"

int n;
char b[6][6];

char c;
void readint(int &q) 
{
    c = getchar();
    while (c > '9' || c < '0') c = getchar();
    q = 0;
    while (c >= '0' && c <= '9') 
    {
        q = 10 * q + c - '0';
        c = getchar();
    }
}

void readchar(char &x) 
{
    while (c < 'A' || c > 'B') c = getchar();
    x = c; c = getchar();
}

void driver()
{
    freopen ("game25.inp","r",stdin);
    freopen ("game25.out","w",stdout);
    readint(n);
    for (int q=0;q<n; ++q) 
    {
        for (int i=0; i<5; ++i) 
        for (int j=0; j<5; ++j) 
            readchar(b[i][j]);

        bool oa = 0, ob = 0;

        for (int i=0; i<3; ++i) 
        {
            for (int j=0; j<5; ++j) 
            {
                if ((b[i][j] == b[i+1][j]) && (b[i][j] == b[i+2][j])) 
                    if (b[i][j] == 'A') oa = 1; else ob = 1;
                if ((b[j][i] == b[j][i+1]) && (b[j][i] == b[j][i+2]))
                    if (b[j][i] == 'A') oa = 1; else ob = 1;
            }
        }
        
        for (int i=1; i<4; ++i) 
        {
            for (int j=1; j<4; ++j) 
            {
                if((b[i-1][j-1] == b[i][j]) && (b[i][j] == b[i+1][j+1])) 
                    if (b[i][j] == 'A') oa = 1; else ob = 1;
                if((b[i-1][j+1] == b[i][j]) && (b[i][j] == b[i+1][j-1])) 
                    if (b[i][j] == 'A') oa = 1; else ob = 1;                
            }
        }

        if (oa ^ ob) 
        {
            if (oa) printf ("A wins\n");
            else printf ("B wins\n");
        }
        else 
        {
            printf ("Draw\n");
        }
    }
}

int main()
{
    driver();
}
