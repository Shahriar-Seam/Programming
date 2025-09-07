#include <bits/stdc++.h>

using namespace std;

struct proc {
    string p;
    int at, bt; // arrival time and burst time

    proc() {}

    proc(int p, int at, int bt) : p(string("p") + to_string(p)), at(at), bt(bt) {}
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
    vector <proc_flow> p_f;

    cin >> n;

    deque <proc> q;

    for (i = 0; i < n; i++) {
        cin >> at >> bt;

        q.push_back(proc(i + 1, at, bt));
    }

    sort(q.begin(), q.end(), [&] (proc a, proc b) {
        return a.at < b.at;
    });

    for (i = 0; i < n; i++) {
        if (q[i].at > total_time) {
            total_time = q[i].at;
        }

        total_time += q[i].bt;
    }

    cout << "Processes:\n";

    for (i = 0; i < n; i++) {
        cout << q[i].p << " " << q[i].at << " " << q[i].bt << "\n";
    }

    cout << "\n";

    cout << "Process flow:\n";

    cout << "Time : Process\n";

    for (i = 0, c_t = 0; i < n; i++) {
        if (c_t < q[i].at) {
            cout << c_t << " - " << q[i].at << " : " << "none\n";

            p_f.push_back({"none", c_t, q[i].at});

            c_t = q[i].at;
        }

        b = c_t;
        e = c_t + q[i].bt;

        cout << b << " - " << e << " : " << q[i].p << "\n";

        p_f.push_back({q[i].p, b, e});

        c_t += q[i].bt;
    }

    cout << "\n";

    cout << "Waiting and Turnaround time:\n";

    for (i = 0, c_t = 0; i < n; i++) {
        wt = max(0, c_t - q[i].at);
        tat = wt + q[i].bt;

        cout << q[i].p << " " << wt << " " << tat << "\n";

        t_wt += wt;
        t_tat += tat;
        
        if (c_t < q[i].at) {
            c_t = q[i].at;
        }

        c_t += q[i].bt;
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

    for (i = 0; i < p_f.size(); i++) {
        auto t = to_string(p_f[i].b);

        if (t.length() < 2) {
            t = "0" + t;
        }

        cout << t << string(p_f[i].l * 4 - 2, ' ');
    }

    cout << p_f.back().e << "\n";

    for (i = 0; i <= 4 * total_time; i++) {
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