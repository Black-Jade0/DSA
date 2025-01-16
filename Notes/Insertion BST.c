#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data)
{
    struct node *n;                                               // creating a node pointer
    n = (struct node *)malloc(sizeof(struct node));               // Allocating memory in the heap
    n->data = data;                                               // Setting the data
    n->left = NULL;                                               // Setting the left and right children to NULL
    n->right = NULL;                                              // Setting the left and right children to NULL
    return n;                                                     // Finally returning the created node
}

void inOrder(struct node *curr)
{
    if (curr != NULL)
    {
        inOrder(curr->left);
        printf("%d ", curr->data);
        inOrder(curr->right);
    }
}

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

int insertBST(struct node *curr, int key)
{
    struct node *prev = NULL;
    while (curr != NULL)
    {
        if (curr->data == key)
        {
            printf("element already present!\n");
            return 0;
        }
        if (curr->data > key)
        {
            prev = curr;
            curr = curr->left;
        }
        else
        {
            prev = curr;
            curr = curr->right;
        }
    }
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr -> data = key;
    ptr -> left = NULL;
    ptr -> right = NULL;
    if (prev->data < key)
    {
        prev -> right = ptr;
        printf("Element inserted : %d\nAt right of %d\n",prev -> right -> data, prev -> data);
        return 0;
    }
    else
    {
        prev -> left = ptr;
        printf("Element inserted : %d \nAt left of %d\n", prev -> left -> data, prev -> data);
        return 0;
    }
}

int main()
{
    // Constructing the root node - Using Function (Recommended)
    struct node *p = createNode(10);
    struct node *p1 = createNode(5);
    struct node *p2 = createNode(14);
    struct node *p3 = createNode(3);
    struct node *p4 = createNode(7);
    // struct node *p5 = createNode(1);
    // Finally The tree looks like this:
    //      10
    //     / \
    //    5   14
    //   / \
    //  3   7

    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    // p3 -> left = p5;

    insertBST(p,1);

    if (isBST1(p))
    {
        printf("This is a bst\n");
    }
    else
    {
        printf("This is not a bst\n");
    }

    inOrder(p);
    

    return 0;
}