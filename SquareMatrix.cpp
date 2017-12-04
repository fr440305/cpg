// SquareMatrix.h {{

#ifndef SQUARE_MATRIX_H
#define SQUARE_MATRIX_H

#include <string>
#include <vector>
#include <istream>
#include <ostream>
#include <iostream>

class SquareMatrix {
public:
	std::vector<double> vct_;
	int rows_;

// Constructors:
	SquareMatrix (int rows);

	// If the length of `lst' is not a perfect square,
	// this function will throw an exception.
	SquareMatrix (std::initializer_list<double> lst);

	// If the length of `vct' is less than `rows * rows',
	// this function will throw an exception.
	// Else, if the length of `vct' is greater than `rows * rows',
	// this function will ignore the extra elements in the `vct'.
	SquareMatrix (const std::vector<double>& vct, int rows);

	// The exception and ignore behaviour of
	// this function is same as the function given above:
	// if `vct.size() < rows * rows' then throw an exception.
	// if `vct.size() > rows * rows' then ignore.
	SquareMatrix (std::istream ist, int rows);

// Stream Operators:
	friend std::ostream& operator << (const std::ostream ost, const SquareMatrix& m);
	friend std::istream& operator >> (const std::istream ist, const SquareMatrix& m);

// Row Operations:
	bool swap (unsigned int xrow, unsigned int yrow);
	void scale (double scaler, unsigned int row);
	bool xpay (unsigned int xrow, double scalar, unsigned int yrow);

// More Operations:
	bool operator == (const SquareMatrix& ano);
	bool operator != (const SquareMatrix& ano);
};

#endif


// }} SquareMatrix.cpp {{

// #include "SquareMatrix.h"
#include <vector>
#include <istream>
#include <ostream>
#include <cmath>

bool IsPerfectSquare (unsigned int nbr);

bool IsPerfectSquare (unsigned int nbr) {
	unsigned int p = static_cast<int>(floor(sqrt(nbr)));
	return (p * p == nbr);
}

// --ctor:

SquareMatrix::SquareMatrix (int rows):
rows_(rows),
vct_(rows) {}

SquareMatrix::SquareMatrix (std::initializer_list<double> lst):
vct_(lst),
rows_(vct_.size()) {
	if (!IsPerfectSquare(vct_.size())) {
		throw (std::string(
			"The length of the initializer_list is not a perfect square"
		));
	}
}

SquareMatrix::SquareMatrix (const std::vector<double>& vct, int rows):
vct_(vct),
rows_(rows) {
	if (vct.size() < rows * rows) {
		throw (std::string(
			"The length of `vct\' does not match with `rows\'"
		));
	}
}

SquareMatrix::SquareMatrix (const std::istream& ist, int rows) {
}

/*

// --ioop
std::istream& operator >> (const std::istream& ist, const SquareMatrix& m) {
	double a;
	return ist >> a;
}
std::ostream& operator << (const std::ostream& ost, const SquareMatrix& m) {
	return (ost << "SquareMatrix::<<");
}

// --mxop
bool SquareMatrix::swap (unsigned int xrow, unsigned int yrow) {
	if (xrow == 0 || xrow > rows_) {
		return false; // fail
	}
	unsigned int tmp;
	// ...
	return true;
}

void SquareMatrix::scale (double scaler, unsigned int row) {
}

bool SquareMatrix::xpay (unsigned int xrow, double scalar, unsigned int yrow) {
	return false;
}

// --eqne
bool SquareMatrix::operator == (const SquareMatrix& ano) {
	return true;
}

bool SquareMatrix::operator != (const SquareMatrix& ano) {
	return !((*this) == ano);
}

*/

// }} main.cpp {{



#include <iostream>

int main () {
	try {
		SquareMatrix m1 = {1, 2, 3};
		SquareMatrix m2 = {1, 2, 3, 4};
		std::vector<double> v = {10, 9, 8, 7, 6, 5};
		SquareMatrix m3(v, 2);
	} catch (std::string& e) {
		std::cout << e << std::endl;
	}
	return 0;
}


// }}
