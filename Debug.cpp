#include <bits/stdc++.h>

using namespace std;

/* BEGIN_DOCUMENT

debug(xxx,yyy,...)でcerrに内容を出力します。
pairでもvectorでもsetでもmapでも大体なんでも扱えます。
他に必要になれば自分でstring to_string()を定義してください。

END_DOCUMENT */

// -------- BEGIN_CODE --------

template <class T>
string to_string(T s);
template <class S, class T>
string to_string(pair<S, T> p);
string to_string(string s);

template <class T>
string to_string(T v) {
  if (v.empty()) return "{}";
  string ret = "{";
  auto itr = v.begin(), next = ++v.begin();
  for (; next != v.end(); ++itr, ++next) ret += to_string(*itr) + ",";
  ret += to_string(*itr) + "}";
  return ret;
}
template <class S, class T>
string to_string(pair<S, T> p) {
  return "{" + to_string(p.first) + "," + to_string(p.second) + "}";
}
string to_string(string s) { return s; }

void debug() { cerr << endl; }
template <class Head, class... Tail>
void debug(Head head, Tail... tail) {
  cerr << to_string(head) << " ";
  debug(tail...);
}

// -------- END_CODE --------

int main() { return 0; }