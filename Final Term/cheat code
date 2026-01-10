#include <bits/stdc++.h>
using namespace std;

struct Node {
    int rating;
    string name;
    long long hp;
    Node *left, *right;
    int sz;

    Node(int r, string n, long long h)
        : rating(r), name(n), hp(h), left(nullptr), right(nullptr), sz(1) {}
};

int size(Node* t) { return t ? t->sz : 0; }

struct BST {
    Node* root = nullptr;

    /* -------- Utility -------- */
    void update(Node* t) {
        if (t) t->sz = 1 + size(t->left) + size(t->right);
    }

    Node* search(Node* t, int x) {
        if (!t || t->rating == x) return t;
        if (x < t->rating) return search(t->left, x);
        return search(t->right, x);
    }

    /* -------- INSERT (JOIN) -------- */
    Node* insert(Node* t, int r, string n, long long h, bool &ok) {
        if (!t) {
            ok = true;
            return new Node(r, n, h);
        }
        if (r < t->rating)
            t->left = insert(t->left, r, n, h, ok);
        else if (r > t->rating)
            t->right = insert(t->right, r, n, h, ok);
        else {
            ok = false;
            return t;
        }
        update(t);
        return t;
    }

    void JOIN(int r, string n, long long h) {
        bool ok = false;
        root = insert(root, r, n, h, ok);
        if (ok) cout << "JOINED\n";
        else cout << "DUPLICATE\n";
    }

    /* -------- STATUS -------- */
    void STATUS(int r) {
        Node* t = search(root, r);
        if (!t) cout << "NOT FOUND\n";
        else cout << t->rating << " " << t->name << " " << t->hp << "\n";
    }

    /* -------- DAMAGE / HEAL -------- */
    void DAMAGE(int r, long long x) {
        Node* t = search(root, r);
        if (!t) cout << "NOT FOUND\n";
        else {
            t->hp = max(0LL, t->hp - x);
            cout << "DAMAGED " << t->hp << "\n";
        }
    }

    void HEAL(int r, long long x) {
        Node* t = search(root, r);
        if (!t) cout << "NOT FOUND\n";
        else {
            t->hp += x;
            cout << "HEALED " << t->hp << "\n";
        }
    }

    /* -------- NEXT / PREV -------- */
    Node* successor(Node* t, int x) {
        Node* ans = nullptr;
        while (t) {
            if (t->rating > x) {
                ans = t;
                t = t->left;
            } else t = t->right;
        }
        return ans;
    }

    Node* predecessor(Node* t, int x) {
        Node* ans = nullptr;
        while (t) {
            if (t->rating < x) {
                ans = t;
                t = t->right;
            } else t = t->left;
        }
        return ans;
    }

    void NEXT(int x) {
        Node* t = successor(root, x);
        if (!t) cout << "NOT FOUND\n";
        else cout << t->rating << " " << t->name << " " << t->hp << "\n";
    }

    void PREV(int x) {
        Node* t = predecessor(root, x);
        if (!t) cout << "NOT FOUND\n";
        else cout << t->rating << " " << t->name << " " << t->hp << "\n";
    }

    /* -------- MATCH -------- */
    void MATCH(int x) {
        Node* p = predecessor(root, x);
        Node* s = successor(root, x);

        if (!p && !s) {
            cout << "EMPTY\n";
            return;
        }
        if (!p) {
            cout << s->rating << " " << s->name << " " << s->hp << "\n";
            return;
        }
        if (!s) {
            cout << p->rating << " " << p->name << " " << p->hp << "\n";
            return;
        }

        int d1 = abs(x - p->rating);
        int d2 = abs(s->rating - x);

        if (d1 <= d2) // tie goes to predecessor
            cout << p->rating << " " << p->name << " " << p->hp << "\n";
        else
            cout << s->rating << " " << s->name << " " << s->hp << "\n";
    }

    /* -------- RANGE -------- */
    void rangeDFS(Node* t, int L, int R) {
        if (!t) return;
        if (t->rating > L) rangeDFS(t->left, L, R);
        if (L <= t->rating && t->rating <= R)
            cout << t->rating << " " << t->name << " " << t->hp << "\n";
        if (t->rating < R) rangeDFS(t->right, L, R);
    }

    void RANGE(int L, int R) {
        rangeDFS(root, L, R);
    }

    /* -------- DELETE (LEAVE) -------- */
    Node* minNode(Node* t) {
        while (t && t->left) t = t->left;
        return t;
    }

    Node* erase(Node* t, int x, bool &ok) {
        if (!t) return nullptr;

        if (x < t->rating)
            t->left = erase(t->left, x, ok);
        else if (x > t->rating)
            t->right = erase(t->right, x, ok);
        else {
            ok = true;
            if (!t->left && !t->right) {
                delete t;
                return nullptr;
            }
            if (!t->left) {
                Node* tmp = t->right;
                delete t;
                return tmp;
            }
            if (!t->right) {
                Node* tmp = t->left;
                delete t;
                return tmp;
            }
            Node* s = minNode(t->right);
            t->rating = s->rating;
            t->name = s->name;
            t->hp = s->hp;
            t->right = erase(t->right, s->rating, ok);
        }
        update(t);
        return t;
    }

    void LEAVE(int x) {
        bool ok = false;
        root = erase(root, x, ok);
        if (!ok) cout << "NOT FOUND\n";
        else cout << "LEFT\n";
    }

    /* -------- RANK -------- */
    int rankLess(Node* t, int x) {
        if (!t) return 0;
        if (x <= t->rating)
            return rankLess(t->left, x);
        return size(t->left) + 1 + rankLess(t->right, x);
    }

    void RANK(int x) {
        cout << rankLess(root, x) << "\n";
    }

    /* -------- KTH -------- */
    Node* kth(Node* t, int k) {
        if (!t) return nullptr;
        int L = size(t->left);
        if (k == L + 1) return t;
        if (k <= L) return kth(t->left, k);
        return kth(t->right, k - L - 1);
    }

    void KTH(int k) {
        if (k <= 0 || k > size(root)) {
            cout << "NOT FOUND\n";
            return;
        }
        Node* t = kth(root, k);
        cout << t->rating << " " << t->name << " " << t->hp << "\n";
    }

    /* -------- STATS -------- */
    int height(Node* t) {
        if (!t) return -1;
        return 1 + max(height(t->left), height(t->right));
    }

    int leaves(Node* t) {
        if (!t) return 0;
        if (!t->left && !t->right) return 1;
        return leaves(t->left) + leaves(t->right);
    }

    void STATS() {
        if (!root) {
            cout << "EMPTY\n";
            return;
        }
        Node* mn = minNode(root);
        Node* mx = root;
        while (mx->right) mx = mx->right;

        cout << "HEIGHT " << height(root) << "\n";
        cout << "LEAVES " << leaves(root) << "\n";
        cout << "MIN " << mn->rating << "\n";
        cout << "MAX " << mx->rating << "\n";
    }

    /* -------- DUEL -------- */
    int depth(int x) {
        Node* t = root;
        int d = 0;
        while (t) {
            if (x == t->rating) return d;
            if (x < t->rating) t = t->left;
            else t = t->right;
            d++;
        }
        return -1;
    }

    Node* LCA(Node* t, int a, int b) {
        while (t) {
            if (a < t->rating && b < t->rating) t = t->left;
            else if (a > t->rating && b > t->rating) t = t->right;
            else return t;
        }
        return nullptr;
    }

    void DUEL(int a, int b) {
        if (!search(root, a) || !search(root, b)) {
            cout << "NOT FOUND\n";
            return;
        }
        Node* lca = LCA(root, a, b);
        int d = depth(a) + depth(b) - 2 * depth(lca->rating);
        cout << "DIST " << d << "\n";
    }
};

/* -------- MAIN DRIVER -------- */
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    BST tree;
    int Q;
    cin >> Q;

    while (Q--) {
        string cmd;
        cin >> cmd;

        if (cmd == "JOIN") {
            int r; string n; long long h;
            cin >> r >> n >> h;
            tree.JOIN(r, n, h);
        }
        else if (cmd == "STATUS") {
            int r; cin >> r;
            tree.STATUS(r);
        }
        else if (cmd == "DAMAGE") {
            int r; long long x;
            cin >> r >> x;
            tree.DAMAGE(r, x);
        }
        else if (cmd == "HEAL") {
            int r; long long x;
            cin >> r >> x;
            tree.HEAL(r, x);
        }
        else if (cmd == "NEXT") {
            int x; cin >> x;
            tree.NEXT(x);
        }
        else if (cmd == "PREV") {
            int x; cin >> x;
            tree.PREV(x);
        }
        else if (cmd == "MATCH") {
            int x; cin >> x;
            tree.MATCH(x);
        }
        else if (cmd == "RANGE") {
            int L, R; cin >> L >> R;
            tree.RANGE(L, R);
        }
        else if (cmd == "LEAVE") {
            int x; cin >> x;
            tree.LEAVE(x);
        }
        else if (cmd == "RANK") {
            int x; cin >> x;
            tree.RANK(x);
        }
        else if (cmd == "KTH") {
            int k; cin >> k;
            tree.KTH(k);
        }
        else if (cmd == "STATS") {
            tree.STATS();
        }
        else if (cmd == "DUEL") {
            int a, b; cin >> a >> b;
            tree.DUEL(a, b);
        }
    }
    return 0;
}
