#include <iostream>

#define QUIT 0
#define SUCCESS 1

template<class T>
class priority_queue {
public:
    priority_queue();

    void push(T a);

    void pop();

    void reset(int x, T pri);

    void erase(int x);

    int length();

    T &operator[](const int &x) const;

    void quit();

    int menu();

    void check_cap();

    void run();

private:
    void shiftdown(int x) {
        while (x * 2 < _length) {
            if (x * 2 + 1 < _length) {
                if (data[x * 2] < data[x] && data[x * 2 + 1] < data[x]) {
                    if (data[x * 2] < data[x * 2 + 1]) {
                        std::swap(data[x], data[x * 2]);
                        x = x * 2;
                    } else {
                        std::swap(data[x], data[x * 2 + 1]);
                        x = x * 2 + 1;
                    }
                } else {
                    if (data[x * 2] < data[x]) {
                        std::swap(data[x], data[x * 2]);
                        x = x * 2;
                    } else if (data[x * 2 + 1] < data[x]) {
                        std::swap(data[x], data[x * 2 + 1]);
                        x = x * 2 + 1;
                    }
                }
            } else if (data[x * 2] < data[x]) {
                std::swap(data[x], data[x * 2]);
                x = x * 2;
            }
        }
    }

    void shiftup(int x) {
        while (x != 1 && data[x] < data[x / 2]) {
            std::swap(data[x], data[x / 2]);
            x >>= 1;
        }
    }

    T *data;
    int _length{};
    int _cap{};
};

template<class T>
priority_queue<T>::priority_queue() {
    _cap = 10;
    _length = 1;
    data = new T[_cap];
}

template<class T>
void priority_queue<T>::check_cap() {
    if (_length * 2 + 1 >= _cap) {
        T *temp = new T[_cap <<= 1];
        for (int i = 0; i < (_cap >> 1); i++)temp[i] = data[i];
        delete data;
        data = temp;
    }
}

template<class T>
void priority_queue<T>::push(T a) {
    check_cap();
    int p = _length;
    data[_length++] = a;
    shiftup(_length - 1);
}

template<class T>
void priority_queue<T>::reset(int x, T pri) {
    erase(x);
    push(pri);
}

template<class T>
int priority_queue<T>::length() {
    return this->_length;
}

template<class T>
T &priority_queue<T>::operator[](const int &x) const {
    return data[x];
}

template<class T>
void priority_queue<T>::quit() {

}

template<class T>
void priority_queue<T>::run() {
    _length = 1;
    while (true) {
        if (menu() == QUIT)break;
        for (int i = 0; i < _length; i++)std::cout << data[i] << ' ';
        std::cout << std::endl;
    }
}

template<class T>
void priority_queue<T>::pop() {
    int p = 1;
    data[p] = data[--_length];
    while (p * 2 < _length && data[p] > data[p * 2]) {
        if (p * 2 + 1 < _length && data[p * 2] > data[p * 2 + 1]) {
            std::swap(data[p], data[p * 2 + 1]);
            p = p * 2 + 1;
        } else {
            std::swap(data[p], data[p * 2]);
            p *= 2;
        }
    }
}

template<class T>
void priority_queue<T>::erase(int x) {
    data[x] = data[--_length];
    shiftdown(x);
}

template<class T>
int priority_queue<T>::menu() {
    std::cout << "菜单内容:\n"
                 "1. 优先队列的插入操作\n"
                 "2. 最大优先级元素出队列操作\n"
                 "3. 调整优先队列某个元素的优先级\n"
                 "4. 求优先队列的长度\n"
                 "5. 优先队列的查询操作\n"
                 "6. 退出系统\n"
                 "请选择:1 – 6:\n";
    int res;
    std::cin >> res;
    if (res == 6)return QUIT;
    switch (res) {
        case 1:
            T p;
            std::cin >> p;
            push(p);
            break;
        case 2:
            pop();
            break;
        case 3:
            int x;
            T newone;
            std::cin >> x >> newone;
            reset(x, newone);
            break;
        case 4:
            std::cout << _length << std::endl;
            break;
        case 5:
            int x;
            std::cin >> x;
            std::cout << data[x] << std::endl;
            break;
        default:
            break;
    }
    return SUCCESS;
}

int main() {
    priority_queue<int> q;
    q.run();
    return 0;
}