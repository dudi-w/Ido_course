#include <iostream>
#include <exception>

#include "gridPlay.hpp"

void cf::GridPlay::display() const
{
    std::string str;// = "\033[2J\033[1;1H";
    str+="\n-----------------------\n";
    for(size_t j = 0 ; j <m_grid[0].size(); ++j){
        for(size_t i = 0 ; i < m_grid.size(); ++i){
            str+=m_grid[i][j].empty()?"|  ":"|"+m_grid[i][j];
        }
        str+="|\n-----------------------\n";
    }
    std::cout<<str<<std::flush;
}

cf::gridType const &cf::GridPlay::getGrid() const
{
    return m_grid;
}

bool cf::GridPlay::isEmptyCell(int i, int j) const
{
    if(0 <= i && i < m_grid.size() && 0 <= j && j < m_grid[0].size()){
        return m_grid[i][j].empty();
    }else throw std::range_error("i = "+std::to_string(i)+" j = "+std::to_string(j)+"\n0 <= i && i < m_grid.size() && 0 <= j && j < m_grid[0].size()");
}

bool cf::GridPlay::insert(int i, int j, std::string_view shape){
    if(isEmptyCell(i,j)){
        m_grid[i][j] = shape;
        return true;
    }
    return false;
}

bool cf::GridPlay::move(size_t from_i, size_t from_j, size_t to_i, size_t to_j)
{
    std::cout<<from_i<<"  "<<from_j<<" "<<to_i<<" "<<to_j<<std::endl;
    if(to_j < m_grid[0].size() && !isEmptyCell(from_i,from_j) && isEmptyCell(to_i,to_j)){
        m_grid[to_i][to_j] = m_grid[from_i][from_j];
        m_grid[from_i][from_j].clear();
        return true;
    }
    return false;
}
