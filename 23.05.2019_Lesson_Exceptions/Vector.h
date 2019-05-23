#pragma once
#include <iostream>
#include<vector>
#include<exception>
using namespace std;

out_of_range upper("out of upper bound\n");
out_of_range lower("out of lower bound\n");

template <typename T>
class my_vector : public vector<T> {//обязательно наследуем от шаблонного vector<T>
public:
	T& operator[](int index);
};

template<typename T>
inline T & my_vector<T>::operator[](int index)throw()// явно пропишем что будем обрабатывать исключение - throw()
{
	//при обработке исключений, порядок условий СТРОГИЙ - логично должны быть расставлены, сначала меньше нуля, затем больше или равно, иначе будет вылетать на первом же условии
	if (index < 0)
		throw lower;
	else if (index >= this->size())
		throw upper;//name (upper), type (out_of range) and what() - "out upper bound\n"
	return this->at(index); //at() готовый метод для возвращения элемента по индексу
}
