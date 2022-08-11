#include "pai.hpp"

Cards::Cards() {
  cards = card (18, 0);
}

Cards::Cards(card v) {
  cards = card(18, 0);
  for (auto i : v) {
    cards[i]++;
  }
}


vector<card> Cards::_1() {
  vector<card> ans;
  for (int i = 3; i < 18; i++) {
    if (cards[i] > 0) {
      ans.push_back(card(1, i));
    }
  }
  return ans;
}

vector<card> Cards::_2() {
  vector<card> ans;
  for (int i = 3; i < 18; i++) {
    if (cards[i] >= 2) {
      ans.push_back(card(2, i));
    }
  }
  return ans;
}


vector<card> Cards::_22() {
  vector<card> ans;
  for (int l = 3; l <= 12; l++) {
    for (int i = 3; i <= 14 - l + 1; i++) {
      int flag = 1;
      for (int k = 0; k < l; k++) {
        if (cards[i + k] < 2) {
          flag = 0;
          break;
        }
      }
      card now;
      if (flag) {
        for (int k = 0; k < l; k++) {
          card tmp(2, k + i);
          now.insert(now.end(), tmp.begin(), tmp.end());
        }
        ans.push_back(now);
      }
    }
  }
  return ans;
}


vector<card> Cards::_3() {
  vector<card> ans;
  for (int i = 3; i <= 18; i++) {
    if (cards[i] >= 3) {
      ans.push_back(card(3, i));
    }
  }
  return ans;
}

vector<card> Cards::_33() {
  vector<card> ans;
  for (int l = 2; l <= 12; l++) {
    for (int i = 3; i <= 14 - l + 1; i++) {
      int flag = 1;
      for (int k = 0; k < l; k++) {
        if (cards[i + k] < 3) {
          flag = 0;
          break;
        }
      }
      card now;
      if (flag) {
        for (int k = 0; k < l; k++) {
          card tmp(3, k + i);
          now.insert(now.end(), tmp.begin(), tmp.end());
        }
        ans.push_back(now);
      }
    }
  }
  return ans;
}

vector<card> Cards::_3_1() {
  vector<card> ans;

  for (int i = 3; i <= 14; i++) {
    for (int j = 3; j <= 14; j++) {
      if (i == j) continue;
      if (cards[i] >= 3 && cards[j] >= 1) {
        card now = card(3, i);
        now.push_back(j);
        ans.push_back(now);
      }
    }
  }
  return ans;
}


vector<card> Cards::_3_2() {
  vector<card> ans;
  for (int i = 3; i <= 14; i++) {
    for (int j = 3; j <= 14; j++) {
      if (i == j) continue;
      if (cards[i] >= 3 && cards[j] >= 2) {
        card now = card(3, i);
        now.push_back(j);
        now.push_back(j);
        ans.push_back(now);
      }
    }
  }
  return ans;
}

vector<card> Cards::_33_11() {
  vector<card> ans;
  for (int l = 2; l <= 12; l++) {
    for (int i = 3; i <= 14 - i + 1; i++) {
      int flag = 1;
      for (int k = 0; k < l; k++) {
        if (cards[i + k] < 3) {
          flag = 0;
          break;
        }
      }
      if (flag) {
        vector<int> free;
        for (int k= 2; k <= 17; k++) {
          if ((k < i || k >= i + l) && cards[k] >= 1) {
            free.push_back(k);
          }
        }
        int free_cnt = free.size();
        if (free_cnt < l) {
          continue;
        }
        for (int k = 0; k < (1 << free_cnt); k++) {
          int bit_cnt = 0;
          int tmp = k;
          while(tmp) {
            bit_cnt += tmp & 1;
            tmp >>= 1;
          }
          if (bit_cnt == l) {
            card now;
            for (int k = 0; k < l; k++) {
              now.push_back(i + k);
              now.push_back(i + k);
              now.push_back(i + k);
            }
            for (int j = 0; j < free_cnt; j++) {
              if ((k >> j) & 1) {
                now.push_back(free[j]);
              }
            }
            ans.push_back(now);
          }
        }
      }
    }
  }
  return ans;
}


vector<card> Cards::_33_22() {
  vector<card> ans;
  for (int l = 2; l <= 12; l++) {
    for (int i = 3; i <= 14 - i + 1; i++) {
      int flag = 1;
      for (int k = 0; k < l; k++) {
        if (cards[i + k] < 3) {
          flag = 0;
          break;
        }
      }
      if (flag) {
        vector<int> free;
        for (int k= 2; k <= 17; k++) {
          if ((k < i || k >= i + l) && cards[k] >= 2) {
            free.push_back(k);
          }
        }
        int free_cnt = free.size();
        if (free_cnt < l) {
          continue;
        }
        for (int k = 0; k < (1 << free_cnt); k++) {
          int bit_cnt = 0;
          int tmp = k;
          while(tmp) {
            bit_cnt += tmp & 1;
            tmp >>= 1;
          }
          if (bit_cnt == l) {
            card now;
            for (int k = 0; k < l; k++) {
              now.push_back(i + k);
              now.push_back(i + k);
              now.push_back(i + k);
            }
            for (int j = 0; j < free_cnt; j++) {
              if ((k >> j) & 1) {
                now.push_back(free[j]);
                now.push_back(free[j]);
              }
            }
            ans.push_back(now);
          }
        }
      }
    }
  }
  return ans;
}

vector<card> Cards::_11() {
  vector<card> ans;
  for (int l = 5; l <= 12; l++) {
    for (int i = 3; i <= 14 - l + 2; i++) {
      int flag = 1;
      for (int k = 0; k < l; k++) {
        if (!cards[i + k]) {
          flag = 0;
          break;
        }
      }
      if (flag) {
        vector<int> now;
        for (int k = 0; k < l; k++) {
          now.push_back(i + k);
        }
        ans.push_back(now);
      }
    }
  }
  return ans;
}

vector<card> Cards::_4() {
  vector<card> ans;
  for (int i = 3; i <= 15; i++) {
    if (cards[i] == 4) {
      ans.push_back(card(4, i));
    }
  }
  if (cards[16] && cards[17]) {
    card now = {16, 17};
    ans.push_back(now);
  }
  return ans;
}

vector<card> Cards::_4_1_1() {
  vector<card> ans;
  for (int i = 3; i <= 15; i++) {
    if (cards[i] == 4) {
      for (int j = 3; j <= 17; j++) {
        if (j == i || cards[j] < 1) continue;
        for (int k = j + 1; k <= 17; k++) {
          if (k == i || cards[k] < 1) continue;
          vector<int> now(4, i);
          now.push_back(j);
          now.push_back(k);
          ans.push_back(now);
        }
      }
    }
  }
  return ans;
}

vector<card> Cards::_4_2_2() {
  vector<card> ans;
  for (int i = 3; i <= 15; i++) {
    if (cards[i] == 4) {
      for (int j = 3; j <= 17; j++) {
        if (j == i || cards[j] < 2) continue;
        for (int k = j + 1; k <= 17; k++) {
          if (k == i || cards[k] < 2) continue;
          vector<int> now(4, i);
          now.push_back(j);
          now.push_back(j);
          now.push_back(k);
          now.push_back(k);
          ans.push_back(now);
        }
      }
    }
  }
  return ans;
}

vector<card> Cards::get_all() {
  vector<card> res;
  vector<card> now;
  now = _1();
  res.insert(res.end(), now.begin(), now.end());
  now = _2();
  res.insert(res.end(), now.begin(), now.end());
  now = _22();
  res.insert(res.end(), now.begin(), now.end());
  now = _3();
  res.insert(res.end(), now.begin(), now.end());
  now = _33();
  res.insert(res.end(), now.begin(), now.end());
  now = _3_1();
  res.insert(res.end(), now.begin(), now.end());
  now = _3_2();
  res.insert(res.end(), now.begin(), now.end());
  now = _33_11();
  res.insert(res.end(), now.begin(), now.end());
  now = _33_22();
  res.insert(res.end(), now.begin(), now.end());
  now = _11();
  res.insert(res.end(), now.begin(), now.end());
  now = _4();
  res.insert(res.end(), now.begin(), now.end());
  now = _4_1_1();
  res.insert(res.end(), now.begin(), now.end());
  now = _4_2_2();
  res.insert(res.end(), now.begin(), now.end());

  return res;
}

Cards Cards::showup(card v) {
  Cards tmp = Cards();
  tmp.cards = card(cards);
  for (auto i : v) {
    tmp.cards[i]--;
  }

  return tmp;
}


ostream& operator << (ostream &o, Cards &x){
  for (int i = 3; i <= 17; i++) {
    for (int j = 0; j < x.cards[i]; j++) {
      if (i == 11)
        o << "J";
      else if (i == 12)
        o << "Q";
      else if (i == 13)
        o << "K";
      else if (i == 14)
        o << "A";
      else if (i == 15)
        o << "2";
      else if (i == 16)
        o << "w";
      else if (i == 17)
        o << "W";
      else
        o << i;
    }
  }
  return o;
}

