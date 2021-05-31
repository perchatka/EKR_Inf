#include <iostream>
#include <cmath>

int main()
{
    int a, b, cnt = 0, mx = a; std::cin>>a>>b;
    int sc;
    for(int i = a; i <= b; ++i)
    {
        sc = std::abs(i) % 100;
        int fs = std::abs(i);
        while(fs >= 100)
        {
            fs /= 10;
        }
        if(std::abs(i) > 9 && fs != sc && i % (fs - sc) == 0)
        {
            ++cnt;
            mx = i;
        }
    }
    std::cout<<cnt<<' '<< mx<<'\n';
    return 0;
}
