#include <iostream>

using namespace std;

struct Applicant
{
	int paper;
	int interview;
};

void CustomSwap(Applicant* a, Applicant* b)
{
	Applicant temp = *a;
	*a = *b;
	*b = temp;
}

void Heapify(Applicant applicants[], int n, int i)
{
	while (true)
	{
		int largest = i;
		int left = i * 2 + 1;
		int right = i * 2 + 2;

		if (left < n && applicants[left].paper > applicants[largest].paper)
			largest = left;
		if (right < n && applicants[right].paper > applicants[largest].paper)
			largest = right;

		if (largest == i)
			break;

		CustomSwap(&applicants[i], &applicants[largest]);
		i = largest;
	}
}

void HeapSort(Applicant applicants[], int n)
{	
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		Heapify(applicants, n, i);
	}
		
	for (int i = n - 1; i > 0; i--)
	{
		CustomSwap(&applicants[0], &applicants[i]);  
		Heapify(applicants, i, 0);    
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T;
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;
		Applicant* applicants = new Applicant[N];
		for (int i = 0; i < N; i++)
		{
			cin >> applicants[i].paper >> applicants[i].interview;
		}

		HeapSort(applicants, N);
		
		int count = 1;
		int bestInterview = applicants[0].interview;
		for (int i = 1; i < N; i++)
		{
			if (applicants[i].interview < bestInterview)
			{
				count++;
				bestInterview = applicants[i].interview;
			}
		}

		cout << count << '\n';
		delete[] applicants;
	}

	return 0;
}