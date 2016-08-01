//
//  Created by TaoSama on 2016-07-30
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

int n;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n) {
        int cycle = 1, num = 5;
        while(num <= n) {
            cycle <<= 1;
            num += cycle * 5;
        }
//        prln(cycle);
        num -= cycle * 5;
        int lft = n - num;
        string names[5] = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};
        if(!lft) {
            cout << names[4] << endl;
            continue;
        }
        int mod = lft % cycle;
        lft /= cycle;
        if(!mod) --lft;
        cout << names[lft] << endl;
    }

    return 0;
}
