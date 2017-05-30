//
//  Created by TaoSama on 2017-05-07
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>

using namespace std;
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

vector<int> get(int s) {
    vector<int> ret;
    for(int x = (s / 50) % 475, i = 1; i <= 25; ++i) {
        x = (x * 96 + 42) % 475;
        ret.push_back(26 + x);
    }
    return ret;
}

int s, x, y;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

//  vector<int> ret1 = get(8000);
//  if(find(ret1.begin(), ret1.end(), 493) != ret1.end()) cout << "ok1\n";
//  vector<int> ret2 = get(10400);
//  if(find(ret2.begin(), ret2.end(), 493) != ret2.end()) cout << "ok2\n";

    while(cin >> s >> x >> y) {
        bool ok = false;
        for(int i = 0; i <= 10000 && !ok; ++i) {
            for(int j = 0; !ok; ++j) {
                int t = x + i * 100 - j * 50;
                if(t < y) break;
                vector<int> ret = get(t);
                if(find(ret.begin(), ret.end(), s) != ret.end()) {
                    cout << i << endl;
                    ok = true;
                }
            }
        }
        assert(ok);
    }
    return 0;
}
