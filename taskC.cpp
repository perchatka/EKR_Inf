#include <iostream>
#include <set>
#include <vector>
#include <string>

std::string str = "AFIN";
std::set<char> glas;
std::vector<std::vector<char> > ans;
std::vector<char> t;

void fun(int &n, int &m)
{
    if(t.size() == n)
    {
        int cnt = 0;
        for(int i = 0; i < t.size(); ++i)
        {
            if(glas.find(t[i]) != glas.end())   ++cnt;
        }
        if(cnt >= m)
        {
            ans.push_back(t);
        }
    }
    else
    {
        for(int i = 0; i < 4; ++i)
        {
            t.push_back(str[i]);
            fun(n, m);
            t.pop_back();
        }
    }
}

int main()
{
    glas.emplace('A'); glas.emplace('I');
    int n, m, k; std::cin>>n>>m>>k;
    fun(n, m);
    if(k - 1 >= ans.size())
        std::cout<<"ERROR\n";
    else
    {
        std::cout<<ans.size()<<' ';
        for(auto i : ans[k - 1])
        {
            std::cout<<i;
        }
        std::cout<<'\n';
    }
}
