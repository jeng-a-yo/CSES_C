#include <stdio.h>
#include <stdlib.h>

#define MAX_N 200000

typedef struct Node {
    int value;
    int count;
    struct Node *left, *right;
} Node;

Node* insert_node(Node* root, int value) {
    if (root == NULL) {
        Node* new_node = (Node*)malloc(sizeof(Node));
        new_node->value = value;
        new_node->count = 1;
        new_node->left = new_node->right = NULL;
        return new_node;
    }
    
    if (value == root->value) {
        root->count++;
    } else if (value < root->value) {
        root->left = insert_node(root->left, value);
    } else {
        root->right = insert_node(root->right, value);
    }
    
    return root;
}

Node* find_max(Node* root) {
    if (root == NULL || root->right == NULL) return root;
    return find_max(root->right);
}

Node* delete_max(Node* root) {
    if (root == NULL) return NULL;
    if (root->right == NULL) {
        Node* temp = root->left;
        free(root);
        return temp;
    }
    root->right = delete_max(root->right);
    return root;
}

Node* find_floor(Node* root, int value) {
    if (root == NULL) return NULL;
    
    if (root->value == value) {
        return root;
    } else if (root->value > value) {
        return find_floor(root->left, value);
    } else {
        Node* right_floor = find_floor(root->right, value);
        return right_floor ? right_floor : root;
    }
}

Node* delete_node(Node* root, int value) {
    if (root == NULL) return NULL;
    
    if (value < root->value) {
        root->left = delete_node(root->left, value);
    } else if (value > root->value) {
        root->right = delete_node(root->right, value);
    } else {
        if (root->count > 1) {
            root->count--;
        } else {
            if (root->left == NULL) {
                Node* temp = root->right;
                free(root);
                return temp;
            } else if (root->right == NULL) {
                Node* temp = root->left;
                free(root);
                return temp;
            }
            Node* temp = find_max(root->left);
            root->value = temp->value;
            root->count = temp->count;
            temp->count = 1;
            root->left = delete_node(root->left, temp->value);
        }
    }
    return root;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    Node* root = NULL;
    
    for (int i = 0; i < n; i++) {
        int price;
        scanf("%d", &price);
        root = insert_node(root, price);
    }
    
    for (int i = 0; i < m; i++) {
        int max_price;
        scanf("%d", &max_price);
        
        Node* floor = find_floor(root, max_price);
        
        if (floor == NULL) {
            printf("-1\n");
        } else {
            printf("%d\n", floor->value);
            root = delete_node(root, floor->value);
        }
    }
    
    return 0;
}