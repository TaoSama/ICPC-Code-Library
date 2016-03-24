//
//  Created by TaoSama on 2015-07-23
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
//#pragma comment(linker, "/STACK:1024000000,1024000000")
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
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, D, I;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n && ~n) {
        for(int i = 1; i <= n; ++i) {
            cin >> D >> I;
            int k = 1;
            for(int i = 1; i < D; ++i) {
                if(I & 1) { //odd for left
                    k <<= 1; //get the node's id
                    I = I + 1 >> 1; // the I th for the subtree
                } else {
                    k = k << 1 | 1;
                    I >>= 1;
                }
            }
            cout << k << '\n';
        }
    }
    return 0;
}
