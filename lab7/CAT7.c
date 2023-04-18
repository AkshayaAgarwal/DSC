#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

// Structure to represent a Node in a binary search tree
typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new Node with the given value
Node* create_node(int value) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Function to insert a new Node with the given value into the binary search tree
void insert_node(Node** root, int value) {
    if (*root == NULL) {
        *root = create_node(value);
    } else if (value < (*root)->value) {
        insert_node(&((*root)->left), value);
    } else if (value > (*root)->value) {
        insert_node(&((*root)->right), value);
    }
}

// Function to perform preorder traversal of the binary search tree
void preorder_traversal(Node* root) {
    if (root != NULL) {
        printf("%d ", root->value);
        preorder_traversal(root->left);
        preorder_traversal(root->right);
    }
}

// Function to perform inorder traversal of the binary search tree
void inorder_traversal(Node* root) {
    if (root != NULL) {
        inorder_traversal(root->left);
        printf("%d ", root->value);
        inorder_traversal(root->right);
    }
}

// Function to perform postorder traversal of the binary search tree
void postorder_traversal(Node* root) {
    if (root != NULL) {
        postorder_traversal(root->left);
        postorder_traversal(root->right);
        printf("%d ", root->value);
    }
}

// Function to search for a Node with the given value in the binary search tree
Node* search_node(Node* root, int value) {
    if (root == NULL || root->value == value) {
        return root;
    } else if (value < root->value) {
        return search_node(root->left, value);
    } else {
        return search_node(root->right, value);
    }
}

// Function to print the binary search tree structure in a visually appealing way
void print_tree(Node* root, int level) {
    if (root == NULL) {
        return;
    }
    int i;
    print_tree(root->right, level + 1);
    for ( i = 0; i < level; i++) {
        printf("   ");
    }
    printf("%d\n", root->value);
    print_tree(root->left, level + 1);
}

int main() {
    Node* root = NULL;
    int num_nodes, value, search_value, option;

    printf("Enter the number of nodes in the binary search tree: ");
    scanf("%d", &num_nodes);
    if (num_nodes < 1 || num_nodes > MAX_NODES) {
        printf("Invalid number of nodes\n");
        return 1;
    }
int i;
    printf("Enter the values for the binary search tree:\n");
    for ( i = 0; i < num_nodes; i++) {
        printf("Value %d: ", i + 1);
        scanf("%d", &value);
        insert_node(&root, value);
    }

    do {
        printf("\nMenu:\n");
           printf("1. Preorder Traversal\n");
    printf("2. Inorder Traversal\n");
    printf("3. Postorder Traversal\n");
    printf("4. Search for a Node\n");
    printf("5. Exit\n");
    printf("Enter your option: ");
    scanf("%d", &option);

    switch (option) {
        case 1:
            printf("\nPreorder Traversal:\n");
            preorder_traversal(root);
            printf("\nTree structure:\n");
            print_tree(root, 0);
            break;
        case 2:
            printf("\nInorder Traversal:\n");
            inorder_traversal(root);
            printf("\nTree structure:\n");
            print_tree(root, 0);
            break;
        case 3:
            printf("\nPostorder Traversal:\n");
            postorder_traversal(root);
            printf("\nTree structure:\n");
            print_tree(root, 0);
            break;
        case 4:
            printf("\nEnter the value to search for: ");
            scanf("%d", &search_value);
            Node* found_node = search_node(root, search_value);
            if (found_node == NULL) {
                printf("Node not found\n");
            } else {
                printf("Node found: %d\n", found_node->value);
            }
            break;
        case 5:
            printf("\nExiting...\n");
            break;
        default:
            printf("\nInvalid option\n");
            break;
    }
} while (option != 5);

return 0;
}
