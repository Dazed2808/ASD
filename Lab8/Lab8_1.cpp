#include <iostream>
#include <fstream>

using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;
};

Node* createNode(char data) {
    Node* node = new Node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node* insert(Node* root, char data) {
    if (root == NULL) {
        root = createNode(data);
    } else if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

void search(Node* root, string path) {
    if (root == NULL) {
        return;
    }
    if (isdigit(root->data)) {
        cout << "Symbol of number " << root->data << " found at address " << path << endl;
    }
    search(root->left, path + "0");
    search(root->right, path + "1");
}

int main() {
    Node* root = NULL;
    ifstream file("input.txt");
    char c;
    while (file >> c) {
        root = insert(root, c);
    }
    file.close();
    if (root == NULL) {
        cout << "No characters found in file." << endl;
    } else {
        search(root, "");
    }
    return 0;
}
