# Priority Queue in C++

A **priority queue** is a data structure that allows efficient access to the highest (or lowest) priority element. By default, C++ implements it as a max-heap, where the largest element is always at the top. To sort elements from largest to smallest, use the default configuration. For sorting from smallest to largest, use a min-heap by combining `greater<T>` with the `priority_queue` template. This structure is ideal for tasks requiring prioritized access, such as shortest path algorithms and task scheduling.

Declare a priority queue with a min-heap (smallest to largest)
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;