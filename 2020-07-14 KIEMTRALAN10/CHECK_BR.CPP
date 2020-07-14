#include <bits/stdc++.h>

using namespace std;

void Init ()
{
    const string FileINP = "CHECK_BR" + (string)".INP";
    const string FileOUT = "CHECK_BR" + (string)".OUT";
    freopen (FileINP.c_str(), "r", stdin);
    freopen (FileOUT.c_str(), "w", stdout);
}

map <char, char> Check_Pre, Check_Top;

char Get_Result (string s)
{
    stack <char> Stack;
    for (int i = 0; i < s.length(); ++i)
    {
        switch (s[i])
        {
        case '(':
        case '[':
        case '{':
            if (!Stack.empty() && Stack.top() != Check_Top[s[i]]) return 'N';
            Stack.push (s[i]);
            break;
        case ')':
        case '}':
        case ']':
            if (!Stack.empty() && Stack.top() != Check_Pre[s[i]]) return 'N';
            Stack.pop();
        default:
            break;
        }
    }
    if (!Stack.empty()) return 'N';
    return 'Y';
}

void Pre ()
{
    Check_Pre[')'] = '(';
    Check_Pre[']'] = '[';
    Check_Pre['}'] = '{';
    Check_Top['('] = '[';
    Check_Top['['] = '{';
    Check_Top['{'] = '{';
}

int main ()
{
    Pre();
    int n;
    string s;
    //Init();
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> s;
        cout << Get_Result(s);
    }
    return 0;
}