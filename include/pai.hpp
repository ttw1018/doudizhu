#include <vector>
#include <iostream>
#define card vector<int>

using namespace std;

class Cards {
  public:
    card cards;
    Cards();
    Cards(card);

    vector<card> _1();
    vector<card> _2();
    vector<card> _22();
    vector<card> _3();
    vector<card> _33();
    vector<card> _3_1();
    vector<card> _3_2();
    vector<card> _33_11();
    vector<card> _33_22();
    vector<card> _11();
    vector<card> _4();
    vector<card> _4_1_1();
    vector<card> _4_2_2();

    vector<card> get_all();
    Cards showup(card);
    bool win();

    friend ostream& operator << (ostream &o, Cards &x);
};
