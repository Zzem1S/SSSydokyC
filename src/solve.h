#pragma once

#include "utils.h"

#include <stdexcept>
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>

std::set<int> get_possible_values_from_row(std::vector<int> &row);

std::set<int> get_possible_values_for_coordinates(std::vector<std::vector<int>> &field, int i, int j);

int get_number(std::vector<std::vector<int>> &field, int i, int j);

bool check_if_filled_correctly(std::vector<std::vector<int>> &field);

bool solve(std::vector<std::vector<int>> &field);
