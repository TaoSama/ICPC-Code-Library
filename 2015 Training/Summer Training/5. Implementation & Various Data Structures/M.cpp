//
//  Created by TaoSama on 2015-07-23
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
//#pragma comment(linker, "/STACK:1024000000,1024000000")
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
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m, cnt;
int d[][2] = { -1, 0, 0, -1, 1, 0, 0, 1};
int s[205][55 << 2];
const char* word = "WAKJSD";

void dfs(int x, int y) {
    s[x][y] = -1;
    for(int i = 0; i < 4; ++i) {
        int nx = x + d[i][0], ny = y + d[i][1];
        if(nx < 0 || nx > n + 1 || ny < 0 || ny > m + 1 || s[nx][ny]) continue;
        dfs(nx, ny);
    }
}

void white(int x, int y) {
    if(s[x][y] == 0) { //inner white
        ++cnt;
        dfs(x, y); //colored them
        return;
    }

    s[x][y] = -1;
    for(int i = 0; i < 4; ++i) {
        int nx = x + d[i][0], ny = y + d[i][1];
        if(nx < 0 || nx > n + 1 || ny < 0 || ny > m + 1 || s[nx][ny] == -1) continue;
        white(nx, ny); //to find the inner white
    }
}

void print() {
    for(int i = 0; i <= n; ++i) {
        for(int j = 0; j <= m; ++j) {
            cout << s[i][j];
        }
        cout << endl;
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int kase = 0;
    while(cin >> n >> m && (n || m)) {
        memset(s, 0, sizeof s);

        for(int i = 1; i <= n; ++i) {
            char buf[55]; cin >> (buf + 1);
            int p = 1, x;
            for(int j = 1; j <= m; ++j) {
                if(isalpha(buf[j])) x = 10 + buf[j] - 'a';
                else x = buf[j] - '0';
                for(int k = 3; k >= 0; --k) s[i][p++] = x >> k & 1;
            }
        }
        m <<= 2;

//        print(); cout << endl;
        dfs(0, 0); //expand one more to remove the outer white
//        print();

        string ans;
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                if(s[i][j] == 1) { //try to color the inner white
                    cnt = 0;
                    white(i, j);
//                    prln(cnt);
                    ans += word[cnt];
                }
            }
        }
        sort(ans.begin(), ans.end());
        cout << "Case " << ++kase << ": " << ans << '\n';
    }
    return 0;
}
