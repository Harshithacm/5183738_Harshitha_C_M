#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string strings_xor(string s, string t) {

    string result = "";
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == t[i])
            result = result+'0';
        else
            result = result+'1';
    }

    return res;
}

int main() {
    string s, t;
    cin >> s >> t;
    cout << strings_xor(s, t) << endl;
    return 0;
}