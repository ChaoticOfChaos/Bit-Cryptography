#pragma once

#include <vector>

#include <iostream>

#include "bits_manipulation.hpp"

namespace cryptography {
    std::vector<std::vector<int>> to_t1x1(std::vector<std::vector<int>> original, std::vector<int> code) {
        std::vector<std::vector<int>> returner;
        std::vector<int> ret;
        std::vector<int> pos_vector;
        std::vector<int> trouble;
        int counter;
        counter = 0;
        returner = {};
        trouble = {0, 0, 0, 0, 0, 0, 0, 0};

        if (code.size() != 8 || code == trouble) {
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
        std::vector<int> trouble = {0, 0, 0, 0, 0, 0, 0, 0};
        if (code.size() != 8 || code == trouble) {
            std::cerr << "[ERROR!] Code Length Error [ERROR!]\n";
            return {};
        }

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
        std::vector<int> trouble;
        int counter;
        counter = 0;
        returner = {};
        trouble = {0, 0, 0, 0, 0, 0, 0, 0};

        if (key.size() != 8 || key == trouble) {
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
        std::vector<int> trouble = {0, 0, 0, 0, 0, 0, 0, 0};
        if (key.size() != 8 || key == trouble) {
            std::cerr << "[ERROR!] Code Length Error! [ERROR!]\n";
            return {};
        }

        std::vector<std::vector<int>> returner;

        returner = to_t1x1s(encrypted, key);

        return returner;
    }

    std::vector<std::vector<int>> to_t1x1s_invert(std::vector<std::vector<int>> original, std::vector<int> key) {
        std::vector<int> trouble = {0, 0, 0, 0, 0, 0, 0, 0};
        if (key.size() != 8 || key == trouble) {
            std::cerr << "[ERROR!] Code Length Error! [ERROR!]\n";
            return {};
        }

        std::vector<std::vector<int>> returner;
        returner = bits_manipulation::invert_bits(to_t1x1s(original, key));

        return returner;
    }
    
    std::vector<std::vector<int>> from_t1x1s_invert(std::vector<std::vector<int>> encrypted, std::vector<int> key) {
        std::vector<std::vector<int>> returner;
        std::vector<int> trouble;
        trouble = {0, 0, 0, 0, 0, 0, 0, 0};

        if (key.size() != 8 || key == trouble) {
            std::cerr << "[ERROR!] Code Length Error! [ERROR!]\n";
            return {};
        }

        returner = from_t1x1s(bits_manipulation::invert_bits(encrypted), key);

        return returner;
    }

    std::vector<std::vector<int>> to_twisted(std::vector<std::vector<int>> original, std::vector<int> key, int type) {
        std::vector<std::vector<int>> returner;
        std::vector<int> temp_byte;
        std::vector<int> pos_vector;
        std::vector<int> trouble;
        int pos_counter;
        int counter;
        pos_counter = 0;
        counter = 0;
        trouble = {0, 0, 0, 0, 0, 0, 0, 0};

        if (type == 0 || type == 1) {
            counter = type;
        } else {
            std::cerr << "[WARNING!] Type not Supported [WARNING!]\n";
        }

        if (key.size() != 8 || key == trouble) {
            std::cerr << "[ERROR!] Code Length Error! [ERROR!]\n";
            return {};
        }

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

    std::vector<std::vector<int>> from_twisted(std::vector<std::vector<int>> encrypted, std::vector<int> key, int type) {
        // EASTER EGG : Surprise! Its Just Take Same Path, But in Reverse.
        // Yes, i know, i am the sloth in person ;)
        return to_twisted(encrypted, key, type);
    }

    std::vector<std::vector<int>> to_t8x8(std::vector<std::vector<int>> original, std::vector<int> key) {
        std::vector<int> vector_pos;
        std::vector<int> trouble;
        trouble = {0, 0, 0, 0, 0, 0, 0, 0};
        int pos;

        if (key.size() != 8 || key == trouble) {
            std::cerr << "[ERROR!] Code Length Error! [ERROR!]\n";
            return {};
        }

        pos = 0;
        for (int k : key) {
            if (k == 1) {
                vector_pos.push_back(pos);
            }

            pos++;
        }

        for (std::vector<int> &byte : original) {
            for (int i : vector_pos) {
                if (byte[i] == 0) {
                    byte[i] = 1;

                } else if (byte[i] == 1) {
                    byte[i] = 0;

                }
            }
        }

        original.push_back(key);

        return original;
    }

    std::vector<std::vector<int>> from_t8x8(std::vector<std::vector<int>> encrypted) {
        std::vector<std::vector<int>> returner;
        std::vector<int> key;

        key = encrypted[encrypted.size()-1];
        encrypted.pop_back();

        returner = to_t8x8(encrypted, key);
        returner.pop_back();

        return returner;
    }

    std::vector<std::vector<int>> to_t8x8s(std::vector<std::vector<int>> original, std::vector<int> key) {
        std::vector<int> vector_pos;
        std::vector<int> trouble;
        trouble = {0, 0, 0, 0, 0, 0, 0, 0};
        int pos;

        if (key.size() != 8 || key == trouble) {
            std::cerr << "[ERROR!] Code Length Error! [ERROR!]\n";
            return {};
        }

        pos = 0;
        for (int k : key) {
            if (k == 1) {
                vector_pos.push_back(pos);
            }

            pos++;
        }

        for (std::vector<int> &byte : original) {
            for (int i : vector_pos) {
                if (byte[i] == 0) {
                    byte[i] = 1;

                } else if (byte[i] == 1) {
                    byte[i] = 0;

                }
            }
        }

        return original;
    }

    std::vector<std::vector<int>> from_t8x8s(std::vector<std::vector<int>> encrypted, std::vector<int> key) {
        std::vector<int> trouble;
        trouble = {0, 0, 0, 0, 0, 0, 0, 0};

        if (key.size() != 8 || key == trouble) {
            std::cerr << "[ERROR!] Code Length Error! [ERROR!]\n";
            return {};
        }

        // Yes, I know. This is not good idea.
        // But this is only "Beta" version. 
        // Later i will change that issue and Impruve the code.
        // I promisse ;)
        return to_t8x8s(encrypted, key);
    }

    std::vector<std::vector<int>> to_t16x16(std::vector<std::vector<int>> original, std::vector<int> key) {
        std::vector<std::vector<int>> returner;
        std::vector<int> temp_byte;
        std::vector<int> key_pos1;
        std::vector<int> key_pos2;
        int counter;
        bool flip_switch;
        std::vector<int> trouble;

        trouble = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

        if (key.size() != 16 || key == trouble) {
            std::cerr << "[ERROR!] Code Length Error! [ERROR!]\n";
            return {};
        }

        counter = 0;
        for (int k : key) {
            if (counter < 8) {
                if (k == 1) {
                    key_pos1.push_back(counter);
                }
            } else {
                if (k == 1) {
                    key_pos2.push_back(counter);
                }
            }

            counter++;
        }

        flip_switch = false;
        for (std::vector<int> byte : original) {
            if (!flip_switch) {
                for (int pos : key_pos1) {
                    if (byte[pos] == 1) {
                        byte[pos] = 0;

                    } else {
                        byte[pos] = 1;

                    }
                }

            } else {
                for (int pos : key_pos2) {
                    if (byte[pos] == 1) {
                        byte[pos] = 0;

                    } else {
                        byte[pos] = 1;

                    }
                }
            }

            returner.push_back(byte);
            flip_switch = !flip_switch;
        }

        std::cout << "ret size : " << returner.size() << std::endl;
        return returner;
    }

    std::vector<std::vector<int>> from_t16x16(std::vector<std::vector<int>> encrypted, std::vector<int> key) {
        // Yes, I know. Yes, Again.
        // In future updates it will be fixed
        return to_t16x16(encrypted, key);
    }
}
