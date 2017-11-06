// Part I:

#include <stdio.h>
#include <math.h>


struct user_input_t {
	int selection; // 1, 2, 3, 4, 5
	double a;
	double b;
	double N;
};

int getUserInput (struct user_input_t* input);
double calculate (int which, double x);
int writeToFile (struct user_input_t input);

int getUserInput (struct user_input_t* input) {
	int selection;
	double a;
	double b;
	double N;

	printf("Functions are:\n");
	printf("\t1. f(x) = sqrt(abs(x - 1)) + 1\n");
	printf("\t2. f(x) = exp(-x)\n");
	printf("\t3. f(x) = sqrt(x * x + 1) - x\n");
	printf("\t4. f(x) = (exp(-x) - 1) / x\n");
	printf("\t5. f(x) = sin(x) + 0.1 * cos(10 * x)\n");
	printf("Choose your function: ");
	scanf("%d", &selection);
	
	/* Check for selection */
	if (selection < 1 && selection > 5) {
		fprintf(stderr, "Your selection does not exist!");
		fprintf(stderr, "Your input should be one of {1, 2, 3, 4, 5}.");
		return -1;
	}
	
	printf("Input a: ");
	scanf("%lf", &a);
	printf("Input b: ");
	scanf("%lf", &b);
	
	if (b <= a) {
		fprintf(stderr, "Interval weird!");
		return -1;
	}
	
	printf("Input N: ");
	scanf("%lf", &N);
	
	if (N >= (b - a)) {
		fprintf(stderr, "N weird!");
		return -1;
	}
	
	input->selection = selection;
	input->a = a;
	input->b = b;
	input->N = N;
	return 0;
}

double calculate (int which, double x) {
	switch (which) {
		case 1: return sqrt(abs(x - 1)) + 1;
		case 2: return exp(-x);
		case 3: return sqrt(x * x + 1) - x;
		case 4: return (exp(-x) - 1) / x;
		case 5: return sin(x) + 0.1 * cos(10 * x);
	}
	// default:
	return 0.0;
}

int writeToFile (struct user_input_t input) {
	double iter;
	FILE* functab = fopen("myFunctionTable.dat", "w+");
	if (functab == NULL) {
		fprintf(stderr, "Cannot open or create file myFunctionTable.dat for writing.");
		return -1;
	}
	for (iter = input.a; iter <= input.b; iter += input.N) {
		fprintf(functab, "%lf\t%lf\n", iter, calculate(input.selection, iter));
	}
	fclose(functab);
	return 0;
}

int main () {
	struct user_input_t USER_INPUT;
	if (getUserInput(&USER_INPUT) != 0) {
		return -1;
	}
	if (writeToFile(USER_INPUT) != 0) {
		return -1;
	}
	return 0;
}
