#pragma once

#include <vector>
#include <set>

enum {
    ROWS = 9, COLUMNS = 9, CELL_NUM = 9
};

std::vector<int> get_column(std::vector<std::vector<int>> &field, int j);

std::vector<int> get_cell(std::vector<std::vector<int>> &field, int n); // n - cell number

bool is_valid_row(std::vector<int> &row);

bool is_valid_sudoku_field(std::vector<std::vector<int>> &field);


/*
 *          [0] [1] [2]
 *          [3] [4] [5]
 *          [6] [7] [8]
 *
 *
 *          [0] [1] [2]
 *          [3] [4] [5]
 *          [6] [7] [8]
 */