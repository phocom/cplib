#include <bits/stdc++.h>

using namespace std;

/* BEGIN_DOCUMENT

数え上げに頻出のnCr,nPr,nHrを提供します。
テンプレート引数で法を指定します。
math.build(int n)でnを引数の最大値として前処理します。

END_DOCUMENT */

// -------- BEGIN_CODE --------

template <int MOD = 1000000007>
struct Math {
  vector<long long> fact, factinv, inv;
  void build(int n) {
    fact.resize(n);
    factinv.resize(n);
    inv.resize(n);
    fact[0] = fact[1] = 1;
    factinv[0] = factinv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i <= n; ++i) {
      fact[i] = fact[i - 1] * i % MOD;
      inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
      factinv[i] = factinv[i - 1] * inv[i] % MOD;
    }
  }
  long long C(int n, int r) {
    if (n < r || n < 0 || r < 0) {
      return 0;
    } else {
      return fact[n] * (factinv[r] * factinv[n - r] % MOD) % MOD;
    }
  }
  long long P(int n, int r) {
    if (n < r || n < 0 || r < 0) {
      return 0;
    } else {
      return fact[n] * factinv[n - r] % MOD;
    }
  }
  long long H(int n, int r) { return C(n + r - 1, r); }
};

// -------- END_CODE --------

int main() {
  Math<1000000007> math;
  math.build(100000);
  cout << math.P(5, 2) << endl;
  cout << math.C(7, 3) << endl;
  cout << math.H(4, 3) << endl;
  return 0;
}