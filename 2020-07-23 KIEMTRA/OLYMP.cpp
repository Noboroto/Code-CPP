#include <bits/stdc++.h>

using namespace std;

void Init ()
{
    const string FileINP = "OLYMP" + (string)".INP";
    const string FileOUT = "OLYMP" + (string)".OUT";
    freopen (FileINP.c_str(), "r", stdin);
    freopen (FileOUT.c_str(), "w", stdout);
}

int const N = 1e6 + 1;

struct Student
{
    int skill, intell;
    long long speed;
    Student (int _skill = 0, int _intell = 0, int k = 0)
    {
        skill = _skill;
        intell = _intell;
        speed = trunc((long double)max ((k - _skill), 0) / (long double) _intell);
        speed += (_skill + speed * _intell < k);
    }

    bool operator < (Student &b)
    {
        if (speed < b.speed) return true;
        return false;
    }
};

int n, c, k, i;
Student s[N];

void GetInput ()
{
    scanf ("%d%d%d", &n, &c, &k);
    int u, v;
    for (i = 0; i < n; ++i)
    {
        scanf ("%d%d", &u, &v);
        s[i] = Student(u, v, k);
    }
}

int GetResult ()
{
    int ans = 0;
    sort (s, s + n);
    for (i = 0; i < n; ++i)
    {
        if (c < 1) break;
        ans += (s[i].speed <= c);
        c -= s[i].speed;
    }
    return ans;
}

int main ()
{
    Init();
    GetInput();
    printf ("%d", GetResult());
    return 0;
}