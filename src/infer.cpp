#include "infer.hpp"
#include <iostream>
using namespace std;

bool check(card a, card b) {
  if (b.size() == 0) {
    return 1;
  }
  if (a.size() == 2 && a[0] == 16 &&  a[1] == 17) {
    return 1;
  }

  if (a.size() == 4 && a[0] == a[a.size() - 1]) {
    if (b.size() == 4 && *b.begin() == *b.rbegin() && a[0] <= b[0]) {
      return 0;
    }
    return 1;
  }
  if (a.size() == b.size()) {
    vector<int> t1, t2;
    int cnt = 1;
    for (int i = 1; i < a.size(); i++) {
      if (a[i] == a[i - 1]) {
        cnt++;
      } else{
        t1.push_back(cnt);
        cnt = 1;
      }
      if(i == a.size() - 1) {
        t1.push_back(cnt);
      }
    }
    cnt = 1;
    for (int i = 1; i < b.size(); i++) {
      if (b[i] == b[i - 1]) {
        cnt++;
      } else{
        t2.push_back(cnt);
        cnt = 1;
      }
      if(i == b.size() - 1) {
        t2.push_back(cnt);
      }
    }
    if (t1.size() == t2.size()) {
      int flag = 1;
      for (int i = 0; i < t1.size(); i++) {
        if(t1[i] != t2[i]) {
          flag = 0;
          break;
        }
      }
      if (a[0] > b[0]) {
        return 1;
      }
    } 
  } 
  return 0;
}

bool Cards::win() {
  for (int i = 3; i <= 17; i++) {
    if (cards[i]) {
      return 0;
    }
  }
  return 1;
}

ostream& operator << (ostream& o, vector<int> v) {
  for (auto i : v) {
    o << i;
  }
  return o;
}

bool infer(Cards user, Cards system, int turn, vector<int> pre) {
  cout << turn << " " << user <<  " " << system << endl;
  if (user.win()) {
    return 1;
  } 
  if (system.win()) {
    return 0;
  }
  // cout << user << " " << system << endl;
  if (turn & 1) {
    if (pre.size() && infer(user, system, turn + 1, card())) {
      return 1;
    }
    vector<card> v = user.get_all();
    for (auto i : v) {
      if (check(i, pre)) {
        Cards next = user.showup(i);
        if (infer(next, system, turn + 1, i)) {
          return 1;
        }
      }
    }
    return 0;
  } else {
    int win = 1;
    if (pre.size())
      win &= infer(user, system, turn + 1, card());
    vector<card> v = system.get_all();
    for (auto i : v) {
      if (check(i, pre)) {
        Cards next = system.showup(i);
        win &= infer(user, next, turn + 1, i);
        if (win == 0) {
          break;
        }
      }
    }
    return win;
  }
}
