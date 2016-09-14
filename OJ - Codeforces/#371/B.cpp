//
//  Created by TaoSama on 2016-09-14
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
#include <cassert>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, cnt;

int query(int x1, int y1, int x2, int y2) {
    assert(++cnt <= 200);
    if(x1 > x2 || y1 > y2) return 0;
    cout << "? " << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
    int ret; cin >> ret;
    return ret;
}

int getRect(int& x1, int& y1, int& x2, int& y2) {
    int l, r, newOne = -1;

    l = x1, r = x2;
    while(l <= r) {
        int m = l + r >> 1;
        if(query(x1, y1, m, y2) >= 1) newOne = m, r = m - 1;
        else l = m + 1;
    }
    x2 = newOne;

    l = y1, r = y2;
    while(l <= r) {
        int m = l + r >> 1;
        if(query(x1, y1, x2, m) >= 1) newOne = m, r = m - 1;
        else l = m + 1;
    }
    y2 = newOne;

    l = x1, r = x2;
    while(l <= r) {
        int m = l + r >> 1;
        if(query(m, y1, x2, y2) >= 1) newOne = m, l = m + 1;
        else r = m - 1;
    }
    x1 = newOne;

    l = y1, r = y2;
    while(l <= r) {
        int m = l + r >> 1;
        if(query(x1, m, x2, y2) >= 1) newOne = m, l = m + 1;
        else r = m - 1;
    }
    y1 = newOne;
}

int main() {
#ifdef LOCAL
//    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    cin >> n;
    int x1 = 1, y1 = 1, x2 = n, y2 = n;
    getRect(x1, y1, x2, y2);
//  pr(x1); pr(y1); pr(x2); prln(y2);

    int x3 = 1, y3 = 1, x4 = n, y4 = n;
    if(query(x2 + 1, y3, x4, y4) == 1) x3 = x2 + 1;
    else if(query(x3, y3, x1 - 1, y4) == 1) x4 = x1 - 1;
    else if(query(x3, y2 + 1, x4, y4) == 1) y3 = y2 + 1;
    else y4 = y1 - 1;

    getRect(x3, y3, x4, y4);

    cout << "! " << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << ' ';
    cout << x3 << ' ' << y3 << ' ' << x4 << ' ' << y4 << endl;


    return 0;
}
