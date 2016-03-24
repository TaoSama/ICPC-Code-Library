//
//  Created by TaoSama on 2015-08-09
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

int n, m;
int a[105][105];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n >> m) {
        for(int i = 1; i <= n; ++i) {
            char buf[105]; cin >> buf;
            for(int j = 0; j < m; ++j)
                a[i][j + 1] = buf[j] - '0';
        }
        set<int> s;
        for(int j = 1; j <= m; ++j) {
            int maxv = -INF;
            for(int i = 1; i <= n; ++i)
                maxv = max(maxv, a[i][j]);
//          cout << maxv << endl;
            for(int i = 1; i <= n; ++i)
                if(a[i][j] == maxv) s.insert(i);
        }
        cout << s.size() << '\n';
    }
    return 0;
}
