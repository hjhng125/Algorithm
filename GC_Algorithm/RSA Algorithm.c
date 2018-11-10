#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
/*
int Miller(int);
int gcd(int, int);
int Euler(int);
int get_Private_key(int, int);
int get_Public_key(int);
int Encryption(int, int, int);
int Decryption(int, int, int);
int Repeat_Squaring(int, int, int);

void main() {
	int n, c, e, tot, m, d, p, q;

	//printf("%f", (float)0x8fffffff);
	printf("Encryption\n");
	printf("Enter Original Message : ");
	scanf("%d", &m);
	do {
		printf("Enter prime number p : ");
		scanf("%d", &p);
	} while (Miller(p) != 1);
	do {
		printf("Enter prime number q : ");
		scanf("%d", &q);
	} while (Miller(q) != 1);

	n = p * q;
	tot = Euler(n);

	e = get_Public_key(tot);
	c = Encryption(m, e, n);

	printf("\nEncryption Result\n");
	printf("Cipher : %d\n", c);
	printf("Public Key : %d\n", e);
	printf("N : %d, phi(n) : %d\n", n, tot);

	printf("\nDecryption\n");
	printf("Enter n : ");
	scanf("%d", &n);
	tot = Euler(n);
	do {
		printf("Enter Public key : ");
		scanf("%d", &e);
	} while (gcd(tot, e) != 1);

	printf("Enter Ciphertext : ");
	scanf("%d", &c);

	d = get_Private_key(e, tot);
	m = Decryption(c, d, n);

	printf("\nDecryption Result\n");
	printf("Original Message : %d\n", m);
	printf("Private Key : %d\n", d);
	printf("N : %d, phi(n) : %d\n", n, tot);
}

int Miller(int p) {
	long n = (long)p;
	long a, b, m = n - 1;
	int i, j, k = 0;
	float f;

	while (m % 2 == 0) {
		m /= 2;
		k++;
	}

	srand(time(0));

	for (i = 0; i < 100; ++i) {
		f = (float)(((float)rand()) / (float)0x8fffffff);
		a = (long)((f)*(n - 2));
		if (a < 2)
			a = 2;

		if (gcd((int)a, (int)n) != 1)
			return 0;

		b = (long)Repeat_Squaring((int)a, (int)m, (int)n);

		if (b == 1 | b == (n - 1))
			continue;
		else {
			for (j = 0; j < k - 1; ++j) {
				b = (b*b) % n;
				if (b == (n - 1))
					break;
			}

			if (b != (n - 1))
				return 0;
		}
	}
	return 1;
}

int gcd(int a, int b) {
	if (b == 0)
		return a;
	gcd(b, a%b);
}

int Euler(int n) {
	int result = n;

	for (int p = 2; p*p < n; ++p) {
		if (n%p == 0) {
			while (n%p == 0)
				n /= p;
			result -= result / p;
		}
	}

	if (n > 1)
		result -= result / n;

	return result;
}

int get_Private_key(int e, int tot) {
	int d = 1;

	while ((e*d) % tot != 1 || d == e)
		d += 1;

	return d;
}


int get_Public_key(int tot) {
	int e = 2;

	while (e < tot && gcd(e, tot) != 1)
		e += 1;

	return e;
}

int Encryption(int m, int e, int n) {
	int c;

	c = Repeat_Squaring(m, e, n);

	return c;
}

int Decryption(int c, int d, int n) {
	int m;

	m = Repeat_Squaring(c, d, n);

	return (int)m;
}

int Repeat_Squaring(int a, int b, int n) {
	long long m = (long long)a;
	long long e = (long long)b;
	long long z = 1;

	while (e > 0) {
		while (e % 2 == 0) {
			e /= 2;
			m = (m*m) % n;
		}
		e--;
		z = (z*m) % n;
	}

	return (int)z;
}*/
int Squaring(int, int, int);
int getD(int, int);
int GCD(int, int);

void main() {
	int N, d, p, q, pN;
	int C, M;
	int e = 2;
	printf("input message: ");
	scanf("%d", &M);
	printf("\ninput p q: ");
	scanf("%d %d", &p, &q);

	N = p * q;
	pN = (p - 1)*(q - 1);

	while (1) {
		if (GCD(e, pN) == 1)
			break;
		e++;
	}

	d = getD(e, pN);

	printf("public key:(%d,%d)\n", e, N);
	printf("private key:(%d,%d)\n", d, N);

	C = Squaring(M, e, N);
	M = Squaring(C, d, N);

	printf("Encryption text: %d\n", C);
	printf("Decryption text: %d", M);


}

int GCD(int a, int b) {
	if (b == 0)
		return a;
	else
		return GCD(b, a%b);
}
int getD(int e, int pN) {
	int k = 1;
	while (1) {
		if (((k*pN) + 1) % e == 0 && ((k*pN) + 1) / e < pN)
			return ((k*pN) + 1) / e;

		++k;
	}
	return -1;

}
int Squaring(int a, int b, int N) {
	int k = 1;
	while (b>0) {
		while (b % 2 == 0) {
			b = b / 2;
			a = (a*a) % N;
		}
		b--;

		k = (k*a) % N;
	}
	return k;
}