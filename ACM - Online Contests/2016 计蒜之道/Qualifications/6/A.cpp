//
//  Created by TaoSama on 2016-06-11
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

string s;

bool isQuote(char c) {
    return c == '\'' || c == '\"';
}

bool judge() {
    char c = -1;
    if(s.size() > 1 && isQuote(s[0]) && s[0] == s.back()) {
        c = s[0];
        s.erase(0, 1);
        s.pop_back();
    }
    if(c == -1) return false;
    for(int i = 0; i < s.size(); ++i) {
        if(s[i] == c) return false;
        if(s[i] == '\\') {
            if(i + 1 < s.size() &&
                    s[i + 1] == '\\' ||
                    s[i + 1] == '\'' ||
                    s[i + 1] == '\"') {}
            else return false;
            ++i;
        }
    }
    return true;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    while(cin >> s) {
        if(judge()) cout << "Yes\n";
        else cout << "No\n";
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
