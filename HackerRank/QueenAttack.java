class Solution
{
    static void Main(String[] args)
    {
        string[] tokens_n = Console.ReadLine().Split(' ');
        int n = Convert.ToInt32(tokens_n[0]);
        int k = Convert.ToInt32(tokens_n[1]);
        string[] tokens_rQueen = Console.ReadLine().Split(' ');
        int rQueen = Convert.ToInt32(tokens_rQueen[0]);
        int cQueen = Convert.ToInt32(tokens_rQueen[1]);

        //Calculate the distances between Queen and edge of board in all directions
        int barrier_above = n - rQueen;
        int barrier_below = rQueen - 1 ;S
        int barrier_right = n - cQueen;
        int barrier_left = cQueen - 1;
        int barrier_up_right = n - Math.Max(rQueen, cQueen);
        int barrier_down_right = Math.Min(n-cQueen, rQueen - 1);
        int barrier_up_left = Math.Min(n-rQueen, Math.Abs(1 - cQueen));
        int barrier_down_left = Math.Min(rQueen, cQueen) - 1;

        for(int a0 = 0; a0 < k; a0++)
        {
            string[] tokens_rObstacle = Console.ReadLine().Split(' ');
            int rObstacle = Convert.ToInt32(tokens_rObstacle[0]);
            int cObstacle = Convert.ToInt32(tokens_rObstacle[1]);

            //Check if obstacle is in-line with Queens in all directions
            //If in-line, check if distance between them is less than the current distance
            if( (cObstacle == cQueen && rObstacle > rQueen) && rObstacle - rQueen < barrier_above)
            {
                barrier_above = rObstacle - rQueen - 1;
            }
            else if( (cObstacle == cQueen && rObstacle < rQueen) && rQueen - rObstacle < barrier_below)
            {
                barrier_below = rQueen - rObstacle - 1;
            }
            else if( (rObstacle == rQueen && cObstacle < cQueen) && cQueen - cObstacle < barrier_left)
            {
                barrier_left = cQueen - cObstacle - 1;
            }
            else if( (rObstacle == rQueen && cObstacle > cQueen) && cObstacle - cQueen < barrier_right)
            {
                barrier_right = cObstacle - cQueen - 1;
            }
            else if((rObstacle > rQueen && cObstacle > cQueen) &&
                    (rObstacle-rQueen == cObstacle-cQueen) &&
                    (rObstacle - rQueen < barrier_up_right)
            {
                barrier_up_right = rObstacle - rQueen - 1;
            }
            else if((rObstacle < rQueen && cObstacle < cQueen) &&
                    (rQueen-rObstacle == cQueen-cObstacle) &&
                    (rQueen - rObstacle < barrier_down_left)
            {
                barrier_down_left = rQueen - rObstacle - 1;
            }
            else if((rObstacle < rQueen && cObstacle > cQueen) &&
                    (rQueen-rObstacle == cObstacle-cQueen) &&
                    (rQueen-rObstacle < barrier_down_right){
                barrier_down_right = rQueen-rObstacle - 1;
            }
            else if((rObstacle > rQueen && cObstacle < cQueen) &&
                    (rObstacle-rQueen == cQueen-cObstacle) &&
                    (rObstacle-rQueen < barrier_up_left)
            {
                barrier_up_left = rObstacle-rQueen - 1;
            }
        }
        //Sum up the distances between Queen and barriers in all directions
        int sum = barrier_above +
                  barrier_below +
                  barrier_right +
                  barrier_left +
                  barrier_up_left +
                  barrier_up_right +
                  barrier_down_left +
                  barrier_down_right;

        Console.WriteLine(sum);
    }
}
