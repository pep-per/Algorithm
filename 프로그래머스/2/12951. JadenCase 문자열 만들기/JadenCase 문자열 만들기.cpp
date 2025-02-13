#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s) {
    bool isWord = false;
    for (auto &c : s) {
        if (c == ' ') {
            isWord = false;
            continue;

        }
        if (!isWord) {
            isWord = true;
        
            if (c >= 'a' && c <= 'z')
                c += 'A' - 'a';
        } else {
           if (c >= 'A' && c <= 'Z')
                c -= 'A' - 'a';
        }
        cout << c;
    }
    return s;
}