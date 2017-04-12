//
//  Created by TaoSama on 2017-03-28
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
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, k;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n >> k) {
        vector<int> v(n);
        iota(v.begin(), v.end(), 1);
        int cur = 0;
        for(int i = 1; i <= k; ++i) {
            int x; cin >> x;
            int step = x % v.size();
            cur = (cur + step) % v.size();
            cout << *(v.begin() + cur) << " \n"[i == k];
            auto iter = v.erase(v.begin() + cur);
            cur = iter - v.begin();
        }

    }

    return 0;
}
