#include <string>
#include <iostream>

using namespace std;

typedef long long ll;
const int N = 10;

struct BigNum{
    ll num[N + 1];
    int n;
    bool am;
    BigNum (){                                                         
        for (int i = 0; i <= N; ++i) 
            num[i] = 0;
        am = false;
        n = 0;
    }

    bool operator < (BigNum x){
        if (n < x.n) return true;
        for (int i = 1; i <= N; ++i) if (num[i] < x.num[i]) return true;
        return false;
    }

    bool operator > (BigNum x){
        if (n > x.n) return true;
        for (int i = 1; i <= N; ++i) if (num[i] > x.num[i]) return true;
        return false;
    }
    
    void swap (BigNum &a, BigNum &b){
        BigNum tmp = b;
        b = a;
        a = tmp;
    }

    bool operator == (BigNum x){
        if (n != x.n) return false;
        for (int i = 1; i <= N; ++i) if (num[i] != x.num[i]) return false;
        return true;
    }

    BigNum min (BigNum a, BigNum b){
        if (a < b) return a;
        else return b;
    }

    BigNum max (BigNum a, BigNum b){
        if (a > b) return a;
        else return b;
    }

    BigNum abs (BigNum x){
        BigNum ans = x;
        ans.am = false;
        return ans;
    }

    BigNum operator - (BigNum x){
        BigNum ans;
        int tmp = 0;
        if (this -> am && x.am){
            ans = *this + abs (x);
            return ans;
        }
        if (this -> am){
            ans = abs (*this) + x;
            ans.am = true;
            return ans;
        }
        if (x.am){
            return *this + abs (x);
        }
        if (*this < x){
            swap (*this, x);
            ans.am = true;
        }
        for (int i = N; i > 0; --i){
            int a = num[i] , b =  x.num[i];
            if (a < b) {
                b += 10;
            }
            int c = a - b - tmp;
            if (a < b) tmp = 1;
            ans.num[i] = c;
            if (ans.num[i] != 0) ans.n = i;
        }
        return ans;
    }

    BigNum operator + (BigNum x){
        BigNum ans;
        if ((am || x.am) && !(am && x.am)) {
            ans = abs (max (*this, x)) - abs(min(*this, x));
            ans.am = max (*this,x).am;
            return ans;
        }
        ans.am = am && x.am;
        int tmp = 0;
        for (int i = N; i > 0; --i){
            int a = num[i] , b =  x.num[i];
            int c = a + b + tmp;
            tmp = c / 10;
            c = c % 10;
            ans.num[i] = c;
            if (ans.num[i] != 0) ans.n = i;
        }
        return ans;
    }

    BigNum operator * (BigNum x){
        BigNum ans;
        ans.am = (am && x.am) ? false : (am || x.am);
        
    }

    void writeln (){
        int i = 0;
        if (am) cout << '-';
        while (num[i] == 0) ++i;
        for (; i <= N; ++i){
            cout << num[i];
        }        
        cout << endl;
    }
};

BigNum TransToBigNum (string s){
    BigNum ans;
    ans.n = (int)s.length();
    int j = ans.n - 1;
    for (int i = N; i > N - ans.n; --i){
        if (s[j] == '-') break;
        ans.num[i] = (int)s[j] - '0';
        j--;
    }
    if (s[0] == '-') {
        ans.am = true;
        ans.n--;
    }
    if (ans.n == 1 && s[0] == '0') ans.n = 0; 
    return ans;
}

string x, y;

int main (){
    getline(cin, x);
    getline(cin, y);
    BigNum a = TransToBigNum (x);
    BigNum b = TransToBigNum (y);
    BigNum ans = a + b;
    ans.writeln();
    ans = a - b;
    ans.writeln();
    char c;
    cin >> c;
}