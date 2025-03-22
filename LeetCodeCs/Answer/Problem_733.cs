using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LeetCodeCS
{
    internal class Problem_733
    {
        static public int[][] FloodFill(int[][] image, int sr, int sc, int color)
        {
            int temp = image[sr][sc];
            if (temp == color)
            {
                return image;   // 기존과 같으면 바로 리턴
            }
            int row = image.Length;
            int col = image[0].Length;

            Stack<(int, int)> stack = new Stack<(int, int)>();
            stack.Push((sr, sc));

            while (stack.Count > 0)
            {
                (int r, int c) = stack.Pop();
                // 유효한 범위 내에서 같은 색상인지 확인 후 변경
                if (r < 0 || r >= row || c < 0 || c >= col || image[r][c] != temp)
                {
                    continue;
                }
                image[r][c] = color;
                //
                stack.Push((r - 1, c)); /// 왼
                stack.Push((r + 1, c)); /// 오른
                stack.Push((r, c - 1)); /// 위
                stack.Push((r, c + 1)); /// 아래
            }
            return image;
        }
    }
}