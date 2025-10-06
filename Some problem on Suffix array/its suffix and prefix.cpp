/*
String t
 is a border of string s
, if it is at the same time its suffix and prefix. For example, string abbabba
 has three borders: abba
, a
 and an empty string.

Given a string s
, calculate total number of borders of all its substrings.
*/

signed main() {
    Go();
    string s;
    cin >> s;
    suffixArray suf(s);
    vector<int> lcp = suf.getLcp(), pos = suf.getPos();
    stack<int> st;
    vector<ll> next(lcp.size()), prev(lcp.size());
    for (int i = 0; i < lcp.size(); i++) {
        while (st.size() && lcp[i] <= lcp[st.top()]) {
            next[st.top()] = i - 1;
            st.pop();
        }
        st.push(i);
    }
    while (st.size()) {
        next[st.top()] = lcp.size() - 1;
        st.pop();
    }
    for (int i = lcp.size() - 1; i >= 0; i--) {
        while (st.size() && lcp[i] < lcp[st.top()]) {
            prev[st.top()] = i + 1;
            st.pop();
        }
        st.push(i);
    }
    while (st.size()) {
        prev[st.top()] = 0;
        st.pop();
    }
    int ans = s.size() * (s.size() + 1) / 2;
    for (int i = 0; i < lcp.size(); i++) {
        int left = prev[i];
        int right = next[i];
        left = i - left;
        right -= i;
        right = max(right, 0ll);
        ans += (left * right) * lcp[i];
        ans += left * lcp[i];
        ans += ((right * lcp[i]));
        ans += lcp[i];
    }
    cout << ans << endl;
    return 0;
}