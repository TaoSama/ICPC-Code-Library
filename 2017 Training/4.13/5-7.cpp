//
//  Created by TaoSama on 2017-04-13
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>

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
    vector<vector<int>> block;
    for(int i = 1; i <= n; ++i) {
        int x; cin >> x;
        bool ok = false;
        for(int j = 0; j < block.size() && !ok; ++j) {
            auto& v = block[j];
            if(accumulate(v.begin(), v.end(), 0) + x <= 100) {
                v.push_back(x);
                ok = true;
                cout << x << ' ' << j + 1 << endl;
            }
        }
        if(!ok) {
            block.push_back(vector<int>(1, x));
            cout << x << ' ' << block.size() << endl;
        }
    }
    cout << block.size() << endl;

    return 0;
}
