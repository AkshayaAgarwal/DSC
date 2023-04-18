#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

int found = 0;

struct node* newNode(int data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}

void insert(struct node *root, int data) {
    if (data < root->data) {
        if (root->left == NULL) {
            root->left = newNode(data);
        }
        else {
            insert(root->left, data);
        }
    }
    else if (data > root->data) {
        if (root->right == NULL) {
            root->right = newNode(data);
        }
        else {
            insert(root->right, data);
        }
    }
}

void preorder(struct node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(struct node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void search(struct node *root, int src) {
    if (root != NULL) {
        search(root->left,src);
        if(root->data == src) {
        	found = 1;
		}
        search(root->right,src);
    }
}

void postorder(struct node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    int choice, data, src;
    struct node *root = NULL;
     while (1) { 
    printf("\nMenu:\n");
    printf("1. Insert node\n");
    printf("2. Preorder Traversal\n");
    printf("3. Inorder Traversal\n");
    printf("4. Postorder Traversal\n");
    printf("5. Search a number\n");
    printf("6. Exit\n");
    
    
      if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }
        
        switch (choice) {
            case 1:
                printf("\nEnter the data to insert: ");
                scanf("%d", &data);
                if (root == NULL) {
                    root = newNode(data);
                }
                else {
                    insert(root, data);
                }
                break;
                
            case 2:
                printf("\nPreorder Traversal: ");
                preorder(root);
                break;
                
            case 3:
                printf("\nInorder Traversal: ");
                inorder(root);
                break;
                
            case 4:
                printf("\nPostorder Traversal: ");
                postorder(root);
                break;
                
            case 5: 
                printf("\nEnter the number to search: ");
                scanf("%d", &src);
                found = 0;
                search(root,src);
                if(found == 1) {
                	printf("Element found");
				}
				else {
					printf("Element not found");
				}
				break;
                
            case 6:
               exit(0);
                break;
                
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (choice != 6);
    
    return 0;
}

