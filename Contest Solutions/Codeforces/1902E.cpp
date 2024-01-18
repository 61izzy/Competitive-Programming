#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    unordered_map<char, TrieNode*> child;
    int cnt = 0;
    TrieNode() {}
} root;
int n;
string s[1000000];
long long ans = 0, res = 0;
void insert(string& s) {
    auto curr = &root;
    for (char c : s) {
        if (curr -> child.find(c) == curr -> child.end()) curr -> child.insert({c, new TrieNode()});
        curr = curr -> child[c];
        curr -> cnt++;
    }
}
void calc(string& s) {
    if (root.child.find(s[0]) == root.child.end()) return;
    TrieNode *curr = root.child[s[0]];
    for (int i = 0; i < s.length() && curr != nullptr; i++) {
        int thing = curr -> cnt;
        curr = (i + 1 < s.length() ? curr -> child[s[i + 1]] : nullptr);
        if (curr != nullptr) thing -= curr -> cnt;
        res += 2LL * thing * (i + 1);
    }
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        ans += s[i].length() * 2LL * n;
        insert(s[i]);
    }
    for (int i = 0; i < n; i++) {
        reverse(s[i].begin(), s[i].end());
        calc(s[i]);
    }
    cout << ans - res << "\n";
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
