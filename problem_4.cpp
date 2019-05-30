#include <iostream>

#define SUCCESS 1
#define QUIT 0

template<class T>
class Control {
public:
    Control() = default;

    void run() {
        t = new T;
        while (t->begin() != 0);
    }

private:
    T *t;
};

template<class T>
class Node {
public:
    Node() {
        left = right = nullptr;
    }

    Node<T> *left;
    Node<T> *right;
    T data;
};

template<class T>
class Tree {
public:
    Tree() {
        bt = nullptr;
    }

    int begin();

    void initial();

    void clear(Node<T> *node);

    void first(Node<T> *node);

    void second(Node<T> *node);

    void third(Node<T> *node);

    void getPath(Node<T> *p);

private:
    Node<T> *bt;
};

template<class T>
void Tree<T>::initial() {
    if (bt != nullptr) {
        clear(bt);
    } else {
        bt = new Node<T>;
    }
};

template<class T>
void Tree<T>::clear(Node<T> *node) {
    if (node->left != nullptr) {
        clear(node->left);
        delete node->left;
    }
    if (node->right != nullptr) {
        clear(node->right);
        delete node->right;
    }
}


template<class T>
int Tree<T>::begin() {
    std::cout << "1. 建立二叉树存储结构\n"
                 "2. 求二叉树的前序遍历\n"
                 "3. 求二叉树的中序遍历\n"
                 "4. 求二叉树的后序遍历\n"
                 "5. 求指定结点的路径\n"
                 "6. 退出系统\n"
                 "请选择:1 – 6:\n";
    int input;
    std::cin >> input;
    switch (input) {
        case 6:
            return QUIT;
    }
    return SUCCESS;
}

template<class T>
void Tree<T>::first(Node<T> *node) {
    std::cout << node->data << std::endl;
    if (node->left != nullptr)
        first(node->left);
    if (node->right != nullptr)
        first(node->right);

}

template<class T>
void Tree<T>::second(Node<T> *node) {
    if (node->left != nullptr)
        first(node->left);
    std::cout << node->data << std::endl;
    if (node->right != nullptr)
        first(node->right);
}

template<class T>
void Tree<T>::third(Node<T> *node) {
    if (node->left != nullptr)
        first(node->left);
    if (node->right != nullptr)
        first(node->right);
    std::cout << node->data << std::endl;
}

template<class T>
void Tree<T>::getPath(Node<T> *p) {

}

int main() {
    Control<Tree<int> > control;
    control.run();
    return 0;
}