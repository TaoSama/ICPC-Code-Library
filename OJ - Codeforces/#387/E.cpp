#include <bits/stdc++.h>
using namespace std;
#define pr(x)   cout << #x << " = " << x << " "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e6 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

vector<string> v, level[N];
int idx, maxd;

void dfs(int d) {
    maxd = max(maxd, d);
    ++idx;
    level[d].push_back(v[idx]);
    int sz = stoi(v[++idx]);
    for(int i = 0; i < sz; ++i)
        dfs(d + 1);
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\luwt\\Desktop\\in.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(false);

    string line;
    cin >> line;
    for(auto& c : line) if(c == ',') c = ' ';
    stringstream ss(line);
    string token;
    while(ss >> token) v.push_back(token);

    idx = -1;
    while(idx < (int)v.size() - 1) {
        dfs(1);
    }
    cout << maxd << endl;
    for(int i = 1; i <= maxd; ++i) {
        for(int j = 0; j < level[i].size(); ++j) {
            cout << level[i][j] << " \n"[j + 1 == level[i].size()];
        }
    }
    return 0;
}
