//The implementation and traversal of binary tree
#include <iostream>

using namespace std;

//tree node
template <typename T> 
struct Node {
    T data;
    struct Node* left = nullptr;
    struct Node* right = nullptr;
};

//tree 
template <typename Tp>
class BinaryTree {
private:
    struct Node<Tp>* root;
    
    template <typename T>
    void visit(struct Node<T>* node) {
        cout << node->data << " ";
    }
public:
    template <typename T>
    void PreOrder(struct Node<T>* node) {
        if (node != nullptr) {
            visit<T>(node);
            PreOrder(node->left);
            PreOrder(node->right);
        }
    }

    template <typename T>
    void InOrder(struct Node<T>* node) {
        if (node != nullptr) {
            PreOrder(node->left);
            visit<T>(node);
            PreOrder(node->right);
        }
    }

    template <typename T>
    void PostOrder(struct Node<T>* node) {
        if (node != nullptr) {
            PreOrder(node->left);
            PreOrder(node->right);
            visit<T>(node);
        }
    }

    template <typename T>
    int Height(struct Node<T>* node) {
        if (node == nullptr)
            return 0;
        int hl = Height(node->left);
        int rl = Height(node->right);

        if (hl > rl)
            return ++hl;
        else
            return ++rl;
    }
};

int main() {
    
}