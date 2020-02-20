#include <iostream>
#include <fstream>
#include <string>
#define s "Start"
#define o "Obstacle"
#define a "Acceleration";
#define f "Finish"

using namespace std;

string ans;
string inp;
string enc;

void pre (int i){
    ans = "";
    inp = "";
    if (i == 1) enc = "©o®o";
    else enc = "";
}

int main(){
    fstream fa;
    fa.open(s + ".txt", ios::in);
    return 0;
}
