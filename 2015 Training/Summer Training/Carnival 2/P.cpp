//
//  Created by TaoSama on 2015-08-02
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

int n, b[10];
pair<int, string> a[55];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n) {
        for(int i = 1; i <= n; ++i) {
            cin >> a[i].second;
            for(int j = 1; j <= 7; ++j) cin >> b[j];
            int sum = 0;
            for(int j = 3; j <= 7; ++j) sum += b[j];
            sum += b[1] * 100 - b[2] * 50;
            a[i].first = sum;
        }
        sort(a + 1, a + 1 + n);
//      cout << a[n].first << endl;
        cout << a[n].second << '\n';
    }
    return 0;
}
