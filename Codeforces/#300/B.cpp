//
//  Created by TaoSama on 2015-04-27
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

string s;
int a[15];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> s) {
        int n = -INF, l = s.size();
        for(int i = 0; i < l; ++i)
            n = max(n, a[i] = s[i] - '0');
        string ans[15];
        for(int i = 1; i <= n; ++i) {
            for(int j = 0; j < l; ++j) {
                if(a[j] > 0) ans[i] += '1', --a[j];
                else ans[i] += '0';
            }
        }
        cout << n << '\n';
        for(int i = 1; i <= n; ++i)
            cout << atoi(ans[i].c_str()) << ' ';
        cout << '\n';
    }
    return 0;
}
