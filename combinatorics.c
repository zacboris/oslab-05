int extern_n = 0;

int factorial(int n) {
	if (n == 0) return 1;
	else return factorial(n - 1) * n;
}

int C(int n, int k) {
	return factorial(n) /
		(factorial(k)*factorial(n - k));
}
