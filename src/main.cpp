#include <iostream>
#include "input.h"
#include "solve.h"
#include "output.h"

int main() {
    std::vector<std::vector<int>> field = parse_input_to_vector();
    if (solve(field)) {
        print_sudoku_field(field);
    } else {
        std::cout << "Could not solve this sudoku" << std::endl;
    }
}
