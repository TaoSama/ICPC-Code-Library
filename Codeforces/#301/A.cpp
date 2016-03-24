//
//  Created by TaoSama on 2015-05-08
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
string s, t;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n >> s >> t) {
        int sum = 0;
        for(int i = 0; i < n; ++i) {
            int x = abs(s[i] - t[i]);
            sum += x > 5 ? 10 - x : x;
        }
        cout << sum << endl;
    }
    return 0;
}
