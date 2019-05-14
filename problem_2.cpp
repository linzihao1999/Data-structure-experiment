#include <iostream>

class List {
public:
    List() : num(-1), next(nullptr) {}

    int num;

    List *toNext() {
        return this->next;
    }

    void link(List *list) {
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
    Sqlist() {
        length_base = 100;
        num = new int[length_base];
        head = 0;
    }

    int length() {
        return this->length_base;
    }

    void push(int data) {
        checkCap();
        num[head++] = data;
    }

    void checkCap() {
        if (head + 1 < length_base)return;
        int *temp = new int[length_base <<= 1];
        for (int i = 0; i < length_base; i++)
            temp[i] = num[i];
        delete num;
        num = temp;
    }

    int &operator[](int i) {
        return num[i];
    }

private:
    int *num;
    int length_base;
    int head;
};

class Joseph {
public:
    Joseph(int n1, int k1) : n(n1), k(k1) {
        list = List::create();
    }

    int useList() {
        List *p = list;
        for (int i = 1; i <= n; i++) {
            p->link(List::create());
            p = p->toNext();
        }
    }

    int useSqlist() {

    }

private:
    List *list;
    Sqlist sqlist;
    int n, k;
};
