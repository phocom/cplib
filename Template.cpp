#include <bits/stdc++.h>

using namespace std;

#define REP(i, N) for (int i = 0; i < (int)N; i++)
#define FOR(i, a, b) for (int i = a; i < (int)b; i++)
#define ALL(x) (x).begin(), (x).end()
#define INF (1 << 30)
#define LLINF (1LL << 62)
#define DEBUG(...) debug(__LINE__, ":" __VA_ARGS__)

constexpr int MOD = 1000000007;
using ll = long long;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

string to_string(string s) { return s; }
template <class T>
string to_string(unordered_set<T> s);
template <class T>
string to_string(set<T> s);
template <class S, class T>
string to_string(unordered_map<S, T> m);
template <class S, class T>
string to_string(map<S, T> m);
template <class T>
string to_string(vector<T> v);

template <class S, class T>
string to_string(pair<S, T> p) {
  return "{" + to_string(p.first) + "," + to_string(p.second) + "}";
}
template <class S>
string to_string(unordered_set<S> s) {
  if (s.empty()) return "{}";
  string ret = "{";
  for (auto itr = s.begin(); itr != s.end(); ++itr)
    ret += to_string(*itr) + ",";
  ret += to_string(*s.end()) + "}";
  return ret;
}
template <class S>
string to_string(set<S> s) {
  if (s.empty()) return "{}";
  string ret = "{";
  for (auto itr = s.begin(); itr != s.end(); ++itr)
    ret += to_string(*itr) + ",";
  ret += to_string(*s.end()) + "}";
  return ret;
}
template <class S, class T>
string to_string(unordered_map<S, T> m) {
  if (m.empty()) return "{}";
  string ret = "{";
  for (auto itr = m.begin(); itr != m.end(); ++itr)
    ret += to_string(*itr) + ",";
  ret += to_string(*m.end()) + "}";
  return ret;
}
template <class S, class T>
string to_string(map<S, T> m) {
  if (m.empty()) return "{}";
  string ret = "{";
  for (auto itr = m.begin(); itr != m.end(); ++itr)
    ret += to_string(*itr) + ",";
  ret += to_string(*m.end()) + "}";
  return ret;
}
template <class T>
string to_string(vector<T> v) {
  if (v.empty()) return "{}";
  string ret = "{";
  for (auto itr = v.begin(); itr != v.end(); ++itr)
    ret += to_string(*itr) + ",";
  ret += to_string(*v.end()) + "}";
  return ret;
}

void debug() { cerr << endl; }
template <class Head, class... Tail>
void debug(Head head, Tail... tail) {
  cerr << to_string(head) << " ";
  debug(tail...);
}
void print() { cout << endl; }
template <class Head, class... Tail>
void print(Head head, Tail... tail) {
  cout << to_string(head) << " ";
  print(tail...);
}

struct IO {
#ifdef _WIN32
  inline char getchar_unlocked() { return getchar(); }
  inline void putchar_unlocked(char c) { putchar(c); }
#endif
  string separator = " ";
  template <class T>
  inline void read(T &x) {
    char c;
    do {
      c = getchar_unlocked();
    } while (c != '-' && c < '0' && '9' < c);
    bool minus = 0;
    if (c == '-') {
      minus = 1;
      c = getchar_unlocked();
    }
    x = 0;
    while ('0' <= c && c <= '9') {
      x *= 10;
      x += c - '0';
      c = getchar_unlocked();
    }
    if (minus) x = -x;
  }
  inline void read(string &x) {
    char c;
    do {
      c = getchar_unlocked();
    } while (c != ' ' && c != '\n');
    x.clear();
    do {
      x += c;
      c = getchar_unlocked();
    } while (c != ' ' && c != '\n' && c != EOF);
  }
  template <class T>
  inline void read(vector<T> &v) {
    for (auto &x : v) read(x);
  }
  template <class Head, class... Tail>
  inline void read(Head &head, Tail &... tail) {
    read(head);
    read(tail...);
  }
  template <class T>
  inline void write(T &x) {
    char buf[32];
    int p = 0;
    T t = x;
    if (t < 0) {
      x = -t;
      putchar_unlocked('-');
    }
    if (t == 0) putchar_unlocked('0');
    while (t > 0) {
      buf[p++] = (t % 10) + '0';
      t /= 10;
    }
    while (p) {
      putchar_unlocked(buf[--p]);
    }
  }
  inline void write(string &x) {
    for (char c : x) putchar_unlocked(c);
  }
  inline void write(const char s[]) {
    for (int i = 0; s[i] != 0; ++i) putchar_unlocked(s[i]);
  }
  template <class T>
  inline void write(vector<T> &v) {
    for (auto itr = v.begin(); itr != v.begin(); ++itr) {
      write(separator);
      write(*itr);
    }
    write(*v.end());
  }
  template <class Head, class... Tail>
  inline void write(Head &head, Tail &... tail) {
    write(head);
    write(separator);
    write(tail...);
  }
  void set_separator(string s) { separator = s; }
} io;

template <int MOD = 1000000007>
struct Math {
  vector<long long> fact, factinv, inv;
  Math(int n = 100000) {
    fact.resize(n + 1);
    factinv.resize(n + 1);
    inv.resize(n + 1);
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

int main() { return 0; }
