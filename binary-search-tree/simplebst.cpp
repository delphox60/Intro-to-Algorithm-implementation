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
    int getKey()
    {
        return this->key;
    }

    node *getRight()
    {
        return this->right;
    }

    node *getLeft()
    {
        return this->left;
    }

    node *getP()
    {
        return this->p;
    }

    void setKey(int key)
    {
        this->key = key;
    }
    void setRight(node *right)
    {
        this->right = right;
    }
    void setLeft(node *left)
    {
        this->left = left;
    }
    void setP(node *p)
    {
        this->p = p;
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

    void insert(int k)
    {
        node n = node(k);
        node *cur = this->root;
        if (cur == nullptr)
        {
            this->root = &n;
            return;
        }
        while (true)
        {
            if (n.getKey() < cur->getKey())
            {
                if (cur->getLeft() == nullptr)

                    n.setP(cur);
                cur->setLeft(&n);
                return;

                cur = cur->getLeft();
            }
            if (cur->getRight() == nullptr)
            {
                n.setP(cur);
                cur->setRight(&n);
                return;
            }
            cur = cur->getRight();
        }
    }
};

int main()
{
    tree t = tree();

    t.insert(3);
    t.insert(4);
    t.insert(31);
    t.insert(23);
    t.insert(98);
    t.insert(46);
    t.insert(42);
    t.insert(5);
}