//
//
//
//  Created by TaoSama on 2015-03-26
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
char a[105][105];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    //freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> m >> n) {
        for(int i = 1; i <= n; ++i) cin >> a[i] + 1;
        for(int j = 1; j <= m; ++j) {
            for(int i = 1; i <= n; ++i) {
                cout << a[i][j] << a[i][j];
            }
            cout << endl;
            for(int i = 1; i <= n; ++i) {
                cout << a[i][j] << a[i][j];
            }
            cout << endl;
        }
    }

    return 0;
}
