#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <list>
#include <cassert>

template <typename T>
class Queue
{
private:
    std::list<T> myQueue;

public:
    Queue() = default;

    Queue(const Queue &other)
    {
        myQueue = other.myQueue;
    } // copy constructor

    Queue &operator=(const Queue &other)
    {
        if (this != other)
        {
            myQueue = other.myQueue;
        }

        return *this;
    } // copy assignment operator, return *this

    bool empty()
    {
        return myQueue.empty();
    }

    size_t size()
    {
        return myQueue.size();
    }

    void push(const T &item)
    {
        myQueue.push_back(item);
        assert(!myQueue.empty() && "queue should not be empty after push");
    }

    T &front()
    {
        assert(!myQueue.empty() && "Cannot access front of an empty queue");
        return myQueue.front();
    }

    T &back()
    {
        assert(!myQueue.empty() && "Cannot access back of an empty queue");
        return myQueue.back();
    }

    void pop()
    {
        assert(!myQueue.empty() && "Cannot pop from an empty queue");
        myQueue.pop_front();
    }

    void clear()
    {
        return myQueue.clear();
    }

    void display()
    {
        for (auto i : myQueue)
        {
            std::cout << i;
        }

        std::cout << std::endl;
    }
};

#endif // QUEUE_H