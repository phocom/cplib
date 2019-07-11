#include <bits/stdc++.h>

using namespace std;

enum Nodetype { EXPR, TERM, FACTOR, NUM, END };

struct Node {
  int type;
  int val;
  vector<Node> child;
  Node(int _type, int _val) {
    type = _type;
    val = _val;
    child = vector<Node>();
  }
  void push(Node node) { child.push_back(node); }
  void trav(string ind) {
    cout << ind << val << endl;
    for (Node node : child) {
      node.trav(ind + " ");
    }
  }
  int eval() {
    switch (type) {
      case EXPR:
        if (child.size() == 1) {
          val = child[0].eval();
        } else {
          if (child[1].val == '+') {
            val = child[0].eval() + child[2].eval();
          } else {
            val = child[0].eval() - child[2].eval();
          }
        }
        break;
      case TERM:
        if (child.size() == 1) {
          val = child[0].eval();
        } else {
          if (child[1].val == '*') {
            val = child[0].eval() * child[2].eval();
          } else {
            val = child[0].eval() - child[2].eval();
          }
        }
        break;
      case FACTOR:
        val = child[0].eval();
        break;
      case NUM:
        val = child[0].eval();
        break;
      case END:
        val;
    }
    return val;
  }
};

Node expr(string& s, int& i);
Node term(string& s, int& i);
Node factor(string& s, int& i);
Node num(string& s, int& i);

Node expr(string& s, int& i) {
  Node node(EXPR, 0);
  node.push(term(s, i));
  if (s[i] == '+') {
    node.push(Node(END, '+'));
    i++;
    node.push(expr(s, i));
  } else if (s[i] == '-') {
    node.push(Node(END, '-'));
    i++;
    node.push(expr(s, i));
  }
  return node;
}

Node term(string& s, int& i) {
  Node node(TERM, 0);
  node.push(factor(s, i));
  if (s[i] == '*') {
    node.push(Node(END, '*'));
    i++;
    node.push(term(s, i));
  } else if (s[i] == '/') {
    node.push(Node(END, '/'));
    i++;
    node.push(term(s, i));
  }
  return node;
}

Node factor(string& s, int& i) {
  Node node(FACTOR, 0);
  if (s[i] == '(') {
    i++;
    node.push(expr(s, i));
    i++;
  } else {
    node.push(num(s, i));
  }
  return node;
}

Node num(string& s, int& i) {
  Node node(NUM, 0);
  int now = 0;
  while ('0' <= s[i] && s[i] <= '9') {
    now = now * 10 + s[i] - '0';
    i++;
  }
  node.push(Node(END, now));
  return node;
}

int main() {
  string S;
  cin >> S;
  S += "\n";
  int i = 0;
  Node node = expr(S, i);
  node.trav("");
  cout << node.eval() << endl;
  return 0;
}