#include <bits/stdc++.h>

using namespace std;

struct proc {
    string p;
    int at, bt; // arrival time and burst time

    proc() {}

    proc(int p, int at, int bt) : p(string("p") + to_string(p)), at(at), bt(bt) {}

    proc(string p, int at, int bt) : p(p), at(at), bt(bt) {}

    bool operator < (proc a) const {
        if (bt == a.bt) {
            if (at == a.at) {
                return p < a.p;
            }
            else {
                return at < a.at;
            }
        }
        else {
            return bt < a.bt;
        }
    }
};

struct p_time {
    string p;
    int t;

    p_time() {}

    p_time(string p, int t) : p(p), t(t) {}
};

struct times {
    int wt, tat, exec;

    times() : wt(0), tat(0), exec(0) {}

    times(int wt, int tat, int exec) : wt(wt), tat(tat), exec(exec) {}
};

struct proc_flow {
    string p;
    int b, e, l;

    proc_flow(string p, int b, int e) : p(p), b(b), e(e), l(e - b) {}
};

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << fixed << setprecision(2);

    int n, i;
    int at, bt, total_time = 0;
    int wt = 0, tat = 0, t_wt = 0, t_tat = 0, c_t = 0;
    double a_wt, a_tat, thr;
    int b, e;
    proc c_p;

    cin >> n;

    deque <proc> q, temp;
    set <proc> s;
    deque <p_time> p_ord;
    map <string, proc> mp;
    map <string, times> mp_t;
    vector <proc_flow> p_f;

    for (i = 0; i < n; i++) {
        cin >> at >> bt;

        q.push_back(proc(i + 1, at, bt));

        mp[q.back().p] = q.back();
    }

    sort(q.begin(), q.end(), [&] (proc a, proc b) {
        return a.at == b.at ? a.bt < b.bt : a.at < b.at;
    });

    for (i = 0; i < n; i++) {
        if (q[i].at > total_time) {
            total_time = q[i].at;
        }

        total_time += q[i].bt;
    }

    temp = q;

    cout << "Processes:\n";

    for (i = 0; i < n; i++) {
        cout << q[i].p << " " << q[i].at << " " << q[i].bt << "\n";
    }

    cout << "\n";

    cout << "Process flow:\n";

    cout << "Time : Process\n";

    for (i = 0, c_t = 0, c_p = {"none", -1, -1}; i < total_time; i++) {
        if (!s.empty()) {
            c_p = *s.begin();

            s.erase(s.begin());

            c_p.bt--;

            if (c_p.bt > 0) {
                s.insert(c_p);
            }

            if (!s.empty()) {
                c_p = *s.begin();
            }
            else {
                c_p.p = "none";
            }
        }

        if (!q.empty()) {
            while (!q.empty() && i == q.front().at) {
                s.insert(q.front());

                q.pop_front();

                c_p = *s.begin();
            }
        }

        if (p_ord.empty()) {
            p_ord.push_back({c_p.p, 1});
        }
        else {
            if (c_p.p == p_ord.back().p) {
                p_ord[p_ord.size() - 1].t++;
            }
            else {
                p_ord.push_back({c_p.p, 1});
            }
        }
    }

    for (i = 0, c_t = 0; i < p_ord.size(); i++) {
        if (mp[p_ord[i].p].at > c_t) {
            cout << c_t << " - " << mp[p_ord[i].p].at << " : none\n";

            p_f.push_back({"none", c_t, mp[p_ord[i].p].at});

            c_t = mp[p_ord[i].p].at;
        }
        
        cout << c_t << " - " << c_t + p_ord[i].t << " : " << p_ord[i].p << "\n";

        p_f.push_back({p_ord[i].p, c_t, c_t + p_ord[i].t});

        c_t += p_ord[i].t;
    }

    cout << "\n";

    for (i = 0, c_t = 0; i < p_ord.size(); i++) {
        if (mp[p_ord[i].p].at > c_t) {
            c_t = mp[p_ord[i].p].at;
        }
        else {
            mp_t[p_ord[i].p].wt += c_t - mp[p_ord[i].p].at - mp_t[p_ord[i].p].exec;
        }

        c_t += p_ord[i].t;
        mp_t[p_ord[i].p].exec += p_ord[i].t;
    }

    for (auto &it : mp_t) {
        it.second.tat = it.second.exec + it.second.wt;
    }

    cout << "Waiting and Turnaround time:\n";

    for (auto &it : mp_t) {
        cout << it.first << " " << it.second.wt << " " << it.second.tat << "\n";

        t_wt += it.second.wt;
        t_tat += it.second.tat;
    }

    cout << "\n";

    a_wt = double(t_wt) / n;
    a_tat = double(t_tat) / n;
    thr = double(n) / total_time;

    cout << "Average waiting time = " << a_wt << " unit\n";
    cout << "Average turnaround time = " << a_tat << " unit\n";
    cout << "Total time taken = " << total_time << " unit\n";
    cout << "Throughput = " << thr << " processes per unit time\n";

    cout << "\n";

    cout << "Gantt Chart:\n";

    bitset <1005> bar;

    for (i = 0; i < p_f.size(); i++) {
        auto t = to_string(p_f[i].b);

        bar[p_f[i].b * 4] = 1;
        bar[p_f[i].e * 4] = 1;

        if (t.length() < 2) {
            t = "0" + t;
        }

        cout << t << string(p_f[i].l * 4 - 2, ' ');
    }

    cout << p_f.back().e << "\n";

    for (i = 0; i <= 4 * total_time; i++) {
        if (bar[i]) {
            // cout << "|";

            // continue;
        }
        
        cout << "-";
    }

    cout << "\n";

    for (i = 0; i < p_f.size(); i++) {
        cout << "|" << string(p_f[i].l * 2 - 1, ' ') << p_f[i].p << string(p_f[i].l * 2 - 2, ' ');
    }

    cout << "|\n";

    for (i = 0; i <= 4 * total_time; i++) {
        cout << "-";
    }

    cout << "\n";

    return 0;
}