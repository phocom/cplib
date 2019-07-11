#include <bits/stdc++.h>

using namespace std;

int calc(int a, int b, char op) {
  if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else if (op == '/') {
    return a / b;
  } else if (op == '*') {
    return a * b;
  }
}

enum Nodetype { VAL, OP };

struct Node {
  int type;
  int val;
  Node(int _type, int _val) {
    type = _type;
    val = _val;
  }
};

string to_string(Node node) {
  if (node.type == VAL) {
    return " VAL: " + to_string(node.val);
  } else {
    string s = " OP: ";
    s += node.val;
    return s;
  }
}

vector<Node> parse(string s) {
  map<char, int> pre;
  pre['+'] = 1;
  pre['-'] = 1;
  pre['*'] = 2;
  pre['/'] = 2;
  stack<char> st;
  vector<Node> ans;
  int num = -1;
  for (int i = 0; i < s.size(); ++i) {
    char c = s[i];
    if ('0' <= c && c <= '9') {
      if (num < 0)
        num = 0;
      num = num * 10 + c - '0';
    } else if (c == '(') {
      st.push(c);
    } else if (c == ')') {
      if (num != -1) {
        ans.push_back(Node(VAL, num));
        num = -1;
      }
      while (!st.empty() && st.top() != '(') {
        char op = st.top();
        ans.push_back(Node(OP, op));
        st.pop();
      }
      if (st.empty() || st.top() != '(') {
        return vector<Node>();
      }
      st.pop();
    } else {
      if (num != -1) {
        ans.push_back(Node(VAL, num));
        num = -1;
      }
      while (!st.empty() && pre[st.top()] >= pre[c]) {
        char op = st.top();
        ans.push_back(Node(OP, op));
        st.pop();
      }
      st.push(c);
    }
  }
  if (num != -1) {
    ans.push_back(Node(VAL, num));
    num = -1;
  }
  while (!st.empty()) {
    char op = st.top();
    if (op == '(') {
      return vector<Node>();
    }
    st.pop();
    ans.push_back(Node(OP, op));
  }
  return ans;
}

int eval(vector<Node> nodes) {
  stack<int> seq;
  for (Node node : nodes) {
    if (node.type == VAL) {
      seq.push(node.val);
    } else {
      int b = seq.top();
      seq.pop();
      int a = seq.top();
      seq.pop();
      seq.push(calc(a, b, node.val));
    }
  }
  return seq.top();
}

int main() {
  string S;
  cin >> S;
  vector<Node> nodes = parse(S);
  if (nodes.empty())
    cout << "error" << endl;
  for (Node node : nodes)
    cout << to_string(node) << endl;
  cout << eval(nodes) << endl;
  return 0;
}