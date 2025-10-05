#ifndef QUEUETYPE_H
#define QUEUETYPE_H

#include <cstddef>
#include <stdexcept>

template <class Type>
class queueType {
public:
    explicit queueType(std::size_t size = 100)
        : maxQueueSize(size ? size : 1),
          count(0),
          queueFront(0),
          queueRear(maxQueueSize - 1),
          list(new Type[maxQueueSize]) {}

    queueType(const queueType& other)
        : maxQueueSize(other.maxQueueSize),
          count(other.count),
          queueFront(other.queueFront),
          queueRear(other.queueRear),
          list(new Type[maxQueueSize]) {
        for (std::size_t i = 0; i < maxQueueSize; ++i) {
            list[i] = other.list[i];
        }
    }

    queueType& operator=(const queueType& other) {
        if (this != &other) {
            queueType temp(other);
            swap(temp);
        }
        return *this;
    }

    queueType(queueType&& other) noexcept
        : maxQueueSize(other.maxQueueSize),
          count(other.count),
          queueFront(other.queueFront),
          queueRear(other.queueRear),
          list(other.list) {
        other.list = nullptr;
        other.maxQueueSize = 0;
        other.count = 0;
        other.queueFront = 0;
        other.queueRear = 0;
    }

    queueType& operator=(queueType&& other) noexcept {
        if (this != &other) {
            delete[] list;
            maxQueueSize = other.maxQueueSize;
            count = other.count;
            queueFront = other.queueFront;
            queueRear = other.queueRear;
            list = other.list;
            other.list = nullptr;
            other.maxQueueSize = 0;
            other.count = 0;
            other.queueFront = 0;
            other.queueRear = 0;
        }
        return *this;
    }

    ~queueType() { delete[] list; }

    bool isEmptyQueue() const noexcept { return count == 0; }

    bool isFullQueue() const noexcept { return count == maxQueueSize; }

    void initializeQueue() noexcept {
        count = 0;
        queueFront = 0;
        queueRear = maxQueueSize - 1;
    }

    Type front() const {
        if (isEmptyQueue()) {
            throw std::underflow_error("Queue is empty.");
        }
        return list[queueFront];
    }

    Type back() const {
        if (isEmptyQueue()) {
            throw std::underflow_error("Queue is empty.");
        }
        return list[queueRear];
    }

    std::size_t size() const noexcept { return count; }

    std::size_t capacity() const noexcept { return maxQueueSize; }

    void addQueue(const Type& newElement) {
        if (isFullQueue()) {
            throw std::overflow_error("Queue is full.");
        }
        queueRear = (queueRear + 1) % maxQueueSize;
        list[queueRear] = newElement;
        ++count;
    }

    void deleteQueue() {
        if (isEmptyQueue()) {
            throw std::underflow_error("Queue is empty.");
        }
        queueFront = (queueFront + 1) % maxQueueSize;
        --count;
    }

private:
    void swap(queueType& other) noexcept {
        std::swap(maxQueueSize, other.maxQueueSize);
        std::swap(count, other.count);
        std::swap(queueFront, other.queueFront);
        std::swap(queueRear, other.queueRear);
        std::swap(list, other.list);
    }

    std::size_t maxQueueSize;
    std::size_t count;
    std::size_t queueFront;
    std::size_t queueRear;
    Type* list;
};

#endif // QUEUETYPE_H