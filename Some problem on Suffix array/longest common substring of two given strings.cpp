/*
Find the longest common substring of two given strings s
 and t.
*/

signed main() {
    Go();
    string s1, s2;
    cin >> s1 >> s2;
    string s = s1 + (char) (('a') - 1) + s2;
    suffixArray suf(s);
    vector<ll> pos = suf.getPos(), lcp = suf.getLcp(), cost = suf.getCost();
    int ans = 0;
    string res = "";
    int idx;
    for (int i = 0; i < s.size(); i++) {
        int first = pos[i];
        int sec = pos[i + 1];
        if (lcp[i] > ans && ((first < s1.size() && sec > s1.size()) || (first > s1.size() && sec < s1.size()))) {
            ans = lcp[i];
            idx = min(first, sec);
        }
    }
    cout << s.substr(idx, ans) << endl;
    return 0;
}