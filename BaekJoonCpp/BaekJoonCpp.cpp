// BaekJoonCpp.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int* BubbleSort(int A[], int  n)
{
	for (int i = 0; i < n - 1; i++)
	{

		// 단계: (n-1)번 반복 
		for (int j = 0; j < n - 1; j++)   // 왼쪽에서 오른쪽으로 진행하는 경우    
		{
			if (A[j] > A[j + 1])
			{
				// ‘왼쪽 데이터 >오른쪽 데이터’이면
				// A[j]와 A[j + 1]의 자리바꿈;
				int temp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = temp;
			}
		}
		for (int j = 0; j < n; j++)   // 왼쪽에서 오른쪽으로 진행하는 경우    
		{
			std::cout << A[j] << " ";
		}
		std::cout << std::endl;
	}
	return A;
}

int* InsertionSort(int A[], int n)
{
	for (int i = 1; i < n; i++)
	{
		// A[0] 정렬 부분;  1, …, (n-1)까지 (n-1)번 반복 
		int val = A[i];
		// 미정렬 부분 A[i..n-1]의 첫 번째 데이터 선택 
		int j;

		for (j = i; j > 0 && A[j - 1] > val; j--)
		{
			// 삽입할 위치 찾기
			A[j] = A[j - 1];
		}
		A[j] = val;	// 최종적으로 val을 적절한 위치에 삽입

		for (int j = 0; j < n; j++)   // 왼쪽에서 오른쪽으로 진행하는 경우    
		{
			std::cout << A[j] << " ";
		}
		std::cout << std::endl;

	}
	return (A);
}

int main()
{
	int arr[6] = { 30, 60, 10, 50, 20, 40 };
	int length = sizeof(arr) / sizeof(arr[0]);
	//BubbleSort(arr, length);

	InsertionSort(arr, length);

}

