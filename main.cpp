/*
	Developer: Sina Fi (github.com/sinafi)
	6:03 AM	Thursday, 4 February 2021 (GMT)
*/
#include <iostream>
#include <string>
#include <cstdio>
#include <iomanip>
#include <math.h>
using namespace std;
void Matrix_Collector(float Matrix[][100] ,int rows,int cols); // Function that collects Matrix[rows][cols]
void ShowMatrix(float Matrix[][100] , int rows , int cols); // Function that prints Matrix[rows][cols]
void MoveMatrix(float Matrix1[][100], float Matrix2[][100], int rows2,int cols2); // Function that replaces Matrix2 to Matrix1
void MultiplyMatrix(float MultiMatrix[][100], float Matrix1[][100], float Matrix2[][100], int rows1 , int cols2 , int cols1); // Function to Multiply
void PlusMatrix(float MatrixPlus[][100],float Matrix1[][100], float Matrix2[][100], int rows , int cols , int PM); // Function that calculates + or -
float MatrixDeterminant(float b[100][100],int m); // Function to calculate Determinant
void CoefficientMatrix(float Matrix[][100], int rows, int cols, int c); // Function that multiply a number to Matrix
void TransposeMatrix(float c[100][100],float MatrixInverse[100][100],int n,int determinant); // Function that Changes value of row to cols(and cols to row)
void AdjugateMatrix(float Matrix[100][100],float MatrixInverse[100][100],int n,int determinant); // Function that Calculates Cofactor of Matrix
void MatrixInverser(float Matrix[100][100],float MatrixInverse[100][100],int n,int determinant); // Function that makes Matrix= Matrix^-1
int main() 
		{
			int ia,ib ,ja,jb ; //Rows & Cols of MatrixA-MatrixB
			int x; //Switch Case Variable
	    	float MatrixA[100][100];
    	    float MatrixB[100][100];
    	    float MatrixMulti[100][100];
    	    float MatrixPlus[100][100];
    	    float MatrixInverse[100][100];
    	    
			do // to repeat menu options until while stops
			{
				cout<<"Matrix Calculator"<<endl<<"0-Exit From Program"<<endl<<"1-A"<<endl<<"2-B"<<endl<<"3-A to B"<<endl<<"4-B to A"<<endl<<"5-A=A*B"<<endl
				<<"6-B=B*A"<<endl<<"7-A=A+B"<<endl<<"8-B=B+A"<<endl<<"9-A=A/B"<<endl<<"10-B=B/A"<<endl<<"11-A=A-B"<<endl<<"12-B=B-A"
				<<endl<<"13-A=a*A"<<endl<<"14-B=b*B"<<endl<<"15-det A"<<endl<<"16-det B"<<endl<<"17-Print A"<<endl<<"18-Print B"<<endl<<endl;
				cout<<"Enter Section Number:";
				cin>>x;
				
				switch(x)
				{
					case 1 : //Matrix A
						{
								cout<<"Matrix A"<<endl<<"Enter i:";
								cin>>ia; //Row A
								cout<<"Enter j:";
								cin>>ja; //Column A
								Matrix_Collector(MatrixA , ia , ja); //Collects MatrixA and Saves into memory
								cout<<endl;
								break;
						}
					case 2 : //Matrix B
						{
								cout<<"Matrix B"<<endl<<"Enter i:";
								cin>>ib; //Row B
								cout<<"Enter j:";
								cin>>jb; //Column B
								Matrix_Collector(MatrixB , ib , jb); //Collects MatrixB and Saves into memory
								cout<<endl;
								break;	
						}
					case  3 : // replaces Matrix A to Matrix B
						{
								cout<<"Matrix A replaced to B"<<endl;
								ib=ia; // Row A to B
								jb=ja; // Col B to A
								MoveMatrix(MatrixB , MatrixA , ia , ja); // Uses function to Replace A to B
								break;
						}
					case 4 : // replaces Matrix B to Matrix A
						{
								cout<<"Matrix B replaced to A"<<endl;
								ia=ib; // Row B to A
								ja=jb; // Row A to B
								MoveMatrix(MatrixA , MatrixB , ib , jb); // Uses function to Replace B to A
								break;
						}
					case 5 : // A=A*B
						{
								
								if (ja == ib & ia*jb <= 100) // Maximum 100 Block and First Matrix Cols equals to second Matrix Rows
								{
								MultiplyMatrix(MatrixMulti, MatrixA, MatrixB, ia, jb , ja); // Use function to Multiply
								ja=jb; // Changes Matrix A Cols to MatrixMulti Cols
								MoveMatrix(MatrixA, MatrixMulti , ia , jb); // replaces MatrixMulti to Matrix A
								cout<<"A=A*B Multiplied Successfully!"<<endl;	
								} 
								else // Matrices that Scientifically can't be Multiplied
								{
									cout<<"A=A*B Impossible to Caluculate!"<<endl;
								}
							break;
						}
					case 6 : // B=B*A
						{
								
								if (jb == ia & ib*ja <= 100) // Maximum 100 Block and First Matrix Cols equals to second Matrix Rows
								{
								MultiplyMatrix(MatrixMulti, MatrixB, MatrixA, ib, ja , jb); // Use function to Multiply
								jb=ja; // Changes Matrix B Cols to MatrixMulti Cols
								MoveMatrix(MatrixB, MatrixMulti , ib , ja); // replaces MatrixMulti to Matrix B
								cout<<"B=B*A Multiplied Successfully!"<<endl;	
								} 
								else // Matrices that Scientifically can't be Multiplied
								{
									cout<<"B=B*A Impossible to Caluculate!"<<endl;
								}
							break;
						}
					case 7 : // A=A+B
						{
								if (ia == ib & ja == jb & ia*jb <= 100) // Maximum 100 Block and m*n=m*n
								{
								PlusMatrix(MatrixPlus,MatrixA , MatrixB , ia , ja , +1); // Use function to calculate
								MoveMatrix(MatrixA,MatrixPlus,ia,ja); // replaces MatrixPlus to Matrix A
								cout<<"A=A+B Calculated Successfully!"<<endl;
								}
								else // Matrices that m*n != m*n
								{
									cout<<"A=A+B Impossible to Calculate!"<<endl;
								}
								break;
						}
					case 8 : // B=B+A
						{
								if (ib == ia & jb == ja & ib*ja <= 100) // Maximum 100 Block and m*n=m*n
								{
								PlusMatrix(MatrixPlus,MatrixB , MatrixA , ib , jb , +1); // Use function to calculate
								MoveMatrix(MatrixB,MatrixPlus,ib,jb); // replaces MatrixPlus to Matrix B
								cout<<"B=B+A Calculated Successfully!"<<endl;
								}
								else // Matrices that m*n != m*n
								{
									cout<<"B=B+A Impossible to Calculate!"<<endl;
								}
								break;
						}
					case 9 : // A=A/B
						{
							if(ia != ja)
							{
								cout<<"Impossible to Calculate!"<<endl;
							}
							if(MatrixDeterminant(MatrixA, ia) == 0)
							{
								cout<<"Impossible to Calculate!"<<endl;
							}
							else
							{
								int l = MatrixDeterminant(MatrixA, ia);
								MatrixInverser(MatrixA, MatrixInverse, ia, l);
								ShowMatrix(MatrixA , ia , ja);
								MultiplyMatrix(MatrixMulti, MatrixA, MatrixB, ia, jb , ja); // Use function to Multiply
								ja=jb; // Changes Matrix A Cols to MatrixMulti Cols
								MoveMatrix(MatrixA, MatrixMulti , ia , jb); // replaces MatrixMulti to Matrix A
								cout<<"Calculated Successfully"<<endl;
							}
							break;
						}
					case 10 : // B=B/A
						{
							if(jb != ia)
								{
									cout<<"Impossible to Calculate!"<<endl;
								}
								if(ib != jb)
								{
									cout<<"Impossible to Calculate!"<<endl;
								}
								if(MatrixDeterminant(MatrixB, ib) == 0)
								{
									cout<<"Impossible to Calculate!"<<endl;
								}
								else
								{
									int l = MatrixDeterminant(MatrixB, ib);
									MatrixInverser(MatrixB, MatrixInverse, ib, l);
									MultiplyMatrix(MatrixMulti, MatrixB, MatrixA, ib, ja , jb); // Use function to Multiply
									ja=jb; // Changes Matrix A Cols to MatrixMulti Cols
									MoveMatrix(MatrixB, MatrixMulti , ib , ja); // replaces MatrixMulti to Matrix A
									cout<<"Calculated Successfully"<<endl;
								}
								break;
						}
					case 11 : // A=A-B
						{
							if (ia == ib & ja == jb & ia*jb <= 100) // Maximum 100 Block and m*n=m*n
								{
								PlusMatrix(MatrixPlus,MatrixA , MatrixB , ia , ja , -1); // Use plus function with (int PM = -1)
								MoveMatrix(MatrixA,MatrixPlus,ia,ja); // replaces MatrixPlus to Matrix A
								cout<<"A=A-B Calculated Successfully!"<<endl;
								}
								else // Matrices that m*n != m*n
								{
									cout<<"A=A-B Impossible to Calculate!"<<endl;
								}
								break;
						}
					case 12 : // B=B-A
						{
							if (ib == ia & jb == ja & ib*ja <= 100) // Maximum 100 Block and m*n=m*n
								{
								PlusMatrix(MatrixPlus,MatrixB , MatrixA , ib , jb , -1); // Use plus function with (int PM = -1)
								MoveMatrix(MatrixB,MatrixPlus,ib,jb); // replaces MatrixPlus to Matrix B
								cout<<"B=B-A Calculated Successfully!"<<endl;
								}
								else // Matrices that m*n != m*n
								{
									cout<<"B=B-A Impossible to Calculate!"<<endl;
								}
								break;
						}
					case 13 : // A=a*A
					{
						int c; // Coefficient of Matrix
						cout<<"Enter Coefficient of Matrix: ";
						cin>>c;
						CoefficientMatrix(MatrixA , ia , ja ,c); // Use Function to Multiply
						cout<<"Multiplied Successfully!"<<endl;
						break;
					}
					case 14 : // B=b*B
					{
						int c; // Coefficient of Matrix
						cout<<"Enter Coefficient of Matrix: ";
						cin>>c;
						CoefficientMatrix(MatrixB , ib , jb ,c); // Use Function to Multiply
						cout<<"Multiplied Successfully!"<<endl;
						break;
					}
					case 15 : //det A
						{
							if(ia == ja) // Matrix That row = col
							{
								cout<<"determinant of Matrix A="<<MatrixDeterminant(MatrixA,ia)<<endl; // int Function return number of determinant
							}
							else // not n*n Matrix
							{
								cout<<"Impossible to Calculate determinant! Only n*n matrices have determinant"<<endl;
							}
							break;
						}
					case 16 : //det B
						{
							if(ib == jb) // Matrix That row = col
							{
								cout<<"determinant of Matrix B="<<MatrixDeterminant(MatrixB,ib)<<endl; // int Function return number of determinant
							//	cout<<"det of Matrix A= "<<DeterminantMatrix(MatrixB , ib)<<endl;
							}
							else // not n*n Matrix
							{
								cout<<"Impossible to Calculate determinant! Only n*n matrices have determinant"<<endl;
							}	
							break;
						}
					case 17 : // Print A
						{
							ShowMatrix(MatrixA , ia , ja); // Use Function to Print Matrix A with setw and iomanip library
							cout<<endl;
							break;
						}
					case 18 : // Print B
						{
							ShowMatrix(MatrixB , ib , jb); // Use Function to Print Matrix B with setw and iomanip library
							cout<<endl;
							break;
						}
				}
			}
			while(x != 0); // do-while proccess works till x != 0
			return 0;
		}
void Matrix_Collector(float Matrix[][100] ,int rows,int cols) // Function that collects Matrix[rows][cols]
		{
			if(rows*cols <= 100) // Maximum Matrix can have 100 Blocks
			{
				int k,n;
				for (k = 0; k < rows; k++) // Nested loop to make Matrix
					{
						for (n = 0; n < cols; n++) // do proccess and when ends(n=cols) ==> k=k + 1 ==> another cols for() proccess
						{
							cout << "a(" << k+1 << "," << n+1 << "):\t"; // prints entry of matrix
							cin>> Matrix[k][n]; // gets value of every entry
						}
							
					}
			}
			else{ // Matrices that software doesn't support
				cout<<"This Type of Matrix is not supported!";
				}
    	}
void ShowMatrix(float Matrix[][100] , int rows , int cols) // Function that prints Matrix[rows][cols]
{
	for(int o=0 ; o<rows ; o++) // Nested loop to print Matrix
	{
		for(int f=0 ; f<cols ; f++) // loops cols
		cout<<setw(5)<<Matrix[o][f]; // setw Function that uses iomanip library to order Matrix
		cout<<endl; // to seperate cols
	}
	
}
void MoveMatrix(float Matrix1[][100], float Matrix2[][100], int rows2,int cols2) // Function that replaces Matrix2 to Matrix1
{
			for(int i=0 ; i<rows2 ; i++) // Nested loop to Equal every Matrix2 to Matrix1
				{
				for(int j=0 ; j<cols2 ; j++)
					{
								Matrix1[i][j] = Matrix2[i][j]; //Every entry of Matrix 1 = Matrix 2
					}
				}
			
}
void MultiplyMatrix(float MultiMatrix[][100], float Matrix1[][100], float Matrix2[][100], int rows1 , int cols2 , int cols1) // Function to Multiply
{
		for(int i=0 ; i<rows1 ; i++) // Nested loop to make MultiMatrix as NULL Matrix
		{
			for(int j=0 ; j<cols2 ; j++)
			{
				MultiMatrix[i][j] = 0 ;
			}
		}
		for(int i = 0; i<rows1; i++) // Nested loop that proccess the Multiply
			{
				for(int j = 0; j<cols2; j++) // i & j for, Makes MultiMatrix[i][j] values equals to Addition of two Matrices
				{
					for(int m=0; m<cols1; m++) // most important loop to do(row to col) Multiply
					{
						MultiMatrix[i][j] += Matrix1[i][m] * Matrix2[m][j]; // every MultiMatrix entry equals to addition of multiplies(Matrix 1 & Matrix 2)
					}
				}
			}
}
void PlusMatrix(float MatrixPlus[][100],float Matrix1[][100], float Matrix2[][100], int rows , int cols , int PM) // Function that calculate + or -
{
	for(int i = 0; i< rows;i++) // Nested loop to proccess + or -
	{
		for(int j = 0; j< cols;j++)
		{
			MatrixPlus[i][j] = Matrix1[i][j] + (PM * Matrix2[i][j]); // int PM is to change sign of second matrix
		}
	}
}
float MatrixDeterminant(float Matrix[100][100],int m)   //Function to calculate Determinant
	{
 		int i,j,det = 0;
		float mMinus1[100][100];
		if(m==1)
		{
			det = Matrix[0][0]; // formula is available
			return det;
		}
 		if(m==2)
  		{          //Base Condition and formula is available
			det = Matrix[0][0]*Matrix[1][1] - Matrix[0][1]*Matrix[1][0];
			return det; // returns value because of int function
 		}
	 	for(int p=0;p<m;p++) // Nested loop that calculates n*n determinant with recurrence relation to (n-1)*(n-1) determinant
	 		{
	  			int h = 0,k = 0;
	  			for(i=1; i<m; i++) // Nested loop to make mMinus1 Function available
	  				{
						for(j=0; j<m; j++)
								{
									if(j==p) // when rows for equals to cols for
									continue;
									mMinus1[h][k] = Matrix[i][j]; // that m*m entry equals to main Matrix i*j entry
									k++; // gets +1 untill k==m-1 and k gets 0 value
									if(k == m-1)
										  {
											 h++; // at this situation h gets +1
											 k = 0;
										  }
	
								}
	 				}
	
	  det = det + Matrix[0][p]*pow(-1,p)*MatrixDeterminant(mMinus1,m-1); // Determinant equals to plus of -1^(i+j) * reccurence of m-1 determinant
	 		}
	 return det; // returns value because of int function
	}
void CoefficientMatrix(float Matrix[][100], int rows, int cols, int c) // Function that multiply a number to Matrix
{
	for(int i=0 ; i<rows ; i++) // Nested Loop to proccess
	{
		for(int j=0 ; j<cols ; j++)
		{
			Matrix[i][j] = c*Matrix[i][j]; // Every Entry= c*entry
		}
	}
}
void TransposeMatrix(float c[100][100],float MatrixInverse[100][100],int n,int determinant) // Function that Changes value of row to cols(and cols to row)
{
	float b[100][100];
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			b[i][j] = c[j][i]; // equal n*n Matrix b(which defined in AdjugateMatrix) to Matrix c
			for (int i=0;i<n;i++)
			for (int j=0;j<n;j++)
			MatrixInverse[i][j] = b[i][j]/determinant; //Matrix Inverse = 1/det * Matrix b(which gets called)
}
void AdjugateMatrix(float Matrix[100][100],float MatrixInverse[100][100],int n,int determinant) // Function that Calculates Cofactor of Matrix
{
	float b[100][100],c[100][100];
	for (int h=0; h<n; h++)
		for (int l=0; l<n; l++)
		{
			int m=0;
			int k=0;
			for (int i=0; i<n; i++)
				for (int j=0; j<n; j++)
					if (i != h && j != l){
						b[m][k]=Matrix[i][j]; // with loop Matrix b equals to Matrix
						if (k<(n-2))
							k++; // when K < n-2(row=col Matrix)
						else{
							k=0; // when K=n-2 ==> k=0
							m++;
						}
					}
			c[h][l] = (int) pow(-1,(h+l))*MatrixDeterminant(b,(n-1)); // Similar to calculation of Matrix Determinant
		}
		TransposeMatrix(c, MatrixInverse,n,determinant); // Recursion of TransposeMatrix at the end of Function
}
void MatrixInverser(float Matrix[100][100],float MatrixInverse[100][100],int n,int determinant) // Function that makes Matrix= Matrix^-1
{
	if(n==1) // formula is available
	{
		Matrix[0][0];
	}
	if(n==2) // formula is available
	{
		int h = Matrix[0][0];
		Matrix[0][0] = Matrix[1][1];
		Matrix[1][1] = h;
		Matrix[0][1] = Matrix[0][1] * -1;
		Matrix[1][0] = Matrix[1][0] * -1;
		CoefficientMatrix(Matrix, 2, 2 , 1/determinant);
	}
	if(n==3) // formula is available
	{
		float a = Matrix[0][0];
		float b = Matrix[0][1];
		float c = Matrix[0][2];
		float d = Matrix[1][0];
		float e = Matrix[1][1];
		float f = Matrix[1][2];
		float g = Matrix[2][0];
		float h = Matrix[2][1];
		float i = Matrix[2][2];
		Matrix[0][0] = (e*i) - (h*f);
		Matrix[0][1] = (h*c) - (b*i);
		Matrix[0][2] = (b*f) - (e*c);
		Matrix[1][0] = (f*g) - (i*d);
		Matrix[1][1] = (i*a) - (g*c);
		Matrix[1][2] = (c*d) - (a*f);
		Matrix[2][0] = (d*h) - (g*e);
		Matrix[2][1] = (g*b) - (a*h);
		Matrix[2][2] = (a*e) - (d*b);
		CoefficientMatrix(Matrix, 3, 3 , 1/determinant);
	}
	
	else{
		AdjugateMatrix(Matrix, MatrixInverse, n, determinant);	// Return void(do proccess of inverse)
		MoveMatrix(Matrix, MatrixInverse, n, n);
		}
}
