#pragma once
#include <iostream>
/*
P181878
알파벳으로 이루어진 문자열 myString과 pat이 주어집니다.
myString의 연속된 부분 문자열 중 pat이 존재하면 1을 그렇지 않으면 0을 return 하는 solution 함수를 완성해 주세요.

단, 알파벳 대문자와 소문자는 구분하지 않습니다.
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
