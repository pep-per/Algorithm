#include <string>
#include <vector>
#include <iostream>

using namespace std;


int gcd(int a, int b)
{
    int c;
	while(b)
	{
		c = a % b;
		a = b;
		b = c;
	}
    return a;
}

int lcm(int num1, int num2) {
    int s, b;
    if (num1 < num2) {
        s = num1;
        b = num2;
    } else {
        s = num2;
        b = num1;
    }
    return s*b/gcd(s,b);
}

int solution(vector<int> arr) {

    int ans = 1;
    for (auto &num : arr) {
        ans = lcm(num, ans);
    }
    return ans;
}