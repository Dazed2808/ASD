#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data) {
    Node* node = new Node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node* insert(Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
    } else if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

int height(Node* root) {
    if (root == NULL) {
        return 0;
    } else {
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        return max(leftHeight, rightHeight) + 1;
    }
}

int countNodes(Node* root) {
    if (root == NULL) {
        return 0;
    } else {
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
}

int countEqualHeights(Node* root, int targetHeight) {
    if (root == NULL) {
        return 0;
    } else {
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        int currentHeight = max(leftHeight, rightHeight) + 1;
        if (currentHeight == targetHeight) {
            return countEqualHeights(root->left, targetHeight) + countEqualHeights(root->right, targetHeight) + 1;
        } else {
            return countEqualHeights(root->left, targetHeight) + countEqualHeights(root->right, targetHeight);
        }
    }
}

int countDescendants(Node* root, char direction) {
    if (root == NULL) {
        return 0;
    } else {
        if (direction == 'R') {
            return countNodes(root->right);
        } else if (direction == 'L') {
            return countNodes(root->left);
        } else {
            return 0;
        }
    }
}

int main() {
    Node* root = NULL;
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 2);
    root = insert(root, 7);
    root = insert(root, 12);
    root = insert(root, 20);
    root = insert(root, 1);
    root = insert(root, 3);
    root = insert(root, 6);
    root = insert(root, 8);
    root = insert(root, 11);
    root = insert(root, 13);
    root = insert(root, 17);
    root = insert(root, 25);

    int treeHeight = height(root);
    int equalHeightCount = countEqualHeights(root, treeHeight);
    int leftDescendantCount = countDescendants(root, 'L');
    int rightDescendantCount = countDescendants(root, 'R');

    cout << "Number of vertices with equal or tree heights: " << equalHeightCount << endl;
    cout << "Number of descendants in the left subtree: " << leftDescendantCount << endl;
    cout << "Number of descendants in the right subtree: " << rightDescendantCount << endl;
    return 0;
}
