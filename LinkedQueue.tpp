// LinkedQueue.tpp

template <typename T>
LinkedQueue<T>::LinkedQueue() : head(nullptr), last(nullptr) {
    this->length = 0;
}

template <typename T>
LinkedQueue<T>::LinkedQueue(const LinkedQueue<T>& copyObj) : head(nullptr), last(nullptr) {
    this->length = 0;
    copy(copyObj);
}

template <typename T>
LinkedQueue<T>& LinkedQueue<T>::operator=(const LinkedQueue<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
LinkedQueue<T>::~LinkedQueue() {
    clear();
}

template <typename T>
T LinkedQueue<T>::back() const {
    if (isEmpty()) {
        throw string("Queue is empty");
    }
    return last->value;
}

template <typename T>
void LinkedQueue<T>::clear() {
    Node* cur = head;
    while (cur) {
        Node* nxt = cur->next;
        delete cur;
        cur = nxt;
    }
    head = last = nullptr;
    this->length = 0;
}

template <typename T>
void LinkedQueue<T>::copy(const LinkedQueue<T>& copyObj) {
    // assumes current queue is empty
    Node* cur = copyObj.head;
    while (cur) {
        enqueue(cur->value);
        cur = cur->next;
    }
}

template <typename T>
void LinkedQueue<T>::dequeue() {
    if (isEmpty()) {
        throw string("Queue is empty");
    }
    Node* old = head;
    head = head->next;
    delete old;
    --this->length;
    if (this->length == 0) {
        last = nullptr;
    }
}

template <typename T>
void LinkedQueue<T>::enqueue(const T& elem) {
    Node* n = new Node(elem, nullptr);
    if (isEmpty()) {
        head = last = n;
    } else {
        last->next = n;
        last = n;
    }
    ++this->length;
}

template <typename T>
T LinkedQueue<T>::front() const {
    if (isEmpty()) {
        throw string("Queue is empty");
    }
    return head->value;
}

template <typename T>
int LinkedQueue<T>::getLength() const {
    return this->length;
}

template <typename T>
bool LinkedQueue<T>::isEmpty() const {
    return this->length == 0;
}
