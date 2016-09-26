//
//  Created by TaoSama on 2016-09-23
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

int n, t;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n >> t) {
        string s; cin >> s;

        vector<int> near(s.size(), -INF);
        bool ok = false;
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == '.') ok = true;
            if(ok) {
                near[i] = near[i - 1];
                if(s[i] >= '5') near[i] = i;
            }
        }

        if(!ok) {
            cout << s << endl;
            continue;
        }

        int carry = 0, i;
        for(i = s.size() - 1; i >= 0 && t--; --i) {
            if(s[i] == '.') {
                --i;
                break;
            }
            s[i] += carry;
            carry = (s[i] - '0') / 10;
            s[i] = (s[i] - '0') % 10 + '0';
            if(s[i] >= '5') {
                carry = 1;
            } else {
                if(i - near[i] > t) break;
            }
            s[i] = '0';
        }
//        prln(i);
//        prln(carry);
//        prln(s);
        if(carry) {
            for(; i >= 0; --i) {
                if(s[i] == '.') continue;
                s[i] += carry;
                carry = (s[i] - '0') / 10;
                s[i] = (s[i] - '0') % 10 + '0';
            }
        }

        while(s.back() == '0') s.pop_back();
        if(s.back() == '.') s.pop_back();

        if(carry) cout << 1;
        cout << s << endl;
    }

    return 0;
}
