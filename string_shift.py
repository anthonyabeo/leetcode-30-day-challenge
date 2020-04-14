from typing import List

class Solution:
    def stringShift(self, s: str, shift: List[List[int]]) -> str:
        N = len(s)
        SN = len(shift)
        agg_shifts = 0;
        str = []

        for i in range(SN):
            if shift[i][0] == 1: agg_shifts += shift[i][1];
            else: agg_shifts -= shift[i][1];

        for j in range(N):
            index = (j + agg_shifts) % N
            str.insert(index, s[j])

        return "".join(str)