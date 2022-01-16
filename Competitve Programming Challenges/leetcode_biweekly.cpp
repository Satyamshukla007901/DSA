int minMoves(int target, int maxDoubles)
{

    if (maxDoubles == 0)
    {
        return target - 1;
    }
    else if ((target & (target - 1)) == 0)
    {
        return (int)(log2(target));
    }
    int cnt = 0;
    while (target > 1)
    {
        if (maxDoubles)
        {
            if (target % 2 == 0)
            {
                target /= 2;
                cnt++;
                maxDoubles--;
            }
            else
            {
                target--;
                cnt++;
            }
        }
        else
        {
            cnt += (target - 1);
            target = 1;
        }
    }
    return cnt;
}
//min step to reach target from 1 is only increements and doubles are allowed