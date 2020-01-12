#include <bits/stdc++.h>

using namespace std;

/* BEGIN_DOCUMENT

UnionFind木です。

root(int v)で頂点vが属する集合の番号を返します。

unite(int u,int v)で頂点uとvを連結します。

size(v)で頂点vが属する集合の要素数を返します。

make_groups()でgroupsに集合を格納します。

END_DOCUMENT */

// -------- BEGIN_CODE --------

struct UnionFind {
  vector<int> data;
  vector<vector<int>> groups;
  UnionFind(int n) : data(n, -1) {}
  int root(int v) { return data[v] < 0 ? v : data[v] = root(data[v]); }
  bool unite(int u, int v) {
    if ((u = root(u)) == (v = root(v))) {
      return 1;
    } else {
      if (-data[u] < -data[v]) swap(u, v);
      data[u] += data[v];
      data[v] = u;
      return 0;
    }
  }
  int size(int v) { return -data[root(v)]; }
  void make_groups() {
    map<int, vector<int>> mp;
    for (int i = 0; i < data.size(); ++i) mp[root(i)].push_back(i);
    groups.clear();
    for (auto p : mp) groups.push_back(p.second);
  }
};

// -------- END_CODE --------

int main() {
  UnionFind uf(10);
  uf.unite(2, 6);
  uf.unite(1, 3);
  uf.unite(7, 6);
  uf.make_groups();
  for (auto x : uf.groups) {
    for (auto y : x) {
      cout << y << " ";
    }
    cout << endl;
  }
  return 0;
}