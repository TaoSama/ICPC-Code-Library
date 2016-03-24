//
//
//
//  Created by TaoSama on 2015-03-31
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

using namespace std;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;

int n, ans, dp[8][8][8][8];
struct Point {
    int x, y;
} king, knight[64];

void read() {
    string s; cin >> s;
    n = (s.size() >> 1) - 1;
    for(int i = 0; i < s.size(); i += 2) {
        if(i == 0) {
            king.y = s[i] - 'A';
            king.x = s[i + 1] - '1';
        } else {
            int t = (i >> 1) - 1;
            knight[t].y = s[i] - 'A';
            knight[t].x = s[i + 1] - '1';
        }
    }
}

void floyd() {
    for(int i = 0; i < 8; ++i) {
        for(int j = 0; j < 8; ++j) {
            for(int k = 0; k < 8; ++k) {
                for(int l = 0; l < 8; ++l) {
                    if(abs(i - k) == 2 && abs(j - l) == 1
                            || abs(i - k) == 1 && abs(j - l) == 2)
                        dp[i][j][k][l] = 1;
                    else if(i == k && j == l) dp[i][j][k][l] = 0;
                    else dp[i][j][k][l] = INF;
                }
            }
        }
    }

    for(int k = 0; k < 64; ++k) {
        for(int i = 0; i < 64; ++i) {
            for(int j = 0; j < 64; ++j) {
                int x1 = i / 8, y1 = i % 8;
                int x2 = j / 8, y2 = j % 8;
                int x3 = k / 8, y3 = k % 8;
                dp[x1][y1][x2][y2] = min(dp[x1][y1][x2][y2],
                                         dp[x1][y1][x3][y3] + dp[x3][y3][x2][y2]);
            }
        }
    }
}

void solve() {
    ans = INF;
    for(int i = 0; i < 64; ++i) {  //最终位置
        int x1 = i / 8, y1 = i % 8;
        int sum = 0;
        for(int j = 0; j < n; ++j)
            sum += dp[x1][y1][knight[j].x][knight[j].y];
        for(int j = 0; j < 64; ++j) { //相遇位置
            int x2 = j / 8, y2 = j % 8;
            int kingMove = max(abs(king.x - x2), abs(king.y - y2));
            int knightMove = INF;
            for(int k = 0; k < n; ++k) { //枚举哪个骑士带国王
                int xk = knight[k].x, yk = knight[k].y;
                knightMove = min(knightMove, dp[xk][yk][x2][y2] +
                                 dp[x2][y2][x1][y1] - dp[xk][yk][x1][y1]);

                ans = min(ans, sum + kingMove + knightMove);
            }
        }
    }
    cout << ans << endl;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    read();
    floyd();
    solve();

    return 0;
}
