#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  long long n;
  cin >> n;

  vector<bool> isPrime(n + 1, true);
  isPrime[0] = false;
  isPrime[1] = false;

  vector<long long> primes;
  for (long long i = 2; i <= n; i++) {
    if (isPrime[i]) {
      primes.push_back(i);
      for (long long j = i * i; j <= n; j += i) {
        isPrime[j] = false;
      }
    }
  }

  long long count = 0;
  long long sum;
  long long end;
  for (long long start = 0; start < primes.size(); start++) {
    sum = 0;
    end = start;

    while (end < primes.size() && sum < n) {
      sum += primes[end];
      end++;

      if (sum == n) {
        count++;
        break;
      }
    }
  }

  cout << count << endl;
  return 0;
}