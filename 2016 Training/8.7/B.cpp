//
//  Created by TaoSama on 2016-08-07
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

int n, d, l;
map<int, pair<int, int> > mp;
vector<int> ans;

bool solve1() {
    for(int i = 1; i <= l; ++i) {
        for(auto& p : mp) {
            int x = p.first;
            auto y = p.second;
            for(int j = 0; j <= n; ++j) {
                int lft = d - i - j * x;
                if(!lft && n - 1 - j * 2 >= 0) {
                    if((n - 1 - j * 2) % 2 == 0) {
                        ans.push_back(i);
                        for(int k = 0; k < j; ++k) {
                            ans.push_back(y.second);
                            ans.push_back(y.first);
                        }
                        for(int k = 0; k < (n - 1 - j * 2) / 2; ++k) {
                            ans.push_back(mp[0].second);
                            ans.push_back(mp[0].first);
                        }
                    }
                    return true;
                }
                for(auto& np : mp) {
                    int nx = np.first;
                    auto ny = np.second;
                    if(nx && lft % nx == 0) {
                        if(lft / nx < 0) continue;
                        int cnt = 1 + j * 2 + lft / nx * 2;
                        if(cnt == n) {
                            ans.push_back(i);
                            for(int k = 0; k < j; ++k) {
                                ans.push_back(y.second);
                                ans.push_back(y.first);
                            }
                            for(int k = 0; k < lft / nx; ++k) {
                                ans.push_back(ny.second);
                                ans.push_back(ny.first);
                            }
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}

bool solve2() {
    for(auto& p : mp) {
        int x = p.first;
        auto y = p.second;
        for(int j = 0; j <= n; ++j) {
            int lft = d - j * x;
            if(!lft && n - j * 2 >= 0) {
                if((n - j * 2) % 2 == 0) {
                    for(int k = 0; k < j; ++k) {
                        ans.push_back(y.first);
                        ans.push_back(y.second);
                    }
                    for(int k = 0; k < (n - j * 2) / 2; ++k) {
                        ans.push_back(mp[0].first);
                        ans.push_back(mp[0].second);
                    }
                    return true;
                }
            }
            for(auto& np : mp) {
                int nx = np.first;
                auto ny = np.second;
                if(nx && lft % nx == 0) {
                    if(lft / nx < 0) continue;
                    int cnt = j * 2 + lft / nx * 2;
                    if(cnt == n) {
                        for(int k = 0; k < j; ++k) {
                            ans.push_back(y.first);
                            ans.push_back(y.second);
                        }
                        for(int k = 0; k < lft / nx; ++k) {
                            ans.push_back(ny.first);
                            ans.push_back(ny.second);
                        }
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n >> d >> l) {
        mp.clear();
        for(int i = 1; i <= l; ++i)
            for(int j = 1; j <= l; ++j)
                if(!mp.count(i - j)) mp[i - j] = {i, j};

        bool ok = true;
        ans.clear();
        if(n & 1) {
            ok = solve1();
        } else {
            ok = solve2();
        }
        if(!ok) puts("-1");
        else {
            for(int i = 0; i < ans.size(); ++i)
                printf("%d%c", ans[i], " \n"[i == ans.size() - 1]);
        }
    }

    return 0;
}
