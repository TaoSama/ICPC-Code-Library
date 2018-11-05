
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

pair<int, char> a[4];
char b[100][100];

vector<string> solve(int a, char aa, int b, char bb) {
    vector<string> v;
    int row = (a + 12) / 13 * 2;
    for(int i = 0; i < row; ++i) v.emplace_back(string(25, bb));
    int lftRow = 50 - row;
    for(int i = 0; i < row; i += 2) {
        for(int j = 0; j < 25; j += 2) {
            if(a > 1) {
                v[i][j] = aa;
                a--;
            }
        }
    }
    b--;
    for(int i = 0; i < lftRow; ++i) v.emplace_back(string(25, aa));
    for(int i = row + 1; i < 50; i += 2) {
        for(int j = 0; j < 25; j += 2) {
            if(b > 0) {
                v[i][j] = bb;
                b--;
            }
        }
    }
    return v;
}

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    while(cin >> a[0].first) {
        a[0].second = 'a';
        for(int i = 1; i < 4; ++i) {
            cin >> a[i].first;
            a[i].second = char('a' + i);
        }
        sort(a, a + 4);
        vector<string> left = solve(a[0].first, a[0].second, a[1].first, a[1].second);
        vector<string> right = solve(a[2].first, a[2].second, a[3].first, a[3].second);
        if(left.size() > right.size()) {
            swap(left, right);
        }
        while(left.size() < right.size()) {
            left.emplace_back(left.back());
        }
        cout << left.size() << ' ' << left[0].size() + right[0].size() << endl;
        for(int i = 0; i < left.size(); ++i) {
            cout << left[i] << right[i] << endl;
        }
    }
    return 0;
}
