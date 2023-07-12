#pragma once
class LQueue{
private:
    struct Node {
        int data;
        Node* next;
    };

    Node* frontNode;
    Node* backNode;

public:
    LQueue();
    ~LQueue();

    void Enqueue(int value);
    void Dequeue();
    int Front();
    int Back();
    bool IsEmpty();
};

