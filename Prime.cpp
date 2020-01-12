#include <bits/stdc++.h>

using namespace std;

/* BEGIN_DOCUMENT

素数、素因数分解を扱います。
コンストラクタで素数テーブルを構築します。
prime.enumerate_primes()でprimesに素数を列挙します。
prime.prime_factor(int x)でxを素因数分解した結果を返します。

END_DOCUMENT */

// -------- BEGIN_CODE --------

struct Prime {
  int n;
  vector<int> table;
  vector<int> primes;
  Prime(int _n = 100000) {
    n = _n + 1;
    table.resize(n, -1);
    table[0] = 0;
    table[1] = -1;
    for (int i = 2; i * i < n; ++i) {
      if (table[i] == -1) {
        for (int j = i * i; j < n; j += i) {
          table[j] = i;
        }
      }
    }
  }
  void enumerate_primes() {
    primes.clear();
    for (int i = 2; i < n; ++i) {
      if (table[i] == -1) primes.push_back(i);
    }
  }
  vector<pair<long long, int>> prime_factor(long long x) {
    map<long long, int> mp;
    long long div = 2;
    int p = 0;
    while (n <= x && div * div <= x) {
      if (x % div == 0) {
        mp[div]++;
        x /= div;
      } else {
        if (p + 1 < primes.size()) {
          div = primes[++p];
        } else {
          div++;
        }
      }
    }
    if (x < n) {
      while (table[x] != -1) {
        mp[table[x]]++;
        x /= table[x];
      }
    }
    if (x > 1) mp[x]++;
    vector<pair<long long, int>> ret;
    for (auto p : mp) ret.push_back(p);
    return ret;
  }
};

// -------- END_CODE --------

int main() {
  Prime prime(100);
  prime.enumerate_primes();
  for (auto x : prime.primes) cout << x << " ";
  cout << endl;
  auto ret = prime.prime_factor(120000);
  for (auto p : ret) cout << "{" << p.first << "," << p.second << "} ";
  cout << endl;
  return 0;
}