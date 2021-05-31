#include <iostream>
#include <cmath>

int main()
{
    int del[3];
    int a, b, c = 0, mx = 0, mxNum = 0;
    std::cin>>a>>b;
    for(int i = a; i <= b; ++i)
    {
        del[0] = 0; del[1] = 0; del[2] = 0;
        int cnt = 0;
        for(int j = 2; j <= i && cnt < 3;)
        {
            if(i % j == 0)
            {
                del[cnt] = j;
                ++cnt;
                j += 10;
                for(; j <= i && cnt < 3;)
                {
                    if(i % j == 0)
                    {
                        del[cnt] = j;
                        ++cnt;
                    }
                    j += 10;
                }
            }
            else
                ++j;
        }

        bool cl = 0;
        for(int k = 0; k < 3; ++k)
        {
            for(int d = 2; d <= std::sqrt(del[k]); ++d)
            {
                if(del[k] % d == 0)
                {
                    cl = 1;
                    break;
                }
            }
            if(cl)  break;
        }
        if(cl)  continue;

        int r = del[2] - del[0];
        if(del[0] * del[1] * del[2] == i && del[0] != del[1] && del[0] != del[2])
        {
            if(del[0] % 10 == del[1] % 10 && del[0] % 10 == del[2] % 10)
            {
                ++c;
                if(r > mx)
                {
                    mx = r;
                    mxNum = i;
                }
            }
        }
    }
    std::cout<<c<<' '<<mxNum<<'\n';
    return 0;
}