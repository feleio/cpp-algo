#ifndef VECTOR_H
#define VECTOR_H

#include <cstddef>
#include <queue>

template <class T>
class Vector{
public:
	Vector():m_buffer(NULL), m_size(0), m_capacity(1){
		m_buffer = new T[m_capacity];
	}
	
	~Vector(){
		delete[] m_buffer;
	}
	
	void push_back(const T& t){
		if(m_size >= m_capacity){
			T* newBuffer = new T[m_capacity*2];
			for(int i=0;i<m_size;++i){
				newBuffer[i] = m_buffer[i];
			}
			delete[] m_buffer;
			m_buffer = newBuffer;
			m_capacity *= 2;
		}
		m_buffer[m_size++] = t;
	}
	
	T& operator[](size_t i){
		return m_buffer[i];
	}
	
	const T& operator[](size_t i) const{
		return m_buffer[i];
	}
	
	std::size_t size() const{
		return m_size;
	}
	
	std::size_t capacity() const{
		return m_capacity;
	}

private:
	T* m_buffer;
	std::size_t m_size;
	std::size_t m_capacity;
};

#endif