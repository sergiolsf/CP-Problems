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

void solve() {
    int n;
    cin >> n;
    vi a(n+1);
    for (int i = 1; i <= n; i++) cin >> a[i];


    int l, r;
    int maior = -1;
    for (int i = 1; i <= n; i++) {
        int maxSum = -1;
        int sum = 0;
        int ind;
        for (int j = i; j <= n; j++) {
            if (a[j] < a[i]) sum++;
            else if (a[j] > a[i]) sum--;
            if (maxSum < sum) {
                maxSum = sum;
                ind = j;
            }
        }
        if (maxSum > maior) {
            l = i;
            r = ind;
            maior = maxSum;
        }
    }

    cout << l << " " << r << endl;
}

signed main() {
    fastio();
    int t;
    cin >> t;
    while(t--) {
        solve();
    }    
    return 0;
}