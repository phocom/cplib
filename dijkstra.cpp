#include <bits/stdc++.h>

using namespace std;

using Pi = pair<int, int>;
const int INF = 1 << 28;

// ----------------

struct Dijkstra {
  vector<int> dists;
  vector<Pi> order;
};

Dijkstra dijkstra(vector<vector<Pi>>& G, int start, int goal) {
  int N = G.size();
  Dijkstra info;
  info.dists = vector<int>(N, INF);
  vector<bool> visited(N);
  priority_queue<Pi, vector<Pi>, greater<Pi>> q;
  q.push(Pi(0, start));
  while (!q.empty()) {
    Pi p = q.top();
    q.pop();
    int d = p.first, v = p.second;
    if (visited[v])
      continue;
    visited[v] = 1;
    info.dists[v] = d;
    if (v == goal)
      break;
    for (Pi e : G[v]) {
      if (info.dists[e.second] <= d + e.first)
        continue;
      q.push(Pi(d + e.first, e.second));
      info.order.push_back(Pi(v, e.second));
    }
  }
  return info;
}

Dijkstra dijkstra(vector<vector<Pi>>& G, int start) {
  return dijkstra(G, start, -1);
}

// ----------------

int main() {
  int n;
  cin >> n;
  vector<vector<Pi>> G(n);
  for (int i = 0; i < n; ++i) {
    cin >> i;
    int k;
    cin >> k;
    for (int j = 0; j < k; ++j) {
      int v, c;
      cin >> v >> c;
      G[i].push_back(Pi(c, v));
    }
  }
  Dijkstra info = dijkstra(G, 0);
  for (int i = 0; i < n; ++i) {
    cout << i << " " << info.dists[i] << endl;
  }
  return 0;
}