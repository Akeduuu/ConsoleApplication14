#include <iostream>  
#include <сmath>  
using namespace std;
class сomplex // класс комплексных чисел  
{
	double re, im; // целая и мнимая части  

	// создаем конструкторы   
public:

	сomplex() {};

	сomplex(double r) // конструктор по умолчанию  
	{
		re = r;
		im = 0;
	}

	сomplex(double r, double i) // конструктор по умолчанию  
	{
		re = r;
		im = i;
	}

	сomplex(сomplex& c) // конструктор копирования  
	{
		re = c.re;
		im = c.im;
	}

	~сomplex() {}

	float abs() // Модуль комплексного числа  
	{
		return sqrt(re * re - im * im);
	}

	сomplex& operator = (сomplex& c) // перегрузка оператора присваивания  
	{
		re = c.re;
		im = c.im;

		return (*this);
	}

	сomplex сomplex::operator + (сomplex& c) // перегрузка оператора сложения  
	{
		сomplex temp;

		temp.re = re + c.re;
		temp.im = im + c.re;

		return temp;
	}

	сomplex сomplex::operator - (сomplex& c) // перегрузка оператора вычитания  
	{
		сomplex temp;

		temp.re = re - c.re;
		temp.im = im - c.re;

		return temp;
	}

	сomplex сomplex::operator * (сomplex& c) // перегрузка оператора умножения  
	{
		сomplex temp;

		temp.re = re * c.re;
		temp.im = re * c.im;

		return temp;
	}

	сomplex сomplex::operator / (сomplex& c) // перегрузка оператора деления  
	{
		сomplex temp;

		double r = c.re * c.re + c.im * c.im;
		temp.re = (re * c.re + im * c.im) / r;
		temp.re = (im * c.re - re * c.im) / r;

		return temp;
	}

	friend ostream& operator<<(ostream&, сomplex); // перегрузка оператора <<  
	friend istream& operator>>(istream&, сomplex); // перегрузка оператора >>  

};

ostream& operator<<(ostream& out, complex& c)
{
	out << "(" << c.re << "," << c.im << ")";

	return out;
}

istream& operator>>(istream& in, сomplex& c)
{
	in >> c.re >> c.im;

	return in;
}

int main()
{
	сomplex value1(5, 2);
	сomplex value2(3, -3);

	cout << value1 << " " << value2 << endl;

	cout << value1 + value2 << endl;

	cout << value1 - value2 << endl;

	cout << value1 * value2 << endl;

	cout << value1 / value2 << endl;

	value1 = value2;

	cout << value1 << " = " << value2 << endl;

	return 0;
}