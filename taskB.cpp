#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <map>

int main()
{
    std::ifstream fin("input.txt");
    std::string str;
    std::getline(fin, str);
    fin.close();
    std::map<char, int> was;

    int cnt, mx = -1;
    char mxC;
    bool ended = 0;

    for(int c = 0; c < str.size(); ++c)
    {
        if(was.find(str[c]) == was.end())
        {
            was.insert({str[c], c});
        }
        else
        {
            ended = 1;
            cnt = c - was[str[c]] - 1;
            if(cnt > mx || cnt == mx && (int)mxC > (int)str[c])
            {
                mx = cnt;
                mxC = str[c];
            }
        }
    }
    if(!ended) std::cout<<0<<'\n';
    else std::cout<<mxC<<' '<<mx<<'\n';
}
