//
//  Created by TaoSama on 2017-01-18
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
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

string s[N];

bool check(int x, int y) {
    return x >= 0 && x < 4 && y >= 0 && y < 4;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    for(int i = 0; i < 4; ++i) cin >> s[i];
    bool ok = false;
    for(int i = 0; i < 4; ++i) {
        for(int j = 0; j < 4; ++j) {
            if(s[i][j] != '.') continue;
            s[i][j] = 'x';

            for(int x = 0; x < 4 && !ok; ++x) {
                for(int y = 0; y < 4 && !ok; ++y) {
                    if(s[x][y] == 'x') {
                        for(int dx = -1; dx <= 1 && !ok; ++dx) {
                            for(int dy = -1; dy <= 1 && !ok; ++dy) {
                                if(dx == 0 && dy == 0) continue;
                                int ax = x + dx, ay = y + dy;
                                int bx = ax + dx, by = ay + dy;
                                if(check(ax, ay) && check(bx, by)) {
                                    if(s[ax][ay] == 'x' && s[bx][by] == 'x')
                                        ok = true;
                                }
                            }
                        }
                    }
                }
            }

            s[i][j] = '.';
        }
    }
    cout << (ok ? "YES" : "NO") << endl;


    return 0;
}
