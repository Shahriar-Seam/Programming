#include <bits/stdc++.h>

using namespace std;

struct proc {
    string p;
    int at, bt; // arrival time, burst time

    proc() {}

    proc(int p, int at, int bt) : p(string("p") + to_string(p)), at(at), bt(bt) {}

    proc(string p, int at, int bt) : p(p), at(at), bt(bt) {}

    bool operator == (proc a) const {
        return p == a.p;
    }
};

ostream &operator << (ostream &os, proc p) {
    return os << p.p << " " << p.at << " " << p.bt;
}

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

    int n, t_q, i;
    int at, bt, pr, total_time = 0;
    int wt = 0, tat = 0, t_wt = 0, t_tat = 0, c_t = 0;
    double a_wt, a_tat, thr;
    int b, e;
    proc c_p;

    cin >> n >> t_q;

    deque <proc> q, temp;
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
        if (a.at == b.at) {
            return a.p < b.p;
        }
        else {
            return a.at < b.at;
        }
    });

    for (i = 0; i < n; i++) {
        if (q[i].at > total_time) {
            total_time = q[i].at;
        }

        total_time += q[i].bt;
    }

    cout << "Processes:\n";

    for (i = 0; i < n; i++) {
        cout << q[i] << "\n";
    }

    cout << "\n";

    cout << "Process flow:\n";

    cout << "Time : Process\n";

    for (i = 0, c_t = 0, c_p = {"NA", -1, -1}; i <= total_time; i++) {
        for (auto &it : q) {
            if (it.at == i) {
                temp.push_back(it);
            }
        }

        c_t++;

        if (!temp.empty()) {
            if (c_t < t_q && c_t < temp.front().bt) {
                continue;
            }
            
            if (c_t == temp.front().bt) {
                p_ord.push_back(p_time(temp.front().p, c_t));

                temp.pop_front();

                c_t = 0;
            }
            else {
                p_ord.push_back(p_time(temp.front().p, c_t));

                auto p = temp.front();

                p.bt -= c_t;

                temp.pop_front();
                temp.push_back(p);

                c_t = 0;
            }
        }
    }

    for (i = 0, c_t = 0; i < p_ord.size(); i++) {
        if (mp[p_ord[i].p].at > c_t) {
            cout << c_t << " - " << mp[p_ord[i].p].at << " : none\n";

            p_f.push_back({"NA", c_t, mp[p_ord[i].p].at});

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

        if (t.length() == 2) {
            cout << t << string(p_f[i].l - 2, ' ');
        }
        else {
            cout << t << string(p_f[i].l - 3, ' ');
        }
    }

    cout << p_f.back().e << "\n";

    for (i = 0; i <= total_time; i++) {
        if (bar[i]) {
            // cout << "|";

            // continue;
        }
        
        cout << "-";
    }

    cout << "\n";

    for (i = 0; i < p_f.size(); i++) {
        cout << "|" << string(p_f[i].l / 2 - 1, ' ') << p_f[i].p << string(p_f[i].l / 2 - 2, ' ');

        if (p_f[i].l & 1) {
            cout << " ";
        }
    }

    cout << "|\n";

    for (i = 0; i <= total_time; i++) {
        cout << "-";
    }

    cout << "\n";

    return 0;
}