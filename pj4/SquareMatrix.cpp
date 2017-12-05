#include "SquareMatrix.h"
#include <vector>
#include <string>
#include <istream>
//#include <iostream>
#include <sstream>
#include <cmath>

bool IsPerfectSquare (unsigned int nbr);

bool IsPerfectSquare (unsigned int nbr) {
	unsigned int p = static_cast<int>(floor(sqrt(nbr)));
	return (p * p == nbr);
}

// --ctor:

SquareMatrix::SquareMatrix (unsigned int rows): rows_(rows), vct_(rows * rows) {
}

SquareMatrix::SquareMatrix (std::initializer_list<double> lst): vct_(lst) {
	if (!IsPerfectSquare(vct_.size())) {
		throw (std::string(
			"SquareMatrix::SquareMatrix (std::initializer_list<double>): "
			"The length of the initializer_list is not a perfect square"
		));
	} else {
		rows_ = static_cast<unsigned int>(floor(sqrt(vct_.size())));
	}
}

SquareMatrix::SquareMatrix (
	const std::vector<double>& vct, unsigned int rows
): vct_(vct), rows_(rows) {
	if (vct.size() < rows * rows) {
		throw (std::string(
			"SquareMatrix::SquareMatrix (const std::vector<double>&, int): "
			"The length of `vct\' does not match with `rows\'"
		));
	}
}

// Note: cannot write `const std::istream&' instead of `std::istream&' or
// `std::istream'
// Note: Do not use istringstream.
SquareMatrix::SquareMatrix (std::istream& ist, unsigned int rows) {
	int rest = rows * rows;
	double el;
	rows_ = rows;
	while (rest > 0) {
		if (ist >> el) {
			vct_.push_back(el);
			rest -= 1;
		} else {
			throw (std::string(
				"SquareMatrix::SquareMatrix (std::istream&, int): "
				"The length of `vct\' does not match with `rows\'"
			));
		}
		//std::cout << "el, rest == " << el << ", " << rest << std::endl;
	}
}

// --ioop
std::istream& operator >> (std::istream& ist, SquareMatrix& m) {
	//std::string buff;
	//std::getline(ist, buff);
	//std::istringstream formator(buff);
	int rest = m.rows_ * m.rows_;
	double el;
	m.vct_.clear();
	while (rest > 0) {
		if (ist >> el) {
			m.vct_.push_back(el);
			rest -= 1;
		} else {
			throw(std::string(
				"std::istream& operator >> (std::istream&, SquatrMatrix&): "
				"Too few elements in `ist\'"
			));
		}
	}
	return ist;
}

std::ostream& operator << (std::ostream& ost, const SquareMatrix& m) {
	for (int i = 0; i < m.rows_; ++i) {
		for (int j = 0; j < m.rows_; ++j) {
			ost << m.vct_[m.rows_ * i + j] << ' ';
		}
		ost << std::endl;
	}
	ost << std::endl;
	return ost;
}

// --mxop
bool SquareMatrix::swap (unsigned int xrow, unsigned int yrow) {
	double tmp;
	xrow -= 1;
	yrow -= 1;
	for (int i = 0; i < rows_; ++i) {
		tmp = vct_[xrow * rows_ + i];
		vct_[xrow * rows_ + i] = vct_[yrow * rows_ + i];
		vct_[yrow * rows_ + i] = tmp;
	}
	return true;
}
bool SquareMatrix::scale (double scaler, unsigned int row) {
	row -= 1;
	for (int i = 0; i < rows_; ++i) {
		vct_[row * rows_ + i] *= scaler;
	}
	return true;
}
bool SquareMatrix::xpay (unsigned int xrow, double scalar, unsigned int yrow) {
	xrow -= 1;
	yrow -= 1;
	for (int i = 0; i < rows_; ++i) {
		vct_[rows_ * xrow + i] += scalar * vct_[rows_ * yrow + i];
	}
	return true;
}

// --eqne
bool SquareMatrix::operator == (const SquareMatrix& ano) {
	if (this->rows_ != ano.rows_) {
		return false;
	}
	for (int i = 0; i < this->rows_ * this->rows_; ++i) {
		if (this->vct_[i] != ano.vct_[i]) {
			return false;
		}
	}
	return true;
}

bool SquareMatrix::operator != (const SquareMatrix& ano) {
	return !((*this) == ano);
}
