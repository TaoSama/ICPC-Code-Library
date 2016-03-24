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

int n, a[N], b[N];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n) {
        for(int i = 1; i <= n; ++i) cin >> a[i];
        sort(a + 1, a + 1 + n);
        int ct = 0;
        for(int i = n; i >= 0; i -= 2) {
            if(a[i] == a[i - 1]) b[ct++] = a[i];
            else {
                if(a[i] - a[i-1] == 1) b[ct++] = a[i-1];
                else ++i;
            }
        }
        long long ans = 0;
        for(int i = 0; i <= ct - 1; i += 2)
            ans += (long long)b[i] * b[i + 1];
        cout << ans << endl;
    }
    return 0;
}
