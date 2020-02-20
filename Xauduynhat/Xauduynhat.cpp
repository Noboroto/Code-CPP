#include <vector>
#include <iostream>

using namespace std;

vector <int> count;

int main () {
    string s;
    cin >> s;
    int n = s.length();
    for (int i = 0; i <= 1000; ++i){
        count.push_back(0);
    }
    int i = 0, j = 0, ans = 0;
    while (i < n)
    {  
        count [(int)s[i]]++;
        if (count[(int)s[i]] != 1){
            ans = max (ans, i - j);
            while (count[(int)s[i] ] != 1)
            {
                count[(int)s[j] ]--;
                j++; 
            }
        }
        ++i;
    }
    ans = max (ans, i - j);
    cout << ans;
    return 0;
}
    