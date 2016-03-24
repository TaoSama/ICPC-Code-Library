//
//  Created by TaoSama on 2015-06-10
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
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 2e5 + 10;

int n, k, a[N];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    cin >> n >> k;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    int Min = INF, idx;
    for(int i = 1; i <= n - k + 1; ++i) {
//      cout << i << ' ' << i + k - 1 << ' ' << i - 1 << endl;
        if(a[i + k - 1] - a[i - 1] < Min) {
            Min = a[i + k - 1] - a[i - 1];
            idx = i;
        }
    }
    cout << idx << '\n';
    return 0;
}
