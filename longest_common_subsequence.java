class Solution {
    public int longestCommonSubsequence(String text1, String text2) {

        int s1Len = text1.length(), 
            s2Len = text2.length();

        int[][] solution = new int[s1Len+1][s2Len+1];

        for (int i = 1; i < s1Len + 1; i++) {
            for (int j = 1; j <  s2Len + 1; j++) {
                if(text1.charAt(i-1) == text2.charAt(j-1)) {
                    solution[i][j] = solution[i-1][j-1] + 1;
                } else {
                    solution[i][j] = Math.max(solution[i-1][j], solution[i][j-1]);
                }
            }
        }

        return solution[s1Len][s2Len];
    }
}