#pragma once

#include <vector>

#include <iostream>

#include "bits_manipulation.hpp"

namespace cryptography {
    std::vector<std::vector<int>> to_t1x1(std::vector<std::vector<int>> original, std::vector<int> code) {
        std::vector<std::vector<int>> returner;
        std::vector<int> ret;
        std::vector<int> pos_vector;
        int counter;
        counter = 0;
        returner = {};

        if (code.size() != 8) {
            std::cerr << "[ERROR!] Code Length Error! [ERROR!]\n";
            return {};
        }

        for (int i = 0; i < code.size(); i++) {
            if (code[i] == 1) {
                pos_vector.push_back(i);
            }
        }

        for (int x = 0; x < original.size(); x++) {
            ret = {};
            for (int y = 0; y < original[x].size(); y++) {
                if (y == pos_vector[counter]) {
                    if (original[x][y] == 0) {
                        ret.push_back(1);
                    } else {
                        ret.push_back(0);
                    }
                } else {
                    ret.push_back(original[x][y]);
                }
            }
            returner.push_back(ret);

            if (counter == pos_vector.size()-1) {
                counter = 0;
            } else {
                counter++;
            }
        }

        returner.push_back(code);

        return returner;
    }

    std::vector<std::vector<int>> from_t1x1(std::vector<std::vector<int>> encrypted) {
        std::vector<std::vector<int>> returner;
        std::vector<int> code;

        code = encrypted[encrypted.size()-1];

        encrypted.pop_back();

        returner = to_t1x1(encrypted, code);
        returner.pop_back();

        return returner;
    }

    std::vector<std::vector<int>> to_t1x1_invert(std::vector<std::vector<int>> original, std::vector<int> code) {
        std::vector<std::vector<int>> returner;
        returner = to_t1x1(original, code);
        returner = bits_manipulation::invert_bits(returner);
        return returner;
    }

    std::vector<std::vector<int>> from_t1x1_invert(std::vector<std::vector<int>> encrypted) {
        std::vector<std::vector<int>> returner;
        returner = bits_manipulation::invert_bits(encrypted);
        returner = from_t1x1(returner);
        return returner;
    }

    std::vector<std::vector<int>> to_t1x1s(std::vector<std::vector<int>> original, std::vector<int> key) {
        std::vector<std::vector<int>> returner;
        std::vector<int> ret;
        std::vector<int> pos_vector;
        int counter;
        counter = 0;
        returner = {};

        if (key.size() != 8) {
            std::cerr << "[ERROR!] Code Length Error! [ERROR!]\n";
            return {};
        }

        for (int i = 0; i < key.size(); i++) {
            if (key[i] == 1) {
                pos_vector.push_back(i);
            }
        }

        for (int x = 0; x < original.size(); x++) {
            ret = {};
            for (int y = 0; y < original[x].size(); y++) {
                if (y == pos_vector[counter]) {
                    if (original[x][y] == 0) {
                        ret.push_back(1);
                    } else {
                        ret.push_back(0);
                    }
                } else {
                    ret.push_back(original[x][y]);
                }
            }
            returner.push_back(ret);

            if (counter == pos_vector.size()-1) {
                counter = 0;
            } else {
                counter++;
            }
        }

        return returner;
    }

    std::vector<std::vector<int>> from_t1x1s(std::vector<std::vector<int>> encrypted, std::vector<int> key) {
        std::vector<std::vector<int>> returner;

        returner = to_t1x1s(encrypted, key);

        return returner;
    }

    std::vector<std::vector<int>> to_t1x1s_invert(std::vector<std::vector<int>> original, std::vector<int> key) {
        std::vector<std::vector<int>> returner;
        returner = bits_manipulation::invert_bits(to_t1x1s(original, key));

        return returner;
    }
    
    std::vector<std::vector<int>> from_t1x1s_invert(std::vector<std::vector<int>> encrypted, std::vector<int> key) {
        std::vector<std::vector<int>> returner;

        returner = from_t1x1s(bits_manipulation::invert_bits(encrypted), key);

        return returner;
    }

    std::vector<std::vector<int>> to_twisted(std::vector<std::vector<int>> original, std::vector<int> key) {
        std::vector<std::vector<int>> returner;
        std::vector<int> temp_byte;
        std::vector<int> pos_vector;
        int pos_counter;
        int counter;
        pos_counter = 0;
        counter = 0;

        for (int i = 0; i < key.size(); i++) {
            if (key[i] == 1) {
                pos_vector.push_back(i);
            }
        }

        for (int x = 0; x < original.size(); x++) {
            temp_byte = {};
            for (int y = 0; y < original[x].size(); y++) {
                if (counter == 0) {
                    if (y == pos_vector[pos_counter]) {
                        if (original[x][y] == 0) {
                            temp_byte.push_back(1);

                        } else if (original[x][y] == 1) {
                            temp_byte.push_back(0);

                        } else {
                            temp_byte.push_back(original[x][y]);

                        }

                        if (pos_counter == pos_vector.size()-1) {
                            pos_counter = 0;

                        } else {
                            pos_counter++;

                        }
                    } else {
                        temp_byte.push_back(original[x][y]);

                    }

                } else {
                    if (original[x][y] == 0) {
                        temp_byte.push_back(1);

                    } else {
                        temp_byte.push_back(0);

                    }
                }
            }
            returner.push_back(temp_byte);

            if (counter == 0) {
                counter = 1;

            } else {
                counter = 0;

            }
        }

        return returner;
    }

    std::vector<std::vector<int>> from_twisted(std::vector<std::vector<int>> encrypted, std::vector<int> key) {
        // EASTER EGG : Surprise! Its Just Take Same Path, But in Reverse.
        // Yes, i know, i am the sloth in person ;)
        return to_twisted(encrypted, key);
    }
}
