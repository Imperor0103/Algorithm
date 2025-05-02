#pragma once
#include <iostream>
/*
P147355
���ڷ� �̷���� ���ڿ� t�� p�� �־��� ��, t���� p�� ���̰� ���� �κй��ڿ� �߿���,
�� �κй��ڿ��� ��Ÿ���� ���� p�� ��Ÿ���� ������ �۰ų� ���� ���� ������ Ƚ���� return�ϴ� �Լ� solution�� �ϼ��ϼ���.

���� ���, t = "3141592"�̰� p = "271" �� ���, t�� ���̰� 3�� �κ� ���ڿ��� 314, 141, 415, 159, 592�Դϴ�.
�� ���ڿ��� ��Ÿ���� �� �� 271���� �۰ų� ���� ���� 141, 159 2�� �Դϴ�.
*/


int solution147355(const char* t, const char* p)
{
	int answer = 0;

	// p�� ���ڼ��� ã�´�
	int pLength = 0;
	while (p[pLength] != '\0')
	{
		pLength++;
	}
	// t���� �ϳ��� ������ ���ڼ���ŭ �ڸ���
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
				break;	// �� ��
			}
			else if (t[i + j] == p[j])
			{
				isHigher = false;	// ������ �ѹ� �� ��
			}
			else
			{
				isHigher = true;
				break;	// �� ��
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
