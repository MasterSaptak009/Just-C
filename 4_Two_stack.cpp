#include <iostream>

class TwoStacks {
private:
    int* arr;
    int size;
    int top1;
    int top2;

public:
    TwoStacks(int size) {
        this->size = size;
        arr = new int[size];
        top1 = -1;
        top2 = size;
    }

    ~TwoStacks() {
        delete[] arr;
    }

    void push1(int value) {
        if (top1 < top2 - 1) {
            arr[++top1] = value;
        } else {
            std::cout << "Stack 1 overflow\n";
        }
    }

    void push2(int value) {
        if (top1 < top2 - 1) {
            arr[--top2] = value;
        } else {
            std::cout << "Stack 2 overflow\n";
        }
    }

    int pop1() {
        if (top1 >= 0) {
            return arr[top1--];
        } else {
            std::cout << "Stack 1 underflow\n";
            return -1;  // Assuming -1 as an error value
        }
    }

    int pop2() {
        if (top2 < size) {
            return arr[top2++];
        } else {
            std::cout << "Stack 2 underflow\n";
            return -1;  // Assuming -1 as an error value
        }
    }
};

int main() {
    TwoStacks twoStacks(5);

    twoStacks.push1(1);
    twoStacks.push2(2);
    twoStacks.push1(3);
    twoStacks.push2(4);
    twoStacks.push1(5);

    std::cout << "Popped element from stack 1: " << twoStacks.pop1() << "\n";
    std::cout << "Popped element from stack 2: " << twoStacks.pop2() << "\n";

    return 0;
}
