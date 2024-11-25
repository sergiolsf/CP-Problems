#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int N, sum;
vi dad(6000,-1);
vector<bool> S(6000, false);
vi a;


signed main() {
    fastio();
    cin >> N;
    a.resize(N+1);
    
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
        sum += a[i];
    }  

    S[0] = true;

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= 5500; j++) {
            if (S[j] && dad[j] != i) {
                if (!S[j + a[i]]) {
                    S[j + a[i]] = true;
                    dad[j + a[i]] = i;
                } 
            }
        }
    }

    if (!S[sum/2] || sum&1) {
        cout << -1 << endl;
        return 0;
    }

    set<int> A;
    int p = sum/2;
    while (p > 0) {
        A.insert(dad[p]);
        p -= a[dad[p]];
    }

    vi groupA,groupB;

    for (int i = 1; i <= N; i++) {
        if (A.count(i)) {
            groupA.push_back(a[i]);
        } else {
            groupB.push_back(a[i]);
        }
    }

    int Sa = 0, Sb = 0;
    int j = 0, k = 0;
    for (int i = 1; i <= N; i++) {
        if (i > 1) cout << " ";
        if (Sa <= Sb) {
            cout << groupA[j];
            Sa += groupA[j];
            j++;
        } else {
            cout << groupB[k];
            Sb += groupB[k];
            k++;
        }
    }

    cout << endl;

    return 0;
}