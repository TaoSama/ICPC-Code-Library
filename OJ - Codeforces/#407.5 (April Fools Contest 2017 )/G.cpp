//
//  Created by TaoSama on 2017-03-31
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
#include <sstream>

using namespace std;
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;


int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);

    string s;
    while(cin >> s) {
        string t;
        for(char c : s) {
            if(!isdigit(c)) t += ' ';
            t += c;
            if(!isdigit(c)) t += ' ';
        }
        stringstream ss(t);
        int ans = 0, sgn = 1;
        while(ss >> s) {
            if(isdigit(s[0])) {
                int x = stoi(s);
                ans += sgn * x;
            } else {
                sgn = s[0] == '-' ? -1 : 1;
            }
        }
        s = to_string(ans);
//        cout << ans << endl;

        int last = 0;
        for(char c : s) {
            int diff = c - last;
            char op[] = "+-", sgn = diff < 0;
            diff = abs(diff);
            while(diff--) cout << op[sgn];
            cout << '.';
            last = c;
        }
    }

    return 0;
}
