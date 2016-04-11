//
//
//
//  Created by TaoSama on 2015-04-16
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

int n;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    cin >> n;
    long long ans;
    if(n == 1) ans = 1;
    else if(n == 2) ans = 2;
    else if(n & 1) ans = 1LL * n * (n - 1) * (n - 2);
    else if(n % 3 == 0) ans = 1LL * (n - 1) * (n - 2) * (n - 3);
    else ans = 1LL * n * (n - 1) * (n - 3);
    cout << ans << endl;
    return 0;
}
