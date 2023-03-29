#include <stdio.h>

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
        if(root->data == src)
        {
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
	int src;
    struct node *root = newNode(27);
    root->left = newNode(14);
    root->right = newNode(35);
    root->left->left = newNode(10);
    root->left->right = newNode(19);
    root->right->left = newNode(31);
    root->right->right = newNode(42);
    
    int choice;
    printf("Menu:\n");
    printf("1. Preorder Traversal\n");
    printf("2. Inorder Traversal\n");
    printf("3. Postorder Traversal\n");
    printf("4. Search a number\n");
    printf("4. Exit\n");
    do {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\nPreorder Traversal: ");
                preorder(root);
                break;
            case 2:
                printf("\nInorder Traversal: ");
                inorder(root);
                break;
            case 3:
                printf("\nPostorder Traversal: ");
                postorder(root);
                break;
            case 4: 
        
            printf("enter the no to search ");
            scanf("%d", &src);
            found = 0;
            search(root,src);
            if(found == 1){
            	printf("element found");
			}
			else printf("element not found");
			break;
            case 5:
                printf("\nExiting program...\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (choice != 4);
    
    return 0;
}
