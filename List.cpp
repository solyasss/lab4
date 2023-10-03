#include <iostream>
using namespace std;

template <typename T>
struct Elem
{
    T data;
    Elem *next, *prev;
};

template <typename T>
class Queue
{
    Elem<T> *Head, *Tail;
    int Count;

public:
    Queue();
    Queue(const Queue &);
    ~Queue();

    int GetCount();
    Elem<T> *GetElem(int);

    void Clear();
    void Squeue(const T &value);
    T Dqueue();

    void Print();
};

template <typename T>
Queue<T>::Queue()
{
    Head = Tail = NULL;
    Count = 0;
}

template <typename T>
Queue<T>::Queue(const Queue &obj)
{
    Head = Tail = NULL;
    Count = 0;

    Elem<T> *temp = obj.Head;

    while (temp != 0)
    {
        Squeue(temp->data);
        temp = temp->next;
    }
}

template <typename T>
Queue<T>::~Queue()
{
    Clear();
}

template <typename T>
void Queue<T>::Squeue(const T &value)
{
    Elem<T> *temp = new Elem<T>;

    temp->prev = 0;
    temp->data = value;
    temp->next = 0;

    if (Count == 0)
    {
        Head = Tail = temp;
    }
    else
    {
        Tail->next = temp;
        temp->prev = Tail;
        Tail = temp;
    }

    Count++;
}

template <typename T>
T Queue<T>::Dqueue()
{
    if (Count == 0)
    {
        cerr << "Queue is empty!" << endl;
        exit(1);
    }

    Elem<T> *temp = Head;
    T value = temp->data;

    Head = Head->next;
    if (Head != nullptr)
    {
        Head->prev = nullptr;
    }
    delete temp;

    Count--;

    return value;
}

template <typename T>
void Queue<T>::Clear()
{
    while (Count != 0)
        Dqueue();
}

template <typename T>
int Queue<T>::GetCount()
{
    return Count;
}

template <typename T>
Elem<T> *Queue<T>::GetElem(int pos)
{
    Elem<T> *temp = Head;

    if (pos < 1 || pos > Count)
    {
        cerr << "Incorrect position!" << endl;
        return nullptr;
    }

    int i = 1;

    while (i < pos && temp != nullptr)
    {
        temp = temp->next;
        i++;
    }

    if (temp == nullptr)
        return nullptr;
    else
        return temp;
}

template <typename T>
void Queue<T>::Print()
{
    if (Count != 0)
    {
        Elem<T> *temp = Head;
        cout << "( ";
        while (temp->next != nullptr)
        {
            cout << temp->data << ", ";
            temp = temp->next;
        }

        cout << temp->data << " )\n";
    }
}

int main()
{
    Queue<int> intQueue;
    intQueue.Squeue(1);
    intQueue.Squeue(2);
    intQueue.Squeue(3);

    cout << "Integer Queue:\n";
    intQueue.Print();

    cout << "Dqueue: " << intQueue.Dqueue() << endl;
    intQueue.Print();

    Queue<string> stringQueue;
    stringQueue.Squeue("Hello");
    stringQueue.Squeue("World");
    stringQueue.Squeue("!");

    cout << "String Queue:\n";
    stringQueue.Print();

    cout << "Dqueue: " << stringQueue.Dqueue() << endl;
    stringQueue.Print();

    return 0;
}
