/*
Consider an array of n
 integers from 1
 to m
. A subsequence of consecutive elements of this array is called refrain if the product of its length and the number of occurrences in the array is maximum possible.

Given an array, your task is to find its refrain.
*/

signed main() {
    Go();
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++)cin >> v[i];
    suffixArray suf = suffixArray(v);
    vector<ll> pos = suf.getPos(), lcp = suf.getLcp(), cost = suf.getCost();
    set<pair<ll, ll>, greater<pair<ll, ll> > > s;
    vector<vector<ll> > sp = build(lcp);
    int ans = 0;
    int idx, len;
    set<ll> idxs;
    for (int i = 0; i < lcp.size(); i++)idxs.insert(i);
    for (int i = 0; i < lcp.size(); i++) {
        int mn = 1e9;
        while (s.size() && lcp[i] < s.begin()->first) {
            if (s.begin()->first * (i - s.begin()->second + 1) >= ans) {
                idx = pos[s.begin()->second];
                len = s.begin()->first;
                ans = max(s.begin()->first * (i - s.begin()->second + 1), ans);
            }
            idxs.erase(s.begin()->second);
            auto [x, y] = *s.begin();
            s.erase(s.begin());
            mn = min(mn, y);
        }
        if (mn != 1e9)
            s.insert({lcp[i], mn});
        if (s.empty() || (lcp[i] > s.begin()->first && lcp[i] != 0))
            s.insert({lcp[i], i});
    }
    while (s.size()) {
        if (s.begin()->first * ((int) lcp.size() - s.begin()->second + 1) > ans) {
            idx = pos[s.begin()->second];
            len = s.begin()->first;
            ans = max(s.begin()->first * ((int) lcp.size() - s.begin()->second + 1), ans);
        }
        s.erase(s.begin());
    }
    if (ans < n) {
        cout << n << endl;
        cout << n << endl;
        for (auto it: v)
            cout << it << " ";
    } else {
        cout << ans << endl;
        cout << len << endl;
        for (int i = idx; i < idx + len; i++)
            cout << v[i] << " ";
        cout << endl;
    }


    return 0;
}