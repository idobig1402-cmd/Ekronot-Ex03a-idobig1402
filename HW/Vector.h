#ifndef VECTOR_H
#define VECTOR_H

class Vector
{
private:
    int* _elements;
    int _size;
    int _capacity;
    int _resizeFactor;

public:
    Vector(int n);
    ~Vector();

    int size() const;
    int capacity() const;
    int resizeFactor() const;
    bool empty() const;

    void reserve(int n);
    void push_back(const int& val);
    int pop_back();
    void resize(int n, const int& val);
    void assign(int val);

    Vector(const Vector& other);
    Vector& operator=(const Vector& other);

    int& operator[](int index);
    const int& operator[](int index) const;
};

#endif