#include <iostream>
#include <exception>

#include "gridPlay.hpp"

void cf::GridPlay::display() const
{
    std::string str = "\033[2J\033[1;1H";
    str+="|\n---------------------\n";
    for(auto const& r : m_grid){
        for(auto const& c : r){
            str+="|"+c;
        }
        str+="|\n---------------------\n";
    }
    std::cout<<str<<std::flush;
}

cf::gridType const &cf::GridPlay::getGrid() const
{
    return m_grid;
}

bool cf::GridPlay::isEmptyCell(int i, int j) const
{
    if(0 < i && i < 8 && 0 < j && j < 7){
        return m_grid[i-1][j-1].empty();
    }else throw std::range_error("i = "+std::to_string(i)+" j = "+std::to_string(j)+"\n0 < i && i > 8 && 0 < j && j > 7");
}

bool cf::GridPlay::move(size_t from_i, size_t from_j, size_t to_i, size_t to_j)
{
    if(!isEmptyCell(from_i,from_j) && isEmptyCell(to_i,to_j)){
        m_grid[to_i][to_j] = m_grid[from_i][from_j];
        m_grid[from_i][from_j].clear();
        return true;
    }
    return false;
}
