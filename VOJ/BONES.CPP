#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

void Init ()
{
}

map <int, int> m;
int s1, s2, s3, position, result;

int main ()
{
    //Init();
    int sum = 0;
    result = 0;
    cin >> s1 >> s2 >> s3;
    for (int x = 1; x <= s1; ++x) 
    {
        sum += x;
        for (int y = 1; y <= s2; ++y) 
        {
            sum += y;
            for (int z = 1; z <= s3; ++z) 
            {
                sum += z;
                m[sum]++;
                if (m[sum] > result) 
                {
                    result = m[sum];
                    position = sum;
                }
                if (m[sum] == result) 
                {
                    position = min (position, sum);
                }
                sum -=z;
            }
            sum -=y;
        }
        sum -=x;
    } 
    cout << position;
    return 0;
}