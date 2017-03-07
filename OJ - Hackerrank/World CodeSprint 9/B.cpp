//
//  Created by TaoSama on 2017-01-29
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
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;



int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    string s; int n;
    cin >> s >> n;
    set<int> vis;
    int sum = 0, last = -1;
    for(int i = 0; i < s.size(); ++i) {
        if(s[i] != last) sum = 0;
        sum += s[i] - 'a' + 1;
        vis.insert(sum);
        last = s[i];
    }
    for(int i = 1; i <= n; ++i) {
        int x; cin >> x;
        cout << (vis.count(x) ? "Yes" : "No") << '\n';
    }

    return 0;
}
