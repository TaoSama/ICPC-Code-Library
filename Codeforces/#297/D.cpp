//
//
//
//  Created by TaoSama on 2015-03-27
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

int n, m;
char a[2005][2005];
typedef pair<int, int> P;

bool judge(int x, int y) {
    if(x < 1 || x > n || y < 1 || y > m || a[x][y] == '.') return false;
    else if(a[x - 1][y] == '.' && a[x][y - 1] == '.'
            && a[x - 1][y - 1] == '.')  return true;
    else if(a[x + 1][y] == '.' && a[x][y - 1] == '.'
            && a[x + 1][y - 1] == '.') return true;
    else if(a[x - 1][y] == '.' && a[x][y + 1] == '.' &&
            a[x - 1][y + 1] == '.') return true;
    else if(a[x + 1][y] == '.' && a[x][y + 1] == '.' &&
            a[x + 1][y + 1] == '.') return true;
    return false;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n >> m) {
        queue<P> q;
        for(int i = 1; i <= n; ++i) cin >> a[i] + 1;
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= m; ++j)
                if(judge(i, j)) q.push(P(i, j));

        while(!q.empty()) {
            P p = q.front(); q.pop();
            if(judge(p.first, p.second)) {
                a[p.first][p.second] = '.';
                for(int i = -1; i <= 1; ++i) {
                    for(int j = -1; j <= 1; ++j) {
                        if(i == 0 && j == 0) continue;
                        P np(p.first + i, p.second + j);
                        if(judge(np.first, np.second))
                            q.push(np);
                    }
                }
            }
        }
        for(int i = 1; i <= n; ++i)
            cout << a[i] + 1 << endl;
    }
    return 0;
}
