//노정훈 고컴 과탑먹자 ^!^ 

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <utility>
#include <queue>
#include <stack>
#include <algorithm>
#include <string.h>
#include <cmath>
using namespace std;

typedef long long ll;

#define MAXN 66666

void update(vector<int>& tree, int node, int start, int end, int index, int val) {
    if (index <start || index> end) return;
    if (start == end) {
        tree[node] += val; return;
    }
    update(tree, node * 2, start, (start + end) / 2, index, val);
    update(tree, node * 2 + 1, (start + end) / 2 + 1, end, index, val);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int kth(vector<int>& tree, int node, int start, int end, int k) {
    if (start == end) return start;
    else {
        if (k <= tree[node * 2]) return kth(tree, node * 2, start, (start + end) / 2, k);
        else return kth(tree, node * 2 + 1, (start + end) / 2 + 1, end, k - tree[node * 2]);
    }
}
int main() {
    int n, k; scanf(" %d %d", &n, &k);
    int h = (int)ceil(log2(MAXN + 1));
    int tree_size = (1 << (h + 1));
    int cnt = (k + 1) / 2;
    vector<int> tree(tree_size, 0);
    vector<int> a(n + 1, 0);
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        scanf(" %d", &a[i]);
        update(tree, 1, 0, MAXN, a[i], 1);
        if (i >= k) {
            if (i != k) update(tree, 1, 0, MAXN, a[i - k], -1);
            int pos = kth(tree, 1, 0, MAXN, cnt);
            ans += (ll)pos;
        }
    }
    printf("%lld\n", ans);
}
