//
//  Created by TaoSama on 2016-06-04
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
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    cin >> n >> m;
    vector<int> v;
    for(int i = 1; i <= n; ++i) {
        int x; cin >> x;
        v.push_back(x);
        push_heap(v.begin(), v.end(), greater<int>());
    }

    cin.get();
    for(int i = 1; i <= m; ++i) {
        string line, tmp; getline(cin, line);
        stringstream ss(line);
        vector<string> split;
        while(ss >> tmp) split.push_back(tmp);
        if(split.size() == 4) {
            int x = stoi(split[0]);
            bool ok = v.front() == x;
            cout << "FT"[ok] << '\n';
        } else if(split.size() == 5) {
            int x = stoi(split[0]);
            int y = stoi(split[2]);
            x = find(v.begin(), v.end(), x) - v.begin();
            y = find(v.begin(), v.end(), y) - v.begin();

            bool ok = (x - 1) / 2 == (y - 1) / 2; //same root ?
            cout << "FT"[ok] << '\n';
        } else {
            int x = stoi(split[0]);
            int y = stoi(split.back());
            if(split[2] == "a") swap(x, y);
            x = find(v.begin(), v.end(), x) - v.begin();
            y = find(v.begin(), v.end(), y) - v.begin();

            //x is father now
            bool ok = x == (y - 1) / 2;
            cout << "FT"[ok] << '\n';
        }
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
