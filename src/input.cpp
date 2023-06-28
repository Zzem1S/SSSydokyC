#include "input.h"

std::vector<std::vector<int>> parse_input_to_vector() {
    std::vector<std::vector<int>> out(ROWS, std::vector<int>(COLUMNS));
    std::string temp;
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLUMNS; ++j) {
            std::cin >> temp;
            try {
                int num;
                num = stoi(temp);
                if (num >= 0 && num <= 9) {
                    out[i][j] = num;
                } else {
                    std::cout << num << " " << temp << std::endl;
                    throw std::invalid_argument("inputs must be from 0 to 9");
                }
            } catch (std::invalid_argument const &ex) {
                throw std::invalid_argument("could not read one of inputs as an integer or integer is not in [0, 9] range");
            }
        }
    }
    return out;
}




//bool is_valid_cell(std::vector<std::vector<int>> &cell) {
//    std::set<int> digits;
//    bool status = true;
//    for (std::vector<int> & i : cell) {
//        for (int j : i) {
//            if (digits.contains(j)) {
//                status = false;
//            }
//            digits.insert(j);
//        }
//    }
//    return status;
//}