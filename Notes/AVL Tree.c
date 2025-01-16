#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
    int height;
};

struct node *createNode(int data)
{
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    n->height = 1;
    return n;
}

int getHeight(struct node *n)
{
    if(n==NULL)
        return 0;
    return n->height;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int getBalanceFactor(struct node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return getHeight(n->left) - getHeight(n->right);
}

struct node *rightRotate(struct node *y)
{
    struct node *x = y->left;

    y->left = x->right;
    x->right = y;

    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;
    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;

    return x;
}

struct node *leftRotate(struct node *x)
{
    struct node *y = x->right;

    x->right = y->left;
    y->left = x;

    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;
    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;

    return y;
}

struct node *insertBST(struct node *root, int key)
{
    struct node *curr = root;

    //    when the recursive function reaches the null place to insert the node to
    //    remember that before inserting the node all nodes were balanced
    if (curr == NULL)
    {
        return createNode(key);
    }

    //    to traverse to the llocation to fit the node in to recursively
    if (curr->data > key)
    {
        curr->left = insertBST(curr->left, key);
    }
    else if (curr->data < key)
    {
        curr->right = insertBST(curr->right, key);
    }

    //    if the node->data is already present at that location
    else if (curr->data == key)
    {
        printf("element already found\n");
        return root;
    }

    //    node is inserted at its right place now to balance the tree :
    //    and our curr is pointing at the parent of the new node currently, as that function is returned after creating a node at that point
    //    and it will travel backwards to the root node as we keep returning the function
    //    and the location of the node is always a leaf node, if u dont get it then u have not given sufficient hours for this

    //    after inserting the node, it can be possible that some of the nodes in the series will become imbalanced
    //    with balancefactor of 2 or -2;

    curr->height = 1 + max(getHeight(curr->left), getHeight(curr->right));
    int balance_factor = getBalanceFactor(curr);

    // Left Left Case - now see, how can we find which case it is,
    // left left case occurs when the heavy node gets a node inserted in the
    // left child's of it's left hcild (left subtree of its left child)
    // therefore its left child will be greater then the key node
    if (balance_factor > 1 && key < curr->left->data)
    {
        // curr = rightRotate(curr);
        // return curr;

        return rightRotate(curr); //   BOSS!
    }

    // right right case :
    else if (balance_factor < -1 && key > curr->right->data)
    {
        return leftRotate(curr);
    }

    // left right case
    else if (balance_factor > 1 && key > curr->left->data)
    {
        curr->left = leftRotate(curr->left);
        return rightRotate(curr);
    }
    // Right Left Case
    if (balance_factor < -1 && key < curr->right->data)
    {
        curr->right = rightRotate(curr->right);
        return leftRotate(curr);
    }
    else
    {
        return curr;
    }
}

void preOrder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(struct node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int main()
{
    struct node *root = NULL;

    root = insertBST(root, 1);
    root = insertBST(root, 2);
    root = insertBST(root, 4);
    root = insertBST(root, 5);
    root = insertBST(root, 6);
    root = insertBST(root, 3);
    // root = insert(root, 7);
    // root = insert(root, 8);
    // root = insert(root, 9);
    // root = insert(root, 10);
    // root = insert(root, 11);
    // root = insert(root, 12);

    preOrder(root);
    printf("\n");
    inOrder(root);

    return 0;
}