#include <iostream>
#include <optional>
#include <vector>

// Lets use a struct to define a node;
template <typename T>
struct Node
{
    // Left and right children
    Node *left;
    Node *right;
    // the value of current node
    T val;

    // Make some constructors as well
    Node(T value) : val(value), left(nullptr), right(nullptr) {}
    Node(T value, Node *l, Node *r) : val(value), left(l), right(r) {}
};

// lets make a bst using those nodes;
template <typename T>
class BST
{
private:
    Node<T> *root;
    void insertHelper(Node<T> *&n, const T &data)
    {
        // Empty space
        if (n == nullptr) n = new Node<T>(data);
        else if (data < n->val) insertHelper(n->left, data);
        else if (data > n->val) insertHelper(n->right, data);
        else return; 
    }

    // Optionals make this a bit easier with some syntactic sugar.
    std::optional<T> searchHelper(Node<T> *&n, const T &data) const
    {
        if (n == nullptr) return std::nullopt;
        else if (data < n->val) return searchHelper(n->left, data);
        else if (data > n->val) return searchHelper(n->right, data);
        else return std::optional<T>(n->val);
    }

    bool removeHelper(Node<T> *&n, const T &data)
    {
        // Nothing..
        if (n == nullptr) return false;
        else if (data < n->val) return removeHelper(n->left, data);
        else if (data > n->val) return removeHelper(n->right, data);
        else if (n->left != nullptr && n->right != nullptr)
        {
            // Find sucessor
            Node<T>* minNode = findMin(n->right);
            n->val = minNode->val;
            return removeHelper(n->right, minNode->val);
        }
        else
        {
            // Delete the oldnode finally.
            Node<T> *oldNode = n;
            n = (n->left != nullptr) ? n->left : n->right;
            delete oldNode;
            return true;
        }
    }

    // We use this for delete..
    Node<T> *findMin(Node<T> *n) const
    {
        if (n == nullptr) return n;
        while (n->left != nullptr) n = n->left;
        return n;
    }

    void clearHelper(Node<T> *n)
    {
        if (n == nullptr)
            return;
        clearHelper(n->left);
        clearHelper(n->right);
        delete n;
    }

public:
    BST() : root(nullptr) {}
    ~BST()
    {
        clearHelper(root);
    }
    void Insert(const T &data)
    {
        insertHelper(root, data);
    }
    bool Remove(const T &data)
    {
        return removeHelper(root, data);
    }
    std::optional<T> Search(const T &data)
    {
        return searchHelper(root, data);
    }
};