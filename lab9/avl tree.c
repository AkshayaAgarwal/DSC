
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct node {
    int key;
    int height;
    struct node * left;
    struct node * right;
}
node;

node * create_node(int key) {
    node * new_node = (node * ) malloc(sizeof(node));
    new_node -> key = key;
    new_node -> height = 1;
    new_node -> left = NULL;
    new_node -> right = NULL;
    return new_node;
}

int get_height(node * n) {
    if (n == NULL)
        return 0;
    return n -> height;
}

int get_balance(node * n) {
    if (n == NULL)
        return 0;
    return get_height(n -> left) - get_height(n -> right);
}

node * right_rotate(node * y) {
    node * x = y -> left;
    node * t2 = x -> right;
    x -> right = y;
    y -> left = t2;
    y -> height = 1 + (get_height(y -> left) > get_height(y -> right) ? get_height(y -> left) : get_height(y -> right));
    x -> height = 1 + (get_height(x -> left) > get_height(x -> right) ? get_height(x -> left) : get_height(x -> right));
    return x;
}

node * left_rotate(node * x) {
    node * y = x -> right;
    node * t2 = y -> left;
    y -> left = x;
    x -> right = t2;
    x -> height = 1 + (get_height(x -> left) > get_height(x -> right) ? get_height(x -> left) : get_height(x -> right));
    y -> height = 1 + (get_height(y -> left) > get_height(y -> right) ? get_height(y -> left) : get_height(y -> right));
    return y;
}

node * insert(node * root, int key) {
    if (root == NULL)
        return create_node(key);
    if (key < root -> key)
        root -> left = insert(root -> left, key);
    else if (key > root -> key)
        root -> right = insert(root -> right, key);
    else
        return root;
    root -> height = 1 + (get_height(root -> left) > get_height(root -> right) ? get_height(root -> left) : get_height(root -> right));
    int balance = get_balance(root);
    if (balance > 1 && key < root -> left -> key)
        return right_rotate(root);
    if (balance < -1 && key > root -> right -> key)
        return left_rotate(root);
    if (balance > 1 && key > root -> left -> key) {
        root -> left = left_rotate(root -> left);
        return right_rotate(root);
    }
    if (balance < -1 && key < root -> right -> key) {
        root -> right = right_rotate(root -> right);
        return left_rotate(root);
    }
    return root;
}

void print_preorder(node * root) {
    if (root != NULL) {
        printf("%d ", root -> key);
        print_preorder(root -> left);
        print_preorder(root -> right);
    }
}

void delete_tree(node * root) {
    if (root != NULL) {
        delete_tree(root -> left);
        delete_tree(root -> right);
        free(root);
    }
}

int main() {
    node * root = NULL;
    int choice, key;
    do {
        printf("\nAVL Tree Menu\n__________________________________________________________\n");
        printf("1. Insert Node\n");
        printf("2. Print Pre-order\n");
        printf("3. Delete Tree\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", & choice);
        switch (choice) {
        case 1:
            printf("Enter key to insert: ");
            while (scanf("%d", & key) != 1) {
                printf("Invalid input. Enter a numeric value: ");
                while (getchar() != '\n');
            }
            root = insert(root, key);
            printf("Node inserted successfully.\n");
            break;

        case 2:
            printf("Pre-order traversal: ");
            print_preorder(root);
            printf("\n");
            break;

        case 3:
            delete_tree(root);
            root = NULL;
            printf("Tree deleted successfully.\n");
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Try again.\n");
            break;
        }
    } while (choice != 6);
    return 0;
}

