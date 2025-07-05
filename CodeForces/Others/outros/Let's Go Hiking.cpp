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
    int n; cin >> n;
    vi p(n+2, 0);
    for (int i = 1; i <= n; i++) cin >> p[i];
    
    vi crescEsq(n+1, 0);
    for (int i = 1; i <= n; i++) {
        if (p[i-1] < p[i]) crescEsq[i] = crescEsq[i-1]+1;
        else crescEsq[i] = 1;
    }

    vi crescDir(n+2, 0);
    for (int i = n; i >= 1; i--) {
        if (p[i+1] < p[i]) crescDir[i] = crescDir[i+1]+1;
        else crescDir[i] = 1;
    }

    ///
    vi decrescEsq(n+1, 0);
    for (int i = 1; i <= n; i++) {
        if (p[i-1] > p[i]) decrescEsq[i] = decrescEsq[i-1]+1;
        else decrescEsq[i] = 1;
    }

    vi decrescDir(n+2, 0);
    for (int i = n; i >= 1; i--) {
        if (p[i+1] > p[i]) decrescDir[i] = decrescDir[i+1]+1;
        else decrescDir[i] = 1;
    }

    vi maxDecresEsq(n+1, 0);
    vi maxDecresDirEsq(n+1, 0);
    vi maxDecresDir(n+2, 0);
    vi maxDecresEsqDir(n+2, 0);

    for (int i = 1; i <= n; i++) {
        maxDecresEsq[i] = max(maxDecresEsq[i-1], decrescEsq[i]);
        //cout << maxDecresEsq[i] << " ";
    }

    for (int i = n; i >= 1; i--) {
        maxDecresDir[i] = max(maxDecresDir[i+1], decrescDir[i]);
        //cout << maxDecresDir[i] << " ";
    }

    for (int i = 1; i <= n; i++) {
        maxDecresDirEsq[i] = max(maxDecresDir[i-1], decrescDir[i]);
        // << maxDecresDirEsq[i] << " ";
    }

    for (int i = n; i >= 1; i--) {
        maxDecresEsqDir[i] = max(maxDecresEsq[i+1], decrescEsq[i]);
        //cout << maxDecresEsqDir[i] << " ";
    }

    // criar maxDecrescDirEsq
    // criar maxDecrescEsqDir

    ///

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (i != 3) continue;

        if (i == 1 || i == n) continue;
        if (!(p[i-1] < p[i] && p[i] > p[i+1])) continue;
        int num1 = crescEsq[i]-1, num2 = crescDir[i]-1;
        if (num1&1 && num2&1) continue;


        int x = 0;
        if (num1&1) {
            if (num1+1 >= num2) continue;
            
            if (num1 > 1) x = maxDecresEsq[i-num1];
            x = max(x, maxDecresEsq[i-num1-1]);
            x = max(x, maxDecresDir[i+num2]);
            x = max(x, maxDecresDirEsq[i-num1-1]);
            x = max(x, maxDecresEsqDir[i+num2+1]);

            if (x > num2) continue;
            ans++;
        } else if (num2&1) {
            if (num2+1 >= num1) continue;

            if (num2 > 1) x = maxDecresDir[i+num2];
            x = max(x, maxDecresDir[i+num2+1]);
            x = max(x, maxDecresEsq[i-num1]);
            x = max(x, maxDecresEsqDir[i+num2+1]);
            x = max(x, maxDecresDirEsq[i-num1-1]);
            if (x > num1) continue;

            ans++;
        } else {
            x = max(x, maxDecresDir[i-num1]);
            x = max(x, maxDecresEsq[i+num2]);
            x = max(x, maxDecresDirEsq[i+num2+1]);
            x = max(x, maxDecresEsqDir[i-num1-1]);
            if (x > max(num1, num2)) continue;
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}