#include "SquareMatrix.h"
SquareMatrix::SquareMatrix()
{
    
}

SquareMatrix::SquareMatrix(unsigned int _n) : n(_n)
{
	arrayElements = new double[n*n];
	fill();
}

SquareMatrix::~SquareMatrix()
{
	delete[] arrayElements;
}

void SquareMatrix::fill()
{
    double myArray[MAX_MY_ARRAY][MAX_MY_ARRAY] =
    {{-1.0,  1.0, -2.0, -0.0,  0.9,  0.1,  0.5,  0.3, -0.5,  0.9, -0.5,  0.2 },
        { 2.0,  1.0, -0.7,  0.6, -0.5,  4.3,  0.7,  0.8,  0.4,  0.1, -0.6, -1.2 },
        { 0.0,  3.0, -1.0, -2.8,  0.1,  0.3, -1.0, -0.5,  0.1,  1.3,  0.7,  0.1 },
        { 0.0,  0.3, -1.8,  0.7, -0.6, -0.4, -0.5,  0.1, -0.1, -0.4,  0.0, -0.0 },
        { 2.0,  2.9,  0.9,  0.0,  1.0,  0.9,  0.7, -0.6,  4.0, -0.6, -1.7, -0.2 },
        {-0.8, -0.2, -0.1,  0.8, -1.2,  0.0,  1.4,  2.9, -1.4,  0.6,  0.9, -0.1 },
        {-1.0,  0.4,  1.7, -3.9,  1.4, -3.0, -0.6,  1.2,  0.3,  1.7,  0.0,  0.9 },
        { 0.8,  1.4,  1.6,  0.8, -1.1,  1.7, -0.3, -0.7, -0.9,  1.1, -2.5,  0.8 },
        { 1.8, -0.9, -3.3,  0.6, -4.2, -0.8, -0.8, -7.6,  1.3,  0.6,  1.8, -0.1 },
        {-3.7, -0.5,  0.4,  0.9,  2.5, -0.1,  7.6, -3.7, -0.2,  4.4,  0.8,  3.7 },
        { 0.6,  0.0, -0.1, -2.3, -0.3, -4.7, -0.7,  0.8, -0.0,  0.3,  1.5,  1.4 },
        {-0.8, -0.2, -0.0,  0.0, -0.2,  0.0,  1.4,  2.9, -1.4,  0.6,  0.9, -0.1 }};
    double m[9]={-2,-1,2,2,1,0,-3,3,1};
    srand(time(NULL));

//    for (int i = 1; i <= n; ++i)
//	{
//		for (int j = 1; j <= n; ++j)
//		{
//			arrayElements[index(i-1, j-1)] = generateRandom(0.9, 1.1);
//            //myArray[i-1][j-1];
//            //generateRandom(-50, 50);
//            //myArray[i-1][j-1];
//            //generateRandom(10, 99);
//		}
//	}
    for (int i=0; i<9; i++) {
        arrayElements[i]=m[i];
    }

}

double SquareMatrix::generateRandom(double leftLimit, double rightLimit)
{
    double r=(double)rand();
    
    return (r / (double) RAND_MAX) * (rightLimit - leftLimit) + leftLimit;
}

void SquareMatrix::print()
{
	std::cout.precision(2);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			std::cout << std::fixed << arrayElements[index(i-1,j-1)] << "   ";
		}
		std::cout << std::endl;
	}
}

void SquareMatrix::forwardElimination(int iEntry, int jEntry)
{
	double multiplier = arrayElements[index(iEntry - 1,jEntry - 1)] / arrayElements[index(jEntry - 1,jEntry - 1)];
    int j=iEntry;
    arrayElements[index(iEntry - 1,j - 1)] = arrayElements[index(iEntry - 1,j - 1)] - multiplier * arrayElements[index(jEntry - 1,j - 1)];

}

double SquareMatrix::getLMatrixDiagonalElement(int iEntry, int jEntry)
{
	//TODO
}

bool SquareMatrix::forwardElimination()
{
	int i = 2;
	int j = 1;
    
	while (i <= n)
	{
		while (j < i)
		{
			//std::cout << "Forward elimination for : " << i << "," << j<< std::endl;
			if(arrayElements[index(j-1,j-1)]==0)
            {
                return false;
            }
            forwardElimination(i, j);
			j++;
		}
		i++;
		j = 1;
	}
    return true;
}

double SquareMatrix::getDeterminant()
{
	forwardElimination();

	double determinant = 1;
	for (int i = 1; i <= n; ++i)
	{
		determinant *= arrayElements[index(i-1, i-1)];
	}
    print();
	return determinant;
}

bool SquareMatrix::isCompatible(SquareMatrix& matrixToCompare)
{
	return n == matrixToCompare.getN();
}

double SquareMatrix::getN()
{
	return n;
}

SquareMatrix& SquareMatrix::additioner(SquareMatrix& matrixToAdd)
{
	// TODO Exception minimalist
	try
	{
		if (!isCompatible(matrixToAdd))
		{
			throw 20;
		}
		SquareMatrix* matrixResult = new SquareMatrix(n);
		for (int i = 1; i <= n; i++)
		{
			matrixResult->arrayElements[i-1]=matrixToAdd.arrayElements[i-1]+this->arrayElements[i-1];
		}
		return *matrixResult;
        
	} catch (int e)
	{
		std::cout << "Your matrices are not compatible. Killing program ... "
        << std::endl;
		exit(1);
	}
}

SquareMatrix& SquareMatrix::substract(SquareMatrix& matrixToSubstract)
{
	try
	{
		if (!isCompatible(matrixToSubstract))
		{
			throw 20;
		}
        
		SquareMatrix* matrixResult = new SquareMatrix(n);
		for (int i = 1; i <= n; i++)
		{
            //TODO
		}
		return *matrixResult;
	} catch (int e)
	{
		std::cout << "Your matrices are not compatible for substraction. Killing program ... " << std::endl;
		exit(1);
	}
}

unsigned int SquareMatrix::index(int x,int y)//row major indexation
{
    return y*n+x;
}