#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i, j;

    cin >> n;

    vector <vector <int> > job(n, vector <int> (3));
    vector <vector <pair <int, int> > > job_indices;
    // job_indices[i] = jobs ended on day i
    map <int, int> indices;
    vector <long long> dp;
    // dp[i] = max reward till day i

    for (i = 0; i < n; i++) {
        cin >> job[i][0] >> job[i][1] >> job[i][2];

        indices[job[i][0]] = 0;
        indices[job[i][0] - 1] = 0;
        indices[job[i][1]] = 0;
        indices[job[i][1] - 1] = 0;
    }

    dp.resize(indices.size() + 1, 0);
    job_indices.resize(indices.size() + 1);

    i = 1;
    for (auto &it : indices) {
        it.second = i;
        i++;
    }

    // https://www.geeksforgeeks.org/vectoremplace_back-c-stl/
    for (i = 0; i < n; i++) {
        job_indices[indices[job[i][1]]].emplace_back(i, indices[job[i][0] - 1]);
    }

    for (i = 1; i < dp.size(); i++) {
        dp[i] = dp[i - 1];

        for (j = 0; j < job_indices[i].size(); j++) {
            dp[i] = max(dp[i], job[job_indices[i][j].first][2] + dp[job_indices[i][j].second]);
        }
    }

    cout << dp.back() << "\n";

    return 0;
}