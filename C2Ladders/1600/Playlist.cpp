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
    int n, k;
    cin >> n >> k;
    vector<pii> music;

    for (int i = 0; i < n; i++) {
        int t, b;
        cin >> t >> b;
        music.pb({b,t});
    }

    sort(music.rbegin(), music.rend());

    int sum = 0, maxSum = 0, quant = 0;
    priority_queue<int, vi, greater<int>> pq;

    for (int i = 0; i < n; i++) {
        int t = music[i].second, b = music[i].first;
        if (quant < k) {
            sum += t;
            quant++;
            pq.push(t);
            maxSum = max(maxSum, b*sum);
        } else {
            int u = pq.top();
            if (u < t) {
                sum -= u;
                sum += t;
                pq.pop();
                pq.push(t);
                maxSum = max(maxSum, b*sum);
            }
        }
    }

    cout << maxSum << endl;


  
    return 0;
}