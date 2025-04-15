#include <iostream>

template <typename T>
class BinaryTree {
private:
    struct Node {
        T data;
        Node* left;
        Node* right;

        Node(const T& value) : data(value), left(nullptr), right(nullptr) {}
    };

    Node* root;

public:
    BinaryTree() : root(nullptr) {}
    BinaryTree(const T& value) : root(new Node(value)) {}
    ~BinaryTree() {
        destroyTree(root);
    }

    void insert(const T& value) {
        if (root == nullptr) {
            root = new Node(value);
        }
        else {
            insertNode(root, value);
        }
    }

    bool search(const T& value) {
        return searchNode(root, value);
    }

    void remove(const T& value) {
        root = removeNode(root, value);
    }

    void print() {
        printTree(root);
    }

    void removeAll() {
        destroyTree(root);
        root = nullptr;
    }

private:
    void insertNode(Node* node, const T& value) {
        if (value < node->data) {
            if (node->left == nullptr) {
                node->left = new Node(value);
            }
            else {
                insertNode(node->left, value);
            }
        }
        else if (value > node->data) {
            if (node->right == nullptr) {
                node->right = new Node(value);
            }
            else {
                insertNode(node->right, value);
            }
        }
    }

    bool searchNode(Node* node, const T& value) {
        if (node == nullptr) {
            return false;
        }
        else if (value == node->data) {
            return true;
        }
        else if (value < node->data) {
            return searchNode(node->left, value);
        }
        else {
            return searchNode(node->right, value);
        }
    }

    Node* removeNode(Node* node, const T& value) {
        if (node == nullptr) {
            return nullptr;
        }
        else if (value < node->data) {
            node->left = removeNode(node->left, value);
        }
        else if (value > node->data) {
            node->right = removeNode(node->right, value);
        }
        else {
            if (node->left == nullptr && node->right == nullptr) {
                delete node;
                return nullptr;
            }
            else if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            else {
                Node* minRight = findMinNode(node->right);
                node->data = minRight->data;
                node->right = removeNode(node->right, minRight->data);
            }
        }
        return node;
    }

    Node* findMinNode(Node* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    void printTree(Node* node) {
        if (node != nullptr) {
            printTree(node->left);
            std::cout << node->data << " ";
            printTree(node->right);
        }
    }

    void destroyTree(Node* node) {
        if (node != nullptr) {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }
};

int main() {
    BinaryTree<int> tree;

    // Инициализация первого элемента
    tree.insert(5);

    // Запись в структуру нового элемента
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);

    // Вывод элементов дерева на экран
    std::cout << "Elements in the tree: ";
    tree.print();
    std::cout << std::endl;

    // Поиск элемента
    int searchValue = 4;
    if (tree.search(searchValue)) {
        std::cout << "Element " << searchValue << " found in the tree." << std::endl;
    }
    else {
        std::cout << "Element " << searchValue << " not found in the tree." << std::endl;
    }

    // Удаление элемента
    int removeValue = 7;
    tree.remove(removeValue);
    std::cout << "Tree after removing element " << removeValue << ": ";
    tree.print();
    std::cout << std::endl;

    // Удаление всех элементов дерева
    tree.removeAll();
    std::cout << "Tree after removing all elements: ";
    tree.print();
    std::cout << std::endl;

    return 0;
}