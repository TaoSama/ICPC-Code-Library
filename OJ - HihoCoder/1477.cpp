//
//  Created by TaoSama on 2017-03-12
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
#include <tuple>

using namespace std;
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

struct Date {
    int y, m1, d;
    int h, m2, s;
    bool operator<(const Date& r) const {
        return make_tuple(y, m1, d, h, m2, s) < make_tuple(r.y, r.m1, r.d, r.h, r.m2, r.s);
    }
    bool operator==(const Date& r) const {
        return make_tuple(y, m1, d, h, m2, s) == make_tuple(r.y, r.m1, r.d, r.h, r.m2, r.s);
    }
    void read() {
        scanf("%d-%d-%d %d:%d:%d", &y, &m1, &d, &h, &m2, &s);
    }
    void see() {
        printf("%d-%d-%d %d:%d:%d\n", y, m1, d, h, m2, s);
    }
};

int mons[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool isLeap(int x) {
    return x % 4 == 0 && x % 100 != 0 || x % 400 == 0;
}

void go1s(Date& d) {
    int days = mons[d.m1];
    if(isLeap(d.y) && d.m1 == 2) ++days;
    if(++d.s == 60) {
        d.s = 0;
        if(++d.m2 == 60) {
            d.m2 = 0;
            if(++d.h == 24) {
                d.h = 0;
                if(++d.d == days + 1) {
                    d.d = 1;
                    if(++d.m1 == 13) {
                        d.m1 = 1;
                        ++d.y;
                    }
                }
            }
        }
    }
}

void go1h(Date& d) {
    int days = mons[d.m1];
    if(isLeap(d.y) && d.m1 == 2) ++days;
    if(++d.h == 24) {
        d.h = 0;
        if(++d.d == days + 1) {
            d.d = 1;
            if(++d.m1 == 13) {
                d.m1 = 1;
                ++d.y;
            }
        }
    }
}

int tt[] = {1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1,
            0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 0, 1
           };
int yy[] = {1972, 1973, 1974, 1975, 1976, 1977, 1978, 1979, 1981, 1982, 1983, 1985, 1987, 1989, 1990, 1992, 1993,
            1994, 1995, 1997, 1998, 2005, 2008, 2012, 2015, 2016
           };

set<Date> fuck;
void gao() {
    for(int i = 0; i < 26; ++i) {
        int a = tt[2 * i];
        int b = tt[2 * i + 1];
        if(a) fuck.insert({yy[i], 6, 30, 23, 59, 60});
        if(b) fuck.insert({yy[i], 12, 31, 23, 59, 60});
    }
}

bool xu1s(Date& d) {
    return fuck.count(d);
}

time_t toTm(Date& d) {
    struct tm cur;
    cur.tm_year = d.y - 1900;
    cur.tm_mon  = d.m1 - 1;
    cur.tm_mday = d.d;
    cur.tm_hour = d.h;
    cur.tm_min  = d.m2;
    cur.tm_sec  = d.s;
    return mktime(&cur);
};
int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

//  for(int i = 1972; i <= 2016; ++i) printf("%d,",i);

    Date s, t;
    s.read(); t.read();

    gao();
//    for(auto x : fuck) x.see();

    int ans = toTm(t) - toTm(s);
    for(const auto& x : fuck) ans += (s < x || s == x) && x < t;

    printf("%d\n", ans);
    return 0;
}
