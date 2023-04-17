#include <iostream>

using namespace std;

class node
{
private:
    int key;
    node *right;
    node *left;
    node *p;

public:
    node()
    {
    }
    node(int key) : key(key)
    {
        this->right = nullptr;
        this->left = nullptr;
        this->p = nullptr;
    }
};

class tree
{
private:
    node *root;

public:
    tree()
    {
        this->root = nullptr;
    }
};

int main()
{
    tree t = tree();
}