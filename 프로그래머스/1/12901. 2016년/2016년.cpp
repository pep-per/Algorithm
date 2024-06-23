#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(int a, int b) {
    string weekArr[7] = {"THU","FRI","SAT","SUN","MON","TUE","WED"};
    int dayArr[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
    vector<int> day;
    day.insert(day.end(), begin(dayArr), end(dayArr));
    int i = 1;
    int j = 0;
    for (auto x : day)
    {
        if (i < a)
            j+= x;
        else
            break;
        i++;
    }
    j += b;
    return weekArr[j % 7];
}