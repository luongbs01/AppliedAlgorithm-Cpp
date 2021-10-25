#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int value;
    Node *left;
    Node *right;
}

class BSTree
{
private:
    Node *root;

public:
    BSTree()
    {
        root = NULL;
    }

    bool isEmpty()
    {
        if (root == NULL)
            return true;
        return false;
    }

    void makeEmpty()
    {
        root->left = NULL;
        root->right = NULL;
        root = NULL;
    }

    void insert(int val1)
    {
        if (root == NULL)
        {
            Node *temp = new Node;
            temp->value = val1;
            temp->left = NULL;
            temp->right = NULL;
        }
        else
        {
            if (val1 < root->value)
                root->left = insert(value);
            else
                root->right = insert(value);
        }
    }

    Node *search(int val2)
    {
        if (root == NULL)
            return NULL;
        if (root->value == val2)
            return root;
        if (val2 < root->value)
        {
            root = root->left;
            search(val2);
        }
        else
        {
            root = root->right;
            search(val2);
        }
    }
}

void
PREORDER_travl(Node *t)
{
    if (t != NULL)
    {
        cout << t->value << " ";
        PREORDER_travl(t->left);
        PREORDER_travlt(t->right);
    }
}

void INORDER_travl(Node *t)
{
    if (t != NULL)
    {
        INORDER_travl(t->left);
        cout << t->value << " ";
        INORDER_travl(t->right);
    }
}

void POSTORDER_travl(Node *t)
{
    if (t != NULL)
    {
        POSTORDER_travl(t->left);
        POSTORDER_travl(t->right);
        cout << t->value << " ";
    }
}