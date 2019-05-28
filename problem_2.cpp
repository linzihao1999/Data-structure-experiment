#include <iostream>

class List {
public:
    List() : num(-1), next(nullptr) {}

    int num;

    List *nextptr();

    void link(List *list);

    static List *create(int Nu = -1, List *Ne = nullptr);

private:
    List *next;
};

class Sqlist {
public:
    Sqlist() {
        length_base = 100;
        num = new int[length_base];
        head = 0;
        Length = 0;
    }

    int length();

    void erase(int x);

    void push(int data);

    void checkCap();

    int &operator[](int i) {
        return num[i];
    }

private:
    int *num;
    int length_base;
    int Length;
    int head;
};

class Joseph {
public:
    Joseph(int n1, int k1) : n(n1), k(k1) {
        list = List::create();
    }

    void useList();

    void useSqlist();

private:
    List *list;
    Sqlist sqlist;
    int n, k;
};

void Joseph::useList() {
    std::cout << "List:" << std::endl;
    List *p = list, *last;
    for (int i = 1; i <= n; i++) {
        p->num = i;
        if (i != n) {
            p->link(List::create());
            p = p->nextptr();
        }
    }
    p->link(list);
    last = p;
    p = list;
    int count = 0;
    while (p->num != p->nextptr()->num) {
        ++count;
        if (count == k) {
            last->link(p->nextptr());
            std::cout << p->num << ' ';
            delete p;
            count = 0;
            p = last->nextptr();
        } else {
            last = p;
            p = p->nextptr();
        }
    }
    std::cout << p->num << std::endl;

}

void Joseph::useSqlist() {
    std::cout << "Sqlist:" << std::endl;
    for (int i = 0; i < n; i++)
        sqlist.push(i + 1);
    int p = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            if (p == -1 || sqlist[p] != 0)p = (p + 1) % n;
            while (sqlist[p] == 0) {
                ++p;
                p %= n;
            }
        }
        std::cout << sqlist[p] << ' ';
        sqlist[p] = 0;
    }
    std::cout << std::endl;
}

int Sqlist::length() {
    return this->Length;
}

void Sqlist::push(int data) {
    checkCap();
    num[head++] = data;
    Length++;
}

void Sqlist::checkCap() {
    if (head + 1 < length_base)return;
    int *temp = new int[length_base <<= 1];
    for (int i = 0; i < length_base; i++)
        temp[i] = num[i];
    delete num;
    num = temp;

}

void Sqlist::erase(int x) {
    for (int i = x; i < Length - 1; i++) {
        num[i] = num[i + 1];
    }
    Length--;
}

List *List::nextptr() {
    return this->next;
}

void List::link(List *list) {
    this->next = list;
}

List *List::create(int Nu, List *Ne) {
    auto list = new List;
    list->num = Nu;
    list->next = Ne;
    return list;
}

int main() {
    int n, k;
    std::cin >> n >> k;
    Joseph joseph(n, k);
    joseph.useList();
    joseph.useSqlist();
    return 0;
}
