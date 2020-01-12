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
    table[1] = 1;
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
  vector<pair<int, int>> prime_factor(int x) {
    map<int, int> mp;
    while (table[x] != -1) {
      mp[table[x]]++;
      x /= table[x];
    }
    if (x > 1) mp[x]++;
    vector<pair<int, int>> ret;
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
  auto ret = prime.prime_factor(84);
  for (auto p : ret) cout << "{" << p.first << "," << p.second << "} ";
  cout << endl;
  return 0;
}