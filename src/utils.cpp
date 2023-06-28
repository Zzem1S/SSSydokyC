#include "utils.h"

std::vector<int> get_column(std::vector<std::vector<int>> &field, int j) {      // cast column to 1d vector
    if (field.empty() || field.size() != 9 || field[0].size() != 9) {
        return std::vector<int> {0};
    }
    std::vector<int> column(field.size());
    for (int i = 0; i < ROWS; ++i) {
        column[i] = field[i][j];
    }
    return column;
}

std::vector<int> get_cell(std::vector<std::vector<int>> &field, int n) {        // cast cell to 1d vector
    if (field.empty() || field.size() != 9 || field[0].size() != 9) {
        return std::vector<int> {0};
    }
    int start_column_number = (n % 3) * 3;      // some number magic
    int start_row_number = n / 3 * 3;
    std::vector<int> cell(ROWS);
    for (int j = start_row_number; j < start_row_number + 3; ++j) {
        for (int k = start_column_number; k < start_column_number + 3; ++k) {
            cell[(j - start_row_number) * 3 + (k - start_column_number)] = field[j][k];
        }
    }
    return cell;
}

bool is_valid_row(std::vector<int> &row) {
    if (row.size() != 9) {
        return false;
    }
    std::set<int> digits;
    for (int i : row) {
        if (digits.contains(i) || i == 0) {
            return false;
        }
        digits.insert(i);
    }
    return true;
}

bool is_valid_sudoku_field(std::vector<std::vector<int>> &field) {
    if (field.size() != 9 || field[0].size() != 9) {
        return false;
    }
    for (std::vector<int> & row : field) {      // checking strings
        if (!is_valid_row(row)) {
            return false;
        }
    }
    for (int i = 0; i < COLUMNS; ++i) {         // checking columns
        std::vector<int> column = get_column(field, i);
        if (!is_valid_row(column)) {
            return false;
        }
    }
    for (int i = 0; i < CELL_NUM; ++i) {                    // checking cells
        std::vector<int> cell = get_cell(field, i);
        if (!is_valid_row(cell)) {
            return false;
        }
    }
    return true;
}
