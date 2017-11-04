#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

string solve(const string& s, int k) {
    vector<pair<char, int>> v;
    for(int i = 0; i < s.size(); ++i) v.push_back({s[i], i});
    sort(v.begin(), v.end());

    int idx = 0;
    string ret = "";
    for(int i = 0; i < v.size() && k > 0; ++i) {
        char c = v[i].first; int p = v[i].second;
        if(p < idx) continue; //那些已经删掉了
        int cost = p - idx;
        if(cost <= k) {
            k -= cost;
            ret += c;
            idx = p + 1;
        }
    }
    ret += s.substr(idx);
    for(; k > 0 && ret.size(); --k) ret.pop_back();
    return ret;
}

int getM(vector<vector<int>> vs, int n) {
    int l = 0, r = 1e9;  //二分中位数答案
    while(l <= r) {
        int m = l + r >> 1;
        int small = 0;
        for(const auto& v : vs) {
            //求<=有多少个
            small += upper_bound(v.begin(), v.end(), m) - v.begin();
        }
        if(small <= n / 2) l = m + 1;
        else r = m - 1;
    }
    return l;
}

struct AA {
    int a;
};

struct BB: AA {
    int b;
};

#include <exception>

int main() {
    string x = "abc";
//    string test = "cabacde"; int k = 4;
//    cout << solve(test, k) << endl;
//
//    cout << getM({{3}, {3}, {3}, {100}, {200}}, 5) << endl;
//    cout << getM({{1}, {2}, {2}, {100}, {200}}, 5) << endl;
//    cout << getM({{1}, {2}, {3}, {100}, {200}}, 5) << endl;
    return 0;
}
