#include <bits/stdc++.h> 

using namespace std;

int main (){
    int h, m;
    long long s;
    cout << "Ban muon tat may sau bao nhieu gio? " << endl;
    cin >> h;
    cout << "va sau bao nhieu phut?" << endl;
    cin >> m;
    s = h*60*60 + m*60;
    string ans = "shutdown -s -t " + to_string(s);
    const char *command = ans.c_str();
    system (command);
    return 0;
}