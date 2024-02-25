#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;


class StackArray{
    int* stack;
    int top;
    int size;

public:
    StackArray(int size){
        this->size = size;
        stack = new int[size];
        top = -1;
    }

    void push(int value){
        top++;
        if (top>size){
            cout << "Stack Overflow" << endl;
        }else{
            stack[top] = value;
        }
    }
    int pop(){
        if(isEmpty()){
            cout << "Stack Underflow" << endl;
        } else {
            top--;
            return stack[top+1];
        }
    }
    bool isEmpty(){
        if(top == -1){
            return true;
        } else {
            return false;
        }
    }
    bool isFull(){
        if(top == size-1){
            return true;
        } else {
            return false;
        }
    }
    int stackTop(){
        if (isEmpty()){
            return INT_MIN;
        } else{
            return stack[top];
        }
    }
    void display(){
        for(int i = top; i >= 0; i--){
            cout << stack[i] << " ";
        }
        cout << endl;
    }
};

class Node{
public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        next = nullptr;
    }
};

class StackLinkedList {
    Node* top;
    Node* head;
    int size{};
public:
    StackLinkedList() {
        top = nullptr;
        head = nullptr;
    }

    void push(int value) {
        if (isEmpty()){
            Node* newNode = new Node(value);
            top = newNode;
            head = newNode;
        } else {
            Node* newNode = new Node(value);
            top->next = newNode;
            top = newNode;
        }
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow" << endl;
            return 0;
        } else {
            int x = top->data;
            if (top == head){
                head = nullptr;
                top = nullptr;
            }else{
                Node* temp = head;
                while (temp->next != top){
                    temp = temp->next;
                }
                temp->next = nullptr;
                top = temp;
            }
            return x;
        }
    }

    bool isEmpty() {
        if (top == nullptr) {
            return true;
        } else {
            return false;
        }
    }

    int stackTop() {
        if (top == nullptr) {
            return INT_MIN;
        } else {
            return top->data;
        }
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;

    }


};

int main() {
    auto start_ll = high_resolution_clock::now();
    StackLinkedList stack;
    stack.push(10);
    stack.push(5);
    stack.push(11);
    stack.push(15);
    stack.push(23);
    stack.push(6);
    stack.push(18);
    stack.push(20);
    stack.push(17);
    stack.display();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.display();
    stack.push(4);
    stack.push(30);
    stack.push(3);
    stack.push(1);
    stack.display();
    auto stop_ll = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop_ll - start_ll);
    cout << "Time taken: " << duration.count() << " microseconds" << endl;

    auto start_arr = high_resolution_clock::now();
    StackArray stack_arr(15);
    stack_arr.push(8);
    stack_arr.push(10);
    stack_arr.push(5);
    stack_arr.push(11);
    stack_arr.push(15);
    stack_arr.push(23);
    stack_arr.push(6);
    stack_arr.push(18);
    stack_arr.push(20);
    stack_arr.push(17);
    stack_arr.display();
    stack_arr.pop();
    stack_arr.pop();
    stack_arr.pop();
    stack_arr.pop();
    stack_arr.pop();
    stack_arr.display();
    stack_arr.push(4);
    stack_arr.push(30);
    stack_arr.push(3);
    stack_arr.push(1);
    stack_arr.display();
    auto stop_arr = high_resolution_clock::now();
    auto duration_arr = duration_cast<microseconds>(stop_arr - start_arr);
    cout << "Time taken: " << duration_arr.count() << " microseconds" << endl;



    return 0;
}
