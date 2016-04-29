//
//  Created by TaoSama on 2016-04-17
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
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
#include <sstream>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    string s;
    while(getline(cin, s)) {
        s = "+ " + s;
        vector<int> v;
        stringstream ss(s);
        int a = 0, b = 0;
        char op;
        while(ss >> op) {
            if(op == '=') {ss >> n; break;}
            if(op == '+') {
                ++a; ss >> op;
                v.push_back(1);
            } else {
                ++b; ss >> op;
                v.push_back(-1);
            }
        }

        int add = n - a + b;
        vector<int> ans(a + b, 1);
        int sign = add > 0 ? 1 : -1;
        add = abs(add);
        for(int i = 0; i < v.size(); ++i) {
            if(v[i] != sign) continue;
            int need = min(add, n - 1);
            ans[i] += need;
            add -= need;
        }
        if(add) {
            cout << "Impossible\n";
            continue;
        }
        cout << "Possible\n";
        for(int i = 0; i < ans.size(); ++i) {
            if(i == 0) cout << ans[i];
            else {
                if(v[i] == 1) cout << " + ";
                else cout << " - ";
                cout << ans[i];
            }
        }
        cout << " = " << n << '\n';
    }
    return 0;
}
