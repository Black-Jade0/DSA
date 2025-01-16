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
    struct node *n;                                 // creating a node pointer
    n = (struct node *)malloc(sizeof(struct node)); // Allocating memory in the heap
    n->data = data;                                 // Setting the data
    n->left = NULL;                                 // Setting the left and right children to NULL
    n->right = NULL;                                // Setting the left and right children to NULL
    return n;                                       // Finally returning the created node
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
    ptr->data = key;
    ptr->left = NULL;
    ptr->right = NULL;
    if (prev->data < key)
    {
        prev->right = ptr;
        printf("Element inserted : %d\nAt right of %d\n", prev->right->data, prev->data);
        return 0;
    }

    else
    {
        prev->left = ptr;
        printf("Element inserted : %d \nAt left of %d\n", prev->left->data, prev->data);
        return 0;
    }
}

int deleteBST(struct node *curr, int key)
{
    if (key == curr->data)
    {
        printf("the root node cant be deleted\n");
        return 0;
    }

    struct node *key_node = curr;
    struct node *key_node_prev;
    key_node_prev = NULL;

    //    finding the node at which our element is present

    while (key_node->data != key && key_node != NULL)
    {
        if (key_node->data > key)
        {
            key_node_prev = key_node;
            key_node = key_node->left;
        }
        else
        {
            key_node_prev = key_node;
            key_node = key_node->right;
        }
    }

    //    if key is found at any node

    if (key_node->data == key)
    {
        //    if the key_node is a leaf

        if (key_node->left == NULL && key_node->right == NULL)
        {
            if (key_node_prev->left == key_node)
            {
                key_node_prev->left = NULL;
            }
            else
            {
                key_node_prev->right = NULL;
            }
            return 1;
        }

        struct node *temp = key_node;
        struct node *prev = NULL;

        //    finding its inorder predecessor if there is a left node and also a right node

        if (key_node->left != NULL && key_node->right != NULL)
        {
            prev = temp;
            temp = temp->left;
            while (temp->right != NULL)
            {
                prev = temp;
                temp = temp->right;
            }

            //    if the predecessor is a leaf node

            if (temp->left == NULL && temp->right == NULL)
            {
                key_node->data = temp->data;
                free(temp);
                return 1;
            }

            //    if the predessor has a node (ofcourse a left node) - predecessor is not the left node of the key_node

            else if (temp != key_node->left)
            {
                key_node->data = temp->data;
                prev->right = temp->left;
                free(temp);
                return 1;
            }

            //    if the predecessor is the left node of the key_node only

            else
            {
                key_node->data = temp->data;
                key_node->left = temp->left;
                free(temp);
                return 1;
            }
        }

        //    what if left node is not present - then we go for the inorder successor

        else if (key_node->left == NULL && key_node->right != NULL)
        {
            prev = temp;
            temp = temp->right;
            while (temp->left != NULL)
            {
                prev = temp;
                temp = temp->left;
            }

            //    if the successor is a leaf node

            if (temp->left == NULL && temp->right == NULL)
            {
                key_node->data = temp->data;
                free(temp);
                return 1;
            }

            //    if it has a node (ofcourse a right one)

            else
            {
                key_node->data = temp->data;
                prev->left = temp->right;
                free(temp);
                return 1;
            }
        }

        //    if only left node is present

        else
        {
            if (key_node_prev->left == key_node)
            {
                key_node_prev->left = key_node->left;
            }
            else
            {
                key_node_prev->right = key_node->left;
            }
        }
    }

    //    //

    else
    {
        printf("key not found\n");
        return 0;
    }
    return 0;
}

struct node *inOrderPredecessor(struct node *root)
{
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

struct node *deleteNode(struct node *root, int value)
{

    struct node *iPre;
    if (root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
    }

    // searching for the node to be deleted
    if (value < root->data)
    {
        root->left = deleteNode(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = deleteNode(root->right, value);
    }
    // deletion strategy when the node is found
    else
    {
        iPre = inOrderPredecessor(root);
        root->data = iPre->data;
        root->left = deleteNode(root->left, iPre->data);
    }
    return root;
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
    // p3->left = NULL;
    // p3->right = NULL;
    // p4->left = NULL;
    // p4->right = NULL;

    insertBST(p, 1);
    inOrder(p);

    printf("\n");

    deleteNode(p, 3);
    inOrder(p);

    return 0;
}