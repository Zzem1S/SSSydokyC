#include "solve.h"

std::set<int> get_possible_values_from_row(std::vector<int> &row) {
    if (row.size() != 9) {
        throw std::invalid_argument("row length must be 9");
    }
    std::set<int> ans {1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (int i : row) {
        ans.erase(i);
    }
    return ans;
}

std::set<int> get_possible_values_for_coordinates(std::vector<std::vector<int>> &field, int i, int j) {
    if (i < 0 || i > 8) {
        throw std::invalid_argument("i must be in range [0, 8]");
    }
    if (j < 0 || j > 8) {
        throw std::invalid_argument("j must be in range [0, 8]");
    }
    if (field.size() != 9 || field[0].size() != 9) {
        throw std::invalid_argument("field size must be 9x9");
    }

    std::vector<int> row = field[i];
    std::set<int> possible_nums_in_row = get_possible_values_from_row(row);

    std::vector<int> column = get_column(field, j);
    std::set<int> possible_nums_in_column = get_possible_values_from_row(column);

    std::vector<int> cell = get_cell(field, (i / 3) * 3 + j / 3);
    std::set<int> possible_nums_in_cell = get_possible_values_from_row(cell);

    std::set<int> result1;
    std::set_intersection(possible_nums_in_row.begin(), possible_nums_in_row.end(),
                          possible_nums_in_column.begin(), possible_nums_in_column.end(),
                          std::inserter(result1, result1.begin()));

    std::set<int> result2;
    std::set_intersection(result1.begin(), result1.end(),
                          possible_nums_in_cell.begin(), possible_nums_in_cell.end(),
                          std::inserter(result2, result2.begin()));
    return result2;
}

int get_number(std::vector<std::vector<int>> &field, int i, int j) {
    if (i < 0 || i > 8) {
        throw std::invalid_argument("i must be in range [0, 8]");
    }
    if (j < 0 || j > 8) {
        throw std::invalid_argument("j must be in range [0, 8]");
    }
    if (field.size() != 9 || field[0].size() != 9) {
        throw std::invalid_argument("field size must be 9x9");
    }
    std::set<int> possible_values = get_possible_values_for_coordinates(field, i, j);
    if (possible_values.size() == 1) {
        int number = *possible_values.begin();  // first element of possible_values set
        return number;
    } else {
        return -1;
    }
}

bool check_if_filled_correctly(std::vector<std::vector<int>> &field) {
    if (!is_valid_sudoku_field(field)) {
        return false;
    }
    for (std::vector<int> & i : field) {
        for (int j : i) {
            if (j == 0) {
                return false;
            }
        }
    }
    return true;
}

bool solve(std::vector<std::vector<int>> &field) {
    if (field.size() != 9 || field[0].size() != 9) {
        throw std::invalid_argument("field size must be 9x9");
    }
    for (int i = 0; i < field.size(); ++i) {
        for (int j = 0; j < field[0].size(); ++j) {
            if (field[i][j] == 0) {
                int temp = get_number(field, i, j);
                if (temp > 0) {
//                    std::cout << "Changed number: i = " << i << ", j = " << j << " from " <<
//                                field[i][j] << " to " << temp << std::endl;
                    field[i][j] = temp;
                    i = 0;
                    j = 0;
                }
            }
        }
    }
    if (check_if_filled_correctly(field)) {
        return true;
    } else {
        for (int i = 0; i < field.size(); ++i) {
            for (int j = 0; j < field[0].size(); ++j) {
                if (field[i][j] == 0) {
                    std::set<int> possible_numbers = get_possible_values_for_coordinates(field, i, j);
                    if (possible_numbers.size() < 4) {
                        for (int num : possible_numbers) {
                            field[i][j] = num;
                            auto field_copy = field;
                            if (solve(field)) {
                                return true;
                            }
                            field = field_copy;
                        }
                    }
                }
            }
        }
    }
    return false;
}
