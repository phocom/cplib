#include <bits/stdc++.h>

using namespace std;

/* BEGIN_DOCUMENT

高速な入出力です。

io.read(xx, yy, ...);で入力します。
整数型、string、vector<T>に対応しています。

io.write(xx, yy,...);で出力します。
整数型、string、const char[],vector<T>に対応しています。

io.set_delimiter(charc)でcを区切り文字に設定します。
複数の引数を指定した場合とvectorの出力で用いられます。
デフォルトでは空白になっています。

END_DOCUMENT */

// -------- BEGIN_CODE --------

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

// -------- END_CODE --------

int main() {
  int a, b, c;
  io.read(a, b, c);
  io.write(c, b, a);
  io.set_separator("\n");
  io.write(c, b, a);
  return 0;
}