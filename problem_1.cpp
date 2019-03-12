#include <utility>

#include <utility>
#include <iostream>

#define SUCCESS 0
#define UNSUCCES 1
#define NOT_FOUND (-1)

class User {
public:
    User *next;
    int address;
    std::string name;

    User() : next(nullptr), address(0) {}

    static User *Create(std::string tname = "", int taddress = 0) {
        auto user = new User;
        user->name = std::move(tname);
        user->address = taddress;
        return user;
    }
};

class UserList {
public:
    void Init();

    void Insert(std::string, int);

    int Search(const std::string &);

    int Change(const std::string &, int);

    int Delete(const std::string &);

    void Show();

private:
    User *head;
};

class AddressBook {
public:
    AddressBook() = default;

    void Run();

    int Menu();

private:
    UserList userList;
};

void UserList::Init() {
    head = User::Create();
}

void UserList::Insert(std::string tname, int taddress) {
    User *user = User::Create(std::move(tname), taddress);
    user->next = head->next;
    head->next = user;
}

void UserList::Show() {
    User *user = head->next;
    while (user != nullptr) {
        std::cout << user->name << " " << user->address << std::endl;
        user = user->next;
    }
}

int UserList::Search(const std::string &tname) {
    User *user = head->next;
    while (user != nullptr) {
        if (tname == user->name)return user->address;
        user = user->next;
    }
    return NOT_FOUND;
}

int UserList::Change(const std::string &tname, int taddress) {
    User *user = head->next;
    while (user != nullptr) {
        if (tname == user->name) {
            user->address = taddress;
            return SUCCESS;
        }
        user = user->next;
    }
    return UNSUCCES;
}

int UserList::Delete(const std::string &tname) {
    User *user = head->next, *last = head;
    while (user != nullptr) {
        if (user->name == tname) {
            User *temp = user;
            last->next = user->next;
            delete temp;
            return SUCCESS;
        }
    }
    return UNSUCCES;
}


void AddressBook::Run() {
    int res = 0;
    std::string name;
    int address;
    while (res != 7) {
        res = Menu();
        switch (res) {
            case 1:
                userList.Init();
                break;
            case 2:
                std::cout << "输入姓名:";
                std::cin >> name;
                std::cout << "输入地址:";
                std::cin >> address;
                userList.Insert(name, address);
                //todo
                break;
            case 3:
                std::cout << "输入姓名:";
                std::cin >> name;
                std::cout << userList.Search(name) << std::endl;
                //todo
                break;
            case 4:
                std::cout << "输入姓名:";
                std::cin >> name;
                std::cout << "输入要更改的地址:";
                std::cin >> address;
                userList.Change(name, address);
                //todo
                break;
            case 5:
                std::cout << "输入姓名:";
                std::cin >> name;
                userList.Delete(name);
                //todo
                break;
            case 6:
                userList.Show();
                break;
            case 7:
                std::cout << "Bye" << std::endl;
                break;
            default:
                std::cout << "undefined" << std::endl;
        }
        std::cout << "-------------------------" << std::endl;
    }
}

int AddressBook::Menu() {
    std::cout << "1. 通讯录链表的建立\n"
                 "2. 通讯者信息的插入\n"
                 "3. 通讯者信息的查询\n"
                 "4. 通讯者信息的修改\n"
                 "5. 通讯者信息的删除\n"
                 "6. 通讯录链表的输出\n"
                 "7. 退出管理系统\n"
                 "请选择:1 – 7:";
    //todo fix
    int in;
    std::cin >> in;
    return in;
}

int main() {
    AddressBook addressBook{};
    addressBook.Run();
    return 0;
}