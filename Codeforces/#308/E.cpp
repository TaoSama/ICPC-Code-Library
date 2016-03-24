//
//  Created by TaoSama on 2015-06-19
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
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;

string s;

long long cal(int l, int r) {
//  cout << l << ' ' << r << endl;
    long long in = 0, mul = s[l] - '0';
    for(int i = l + 1; i <= r; i += 2) {
        if(s[i] == '*') mul *= s[i + 1] - '0';
        else {
            in += mul;
//          cout << "mul: " << mul << endl;
            mul = s[i + 1] - '0';
        }
    }
    in += mul;
//  cout << "in: " << in << endl;

    long long ret = 0;
    mul = s[0] - '0';
    for(int i = 1; i < s.size(); i += 2) {
        if(i + 1 == l) {
            mul *= in;
//          cout << "turn: " << mul << endl;
            i = r - 1;
            continue;
        }
        if(s[i] == '*') mul *= s[i + 1] - '0';
        else {
            ret += mul;
            mul = s[i + 1] - '0';
        }
    }
    ret += mul;
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> s) {
        s = "1*" + s; s = s + "*1";

        long long ans = -INF;
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] != '*') continue;
            for(int j = i + 1; j < s.size(); ++j) {
                if(s[j] != '*') continue;
                ans = max(ans, cal(i + 1, j - 1)); //À¨ºÅÀïµÄ[]
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
