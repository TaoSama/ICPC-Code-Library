//
//  Created by TaoSama on 2015-05-06
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

long long a, b;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> a >> b) {
        long long ans = 0;
        for(long long i = 1; i * i * i <= b; ++i) {
            ans += b / (i * i) - max((a - 1) / (i * i), i - 1);
        }
        cout << ans << '\n';
    }
    return 0;
}
