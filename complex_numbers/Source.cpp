#include <iostream>

using namespace std;

class Complex {
public:
	float Re, Im;

	void input() {
		cout << "z (real) = ";
		cin >> Re;
		cout << "z (imaginary) = ";
		cin >> Im;
		cout << endl;
	}

	void print() {
		if (Im == 0 && Re == 0)
			cout << 0 << "  -- Complex number equal zero" << endl;
		else if (Im == 0)
			cout << Re << "  -- Real number" << endl;
		else if (Re == 0)
			cout << Im << " * i" << "  -- Imaginary number" << endl;
		else if (Im > 0)
			cout << Re << " + " << Im << " * i" << endl;
		else if (Im < 0)
			cout << Re << " - " << (-1) * Im << " * i" << endl;
	}

	Complex operator+(Complex a) {
		Complex c;
		c.Re = a.Re + Re;
		c.Im = a.Im + Im;
		return c;
	}

	Complex operator-(Complex a) {
		Complex c;
		c.Re = Re - a.Re;
		c.Im = Im - a.Im;
		return c;
	}

	Complex operator*(Complex a) {
		Complex c;
		c.Re = Re * a.Re - Im * a.Im;
		c.Im = Re * a.Im + a.Re * Im;
		return c;
	}

	Complex operator/(Complex a) {
		Complex c;
		if (a.Re * a.Re + a.Im * a.Im != 0) {
			c.Re = (Re * a.Re + Im * a.Im) / (a.Re * a.Re + a.Im * a.Im);
			c.Im = (a.Re * Im - Re * a.Im) / (a.Re * a.Re + a.Im * a.Im);
			return c;
		}
		else {
			c.Re = NULL;
			c.Im = NULL;
			return c;
		}
	}
};


int main() {
	Complex a, b, c;
	cout << "Input two complex value:\n";
	a.input();
	b.input();

	cout << "z = z1 + z2 = ";
	c = a + b;
	c.print();

	cout << "z = z1 - z2 = ";
	c = a - b;
	c.print();

	cout << "z = z1 * z2 = ";
	c = a * b;
	c.print();

	cout << "z = z1 / z2 = ";
	c = a / b;
	if (c.Re != NULL)
		c.print();
	else
		cout << "Division by zero!" << endl;
}