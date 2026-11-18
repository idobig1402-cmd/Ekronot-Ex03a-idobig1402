#include "Vector.h"
#include <iostream>

Vector::Vector(int n)
{
	if(n < 2)
	{
		_resizeFactor = 2;
	}
	else
	{
		_resizeFactor = n;
	}

	_capacity = _resizeFactor;
	_size = 0;
	_elements = new int[_capacity];
}

Vector::~Vector()
{
	delete[] _elements;
	_elements = nullptr;
}

int Vector::size() const {
	return _size;
}

int Vector::capacity() const {
	return _capacity;
}

int Vector::resizeFactor() const {
	return _resizeFactor;
}

bool Vector::empty() const {
	return _size == 0;
}

void Vector::reserve(int n)
{
	if (n <= _capacity) {
		return;
	}

	while (_capacity < n) {
		_capacity += _resizeFactor;
	}

	int* newElements = new int[_capacity];

	for (int i = 0; i < _size; ++i) {
		newElements[i] = _elements[i];
	}

	delete[] _elements;

	_elements = newElements;

}

void Vector::push_back(const int& val)
{
	if (_size == _capacity) 
	{
		reserve(_capacity + _resizeFactor);
	}

	_elements[_size] = val;
	_size++;
}

int Vector::pop_back() 
{
	if (empty()) {
		std::cout << "error: pop from empty vector" << std::endl;
		return -9999;
	}

	_size--;
	return _elements[_size];
}

void Vector::resize(int n, const int& val) 
{
	if (n < 0) return;

	if (n <= _capacity) {
		for (int i = _size; i < n; ++i) {
			_elements[i] = val;
		}
		_size = n;
	}
	else {
		reserve(n);
		for (int i = _size; i < n; ++i) {
			_elements[i] = val;
		}
		_size = n;
	}
}

void Vector::assign(int val) 
{
	for (int i = 0; i < _size; ++i) {
		_elements[i] = val;
	}
}

Vector::Vector(const Vector& other) 
{
	_elements = nullptr;
	*this = other;
}

Vector& Vector::operator=(const Vector& other)
{
	if (this == &other) {
		return *this;
	}

	delete[] _elements;

	_size = other._size;
	_capacity = other._capacity;
	_resizeFactor = other._resizeFactor;

	_elements = new int[_capacity];
	for (int i = 0; i < _size; ++i)
	{
		_elements[i] = other._elements[i];
	}
}


int& Vector::operator[](int index) 
{
	if (index < 0 || index >= _size) 
	{
		std::cerr << "error: index out of bounds" << std::endl;
		return _elements[0];
	}
	return _elements[index];
}

const int& Vector::operator[](int index) const 
{
	if (index < 0 || index >= _size) 
	{
		std::cerr << "error: index out of bounds" << std::endl;
		return _elements[0];
	}
	return _elements[index];
}