//
//  Created by TaoSama on 2017-04-09
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <set>
#include <vector>

using namespace std;
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

struct Date {
    char s[9];
    Date() {}
    Date(const char* a) {
        for(int i = 0; i < 8; ++i) s[i] = a[i];
        s[8] = 0;
    }
    char& operator[](int k) {
        return s[k];
    }
    bool operator<(const Date& d) const {
        return strcmp(s, d.s) < 0;
    }
};

bool isLeap(int x) {
    return x % 4 == 0 && x % 100 != 0 || x % 400 == 0;
}
int ms[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    auto go = [](Date & cur) {
        int y = 0;
        for(int i = 0; i < 4; ++i) y = y * 10 + cur[i] - '0';
        int m = 0;
        for(int i = 4; i < 6; ++i) m = m * 10 + cur[i] - '0';
        int d = 0;
        for(int i = 6; i < 8; ++i) d = d * 10 + cur[i] - '0';

        int mdays = ms[m] + (m == 2 && isLeap(y));
        if(++d > mdays) {
            d = 1;
            if(++m > 12) {
                m = 1;
                ++y;
            }
        }
        cur[3] = y % 10 + '0'; y /= 10;
        cur[2] = y % 10 + '0'; y /= 10;
        cur[1] = y % 10 + '0'; y /= 10;
        cur[0] = y % 10 + '0';

        cur[4] = m / 10 + '0';
        cur[5] = m % 10 + '0';
        cur[6] = d / 10 + '0';
        cur[7] = d % 10 + '0';

        int ret = 0;
        for(int i = 0; i < 8; ++i) ret += cur[i] == '9';
        return ret;
    };

    Date st("20000100");
    Date ed("99991231");

    vector<Date> v; v.reserve(int(3e6));
    vector<int> pp; pp.reserve(int(3e6));
    v.push_back(st); pp.push_back(0);

    while(true) {
        v.push_back(v.back());
        pp.push_back(pp.back());

        Date& cur = v.back();
        pp.back() += go(cur);

        if(strcmp(cur.s, ed.s) == 0) break;
    }

//  for(int i = 0; i < 20; ++i){
//      printf("%s %d\n", v[i].s, pp[i]);
//  }

    int t; scanf("%d", &t);
    while(t--) {
        Date A, B;
        scanf("%s%s%s", A.s, A.s + 4, A.s + 6);
        scanf("%s%s%s", B.s, B.s + 4, B.s + 6);
        int r = lower_bound(v.begin(), v.end(), B) - v.begin();
        int l = lower_bound(v.begin(), v.end(), A) - v.begin();
        printf("%d\n", pp[r] - pp[l - 1]);
    }


    return 0;
}
