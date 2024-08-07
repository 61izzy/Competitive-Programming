#include <bits/stdc++.h>
using namespace std;

int t, n, a[50001];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        int mn = 0x3f3f3f3f;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (i > 1) mn = min(mn, max(a[i], a[i - 1]));
        }
        cout << mn - 1 << "\n";
    }
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