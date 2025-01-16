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
    struct node *n;                                 // creating a node pointer
    n = (struct node *)malloc(sizeof(struct node)); // Allocating memory in the heap
    n->data = data;                                 // Setting the data
    n->left = NULL;                                 // Setting the left and right children to NULL
    n->right = NULL;                                // Setting the left and right children to NULL
    return n;                                       // Finally returning the created node
}

//    u can just see if the inorder representation of the tree is in asccending order

void inOrder(struct node *curr)
{
    if (curr != NULL)
    {
        inOrder(curr->left);
        printf("%d ", curr->data);
        inOrder(curr->right);
    }
}

//    OR - need to be enlightened -- FUCKING DONE (a great 5h work)

int isBST(struct node *curr)
{
    static struct node *prev = NULL;
    if (curr != NULL)
    {
        if (!isBST(curr->left))
        {
            return 0;
        }
        if (prev != NULL && curr->data <= prev->data)
        {
            return 0;
        }
        prev = curr;
        curr = curr -> right;

        return isBST(curr);
    }
    else
    {
        return 1;
    }
}

// same code using loops : included in 5h

int isBST1(struct node *root)
{
    struct node *curr = root;
    struct node *prev = NULL;

    while (curr != NULL)
    {
        struct node *temp;
        if (curr->left != NULL)
        {
            temp = curr->left;
            while (temp->right != NULL && temp->right != curr)
            {
                temp = temp->right;
            }

            // temp->right = curr;
            // prev = curr;
            // curr = curr->left;

            // if we dont put it in a loop it will update the curr value when we are getting up the nodes while prev in at the last

            if (temp->right == NULL)
            {
                temp->right = curr;
                curr = curr->left;
            }
        }

        if (curr->left == NULL && curr->right != NULL)
        {
            prev = curr;
            curr = curr->right;
            if (prev != NULL && prev->data >= curr->data)
            {
                return 0;
            }
        }
        else if (temp->right == curr)
        {
            prev = temp->right;
            temp->right = NULL;
            curr = curr->right;
            if (prev->data >= curr->data)
            {
                return 0;
            }
        }
        else if (curr->left == NULL && curr->right == NULL)
        {
            return 1;
        }
    }
    return 1;
}

int isBST2(struct node *root)
{
    struct node *prev = NULL;
    struct node *curr = root;

    while (curr != NULL)
    {
        if (curr->left != NULL)
        {
            // Find the inorder predecessor of the current node
            struct node *temp = curr->left;
            while (temp->right != NULL && temp->right != curr)
            {
                temp = temp->right;
            }

            // Link the inorder predecessor to the current node
            if (temp->right == NULL)
            {
                temp->right = curr;
                curr = curr->left;
            }
            else
            {
                // Revert the link and check the current node
                temp->right = NULL;
                if (prev != NULL && curr->data <= prev->data)
                {
                    return 0; // Not a BST
                }
                prev = curr;
                curr = curr->right;
            }
        }
        else
        {
            if (prev != NULL && curr->data <= prev->data)
            {
                return 0; // Not a BST
            }
            prev = curr;
            curr = curr->right;
        }
    }

    return 1; // Is a BST
}

int main()
{

    // Constructing the curr node - Using Function (Recommended)
    struct node *p = createNode(5);
    struct node *p1 = createNode(3);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(1);
    struct node *p4 = createNode(4);
    // Finally The tree looks like this:
    //      5
    //     / \
    //    3   6
    //   / \
    //  1   4

    // Linking the curr node with left and right children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    // preOrder(p);
    // printf("\n");
    // postOrder(p);
    // printf("\n");
    inOrder(p);
    printf("\n");
    // printf("%d", isBST(p));
    if (isBST1(p))
    {
        printf("This is a bst");
    }
    else
    {
        printf("This is not a bst");
    }

    return 0;
}
