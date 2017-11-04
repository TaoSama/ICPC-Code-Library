#include <bits/stdc++.h>

using namespace std;

class EllysSocks {
public:
    int f[2005];

    bool check(int x, int p, vector<int>& S) {
        int n = S.size();
        memset(f, 0, sizeof f);
        for(int i = 1; i <= n; ++i){
            f[i] = max(f[i], f[i - 1]);
            if(i < n && S[i] - S[i - 1] <= x)
                f[i + 1] = max(f[i + 1], f[i - 1] + 1);
        }
        return f[n] >= p;
    }

    int getDifference(vector<int> S, int P) {
        sort(S.begin(), S.end());

        int l = 0, r = 1e9;
//        if(P == 2) check(1, P, S);
        while(l <= r) {
            int m = l + r >> 1;
            if(check(m, P, S)) r = m - 1;
            else l = m + 1;
        }
        return l;
    }
};

// CUT begin
ifstream data("EllysSocks.sample");

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

bool do_test(vector<int> S, int P, int __expected) {
    time_t startClock = clock();
    EllysSocks *instance = new EllysSocks();
    int __result = instance->getDifference(S, P);
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
        vector<int> S;
        from_stream(S);
        int P;
        from_stream(P);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if(case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if(do_test(S, P, __answer)) {
            passed++;
        }
    }
    if(mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1459008382;
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
        cout << "EllysSocks (500 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
