#include<iostream>
#include<exception>
using namespace std;

int main() {

	int a;
	cin >> a;

	try {
		if (a > 0)
			throw "a is positive";//the way how to handle an exception
		else if (a == 0)
			throw "a is 0";
		else
			throw 404;//or "a is negative"

	}
	//catch может быть сколько угодно, для каждого типа ошибки (int, const char*) свой catch!
	catch (const char *c) {//если используем текст для возвращения, то всегда const char*, а если указатель то просто char*
		cout << c << endl;
	}
	catch (int a) {
		cout << "Integer type error with code " << a << endl;
	}

	system("pause");
	return 0;
}