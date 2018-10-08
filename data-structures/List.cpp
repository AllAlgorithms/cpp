
#include <iostream>
#include <assert.h>

template<typename T>
struct Elem {
    T value;
    Elem<T> *next;
};

template <typename T>
class List{
public:
    List() : mHead(nullptr) {}

    
    T operator[] (int x);
    void push_back (T val);
    void insert (int n, T val);
    void remove (int n);
    size_t size(void);

protected:
    Elem<T> *mHead;

    bool isTail(Elem<T> &e);
};

template<typename T>
T List<T>::operator[](int n)
{
    assert(nullptr != mHead);
    assert(n < this->size());
    auto ptr = mHead;
    for (int i = 0; i < n ; ptr = ptr->next, i++);
    return ptr->value;
}

template<typename T>
void List<T>::push_back(T val){
    Elem<T> *e = new Elem<T>();
    e->value = val;
    e->next = nullptr;

    if (nullptr == mHead) {
        mHead = e;
        return ; 
    }

    auto ptr = mHead;
    for (;!this->isTail(*ptr); ptr = ptr->next);
    ptr->next = e;
}

template<typename T>
void List<T>::insert (int n, T val){
    Elem<T> *e = new Elem<T>();
    e->value = val;

    assert(n <= this->size());

    if (n == 0){
        e->next = mHead;
        mHead = e;
        return ;
    }

    auto ptr = mHead;
    int i = 0;
    for (; i < n-1 ; ptr = ptr->next, i++);
    e->next = ptr->next;
    ptr->next = e;
}

template<typename T>
void List<T>::remove (int n){
    assert(nullptr != mHead);
    assert(n <= this->size());

    if (n == 0){
        if (nullptr != mHead->next){
            auto ptr = mHead->next;        
            delete(mHead);
            mHead = ptr;
        }else{
            delete(mHead);
            mHead = nullptr;
        }
        return ;
    }

    auto ptr = mHead;
    for (int i=0; i < n-1 ; ptr = ptr->next, i++);
    if ( nullptr != ptr->next->next){
        auto _ptr = ptr->next->next;
        delete(ptr->next);
        ptr->next = _ptr;
    }else{
        delete(ptr->next);
        ptr->next = nullptr;
    }
}

template<typename T>
size_t List<T>::size(void){
    if (nullptr == mHead){
        return 0;
    }

    size_t len = 1;
    for (auto ptr = mHead; !this->isTail(*ptr); len++, ptr = ptr->next);
    return len;
}

template<typename T>
bool List<T>::isTail(Elem<T> &e){
    return e.next == nullptr;
}



int main(){
    List<int> list;
    std::cout << list.size() << std::endl; // 0

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    std::cout << list.size() << std::endl; // 3

    std::cout << list[0] << std::endl; // 1
    std::cout << list[1] << std::endl; // 2
    std::cout << list[2] << std::endl; // 3
    // cout << list[3] << endl; // Assertion Error.

    list.insert(0, 4);
    list.insert(4, 5);
    std::cout << list[0] << std::endl; // 4
    std::cout << list[1] << std::endl; // 1
    std::cout << list[2] << std::endl; // 2
    std::cout << list[3] << std::endl; // 3
    std::cout << list[4] << std::endl; // 5

    list.remove(2);
    list.remove(2);
    list.remove(2);
    std::cout << list[0] << std::endl; // 4
    std::cout << list[1] << std::endl; // 1
    //cout << list[2] << endl; // Assertion Error.
    
    
}