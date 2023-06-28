#include "output.h"

void print_sudoku_field(std::vector<std::vector<int>> &field, std::ostream &output_stream) {
    if (field.size() != 9 || field[0].size() != 9) {
        throw std::invalid_argument("sudoku field must be 9x9");
    }
    for (std::vector<int> & i : field) {
        for (int j : i) {
            output_stream << j << " ";
        }
        output_stream << std::endl;
    }
}