class Solution
{
public:
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        int cut[3];
        cut[0] = x;
        cut[1] = y;
        cut[2] = z;
        int t[4][n + 1];

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < n + 1; j++)
            {
                if (i == 0)
                {
                    t[i][j] = INT_MIN;
                }
                if (j == 0)
                {
                    t[i][j] = 0;
                }
            }
        }
        for (int i = 1; i < 4; i++)
        {
            for (int j = 1; j < n + 1; j++)

            {
                if (cut[i - 1] <= j)
                {
                    t[i][j] = max(t[i - 1][j], t[i][j - cut[i - 1]] + 1);
                }
                else
                {
                    t[i][j] = t[i - 1][j];
                }
            }
        }
        if (t[3][n] < 0)
        {
            return 0;
        }
        return t[3][n];
    }
};