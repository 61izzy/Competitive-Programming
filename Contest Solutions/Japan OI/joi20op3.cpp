#include <bits/stdc++.h>
using namespace std;

int n, a, b, dp[200001], ans = 0;
string s;
vector<int> adj[200001];
void dfs1(int i, int p) {
    for (int j : adj[i]) {
        if (j == p) continue;
        dfs1(j, i);
        // if child has power generator, we can always take at least one
        if (s[j - 1] == '1') dp[i] += max(dp[j] - 1, 1);
        else dp[i] += dp[j];
    }
}
void dfs2(int i, int p, int v, bool thing) {
    dp[i] += v;
    for (int j : adj[i]) {
        if (j == p) continue;
        // honestly i forgot what this does but probably smth about propagating down the tree
        if (s[i - 1] == '1' && dp[i] == dp[j] - (s[j - 1] == '1' && dp[j] > 1)) dfs2(j, i, 1, true);
        else if (s[i - 1] == '1' && (dp[i] - dp[j] + (s[j - 1] == '1' && dp[j] > 1))) dfs2(j, i, max(1, dp[i] - dp[j] + (s[j - 1] == '1' && dp[j] > 1) - 1), true);
        else dfs2(j, i, (thing ? max(1, dp[i] - dp[j] + (s[j - 1] == '1' && dp[j] > 1)) : dp[i] - dp[j] + (s[j - 1] == '1' && dp[j] > 1)), dp[i] - dp[j] + (s[j - 1] == '1' && dp[j] > 1) > 0 || thing);
    }
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cin >> s;
    dfs1(1, 0);
    dfs2(1, 0, 0, 0);
    // weird case where if dp[i] == 1 and s[i - 1] == 1, dp[i] remains 1
    for (int i = 1; i <= n; i++) if (s[i - 1] == '1') dp[i] = (dp[i] > 2 ? dp[i] - 1 : max(dp[i], 1));
    // only affects the ans if two adjacent nodes have power generators and no other nodes do
    for (int i = 1; i <= n; i++) ans = max(ans, dp[i]);
    cout << ans << "\n";
    return 0;
}

/*
tips:
- look out for int overflow and array out of bounds
- don't get stuck debugging a wrong solution, take time to think of a new one instead of spamming submissions
- make sure stuestion was read correctly
- for certain problems, solve a few cases by hand and try to make observations
- if behind, stop looking at leaderboard and focus on solving
*/
