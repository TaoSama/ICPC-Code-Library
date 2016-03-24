//
//  Created by TaoSama on 2015-07-18
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

string s;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    while(t--) {
        cin >> s;
        int n = s.size();
        int ans = 0;
        for(int i = 1; i < n; ++i) {
            bool ok = true;
            for(int j = 0; j < n; ++j) {
//              pr(s[(i + j) % n]); prln(s[(ans + j) % n]);
                if(s[(i + j) % n] > s[(ans + j) % n]) {
                    ok = false;
                    break;
                } else if(s[(i + j) % n] < s[(ans + j) % n]) {
                    ans = i;
                    break;
                }
            }
//            cout << endl;
        }
        for(int i = 0; i < n; ++i) cout << s[(ans + i) % n];
        cout << '\n';
    }
    return 0;
}
