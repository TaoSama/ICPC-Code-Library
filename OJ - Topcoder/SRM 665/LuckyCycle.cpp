#include <bits/stdc++.h>

using namespace std;

class LuckyCycle {
public:

    int n, G[105][105];
    bool vis[105];
    int four, seven, first, pre[105];
    bool dfs(int u, int f) {
        vis[u] = true;
        for(int i = 1; i <= n; ++i) {
            if(!G[u][i] || i == f) continue;
            pre[i] = u;
            if(vis[i]) {
                first = i;
                return true;
            }
            if(dfs(i, u)) return true;
        }
        return false;
    }

    bool check() {
        memset(vis, false, sizeof vis);
        four = seven = 0;
        if(!dfs(1, -1)) return false;
        int cur = first;
//        cout << cur << ' ';
        while(true) {
            if(G[cur][pre[cur]] == 4) four++;
            else seven++;
            cur = pre[cur];
//            cout << cur << ' ';
            if(cur == first) break;
        }
//        cout << endl;
        return four == seven;
    }

    vector<int> getEdge(vector<int> edge1, vector<int> edge2, vector<int> weight) {
        n = edge1.size() + 1;
        memset(G, 0, sizeof G);
        for(int i = 0; i < edge1.size(); ++i) {
            int u = edge1[i], v = edge2[i], c = weight[i];
            G[u][v] = G[v][u] = c;
        }

        int w[] = {4, 7};
        for(int i = 1; i <= n; ++i) {
            for(int j = i + 1; j <= n; ++j) {
                for(int k = 0; k < 2; ++k) {
                    if(G[i][j]) continue;
//                    if(i == 1 && j == 5) cout << "begin: " << endl;
                    G[i][j] = G[j][i] = w[k];
                    if(check()) {
                        vector<int> v;
                        v.push_back(i);
                        v.push_back(j);
                        v.push_back(w[k]);
                        return v;
                    }
//                    if(i == 1 && j == 5) cout << "end: " << endl;
                    G[i][j] = G[j][i] = 0;
                }
            }
        }

        return vector<int>();
    }
};

// CUT begin
ifstream data("LuckyCycle.sample");

string next_line() {
    string s;
    getline(data, s);
    return s;
}

template <typename T> void from_stream(T &t) {
    stringstream ss(next_line());
    ss >> t;
}

void from_stream(string &s) {
    s = next_line();
}

template <typename T> void from_stream(vector<T> &ts) {
    int len;
    from_stream(len);
    ts.clear();
    for(int i = 0; i < len; ++i) {
        T t;
        from_stream(t);
        ts.push_back(t);
    }
}

template <typename T>
string to_string(T t) {
    stringstream s;
    s << t;
    return s.str();
}

string to_string(string t) {
    return "\"" + t + "\"";
}

template <typename T> string to_string(vector<T> ts) {
    stringstream s;
    s << "[ ";
    for(int i = 0; i < ts.size(); ++i) {
        if(i > 0) s << ", ";
        s << to_string(ts[i]);
    }
    s << " ]";
    return s.str();
}

bool do_test(vector<int> edge1, vector<int> edge2, vector<int> weight,
             vector<int> __expected) {
    time_t startClock = clock();
    LuckyCycle *instance = new LuckyCycle();
    vector<int> __result = instance->getEdge(edge1, edge2, weight);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if(__result == __expected) {
        cout << "PASSED!" << " (" << elapsed << " seconds)" << endl;
        return true;
    } else {
        cout << "FAILED!" << " (" << elapsed << " seconds)" << endl;
        cout << "           Expected: " << to_string(__expected) << endl;
        cout << "           Received: " << to_string(__result) << endl;
        return false;
    }
}

int run_test(bool mainProcess, const set<int> &case_set, const string command) {
    int cases = 0, passed = 0;
    while(true) {
        if(next_line().find("--") != 0)
            break;
        vector<int> edge1;
        from_stream(edge1);
        vector<int> edge2;
        from_stream(edge2);
        vector<int> weight;
        from_stream(weight);
        next_line();
        vector<int> __answer;
        from_stream(__answer);

        cases++;
        if(case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if(do_test(edge1, edge2, weight, __answer)) {
            passed++;
        }
    }
    if(mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1439291373;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT *
                                      TT)) << " points" << endl;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    set<int> cases;
    bool mainProcess = true;
    for(int i = 1; i < argc; ++i) {
        if(string(argv[i]) == "-") {
            mainProcess = false;
        } else {
            cases.insert(atoi(argv[i]));
        }
    }
    if(mainProcess) {
        cout << "LuckyCycle (500 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
