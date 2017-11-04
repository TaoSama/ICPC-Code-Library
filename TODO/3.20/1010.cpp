//
//  Created by TaoSama on 2017-03-24
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
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e6 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;



int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

	string s;
    while(cin >> s){
		reverse(s.begin(), s.end());
		vector<int> v;
		for(int i = 1; i < s.size(); ++i)
			if(s[i] - '0' + s.front() - '0' == 10) v.push_back(i);
		v.push_back(s.size());

        if(v.size() == 1) {cout << "-1\n"; continue;}

		int ans = 0;
        string to = s.substr(v[1] + 1);
        for(int i = 0; i + 1 < v.size(); ++i){
			string from = s.substr(v[i] + 1, v[i + 1] - v[i]);
			int cnt = 1;

        }
    }

    return 0;
}
