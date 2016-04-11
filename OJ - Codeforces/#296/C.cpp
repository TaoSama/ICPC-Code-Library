//
//
//
//  Created by TaoSama on 2015-03-18
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <set>
#include <vector>
#define CLR(x,y) memset(x, y, sizeof(x))

using namespace std;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;

int n, w, h;

void inline cut(set<int> &s, multiset<int> &ss, int t) {
    s.insert(t);
    auto l = s.find(t), r = l;
    --l, ++r;
    int cur = *r - *l;
    //cout<<"cur: "<<cur<<endl;
    ss.erase(ss.find(cur));
    ss.insert(*r - t);
    ss.insert(t - *l);
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> w >> h >> n) {
        set<int> x, y;  //切割的位置
        multiset<int> xx, yy; //所有线段

        x.insert(0), x.insert(w);
        y.insert(0), y.insert(h);
        xx.insert(w), yy.insert(h);

        for(int i = 1; i <= n; ++i) {
            char c; int t; cin >> c >> t;
            if(c == 'H') cut(y, yy, t);
            else cut(x, xx, t);
            cout << 1LL * *xx.rbegin() * *yy.rbegin()<<'\n';
        }
    }

    return 0;
}

