#include <iostream>

class List {
public:
    List() : num(-1), next(nullptr) {}

    int num;

    List *ToNext() {
        return this->next;
    }

    void Link(List *list) {
        this->next = list;
    }

    static List *create(int Nu = -1, List *Ne = nullptr) {
        auto list = new List;
        list->num = Nu;
        list->next = Ne;
        return list;
    }

private:
    List *next;
};

class Sqlist {
public:
    Sqlist() {}

    int length() {
        return this->length_base;
    }

    void push(int data);

    void CheckCap();


    int &operator[](int i) {
        return num[i];
    }

private:
    int *num;
    int length_base;
    int head;
};

void Sqlist::CheckCap() {
    if (head + 1 < length_base)return;
    int *temp = new int[length_base << 1];
    for (int i = 0; i < length_base; i++)
        temp[i] = num[i];
    delete num;
    num = temp;
}

void Sqlist::push(int data) {

}

class Joseph {
public:
private:
    int n, k;
};