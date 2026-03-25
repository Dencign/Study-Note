#include <bits/stdc++.h>
using namespace std;

const int N = 100010;
int n, m;
int arr[N];

struct Node{
    int l, r;
    long long sum;
}tr[4 * N];

//用子节点更新当前结点 pushup()
void pushup(int index) {
    tr[index].sum = tr[index << 1].sum + tr[index << 1 | 1].sum;
}
//在一段区间上初始化线段树 build(当前点，当前区间)
void build(int x, int l, int r) {
    //当前区间压缩成一个点了说明是叶子结点
    if (l == r) tr[x] = {l, r, arr[l]};
    else {
        tr[x].l = l; tr[x].r = r;
        int mid = (l + r) / 2;
        build(x << 1, l, mid);
        build(x << 1 | 1, mid + 1, r);
        pushup(x);
    }
}
//修改 modify(当前点，修改点，value)
void modify(int x, int w, int v) {
    if (tr[x].l == tr[x].r) tr[x].sum += v;
    else {
        int mid = (tr[x].l + tr[x].r) / 2;
        if (w <= mid) modify(x << 1, w, v);
        else modify(x << 1 | 1, w, v);
        pushup(x);
    }
}
//查询 query(当前点，查询区间) 
long long query(int x, int l, int r) {
    if (tr[x].l >= l && tr[x].r <= r) return tr[x].sum;
    int mid = (tr[x].l + tr[x].r) / 2;
    long long sum = 0;
    //如果 l <= mid，说明查询区间与左子区间（[tr[x].l, mid]）有重叠，因此需要递归左子树
        if (l <= mid) sum += query(x << 1, l, r);
        //如果 r > mid，说明查询区间与右子区间（[mid+1, tr[x].r]）有重叠，因此需要递归右子树
        if (r > mid) sum += query(x << 1 | 1, l, r);
    return sum;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    build(1, 1, n);

    while (m--) {
        int k, a, b;
        cin >> k >> a >> b;
        if (k == 0) {
            cout << query(1, a, b) << '\n';
        }else {
            modify(1,a, b);
        }
    }

}