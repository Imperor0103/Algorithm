using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LeetCodeCS
{
    internal class Problem_84
    {
        static public int FindLargestRect(int[] heightArr)
        {
            Stack<int> heightIndex = new Stack<int>();  // 높이의 인덱스를 저장하는 스택
            int[] leftBounds = new int[heightArr.Length];   // 그 높이의 왼쪽 경계를 저장
            int[] rightBounds = new int[heightArr.Length];  // 그 높이의 오른쪽 경계를 저장
            for (int i = 0; i < heightArr.Length; i++)
            {
                while (heightIndex.Count != 0 && heightArr[heightIndex.Peek()] >= heightArr[i])
                {
                    // 이전 루프에서 왼쪽의 경계만 확정하고 스택에 넣었던 것들의 오른쪽 경계를 확정한다
                    int top = heightIndex.Pop();
                    if (heightArr[top] >= heightArr[i])
                    {
                        // 스택에 저장된 맨 꼭대기의 오른쪽 경계
                        rightBounds[top] = i - 1;
                    }
                }
                // while 루프가 해제된 것은 heightArr[top] 높이가 heightArr[i] 보다 작거나, 스택이 비었기 때문
                // 최소높이의 인덱스를 저장하기 직전에는 스택이 비어있게 된다
                // 이는 heightArr에 저장되어있는 순서와 연관이 있다
                // 스택이 비어있지 않다면, heightArr[i]는 최솟값이 아니므로 i의 왼쪽 경계는 스택의 맨 위에 저장된 인덱스+1이다
                leftBounds[i] = heightIndex.Count == 0 ? 0 : heightIndex.Peek() + 1;
                // 현재 인덱스를 저장한다
                heightIndex.Push(i);
            }
            // 스택에 남아 있는 것들의 오른쪽 경계는 마지막 인덱스이다
            while (heightIndex.Count != 0)
            {
                rightBounds[heightIndex.Pop()] = heightArr.Length - 1;
            }
            // 이제 넓이 비교하자
            int maxRect = 0;
            for (int i = 0; i < heightArr.Length; i++)
            {
                maxRect = maxRect > heightArr[i] * (rightBounds[i] - leftBounds[i] + 1) ?
                    maxRect : heightArr[i] * (rightBounds[i] - leftBounds[i] + 1);
            }
            return maxRect;
        }

    }
}
