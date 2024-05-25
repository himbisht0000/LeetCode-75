class Solution {
public:
    int correct_value(int i , int j, int m, int n)
    {
        if( i + 1 >= m)
        return 1;

        if( j + 1 >= n)
        return 1;

        return 0;
    }

    int longestCommonSubsequence(string text1, string text2) {
        int matrix[text1.size()][text2.size()];
        int a =0,b=0;
        memset(matrix,0,sizeof(int) * text1.size()*text2.size() );


        for(int i = text1.size()-1; i >=0 ; i--)
        {
            for(int j = text2.size()-1; j >=0 ; j--)
            {
                if(text1[i] == text2[j])
                {
                if(correct_value(i,j,text1.size(),text2.size()))
                    matrix[i][j] = 1 ;
                else
                     matrix[i][j] = 1 + matrix[i+1][j+1];
                }
                else
                {
                    a = b =0;
                    if( i+1 >= text1.size())
                    a = 0;
                    else
                    a = matrix[i+1][j];

                    if( j+1 >= text2.size())
                    b = 0;
                    else
                    b = matrix[i][j+1];

                    matrix[i][j] = max(a,b);
                }
                
            }
        }

        return matrix[0][0];
    }
};
