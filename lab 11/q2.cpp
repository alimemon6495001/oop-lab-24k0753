#include <iostream>
#include <exception>

class QueueOverflowException : public std::exception {};
class QueueUnderflowException : public std::exception {};

template <typename T>
class Queue {
private:
    int front, rear, capacity, size;
    T* arr;
public:
    Queue(int cap) : capacity(cap), size(0), front(0), rear(-1) {
        arr = new T[capacity];
    }

    ~Queue() {
        delete[] arr;
    }

    void enqueue(T value) {
        if (size == capacity) {
            throw QueueOverflowException();
        }
        rear = (rear + 1) % capacity;
        arr[rear] = value;
        ++size;
    }

    T dequeue() {
        if (size == 0) {
            throw QueueUnderflowException();
        }
        T val = arr[front];
        front = (front + 1) % capacity;
        --size;
        return val;
    }
};

int main() {
    try {
        Queue<int> q(2);
        q.enqueue(10);
        q.enqueue(20);
        q.enqueue(30);  
    } catch (const QueueOverflowException&) {
        std::cout << "Caught QueueOverflowException - what(): std::exception\n";
    }

    try {
        Queue<int> q(2);
        q.dequeue();  
    } catch (const QueueUnderflowException&) {
        std::cout << "Caught QueueUnderflowException - what(): std::exception\n";
    }

    return 0;
}
