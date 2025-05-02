#pragma once
#include <iostream>
/*
P181878
���ĺ����� �̷���� ���ڿ� myString�� pat�� �־����ϴ�.
myString�� ���ӵ� �κ� ���ڿ� �� pat�� �����ϸ� 1�� �׷��� ������ 0�� return �ϴ� solution �Լ��� �ϼ��� �ּ���.

��, ���ĺ� �빮�ڿ� �ҹ��ڴ� �������� �ʽ��ϴ�.
*/

#include <stdlib.h>	// malloc
#include <string.h>
#include <stdbool.h>

int solution181878(const char* myString, const char* pat)
{
	int answer = 0;

	int myLength = strlen(myString);
	int patLength = strlen(pat);

	if (myLength < patLength)
		return 0;

	char* myLower = (char*)malloc(sizeof(char) * (myLength + 1));
	char* patLower = (char*)malloc(sizeof(char) * (patLength + 1));

	for (int i = 0; i < myLength; i++)
	{
		myLower[i] = (myString[i] >= 'A' && myString[i] <= 'Z') ? (myString[i] + 32) : myString[i];
	}
	myLower[myLength] = '\0';

	for (int i = 0; i < patLength; i++)
	{
		patLower[i] = (pat[i] >= 'A' && pat[i] <= 'Z') ? (pat[i] + 32) : pat[i];
	}
	patLower[patLength] = '\0';


	int i = 0;
	while (myLower[i + patLength - 1] != '\0')
	{
		bool isSame = myLower[i] == patLower[0] ? true : false;
		int j = 0;
		while (j < patLength && isSame)
		{
			if (myLower[i + j] != patLower[j])
			{
				isSame = false;
				break;
			}
			else
			{
				isSame = true;
			}
			j++;
		}
		if (isSame)
		{
			answer = 1;
			break;
		}
		i++;
	}
	free(myLower);
	free(patLower);

	return answer;
}
