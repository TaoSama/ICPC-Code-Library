//
//  Created by TaoSama on 2017-01-19
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
const int N = 1e2 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

const string bulb = "RBYG";

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    string s;
    while(cin >> s) {
        vector<int> idx(4, 0);
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == '!') continue;
            int p = bulb.find(s[i]);
            idx[i % 4] = p;
        }

        vector<int> ans(4, 0);
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] != '!') continue;
            ++ans[idx[i % 4]];
        }
        for(int i = 0; i < 4; ++i)
            cout << ans[i] << " \n"[i == 3];
    }


    return 0;
}
