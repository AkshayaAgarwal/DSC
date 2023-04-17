#include <stdio.h>
#include <stdlib.h>

// structure of a node in the binary search tree
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// function prototypes
struct node *create_node(int value);
struct node *insert(struct node *root, int value);
struct node *delete(struct node *root, int value);
struct node *min_value_node(struct node *node);
void inorder_traversal(struct node *root);
void preorder_traversal(struct node *root);
void postorder_traversal(struct node *root);

int main() {
    struct node *root = NULL;
    int choice, value;

    do {
        // print menu
        printf("\nBinary Search Tree Menu\n");
        printf("-----------------------\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Inorder traversal\n");
        printf("5. Preorder traversal\n");
        printf("6. Postorder traversal\n");
        printf("7. Exit\n");

        // get user choice
         // get user choice
        printf("\nEnter your choice (1-7): ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                // insert node
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 2:
                // delete node
                printf("Enter the value to delete: ");
                scanf("%d", &value);
                root = delete(root, value);
                break;
            case 3:
                // search for node
                printf("Enter the value to search for: ");
                scanf("%d", &value);
                if (search(root, value)) {
                    printf("Value %d was found in the tree.\n", value);
                } else {
                    printf("Value %d was not found in the tree.\n", value);
                }
                break;
            case 4:
                // inorder traversal
                printf("Inorder traversal: ");
                inorder_traversal(root);
                printf("\n");
                break;
            case 5:
                // preorder traversal
                printf("Preorder traversal: ");
                preorder_traversal(root);
                printf("\n");
                break;
            case 6:
                // postorder traversal
                printf("Postorder traversal: ");
                postorder_traversal(root);
                printf("\n");
                break;
            case 7:
                // exit program
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please enter a value between 1 and 7.\n");
                break;
        }
    } while (choice != 7);

    return 0;
}

// create a new node with the given value
struct node *create_node(int value) {
    struct node *new_node = (struct node *) malloc(sizeof(struct node));
    new_node->data = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// insert a new node with the given value into the tree
struct node *insert(struct node *root, int value) {
    if (root == NULL) {
        return create_node(value);
    } else if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

// search for a node with the given value
// in the tree
int search(struct node *root, int value) {
if (root == NULL) {
return 0;
} else if (value == root->data) {
return 1;
} else if (value < root->data) {
return search(root->left, value);
} else {
return search(root->right, value);
}
}

// delete a node with the given value from the tree
struct node *delete(struct node *root, int value) {
if (root == NULL) {
return NULL;
} else if (value < root->data) {
root->left = delete(root->left, value);
} else if (value > root->data) {
root->right = delete(root->right, value);
} else {
// node with value found
if (root->left == NULL) {
// node has no left child
struct node *temp = root->right;
free(root);
return temp;
} else if (root->right == NULL) {
// node has no right child
struct node *temp = root->left;
free(root);
return temp;
} else {
// node has two children
struct node *temp = min_value_node(root->right);
root->data = temp->data;
root->right = delete(root->right, temp->data);
}
}
return root;
}

// find the node with the minimum value in the tree
struct node *min_value_node(struct node *node) {
struct node *current = node;
while (current->left != NULL) {
current = current->left;
}
return current;
}

// perform an inorder traversal of the tree
void inorder_traversal(struct node *root) {
if (root != NULL) {
inorder_traversal(root->left);
printf("%d ", root->data);
inorder_traversal(root->right);
}
}

// perform a preorder traversal of the tree
void preorder_traversal(struct node *root) {
if (root != NULL) {
printf("%d ", root->data);
preorder_traversal(root->left);
preorder_traversal(root->right);
}
}

// perform a postorder traversal of the tree
void postorder_traversal(struct node *root) {
if (root != NULL) {
postorder_traversal(root->left);
postorder_traversal(root->right);
printf("%d ", root->data);
}
}
