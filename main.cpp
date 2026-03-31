#include <bits/stdc++.h>
using namespace std;

// Maintain a set of non-overlapping, non-touching intervals.
// Operation A l r: remove all intervals that overlap (inclusive) with [l, r],
// report how many were removed, then insert [l, r].
// Operation B: report current number of intervals.

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    set<pair<int,int>> S; // ordered by start
    for (int i = 0; i < n; ++i) {
        char op;
        cin >> op;
        if (op == 'A') {
            int l, r;
            cin >> l >> r;

            int removed = 0;
            // Find first interval with start >= l
            auto it = S.lower_bound({l, INT_MIN});
            // Check the previous interval in case it overlaps from the left
            if (it != S.begin()) {
                auto pit = prev(it);
                if (max(pit->first, l) <= min(pit->second, r)) {
                    // overlaps
                    ++removed;
                    it = S.erase(pit);
                }
            }
            // Remove all intervals starting at <= r that overlap
            while (it != S.end() && it->first <= r) {
                // Since set maintains non-overlapping, any with start <= r will overlap (or touch) because
                // previous removals ensure no gaps that would avoid overlap when start <= r.
                ++removed;
                it = S.erase(it);
            }

            S.insert({l, r});
            cout << removed << '\n';
        } else if (op == 'B') {
            cout << (int)S.size() << '\n';
        } else {
            // In case of unexpected format, consume rest of line safely
            string rest;
            getline(cin, rest);
            cout << 0 << '\n';
        }
    }

    return 0;
}

