#include <bits/stdc++.h>

using namespace std;

/* BEGIN_DOCUMENT

重み付き有向グラフを扱います。

add_edge(int u,int v, T d)で頂点uからvへ重みdの辺を張ります。

search_from(int s)で頂点sからの最短経路探索の結果を返します。
dist[v]には頂点vまでの距離が入っています。
get_path(int g)で頂点sからgまでの最短経路を返します。

END_DOCUMENT */

// -------- BEGIN_CODE --------

template <class T>
struct Graph {
  using Edge = pair<T, int>;
  vector<vector<Edge>> G;
  struct Search {
    const T inf = numeric_limits<T>::max();
    vector<T> dist;
    vector<int> prev;
    Search(int n) {
      dist.assign(n, inf);
      prev.assign(n, -1);
    }
    vector<int> get_path(int g) {
      vector<int> ret;
      while (g != -1) {
        ret.push_back(g);
        g = prev[g];
      }
      reverse(ret.begin(), ret.end());
      return ret;
    }
  };
  Graph(int n) { G.resize(n); }
  void add_edge(int u, int v, int d) { G[u].push_back(Edge(d, v)); }
  Search search_from(int s) {
    int n = G.size();
    Search search(n);
    search.dist[s] = 0;
    priority_queue<Edge, vector<Edge>, greater<Edge>> q;
    q.push(Edge(0, s));
    while (!q.empty()) {
      T d = q.top().first;
      int u = q.top().second;
      q.pop();
      for (Edge e : G[u]) {
        if (search.dist[u] + e.first < search.dist[e.second]) {
          search.dist[e.second] = search.dist[u] + e.first;
          search.prev[e.second] = u;
          q.push(Edge(search.dist[e.second], e.second));
        }
      }
    }
    return search;
  }
};

// -------- END_CODE --------

int main() { return 0; }