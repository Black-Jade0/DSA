#include <stdio.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data)
{
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void PreOrder(struct node * root)
{
    if (root != NULL)
    {
        printf("%d", root->data);
        PreOrder(root->left);
        PreOrder(root->right);
    }
    return;
}

void PostOrder(struct node *root)
{
    if (root != NULL)
    {
        PostOrder(root->left);
        PostOrder(root->right);
        printf("%d", root->data);
    }
    return;
}

void InOrder(struct node *root)
{
    if (root != NULL)
    {
        PostOrder(root->left);
        printf("%d", root->data);
        PostOrder(root->right);
    }
    return;
}

int main()
{
    struct node *root = createNode(1);
    struct node *root1 = createNode(2);
    struct node *root2 = createNode(3);
    struct node *root11 = createNode(4);
    struct node *root12 = createNode(5);
    struct node *root21 = createNode(6);
    struct node *root22 = createNode(7);

    root->left = root1;
    root->right = root2;
    root1->left = root11;
    root1->right = root12;
    root->right = root2;
    root2->left = root21;
    root2->right = root22;

    //         1
    //       /   \
    //     2       3
    //   /   \   /   \
    //  4     5 6     7

    PreOrder(root);
    printf("\n");
    printf("\n");

    PostOrder(root);
    printf("\n");
    printf("\n");

    InOrder(root);

    return 0;
}
