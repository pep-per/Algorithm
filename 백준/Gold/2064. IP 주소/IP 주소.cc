#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  cin.ignore();

  vector<uint32_t> ips(n);
  for (int i = 0; i < n; i++) {
    string str;
    getline(cin, str);
    stringstream ss(str);
    string seg;
    uint32_t ip = 0;
    while (getline(ss, seg, '.')) {
      ip = (ip << 8) | stoi(seg);
    }
    ips[i] = ip;
  }

  uint32_t diff = 0;
  for (int i = 1; i < n; i++) {
    diff |= (ips[0] ^ ips[i]);
  }

  uint32_t mask = 0xFFFFFFFF;
  while (diff) {
    mask <<= 1;
    diff >>= 1;
  }
  uint32_t networkAddress = ips[0] & mask;

  for (int i = 3; i >= 0; i--) {
    cout << ((networkAddress >> (i * 8)) & 0xFF);
    if (i > 0) cout << ".";
  }
  cout << endl;

  for (int i = 3; i >= 0; i--) {
    cout << ((mask >> (i * 8)) & 0xFF);
    if (i > 0) cout << ".";
  }
  cout << endl;

  return 0;
}