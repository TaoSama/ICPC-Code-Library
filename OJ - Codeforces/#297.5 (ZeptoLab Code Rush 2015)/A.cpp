//
//
//
//  Created by TaoSama on 2015-04-05
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
char a[105];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n >> (a + 1)) {
        bool ok = false;
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; i + 4 * j <= n; ++j) {
                if(a[i] == '*' && a[i + j] == '*'
                        && a[i + 2 * j] == '*' && a[i + 3 * j] == '*'
                        && a[i + 4 * j] == '*') {
                    ok = true;
                    break;
                }
            }
            if(ok) break;
        }
        if(ok) cout << "yes" << endl;
        else cout << "no" << endl;
    }
    return 0;
}
