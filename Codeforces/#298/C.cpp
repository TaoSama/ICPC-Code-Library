//
//
//
//  Created by TaoSama on 2015-04-12
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
const int N = 2e5 + 10;

int n, a[N];
long long A;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n >> A) {
        long long sum = 0;
        for(int i = 1; i <= n; ++i) cin >> a[i], sum += a[i];
		for(int i = 1; i <= n; ++i){
			int l = max(1LL, A - (sum - a[i]));
			int r = min(0LL + a[i], A - (n - 1));
			cout<<a[i] - (r - l + 1);
			cout<<(i == n ? '\n' :' ');
		}
    }
    return 0;
}
