/*
Given the string s
 and a set of its substrings. Substrings are defined by pairs of numbers li,ri
, the position of the left end and the right end of the substring. You need to sort substrings in lexicographic order. If substrings are equal as words, then use the pairs themselves as an additional sorting key (i.e., first compare by l
, then by r
).
*/


suffixArray suf("");

bool comp(pair<ll, ll> p1, pair<ll, ll> p2) {
    int l1 = p1.first, r1 = p1.second, l2 = p2.first, r2 = p2.second;
    int range1 = r1 - l1 + 1;
    int range2 = r2 - l2 + 1;
    for (int i = 30; i >= 0; i--) {
        if ((range1 >= (1 << i)) && (range2 >= (1 << i))) {
            if (suf.totCost[i][l1] != suf.totCost[i][l2]) {
                return suf.totCost[i][l1] < suf.totCost[i][l2];
            } else l1 += (1 << i), l2 += (1 << i), range1 -= (1 << i), range2 -= (1 << i);
        }
    }
    if (range1 == 0 && range2 == 0)return p1 < p2;
    if (range1 == 0)return true;
    if (range2 == 0)return false;
    return true;
}

signed main() {
    Go();
    string s;
    cin >> s;
    suf = suffixArray(s);
    vector<ll> pos = suf.getPos(), lcp = suf.getLcp(), cost = suf.getCost();
    vector<pair<int, int> > queries;
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        queries.push_back({l, r});
    }
    sort(queries.begin(), queries.end(), comp);
    for (auto it: queries)
        cout << it.first + 1 << " " << it.second + 1 << endl;
    return 0;
}
