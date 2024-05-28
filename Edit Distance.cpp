class Solution {
public:
    int minDistance(string word1, string word2) {
        int matrix[word1.length() + 1][word2.length()+1 ];
        int value ;
        memset(matrix,0,sizeof(matrix));

        matrix[word1.length()][word2.length()] = 0;

        value = word2.length();
        for(int i = 0 ; i <= word2.length();i++)
        {
            matrix[word1.length()][i] = value;
            value--; 
        }

        value = word1.length();
        for(int i = 0 ; i <= word1.length();i++)
        {
            matrix[i][word2.length()]= value;
            value--; 
        }

        for(int i = word1.size()-1 ; i>=0 ;i--)
        {
            for(int j = word2.size()-1 ; j >=0 ; j--)
            {
                if(word1[i] == word2[j])
                {
                    matrix[i][j] = matrix[i+1][j+1];
                }
                else
                {
                    int temp ;
                    temp = min( matrix[i+1][j+1] , matrix[i+1][j]);               
                    matrix[i][j] = 1 +  min(temp, matrix[i][j+1]);
                }
                
            }
        }

        return matrix[0][0];
    }
};
