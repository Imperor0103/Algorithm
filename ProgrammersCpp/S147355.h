#pragma once
#include <iostream>
/*
P147355
숫자로 이루어진 문자열 t와 p가 주어질 때, t에서 p와 길이가 같은 부분문자열 중에서,
이 부분문자열이 나타내는 수가 p가 나타내는 수보다 작거나 같은 것이 나오는 횟수를 return하는 함수 solution을 완성하세요.

예를 들어, t = "3141592"이고 p = "271" 인 경우, t의 길이가 3인 부분 문자열은 314, 141, 415, 159, 592입니다.
이 문자열이 나타내는 수 중 271보다 작거나 같은 수는 141, 159 2개 입니다.
*/


int solution147355(const char* t, const char* p)
{
	int answer = 0;

	// p의 글자수를 찾는다
	int pLength = 0;
	while (p[pLength] != '\0')
	{
		pLength++;
	}
	// t에서 하나씩 읽으며 글자수만큼 자른다
	int i = 0;
	while (t[i + pLength - 1] != '\0')
	{
		bool isHigher = t[i] > p[0] ? true : false;
		int j = 0;
		while (j < pLength && !isHigher)
		{
			if (t[i + j] < p[j])
			{
				isHigher = false;
				break;	// 비교 끝
			}
			else if (t[i + j] == p[j])
			{
				isHigher = false;	// 같으면 한번 더 비교
			}
			else
			{
				isHigher = true;
				break;	// 비교 끝
			}
			j++;
		}
		if (!isHigher)
		{
			answer++;
		}
		i++;
	}
	return answer;
}
