#include <iostream>
using namespace std;

class DynamicArray {
public:
    int *arr;
    int length;
    int capacity;

    DynamicArray(int capacity) : capacity(capacity), length(0) {
        arr = new int[capacity];
    }

    int get(int i) {
        return arr[i];
    }

    void set(int i, int n) {
        arr[i] = n;
    }

    void pushback(int n) {
        if (length == capacity)
        {
            resize();
        }
        arr[length] = n;
        length++;
    }

    int popback() {
        if (length > 0)
            length--;
        return arr[length];
    }

    void resize() {
        int *newArr;
        capacity *= 2;
        newArr = new int[capacity];

        for (int i = 0; i < length; i++)
        {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
    }

    int getSize() {
        return length;
    }

    int getCapacity() {
        return capacity;
    }
};

int main() {
    DynamicArray array(1);
    array.pushback(1);
    cout << array.getCapacity() << endl;
    array.pushback(2);
    cout << array.getCapacity() << endl;
}