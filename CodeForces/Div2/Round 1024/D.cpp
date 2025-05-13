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

// Função auxiliar para mesclar e contar inversões
long long mergeAndCount(vector<int>& arr, vector<int>& temp, int start, int mid, int end) {
    int i = start;      // Índice para a subarray esquerda
    int j = mid + 1;    // Índice para a subarray direita
    int k = start;      // Índice para o array temporário
    long long inv_count = 0;

    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            // Todos elementos restantes na esquerda formam inversões
            inv_count += (mid - i + 1);
        }
    }

    // Copiar elementos restantes da esquerda
    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    // Copiar elementos restantes da direita
    while (j <= end) {
        temp[k++] = arr[j++];
    }

    // Copiar de volta para o array original
    for (i = start; i <= end; i++) {
        arr[i] = temp[i];
    }

    return inv_count;
}

// Função recursiva de Merge Sort modificada
long long mergeSortAndCount(vector<int>& arr, vector<int>& temp, int start, int end) {
    if (start >= end) return 0; // Caso base

    int mid = start + (end - start) / 2;
    long long inv_count = 0;

    // Contar inversões nas metades esquerda e direita
    inv_count += mergeSortAndCount(arr, temp, start, mid);
    inv_count += mergeSortAndCount(arr, temp, mid + 1, end);

    // Contar inversões durante a mesclagem
    inv_count += mergeAndCount(arr, temp, start, mid, end);

    return inv_count;
}

// Função principal para contar inversões
long long countInversions(vector<int> arr) {
    vector<int> temp(arr.size());
    return mergeSortAndCount(arr, temp, 0, arr.size() - 1);
}

void solve() {
    int n; cin >> n;
    vector<pii> vp;
    vi arr;
    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        vp.push_back({a, i});
        arr.push_back(a);
    }

    int p = countInversions(arr)%2;

    sort(all(vp));
    int par = 2, impar = 1;
    vi ans(n+1);

    for (auto e: vp) {
        int f = e.first;
        int s = e.second;
        if (s%2 == 1) {
            ans[impar] = f;
            impar += 2;
        } else {
            ans[par] = f;
            par += 2;
        }
    }

    for (int i = 1; i <= n-4; i++) {
        cout << ans[i] << " ";
        
    }


    vi ar;
    for (int i = 1; i <= n; i++) {
        ar.push_back(ans[i]);
    }

    int p1 = countInversions(ar)%2;


    int paridade;
    vi v1(4), v2(4);
    v1[0] = ans[n-3], v1[1] = ans[n-2], v1[2] = ans[n-1], v1[3] = ans[n];
    v2[0] = ans[n-1], v2[1] = ans[n], v2[2] = ans[n-3], v2[3] = ans[n-2];

    if (p1 == p) {
        for (int i = 0; i <= 3; i++) {
            cout << v1[i] << (i == 3 ? "\n" : " ");
        }
    } else {
        for (int i = 0; i <= 3; i++) {
            cout << v2[i] << (i == 3 ? "\n" : " ");
        }
    }

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