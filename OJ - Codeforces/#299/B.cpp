//
//
//
//  Created by TaoSama on 2015-04-15
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

char a[10];
int x[10], sum[10];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    x[0] = 1;
    for(int i = 1; i <= 9; ++i) {
        x[i] = x[i - 1] << 1;
        sum[i] = sum[i - 1] + x[i];
        //cout << sum[i] << ' ' << x[i] << endl;
    }
    while(cin >> (a + 1)) {
        int n = strlen(a + 1);
        int ans = 0;
        for(int i = 1; i <= n; ++i) {
            ans += (a[i] == '7' ? 1 : 0) * x[n - i];
        }
        ans += sum[n - 1] + 1;
        cout << ans << endl;
    }
    return 0;
}
