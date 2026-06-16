#include "RedBlackTree.h"
#include <iostream>
#include <vector>
using namespace std;

void preorder (const RedBlackTree::Node* node, const RedBlackTree::Node* nil, vector<int>& hasil) {
    if (node->isNil) return;
    hasil.push_back(node->key);
    preorder(node->left, nil, hasil);
    preorder(node->right, nil, hasil);
}

void inorder (const RedBlackTree::Node* node, const RedBlackTree::Node* nil, vector<int>& hasil) {
    if (node->isNil) return;
    inorder(node->left, nil, hasil);
    hasil.push_back(node->key);
    inorder(node->right, nil, hasil);
}

void postorder(const RedBlackTree::Node* node, const RedBlackTree::Node* nil, vector<int>& hasil) {
    if (node->isNil) return;
    postorder(node->left, nil, hasil);
    postorder(node->right, nil, hasil);
    hasil.push_back(node->key);
}

void print(string label, vector<int>& hasil) {
    cout << label << " : ";
    for (int i=0; i< hasil.size(); i++) {
        if (i > 0) cout << " ";
        cout << hasil[i];
    }
    cout << endl;
}

int main() {
    RedBlackTree rbt;

    int N;
    cin >> N;

    for (int i=0; i<N; i++) {
        int num;
        cin >> num;
        if (!rbt.contains(num)) {
            rbt.insert(num);
        }
    }

    int Q;
    cin >> Q;

    for (int i=0; i<Q; i++) {
        string query;
        cin >> query;

        if (rbt.empty()) {
            cout << "Tree kosong. Tidak ada yang bisa ditampilkan.\n";
            continue;
        }

        vector<int> pre, in, post;
        preorder(rbt.root(), rbt.nil(), pre);
        inorder(rbt.root(), rbt.nil(), in);
        postorder(rbt.root(), rbt.nil(), post);

        if (query == "PREORDER") {
            print("[Preorder] ", pre);
        } else if (query == "INORDER") {
            print("[Inorder] ", in);
        } else if (query == "POSTORDER") {
            print("[Postorder] ", post);
        } else if (query == "ALL") {
            print("[Preorder] ", pre);
            print("[Inorder] ", in);
            print("[Postorder] ", post);
        }
    }
}