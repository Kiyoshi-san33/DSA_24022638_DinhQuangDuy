#include <iostream>
using namespace std;

/* Cấu trúc của một nút trong cây nhị phân */
struct Node {
    int data;
    Node* left;
    Node* right;
};

/* Hàm tạo một nút mới */
Node* newNode(int data) {
    Node* node = new Node();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

/* Duyệt cây theo thứ tự Inorder: Trái -> Gốc -> Phải */
void Inorder(struct Node* node) {
    if (node == NULL) return;
    Inorder(node->left);
    cout << node->data << " ";
    Inorder(node->right);
}

/* Duyệt cây theo thứ tự Preorder: Gốc -> Trái -> Phải */
void Preorder(struct Node* node) {
    if (node == NULL) return;
    cout << node->data << " ";
    Preorder(node->left);
    Preorder(node->right);
}

/* Duyệt cây theo thứ tự Postorder: Trái -> Phải -> Gốc */
void Postorder(struct Node* node) {
    if (node == NULL) return;
    Postorder(node->left);
    Postorder(node->right);
    cout << node->data << " ";
}

int main() {
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);

    cout << "Inorder: "<< endl;
    Inorder(root);
    cout << endl;

    cout << "Preorder: "<< endl;
    Preorder(root);
    cout << endl;
    
    cout << "Postorder: "<< endl;
    Postorder(root);
    cout << endl;

    return 0;
}
