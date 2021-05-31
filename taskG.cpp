#include <iostream>
#include <vector>
#include <set>

int col, fcol, m, n;
std::set<std::vector<int> > was;
void func(std::vector<std::vector<int> > &v, int x, int y)
{
    v[x][y] = col;
    std::vector<int> coord = {x, y};
    was.emplace(coord);
    if(x != 0 && was.find({x - 1, y}) == was.end() && v[x - 1][y] == fcol) func(v, x - 1, y);
    if(x != n - 1 && was.find({x + 1, y}) == was.end() && v[x + 1][y] == fcol) func(v, x + 1, y);
    if(y != 0 && was.find({x, y - 1}) == was.end() && v[x][y - 1] == fcol) func(v, x, y - 1);
    if(y != m - 1 && was.find({x, y + 1}) == was.end() && v[x][y + 1] == fcol) func(v, x, y + 1);
}

int main()
{
    std::cin>>m>>n;
    int x, y; std::cin>>y>>x; --x; --y;
    std::cin>>col;
    std::vector<std::vector<int> > v(m, std::vector<int>(n));
    for(int j = 0; j < n; ++j)
        for(int i = 0; i < m; ++i)
            std::cin>>v[i][j];
    fcol = v[x][y];
    func(v, x, y);

    for(int j = 0; j < n; ++j)
    {
        for(int i = 0; i < m; ++i)
        {
            std::cout<<v[i][j]<<' ';
        }
        std::cout<<'\n';
    }
    return 0;
}
