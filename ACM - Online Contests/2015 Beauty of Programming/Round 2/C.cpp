//
//  Created by TaoSama on 2015-04-26
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

typedef pair<int, int> P;

int sex[105];

map<P, int> degree;
int T, n, m, Q;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin >> T;
    for(int t = 1; t <= T; t++) {
        degree.clear();
        cin >> n >> m >> Q;
        int tt;
        for(int i = 1; i <= n; i++) {
            cin >> tt;
            sex[i] = tt;
        }
        for(int i = 1; i <= n - 1; i++) {
            for(int j = i + 1; j <= n; j++) {
                degree[P(i, j)] = 0;
            }
        }

        int a, b, d;
        for(int i = 0; i < m; i++) {
            cin >> a >> b >> d;
            if(a > b) swap(a, b);
            degree[P(a, b)] = d;
        }
        cout << "Case #" << t << ":" << endl;
        int ope, id;
        for(int q = 0; q < Q; q++) {
            cin >> ope;
            if(ope == 1) {
                cin >> id;
                sex[id] ^= 1;
            } else if(ope == 2) {
                cin >> a >> b >> d;
                if(a > b) swap(a, b);
                degree[P(a, b)] = d;
            } else if(ope == 3) {
                int res = 0;
                for(int i = 1; i <= n - 1; i++) {
                    for(int j = i + 1; j <= n; j++) {
                        if(sex[i] ^ sex[j])
                            res += degree[P(i, j)];
                    }
                }
                cout << res << endl;
            }
        }
    }
    return 0;
}
