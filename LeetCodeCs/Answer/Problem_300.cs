using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection.Emit;
using System.Text;
using System.Threading.Tasks;

namespace LeetCodeCS
{
    internal class Problem_300
    {
        static public int LengthOfLIS(int[] nums)
        {
            int[] assendingLength = new int[nums.Length]; // 기본값 0 초기화
            int max = -1;    // i보다 작은 nums의 인덱스 중에서 nums의 값이 최대가 되는 인덱스
            int answer = 0; // assendingLength[i] 중에서 최댓값
            for (int i = 0; i < nums.Length; i++)
            {
                max = -1;   // 초기값은 -1
                assendingLength[i] = 1; // 자기자신 1개는 포함
                // i번째의 수가 마지막이다
                for (int j = 0; j < i; j++)
                {
                    // 0~i-1 까지 순회하며 i보다 작은 숫자들 오름차순으로 표시
                    // i 보다는 작아야 한다
                    if (nums[j] < nums[i])
                    {
                        // max의 갱신 문제
                        if (max == -1 || assendingLength[max] < assendingLength[j])
                        {
                            max = j;
                        }
                    }
                }
                // 그런데.. 더하면 안될 때가 있다
                // 끝나면 nums[i]보다 작은 nums[j]가 최대가 되게 하는 j가 max에 저장
                // 유효한 max가 존재할 때만 더하기
                if (max != -1 && (nums[max] < nums[i]))
                {
                    assendingLength[i] += assendingLength[max];
                }
                answer = answer > assendingLength[i] ? answer : assendingLength[i];
            }
            return answer;
        }
    }
}
