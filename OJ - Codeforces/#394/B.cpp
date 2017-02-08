//
//  Created by TaoSama on 2017-01-31
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

int n, L;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n >> L) {
        vector<int> a(n), b(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        for(int i = 0; i < n; ++i) cin >> b[i];

        bool ok = false;
        for(int A = 0; A < L; ++A) {
            vector<int> pos;
            for(int i = 0; i < n; ++i) pos.push_back((A + a[i]) % L);
            sort(pos.begin(), pos.end());
            for(int i = 0; i < n; ++i) {
                pos.push_back(pos[i] + L);
            }
            for(int B = 0; B < L; ++B) {
                int st = lower_bound(pos.begin(), pos.end(), B) - pos.begin();
                vector<int> pos2;
                for(int j = 0; j < n; ++j) {
                    pos2.push_back(pos[st + j] - B);
                }
                ok |= pos2 == b;
            }
        }

        cout << (ok ? "YES" : "NO") << endl;
    }

    return 0;
}
