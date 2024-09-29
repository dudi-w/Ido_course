#ifndef GRID_PLAY_HPP
#define GRID_PLAY_HPP

#include <array>
#include <string>

namespace cf {

using gridType = std::array<std::array<std::string,6>,7>;
class GridPlay
{
public:
    GridPlay() = default;
    GridPlay(GridPlay const& other) = default;
    GridPlay& operator=(GridPlay const& other) = default;
    ~GridPlay() = default;

    void display() const;
    cf::gridType const& getGrid() const;
    bool isEmptyCell(int i, int j) const;
    bool insert(int i, int j, std::string_view shape);
    bool move(size_t from_i, size_t from_j, size_t to_i, size_t to_j);

private:
    cf::gridType m_grid;
};

}// namespace cf

#endif
