#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\admin\source\repos\Project_7.2_rec\Project_7.2_rec\lab_7.2_rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const int n = 3;

			// Створюємо та заповнюємо тестову матрицю 3x3
			int** testMatrix = new int* [n];
			for (int i = 0; i < n; i++)
				testMatrix[i] = new int[n];

			testMatrix[0][0] = 1; testMatrix[0][1] = 2; testMatrix[0][2] = 3;
			testMatrix[1][0] = 4; testMatrix[1][1] = 5; testMatrix[1][2] = 6;
			testMatrix[2][0] = 7; testMatrix[2][1] = 8; testMatrix[2][2] = 9;

			// Викликаємо функцію Transpose
			Transpose(testMatrix, n);

			// Очікувана транспонована матриця:
			// 1 4 7
			// 2 5 8
			// 3 6 9

			// Перевіряємо правильність транспонування
			Assert::AreEqual(1, testMatrix[0][0]);
			Assert::AreEqual(4, testMatrix[0][1]);
			Assert::AreEqual(7, testMatrix[0][2]);
			Assert::AreEqual(2, testMatrix[1][0]);
			Assert::AreEqual(5, testMatrix[1][1]);
			Assert::AreEqual(8, testMatrix[1][2]);
			Assert::AreEqual(3, testMatrix[2][0]);
			Assert::AreEqual(6, testMatrix[2][1]);
			Assert::AreEqual(9, testMatrix[2][2]);

			// Звільняємо пам'ять
			for (int i = 0; i < n; i++)
				delete[] testMatrix[i];
			delete[] testMatrix;
		}
	};
}
