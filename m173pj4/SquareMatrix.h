#ifndef SQUARE_MATRIX_H
#define SQUARE_MATRIX_H

#include <string>
#include <vector>
#include <istream>
#include <ostream>

class SquareMatrix {
public:
	std::vector<double> vct_;
	unsigned int rows_;
	//double& at_ (unsigned int row, unsigned int col);

// Constructors:
	SquareMatrix (unsigned int rows);

	// If the length of `lst' is not a perfect square,
	// this function will throw an exception.
	SquareMatrix (std::initializer_list<double> lst);

	// If the length of `vct' is less than `rows * rows',
	// this function will throw an exception.
	// Else, if the length of `vct' is greater than `rows * rows',
	// this function will ignore the extra elements in the `vct'.
	SquareMatrix (const std::vector<double>& vct, unsigned int rows);

	// The exception and ignore behaviour of
	// this function is same as the function given above:
	// if `vct.size() < rows * rows' then throw an exception.
	// if `vct.size() > rows * rows' then ignore.
	SquareMatrix (std::istream& ist, unsigned int rows);

// Stream Operators:
	friend std::istream& operator >> (std::istream& ist, SquareMatrix& m);
	friend std::ostream& operator << (std::ostream& ost, const SquareMatrix& m);

// Row Operations:
// If the operation fails, it will return false.

	// Swap two rows.
	bool swap (unsigned int xrow, unsigned int yrow);

	// Scale one row in matrix by a scaler.
	bool scale (double scaler, unsigned int row);

	// row X is rePlaced by A * Y.(xpay)
	bool xpay (unsigned int xrow, double scalar, unsigned int yrow);

// More Operations:
	bool operator == (const SquareMatrix& ano);
	bool operator != (const SquareMatrix& ano);
};

#endif
