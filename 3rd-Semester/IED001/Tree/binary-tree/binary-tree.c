#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} Node;

void addNode(Node **node, int value)
{
    if (*node == NULL)
    {
        *node = (Node *)malloc(sizeof(Node));
        (*node)->val = value;
        (*node)->left = NULL;
        (*node)->right = NULL;
    }
    else if (value < (*node)->val)
    {
        addNode(&((*node)->left), value);
    }
    else
    {
        addNode(&((*node)->right), value);
    }
}

// In the preorder traversal,
// we visit the root node first, 
// then the left subtree,
// and finally the right subtree.
void preorderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->val);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// In the inorder traversal,
// we visit the left subtree first,
// then the root node,
// and finally the right subtree.
void inorderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorderTraversal(root->left);
    printf("%d ", root->val);
    inorderTraversal(root->right);
}

// In the postorder traversal,
// we visit the left subtree first,
// then the right subtree,
// and finally the root node.
void postorderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->val);
}

int main()
{
    Node *bst = NULL;

    addNode(&bst, 5);
    addNode(&bst, 3);
    addNode(&bst, 7);
    addNode(&bst, 2);
    addNode(&bst, 4);

    printf("Preorder traversal: ");
    preorderTraversal(bst);
    printf("\n=================================\n");

    printf("Inorder traversal: ");
    inorderTraversal(bst);
    printf("\n=================================\n");

    printf("Postorder traversal: ");
    postorderTraversal(bst);
    printf("\n");

    Node *tree = NULL;

    addNodeWithoutOrder(&tree, 5);
    addNodeWithoutOrder(&tree, 3);
    addNodeWithoutOrder(&tree, 7);
    addNodeWithoutOrder(&tree, 2);
    addNodeWithoutOrder(&tree, 4);

    printf("Preorder traversal: ");
    preorderTraversal(tree);
    printf("\n=================================\n");

    printf("Inorder traversal: ");
    inorderTraversal(tree);
    printf("\n=================================\n");

    printf("Postorder traversal: ");
    postorderTraversal(tree);
    printf("\n");

    return 0;
}
