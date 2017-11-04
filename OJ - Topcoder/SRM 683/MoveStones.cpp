#include <bits/stdc++.h>

using namespace std;

class MoveStones {
public:
    long long get(vector<int> a, vector<int> b) {
        long long as = accumulate(a.begin(), a.end(), 0LL);
        long long bs = accumulate(b.begin(), b.end(), 0LL);
        if(as != bs) return -1;

        long long ans = 1e18;
        for(int i = 0; i < a.size(); ++i) {
            long long cur = 0, dif = 0;
            for(int j = 0; j < a.size(); ++j) {
                int k = (j + i) % a.size();
                cur += abs(dif);
                dif += a[k] - b[k];
            }
            ans = min(ans, cur);
        }
        return ans;
    }
};

// CUT begin
ifstream data("MoveStones.sample");

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

bool do_test(vector<int> a, vector<int> b, long long __expected) {
    time_t startClock = clock();
    MoveStones *instance = new MoveStones();
    long long __result = instance->get(a, b);
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
        vector<int> a;
        from_stream(a);
        vector<int> b;
        from_stream(b);
        next_line();
        long long __answer;
        from_stream(__answer);

        cases++;
        if(case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if(do_test(a, b, __answer)) {
            passed++;
        }
    }
    if(mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1456749388;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT *
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
        cout << "MoveStones (250 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end