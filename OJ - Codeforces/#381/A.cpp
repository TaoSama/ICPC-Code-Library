//
//  Created by TaoSama on 2016-11-24
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

long long n, a, b, c;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n >> a >> b >> c) {
        long long ans = 1e18;
        for(int i = 0; i <= 4; ++i) {
            for(int j = 0; j <= 4; ++j) {
                for(int k = 0; k <= 4; ++k) {
                    long long sum = n + i + 2 * j + 3 * k;
                    if(sum % 4 == 0) {
                        ans = min(ans, i * a + j * b + k * c);
                    }
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}