#include<iostream>
#include<exception>
#include"Vector.h"
using namespace std;

double division(double a, double b) {
	if (b == 0) throw runtime_error("divion by zero!!!");
	return a / b;
}

//чтобы увидеть все имеющиеся библиотеки:
//название проекта "Решение ..." правой кнопкой - свойства - исходные файлы отладки - верхнюю строку копируем (адрес) и вставлем в проводник - откроется список библиотек

int main() {

	//int a;
	//cin >> a;

	//try {
	//	if (a > 0)
	//		throw out_of_range("a is negative");//"a is positive";//the way how to handle an exception
	//	//out_of_range дочерний класс класса exception
	//	else if (a == 0)
	//		throw "a is 0";
	//	else
	//		throw 404;//or "a is negative"

	//}
	////catch может быть сколько угодно, для каждого типа ошибки (int, const char*) свой catch!
	//catch (const char *c) {//если используем текст для возвращения, то всегда const char*, а если указатель то просто char*
	//	cout << c << endl;
	//}
	//catch (out_of_range obj) {
	//	cout << obj.what() << endl; //what() - общая функция класса exception для всех исключений, показывает что именно вывести, какое сообщение
	//}
	//catch (int a) {
	//	cout << "Integer type error with code " << a << endl;
	//}

	//double a, b;
	//try {
	//	cin >> a >> b;
	//	double r = division(a, b);
	//	cout << r * 10 << endl;
	//}
	//catch (runtime_error err){ //обработчик для типа ошибки runtime_error, т.е. как именно обработать исключение при улове в функции division
	//	cout << "Runtime error: " << err.what() << endl;
	//}



	my_vector<int> mv; //обязательно подключить СВОЙ класс вектор, с обработкой исключения!
	for (int i = 0; i < 5; i++)
		mv.push_back(i);
	
	//тест
	try {
		for (int i = 0; i < 10; i++)
			cout << mv[i] << endl;
	}
	//улавливаем
	catch (out_of_range err) {//err - псевдоним
		cout << err.what();
	}

	try {
		cout << mv[-3] << endl;
	}
	catch (out_of_range err) {
		cout << err.what();
	}

	//после try-catch остальная прога спокойно работает дальше
	cout << mv[2] << endl;

	system("pause");
	return 0;
}