#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define pb push_back
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

signed main() {
    fastio();
    int n, k; cin >> n >> k;

    int A[2*n];
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        A[i] = a-k*i;
		A[i+n] = a-k*(i+n);
    }
    int ans[2*n];

    stack<pii> st;
    st.push({A[0], 0});
    
    for (int i = 1; i < 2*n; i++) {
        int a = A[i];
        while (!st.empty() && st.top().first > a) {
            ans[st.top().second] = i;
            st.pop();
        }
        st.push({a, i});
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i]%n + 1 << (i == n-1 ? "\n" : " ");
    }
    
    return 0;
}