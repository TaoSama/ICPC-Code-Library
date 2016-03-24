//
//  Created by TaoSama on 2015-05-07
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



int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    int kase = 0;
    while(t--) {
        cout << "Case #" << ++kase << ":\n";
        cout << "*------------*\n";
        int x; cin >> x;
        x /= 10;
        for(int i = 1; i <= 10 - x; ++i)
            cout << '|' << string(12, '.') << "|\n";
		for(int i = 1; i <= x; ++i)
			cout << '|' << string(12, '-') << "|\n";
		cout << "*------------*\n";
    }
    return 0;
}
