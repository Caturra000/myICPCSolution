#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
struct Node {
    int r, l;
    Node *rc, *lc;
    long long key, inc;
};
Node *buildtree(int left, Node * root, int right) {
    root->l = left, root->r = right, root->key = 0, root->inc = 0;
    register int temp = left + right >> 1;
    if (left == right) {
        root->lc = NULL;
        root->rc = NULL;
        return root;
    }
    Node *newleft;
    newleft = new Node, root->lc = newleft, buildtree(left, root->lc, temp);
    Node *newright;
    newright = new Node, root->rc = newright, buildtree(temp + 1, root->rc, right);
    return root;
}
inline void insert(int point, Node * root1, int real) {
    int temp1 = (root1->l + root1->r) / 2;
    if (point == root1->l && point == root1->r) {
        root1->key += real;
        return ;
    }
    root1->key += real;
    if (point >= root1->l && point <= temp1) insert(point, root1->lc, real);
    else insert(point, root1->rc, real);
}
inline void addsum(int left2, int right2, int add, Node * root2) {
    if (root2->l == left2 && root2->r == right2) {
        root2->inc += add;
        return ;
    }
    root2->key += add * (right2 - left2 + 1);
    if (right2 <= (root2->l + root2->r) / 2) {
        addsum(left2, right2, add, root2->lc);
    }
    else if (left2 >= (root2->l + root2->r) / 2 + 1) {
        addsum(left2, right2, add, root2->rc);
    }
    else {
        addsum(left2, (root2->l + root2->r) / 2, add, root2->lc);
        addsum((root2->l + root2->r) / 2 + 1, right2, add, root2->rc);
    }
}
long long query(int left1, int right1, Node *root3) {
    if (left1 == root3->l && right1 == root3->r) return (root3->key) + (root3->inc * (right1 - left1 + 1));
    root3->key += root3->inc * (root3->r - root3->l + 1);
    int temp2 = (root3->l + root3->r) / 2;
    addsum(root3->l, temp2, root3->inc, root3->lc);
    addsum(temp2 + 1, root3->r, root3->inc, root3->rc);
    root3->inc = 0;
    if (left1 >= root3->l && right1 <= temp2) return query(left1, right1, root3->lc);
    else if (left1 >= temp2 + 1 && right1 <= root3->r) return query(left1, right1, root3->rc);
    else return query(left1, (root3->l + root3->r) / 2, root3->lc) + query((root3->l + root3->r) / 2 + 1, right1, root3->rc);
}
int main() {
    int n1, n2;
    while (scanf("%d%d", &n1, &n2) != EOF) {
        Node * newtree;
        newtree = new Node;
        buildtree(1, newtree, n1);
        for (int g = 1; g <= n1; g++) {
            int tep3;
            scanf("%d", &tep3);
            insert(g, newtree, tep3);
        }
        for (int i = 1; i <= n2; i++) {
            char temp4;
            getchar();
            scanf("%c", &temp4);
            if (temp4 == 'C') {
                int temp5, temp6;
                int temp7;
                scanf("%d%d%d", &temp5, &temp6, &temp7);
                addsum(temp5, temp6, temp7, newtree);
            } else if (temp4 == 'Q') {
                int tep1, tep2;
                scanf("%d%d", &tep1, &tep2);
                long long tep5 = query(tep1, tep2, newtree);
                printf("%I64d\n", tep5);
            }
        }
    }
    return 0;
}