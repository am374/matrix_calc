#include "matrix_calc1.h"

/*****************************************************/
/*                                                   */
/*  Andrew's Matrix Calculator                       */
/*  Ver 0.1                                          */
/*****************************************************/

int main() {
	system("color 3F");
	system("title Andrew's Awesome Matrix Calculator");
	int chsA = 0, chsB = 0;
	char chsM1 = 'x';
	bool checker = false;
	MATRIX A;
	MATRIX B;
	MATRIX C;
	MATRIX D;
	
	initarray(A.mat, ARRAYMAX, ARRAYMAX);
	initarray(B.mat, ARRAYMAX, ARRAYMAX);
	initarray(C.mat, ARRAYMAX, ARRAYMAX);
	initarray(D.mat, ARRAYMAX, ARRAYMAX);
	A.name = 'A';
	B.name = 'B';
	C.name = 'C';
	D.name = 'D';
	
	welcome();
	do {
		cout<<"1  - Enter Matrix   2  - Print Matrix  \n";
		cout<<"3  - REF Matrix     4  - RREF Matrix   \n";
		cout<<"5  - Add A+B=C      6  - Subtract A-B=C\n";
		cout<<"7  - Multiply A*B=C 8  - Augment A|B=C \n";
		cout<<"9  - Copy Matrix    10 - Erase All     \n";
		cout<<"99 - Quit\n";
		cout<<"Select menu option: ";
		cin>>chsA;
		switch (chsA) {
			case 1:
				cout<<"Enter matrix A, B, C, or D:  ";
				cin>>chsM1;
				switch (chsM1) {
					case 'A':
						getmatrix(A.mat, A.m, A.n, A.name);
						break;
					case 'B':
						getmatrix(B.mat, B.m, B.n, B.name);
						break;
					case 'C':
						getmatrix(C.mat, C.m, C.n, C.name);
						break;
					case 'D':
						getmatrix(D.mat, D.m, D.n, D.name);
						break;
				}
				break;
			case 2:
				cout<<"Enter matrix A, B, C, or D:  ";
				cin>>chsM1;
				switch (chsM1) {
					case 'A':
						printmatrix(A.mat, A.m, A.n, A.name);
						break;
					case 'B':
						printmatrix(B.mat, B.m, B.n, B.name);
						break;
					case 'C':
						printmatrix(C.mat, C.m, C.n, C.name);
						break;
					case 'D':
						printmatrix(D.mat, D.m, D.n, D.name);
						break;
				}
				break;
			case 3:
				cout<<"Enter matrix A, B, C, or D:  ";
				cin>>chsM1;
				switch (chsM1) {
					case 'A':
						A.inRef = ref(A.mat, A.m, A.n);
						break;
					case 'B':
						B.inRef = ref(B.mat, B.m, B.n);
						break;
					case 'C':
						C.inRef = ref(C.mat, C.m, C.n);
						break;
					case 'D':
						D.inRef = ref(D.mat, D.m, D.n);
						break;
				}
				break;
			case 4:
				cout<<"Enter matrix A, B, C, or D:  ";
				cin>>chsM1;
				switch (chsM1) {
					case 'A':
						if (!A.inRef) ref(A.mat, A.m, A.n);
						rref(A.mat, A.m, A.n);
						break;
					case 'B':
						if (!B.inRef) ref(B.mat, B.m, B.n);
						rref(B.mat, B.m, B.n);
						break;
					case 'C':
						if (!C.inRef) ref(C.mat, C.m, C.n);
						rref(C.mat, C.m, C.n);
						break;
					case 'D':
						if (!D.inRef) ref(D.mat, D.m, D.n);
						rref(D.mat, D.m, D.n);
						break;
				}
				break;
			
			case 5:
				addmatrix(A.mat, A.m, A.n, B.mat, B.m, B.n, C.mat, C.m, C.n);
				break;
				
			case 6:
				subtractmatrix(A.mat, A.m, A.n, B.mat, B.m, B.n, C.mat, C.m, C.n);
				break;
			
			case 7:
				multmatrix(A.mat, A.m, A.n, B.mat, B.m, B.n, C.mat, C.m, C.n);
				printmatrix(A.mat,A.m,A.n,A.name);
				cout<<"X\n";
				printmatrix(B.mat,B.m,B.n,B.name);
				cout<<"equals\n";
				printmatrix(C.mat,C.m,C.n,C.name);
				break;
			
			case 8:
				augmatrix(A.mat, A.m, A.n, B.mat, B.m, B.n, C.mat, C.m, C.n);
				break;
			
			case 9:
				cout<<"1 - Copy C->A  2 - Copy C->D\n";
				cout<<"3 - Copy A->D               \n";
				cin>>chsB;
				switch (chsB) {
					case 1:
						copymatrix(C.mat, C.m, C.n, A.mat, A.m, A.n);
						break;
					case 2:
						copymatrix(C.mat, C.m, C.n, D.mat, D.m, D.n);
						break;
					case 3:
						copymatrix(A.mat, A.m, A.n, D.mat, D.m, D.n);
						break;
				}
				break;
			
			case 10:
				initarray(A.mat, ARRAYMAX, ARRAYMAX);
				initarray(B.mat, ARRAYMAX, ARRAYMAX);
				initarray(C.mat, ARRAYMAX, ARRAYMAX);
				initarray(D.mat, ARRAYMAX, ARRAYMAX);
				break;
			
			case 99:
				break;
			default:
			cout<<"Function Not Available\n";
		}		
	} while (chsA != 99);
	
	cout<<"Thank you for using...Goodbye!";
	return 0;

}

//Welcome Message
void welcome() {
cout<<"Welcome to Andrew Awesome Matrix Calculator\n";
cout<<"Version 0.1\n\n";
return;
}


//Initialize Matrix (Zero all values)
void initarray(double matrixIn[ARRAYMAX] [ARRAYMAX],int m, int n){
	for (int i = 0; i<m; i++){
		for (int j = 0; j<n; j++){
			matrixIn [i] [j] = 0;
		}
	}
	return;
}

//Enter Matrix Function
void getmatrix(double matrixIn[ARRAYMAX] [ARRAYMAX],int& m, int& n, char name){
	cout<<"Max matrix size is 50 x 50\n";
	cout<<"Enter # of rows: ";
	cin>>m;
	cout<<"Enter # of columns: ";
	cin>>n;
	cout<<"This is a "<<m<<" X "<<n<<" matrix\n";
	cout<<"Enter matrix "<<name<<" 1 row at a time\n";
	for (int i = 0; i<m; i++) {
		cout<<"Enter row "<<i+1<<endl;
		for (int j = 0; j<n; j++) {
			cin>>matrixIn [i] [j];
		}
	}
	return;	
}

//Print Matrix Function
void printmatrix(double matrixIn [ARRAYMAX] [ARRAYMAX], int m, int n, char name){
	cout<<"Matrix "<<name<<endl;
	for (int i = 0; i<m; i++) {
		for (int j = 0; j<n; j++) {
			cout<<setw(5)<<matrixIn [i] [j]<<" ";
		}
		cout<<endl;
	}
	return;	
}

//Copy Matrix Function
void copymatrix(const double matrixIn[ARRAYMAX] [ARRAYMAX], const int mIn, const int nIn,
		double matrixOut[ARRAYMAX] [ARRAYMAX], int& mOut, int& nOut){
	initarray(matrixOut,ARRAYMAX,ARRAYMAX);
	mOut = mIn;
	mOut = nIn;
	for (int i = 0; i<mIn; i++) {
		for (int j = 0; j<nIn; j++) {
			matrixOut [i] [j] = matrixIn [i] [j];
		}
	}
	return;	
}

//Swap matrix row function
void rowswap(double matrixIn[ARRAYMAX] [ARRAYMAX],int i1, int i2, int n) {
	double swap = 0;
	for (int j = 0; j<n ; j++){
		swap = matrixIn [i1] [j];
		matrixIn [i1] [j] = matrixIn [i2] [j];
		matrixIn [i2] [j] = swap;
	}
	return;
}

//Row Echelon Form of Matrix Function
bool ref(double matrixIn[ARRAYMAX] [ARRAYMAX],int m, int n){
	double factor = 0; //factor value row operations
	int  pc = 0, pr = 0; //pivot column and pivot row variables
	
	for (pc = 0; pc<n; pc++) {
		if (!matrixIn [pr] [pc]){
		int np = pr + 1;
		do {
			if (!matrixIn [np] [pc]) np++;
			if (matrixIn [np] [pc]) rowswap(matrixIn, pr, np, n);
			} while (!matrixIn [pc] [pr] && np<m);
		}
		if (matrixIn [pr] [pc] != 1 && matrixIn [pc] [pr]) {
			factor = matrixIn [pc] [pr];
			for (int j = 0; j<n; j++) matrixIn [pr] [j] = 1.*matrixIn [pr] [j]/factor;
		}
		for (int i = pr + 1; i<m; i++) {
			if (matrixIn [i] [pc]) {
				factor = -1*matrixIn [i] [pc];
				for (int j = pc; j<n; j++) {
					matrixIn [i] [j] = matrixIn [i] [j] + factor*matrixIn [pr] [j];
				}
			}
		}
		pr++;
	}
	return true;
}

//Reduced Row Echelon Form of Matrix Function
bool rref(double matrixIn[ARRAYMAX] [ARRAYMAX],int m, int n){
	double factor = 0; //factor value row operations
	int  pc = 0, pr = (m - 1); //pivot column and pivot row variables
		
	for (pc = (n-1); pc>=0; pc--) {
		for (int i = (pr - 1); i>=0; i--) {
			if (matrixIn [i] [pc]) {
				factor = -1*matrixIn [i] [pc];
				for (int j = pc; j<n; j++) {
					matrixIn [i] [j] = matrixIn [i] [j] + factor*matrixIn [pr] [j];
				}
			}
		}
		pr--;
	}
}

//add matrix function
bool addmatrix(const double matrix1 [ARRAYMAX] [ARRAYMAX],const int m1, const int n1,
		const double matrix2 [ARRAYMAX] [ARRAYMAX], const int m2, const int n2,
		double matrixOut [ARRAYMAX] [ARRAYMAX], int& mOut, int& nOut) {
	if (m1 != m2 || n1 != n2) {
		cout<<"Dimensions do not match...aborting\n";
		return false;
	}
	mOut = m1;
	nOut = n1;
	for (int i = 0; i<mOut; i++) {
		for (int j = 0; j<nOut; j++) {
			matrixOut [i] [j] = matrix1 [i] [j] + matrix2 [i] [j];
		}
	}
	return true;

}

//subtract matrix function
bool subtractmatrix(const double matrix1 [ARRAYMAX] [ARRAYMAX],const int m1, const int n1,
		const double matrix2 [ARRAYMAX] [ARRAYMAX], const int m2, const int n2,
		double matrixOut [ARRAYMAX] [ARRAYMAX], int& mOut, int& nOut) {
	if (m1 != m2 || n1 != n2) {
		cout<<"Dimensions do not match...aborting\n";
		return false;
	}
	mOut = m1;
	nOut = n1;
	for (int i = 0; i<mOut; i++) {
		for (int j = 0; j<nOut; j++) {
			matrixOut [i] [j] = matrix1 [i] [j] - matrix2 [i] [j];
		}
	}
	return true;

}

//multiply matrix function
bool multmatrix(const double matrix1 [ARRAYMAX] [ARRAYMAX],const int m1, const int n1,
		const double matrix2 [ARRAYMAX] [ARRAYMAX], const int m2, const int n2,
		double matrixOut [ARRAYMAX] [ARRAYMAX], int& mOut, int& nOut) {
	if (n1 != m2) {
		cout<<"Dimensions do not match...aborting\n";
		return false;
	}
	initarray(matrixOut,ARRAYMAX,ARRAYMAX);
	mOut = m1;
	nOut = n2;
	for (int j = 0; j<nOut; j++) {
		for (int iOut = 0; iOut<mOut; iOut++) {
			for (int iIn = 0; iIn<mOut; iIn++) {
				matrixOut [iOut] [j] += matrix1 [iOut] [iIn]*matrix2 [iIn] [j];
				cout<<matrixOut [iOut] [j]<<endl;
			}
		}
	}
	
	return true;

}

//augement matrix function
bool augmatrix(const double matrix1 [ARRAYMAX] [ARRAYMAX],const int m1, const int n1,
		const double matrix2 [ARRAYMAX] [ARRAYMAX], const int m2, const int n2,
		double matrixOut [ARRAYMAX] [ARRAYMAX], int& mOut, int& nOut) {
	if (m1 != m2) {
		cout<<"Dimensions do not match...aborting\n";
		return false;
	}
	initarray(matrixOut,ARRAYMAX,ARRAYMAX);
	mOut = m1;
	nOut = n1 + n2;
	for (int i = 0; i<m1; i++) {
		for (int j = 0; j<n1; j++) {
			matrixOut [i] [j] = matrix1 [i] [j];
		}
		for (int j = 0; j<n2; j++) {
			matrixOut [i] [j+n1] = matrix2 [i] [j];
		}
	}
	return true;

}