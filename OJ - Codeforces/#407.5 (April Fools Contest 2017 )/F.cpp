//
//  Created by TaoSama on 2017-04-01
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



int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int n; cin >> n;
    vector<int> v;
    for(int i = 1; i <= n; ++i) {
        int x; cin >> x;
        v.push_back(x);
    }
    clock_t fuck = clock();
    while(1.0 * (clock() - fuck) / CLOCKS_PER_SEC < 1.5)
        sort(v.begin(), v.end());
    for(int i = 1; i <= n; ++i)
        cout << v[i - 1] << " \n"[i == n];

    return 0;
}
