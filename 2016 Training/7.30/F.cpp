//
//  Created by TaoSama on 2016-07-30
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

int n;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    cin >> n;
    vector<pair<int, string> > v(n);
    for(int i = 0; i < n; ++i) {
        cin >> v[i].second;
        int c, h; cin >> c >> h;
        int sum = 100 * c - 50 * h;
        for(int j = 0; j < 5; ++j) {
            int x; cin >> x;
            sum += x;
        }
        v[i].first = sum;
    }
    sort(v.begin(), v.end());
    cout << v.back().second << endl;

    return 0;
}
