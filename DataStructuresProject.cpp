#include <iostream>
#include <stdexcept>
#include <vector>
#include <list>
#include <string>

using namespace std;

// Stack class
template <typename T>
class StackNode {
public:
    T data;
    StackNode<T>* next;

    StackNode(T data) : data(data), next(nullptr) {}
};

template <typename T>
class Stack {
private:
    StackNode<T>* top;

public:
    Stack() : top(nullptr) {}

    void Push(T item) {
        StackNode<T>* newNode = new StackNode<T>(item);
        newNode->next = top;
        top = newNode;
    }

    T Pop() {
        if (!top) {
            throw runtime_error("Stack is empty.");
        }
        T item = top->data;
        StackNode<T>* temp = top;
        top = top->next;
        delete temp;
        return item;
    }

    T Peek() {
        if (!top) {
            throw runtime_error("Stack is empty.");
        }
        return top->data;
    }

    int Count() {
        int count = 0;
        StackNode<T>* current = top;
        while (current) {
            count++;
            current = current->next;
        }
        return count;
    }

    void Clear() {
        while (top) {
            StackNode<T>* temp = top;
            top = top->next;
            delete temp;
        }
    }

    void Display() {
        StackNode<T>* current = top;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

// Queue class
template <typename T>
class QueueNode {
public:
    T data;
    QueueNode<T>* next;

    QueueNode(T data) : data(data), next(nullptr) {}
};

template <typename T>
class Queue {
private:
    QueueNode<T>* front;
    QueueNode<T>* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    void Enqueue(T item) {
        QueueNode<T>* newNode = new QueueNode<T>(item);
        if (!rear) {
            front = rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    T Dequeue() {
        if (!front) {
            throw runtime_error("Queue is empty.");
        }
        T item = front->data;
        QueueNode<T>* temp = front;
        front = front->next;
        if (!front) {
            rear = nullptr;
        }
        delete temp;
        return item;
    }

    T Peek() {
        if (!front) {
            throw runtime_error("Queue is empty.");
        }
        return front->data;
    }

    int Count() {
        int count = 0;
        QueueNode<T>* current = front;
        while (current) {
            count++;
            current = current->next;
        }
        return count;
    }

    void Clear() {
        while (front) {
            QueueNode<T>* temp = front;
            front = front->next;
            delete temp;
        }
        rear = nullptr;
    }

    void Display() {
        QueueNode<T>* current = front;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

// Singly Linked List class
template <typename T>
class LinkedListNode {
public:
    T data;
    LinkedListNode<T>* next;

    LinkedListNode(T data) : data(data), next(nullptr) {}
};

template <typename T>
class SinglyLinkedList {
private:
    LinkedListNode<T>* head;

public:
    SinglyLinkedList() : head(nullptr) {}

    void Add(T item) {
        LinkedListNode<T>* newNode = new LinkedListNode<T>(item);
        if (!head) {
            head = newNode;
        }
        else {
            LinkedListNode<T>* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    bool Remove(T item) {
        if (!head) {
            return false;
        }
        if (head->data == item) {
            LinkedListNode<T>* temp = head;
            head = head->next;
            delete temp;
            return true;
        }
        LinkedListNode<T>* temp = head;
        while (temp->next && temp->next->data != item) {
            temp = temp->next;
        }
        if (temp->next) {
            LinkedListNode<T>* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
            return true;
        }
        return false;
    }

    bool Contains(T item) {
        LinkedListNode<T>* temp = head;
        while (temp) {
            if (temp->data == item) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    int Count() {
        int count = 0;
        LinkedListNode<T>* temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void Clear() {
        while (head) {
            LinkedListNode<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void Display() {
        LinkedListNode<T>* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// Binary Search Tree class
template <typename T>
class BinarySearchTree {
private:
    class Node {
    public:
        T data;
        Node* left;
        Node* right;

        Node(T data) : data(data), left(nullptr), right(nullptr) {}
    };
    Node* root;

    void Insert(Node*& node, T item) {
        if (!node) {
            node = new Node(item);
        }
        else if (item < node->data) {
            Insert(node->left, item);
        }
        else {
            Insert(node->right, item);
        }
    }

    bool Search(Node* node, T item) {
        if (!node) {
            return false;
        }
        else if (node->data == item) {
            return true;
        }
        else if (item < node->data) {
            return Search(node->left, item);
        }
        else {
            return Search(node->right, item);
        }
    }

    void Clear(Node*& node) {
        if (node) {
            Clear(node->left);
            Clear(node->right);
            delete node;
            node = nullptr;
        }
    }

    int Count(Node* node) {
        if (!node) {
            return 0;
        }
        return 1 + Count(node->left) + Count(node->right);
    }

    void DisplayInOrder(Node* node) {
        if (node) {
            DisplayInOrder(node->left);
            cout << node->data << " ";
            DisplayInOrder(node->right);
        }
    }

    void DisplayPreOrder(Node* node) {
        if (node) {
            cout << node->data << " ";
            DisplayPreOrder(node->left);
            DisplayPreOrder(node->right);
        }
    }

    void DisplayPostOrder(Node* node) {
        if (node) {
            DisplayPostOrder(node->left);
            DisplayPostOrder(node->right);
            cout << node->data << " ";
        }
    }

public:
    BinarySearchTree() : root(nullptr) {}

    void Insert(T item) {
        Insert(root, item);
    }

    bool Search(T item) {
        return Search(root, item);
    }

    void Clear() {
        Clear(root);
    }

    int Count() {
        return Count(root);
    }

    void DisplayInOrder() {
        DisplayInOrder(root);
        cout << endl;
    }

    void DisplayPreOrder() {
        DisplayPreOrder(root);
        cout << endl;
    }

    void DisplayPostOrder() {
        DisplayPostOrder(root);
        cout << endl;
    }
};

// Hash Table class
template <typename K, typename V>
class HashTable {
private:
    vector<list<pair<K, V>>> items;
    int hashFunction(K key) {
        return key % items.size();
    }

public:
    HashTable(int size) : items(size) {}

    void Add(K key, V value) {
        int position = hashFunction(key);
        auto& linkedList = items[position];
        for (auto& item : linkedList) {
            if (item.first == key) {
                item.second = value;
                return;
            }
        }
        linkedList.emplace_back(key, value);
    }

    void Remove(K key) {
        int position = hashFunction(key);
        auto& linkedList = items[position];
        linkedList.remove_if([key](const pair<K, V>& item) { return item.first == key; });
    }

    V Get(K key) {
        int position = hashFunction(key);
        auto& linkedList = items[position];
        for (const auto& item : linkedList) {
            if (item.first == key) {
                return item.second;
            }
        }
        throw runtime_error("Key not found.");
    }

    int Count() {
        int count = 0;
        for (const auto& linkedList : items) {
            count += linkedList.size();
        }
        return count;
    }

    void Clear() {
        for (auto& linkedList : items) {
            linkedList.clear();
        }
    }

    void Display() {
        for (const auto& linkedList : items) {
            for (const auto& item : linkedList) {
                cout << "Key: " << item.first << ", Value: " << item.second << endl;
            }
        }
    }
};

void StackMenu(Stack<int>& stack) {
    while (true) {
        cout << "Stack Operations:" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Clear" << endl;
        cout << "5. Count" << endl;
        cout << "6. Display" << endl;
        cout << "7. Back" << endl;
        int op;
        cin >> op;

        switch (op) {
        case 1: {
            cout << "Enter value to push: ";
            int val;
            cin >> val;
            stack.Push(val);
            break;
        }
        case 2: {
            try {
                int val = stack.Pop();
                cout << "Popped value: " << val << endl;
            }
            catch (runtime_error& e) {
                cout << e.what() << endl;
            }
            break;
        }
        case 3: {
            try {
                int val = stack.Peek();
                cout << "Top value: " << val << endl;
            }
            catch (runtime_error& e) {
                cout << e.what() << endl;
            }
            break;
        }
        case 4: {
            stack.Clear();
            cout << "Stack cleared." << endl;
            break;
        }
        case 5: {
            int count = stack.Count();
            cout << "Stack count: " << count << endl;
            break;
        }
        case 6: {
            stack.Display();
            break;
        }
        case 7: {
            return;
        }
        default: {
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
        }
    }
}

// Queue class and menu function
template <typename T>
class Queue;

template <typename T>
void QueueMenu(Queue<T>& queue) {
    while (true) {
        cout << "Queue Operations:" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Clear" << endl;
        cout << "5. Count" << endl;
        cout << "6. Display" << endl;
        cout << "7. Back" << endl;
        int op;
        cin >> op;

        switch (op) {
        case 1: {
            cout << "Enter value to enqueue: ";
            T val;
            cin >> val;
            queue.Enqueue(val);
            break;
        }
        case 2: {
            try {
                T val = queue.Dequeue();
                cout << "Dequeued value: " << val << endl;
            }
            catch (runtime_error& e) {
                cout << e.what() << endl;
            }
            break;
        }
        case 3: {
            try {
                T val = queue.Peek();
                cout << "Front value: " << val << endl;
            }
            catch (runtime_error& e) {
                cout << e.what() << endl;
            }
            break;
        }
        case 4: {
            queue.Clear();
            cout << "Queue cleared." << endl;
            break;
        }
        case 5: {
            int count = queue.Count();
            cout << "Queue count: " << count << endl;
            break;
        }
        case 6: {
            queue.Display();
            break;
        }
        case 7: {
            return;
        }
        default: {
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
        }
    }
}

// Singly Linked List class and menu function
template <typename T>
class SinglyLinkedList;

template <typename T>
void SinglyLinkedListMenu(SinglyLinkedList<T>& sll) {
    while (true) {
        cout << "Singly Linked List Operations:" << endl;
        cout << "1. Add" << endl;
        cout << "2. Remove" << endl;
        cout << "3. Contains" << endl;
        cout << "4. Count" << endl;
        cout << "5. Clear" << endl;
        cout << "6. Display" << endl;
        cout << "7. Back" << endl;
        int op;
        cin >> op;

        switch (op) {
        case 1: {
            cout << "Enter value to add: ";
            T val;
            cin >> val;
            sll.Add(val);
            break;
        }
        case 2: {
            cout << "Enter value to remove: ";
            T val;
            cin >> val;
            if (sll.Remove(val)) {
                cout << "Value removed." << endl;
            }
            else {
                cout << "Value not found." << endl;
            }
            break;
        }
        case 3: {
            cout << "Enter value to check: ";
            T val;
            cin >> val;
            if (sll.Contains(val)) {
                cout << "Value exists." << endl;
            }
            else {
                cout << "Value not found." << endl;
            }
            break;
        }
        case 4: {
            int count = sll.Count();
            cout << "List count: " << count << endl;
            break;
        }
        case 5: {
            sll.Clear();
            cout << "List cleared." << endl;
            break;
        }
        case 6: {
            sll.Display();
            break;
        }
        case 7: {
            return;
        }
        default: {
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
        }
    }
}

// Binary Search Tree class and menu function
template <typename T>
class BinarySearchTree;

template <typename T>
void BinarySearchTreeMenu(BinarySearchTree<T>& bst) {
    while (true) {
        cout << "Binary Search Tree Operations:" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Search" << endl;
        cout << "3. Clear" << endl;
        cout << "4. Count" << endl;
        cout << "5. Display InOrder" << endl;
        cout << "6. Display PreOrder" << endl;
        cout << "7. Display PostOrder" << endl;
        cout << "8. Back" << endl;
        int op;
        cin >> op;
        switch (op) {
        case 1: {
            cout << "Enter value to insert: ";
            T val;
            cin >> val;
            bst.Insert(val);
            break;
        }
        case 2: {
            cout << "Enter value to search: ";
            T val;
            cin >> val;
            if (bst.Search(val)) {
                cout << "Value found." << endl;
            }
            else {
                cout << "Value not found." << endl;
            }
            break;
        }
        case 3: {
            bst.Clear();
            cout << "Tree cleared." << endl;
            break;
        }
        case 4: {
            int count = bst.Count();
            cout << "Tree node count: " << count << endl;
            break;
        }
        case 5: {
            bst.DisplayInOrder();
            break;
        }
        case 6: {
            bst.DisplayPreOrder();
            break;
        }
        case 7: {
            bst.DisplayPostOrder();
            break;
        }
        case 8: {
            return;
        }
        default: {
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
        }
    }
}

// Hash Table class and menu function
template <typename K, typename V>
class HashTable;

template <typename K, typename V>
void HashTableMenu(HashTable<K, V>& hashTable) {
    while (true) {
        cout << "Hash Table Operations:" << endl;
        cout << "1. Add" << endl;
        cout << "2. Remove" << endl;
        cout << "3. Get" << endl;
        cout << "4. Count" << endl;
        cout << "5. Clear" << endl;
        cout << "6. Display" << endl;
        cout << "7. Back" << endl;
        int op;
        cin >> op;
        switch (op) {
        case 1: {
            cout << "Enter key-value pair to add (key value): ";
            K key;
            V value;
            cin >> key >> value;
            hashTable.Add(key, value);
            break;
        }
        case 2: {
            cout << "Enter key to remove: ";
            K key;
            cin >> key;
            hashTable.Remove(key);
            break;
        }
        case 3: {
            cout << "Enter key to get value: ";
            K key;
            cin >> key;
            try {
                V value = hashTable.Get(key);
                cout << "Value: " << value << endl;
            }
            catch (runtime_error& e) {
                cout << e.what() << endl;
            }
            break;
        }
        case 4: {
            int count = hashTable.Count();
            cout << "Hash Table item count: " << count << endl;
            break;
        }
        case 5: {
            hashTable.Clear();
            cout << "Hash Table cleared." << endl;
            break;
        }
        case 6: {
            hashTable.Display();
            break;
        }
        case 7: {
            return;
        }
        default: {
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
        }
    }
}

void MainMenu() {
    Stack<int> stack;
    Queue<int> queue;
    SinglyLinkedList<int> sll;
    BinarySearchTree<int> bst;
    HashTable<int, string> hashTable(10);
    while (true) {
        cout << "Main Menu:" << endl;
        cout << "1. Stack" << endl;
        cout << "2. Queue" << endl;
        cout << "3. Singly Linked List" << endl;
        cout << "4. Binary Search Tree" << endl;
        cout << "5. Hash Table" << endl;
        cout << "6. Exit" << endl;
        int choice;
        cin >> choice;

        switch (choice) {
        case 1: {
            StackMenu(stack);
            break;
        }
        case 2: {
            QueueMenu(queue);
            break;
        }
        case 3: {
            SinglyLinkedListMenu(sll);
            break;
        }
        case 4: {
            BinarySearchTreeMenu(bst);
            break;
        }
        case 5: {
            HashTableMenu(hashTable);
            break;
        }
        case 6: {
            return;
        }
        default: {
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
        }
    }
}

int main() {
    MainMenu();
    return 0;
}