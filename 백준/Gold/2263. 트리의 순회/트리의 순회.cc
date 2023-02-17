#include <bits/stdc++.h>
using namespace std;

typedef struct _NODE {
    int key;
    struct _NODE *left, *right;
} NODE;

NODE *insert(int num) {
    NODE *node = (NODE*)malloc(sizeof(NODE));
    node->key = num;
    node->left = node->right = NULL;
    return node;
}

void printNode(NODE *root) {
    if(root == NULL)
        return;

    cout << root->key << ' ';
    printNode(root->left);
    printNode(root->right);
}

NODE *di(vector<int>::iterator inorderbegin, vector<int>::iterator inorderend, vector<int>::iterator postorderbegin, vector<int>::iterator postorderend, NODE *node) {
    int key = *(postorderend-1);
    int index = find(inorderbegin, inorderend, key) - inorderbegin;
    node = insert(key);

    if(index != 0) {
        node->left  = di(inorderbegin, inorderbegin+index, postorderbegin, postorderbegin+index, node->left);
    }
    if(inorderbegin+index+1-inorderend != 0) {
        node->right = di(inorderbegin+index+1, inorderend, postorderbegin+index, postorderend-1, node->right);
    }

    return node;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    //freopen("input.txt", "r", stdin);

    int n;
    cin >> n;
    vector<int> inorder, postorder;
    inorder.resize(n), postorder.resize(n);

    for(int i=0; i<n; i++)
        cin >> inorder[i];
    for(int i=0; i<n; i++)
        cin >> postorder[i];

    NODE *root = NULL;
    root = di(inorder.begin(), inorder.end(), postorder.begin(), postorder.end(), root);

    printNode(root);

    return 0;
}
