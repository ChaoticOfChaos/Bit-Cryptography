#pragma once

#include <vector>
#include <fstream>
#include <string>

#include <iostream>

namespace bits_manipulation {

    std::vector<std::vector<int>> invert_bits(std::vector<std::vector<int>> bytes) {
        std::vector<std::vector<int>> returner;
        std::vector<int> bt;

        for (std::vector<int> byte : bytes) {
            bt = {};

            for (int bit : byte) {
                if (bit == 1) {

                    bt.push_back(0);

                } else {

                    bt.push_back(1);

                }
            }

            returner.push_back(bt);
        }

        return returner;
    }

    int bits_to_txt(std::string output_file, std::vector<std::vector<int>> bytes) {
        std::ofstream output(output_file, std::ios::binary);

        if (!output) {
            std::cerr << "Erro ao abrir arquivo\n";
            return 1;
        }

        // Percorre cada byte
        for (const std::vector<int>& bits : bytes) {

            // Garante 8 bits
            if (bits.size() != 8) {
                std::cerr << "Byte inválido\n";
                continue;
            }

            unsigned char byte = 0;

            // Reconstrói o byte
            for (int i = 0; i < 8; ++i) {
                byte |= (bits[i] << (7 - i));
            }

            // Escreve o byte no arquivo
            output.write(reinterpret_cast<char*>(&byte), 1);
        }

        output.close();

        std::cout << "Arquivo escrito com sucesso!\n";

        return 0;
    }

    std::vector<std::vector<int>> txt_to_bits(std::string path) {
        std::ifstream file(path, std::ios::binary);
        std::vector<std::vector<int>> full_file;
        std::vector<int> bt;

        unsigned char byte;

        while (file.read(reinterpret_cast<char*>(&byte), 1)) {
            bt = {};

            for (int i = 7; i >= 0; --i) {
                int bit = (byte >> i) & 1;
                bt.push_back(bit);
            }
            full_file.push_back(bt);
        }
        return full_file;
    }

    void display_bits(std::vector<std::vector<int>> bytes) {
        for (std::vector<int> byte : bytes) {
            for (int bit : byte) {
                std::cout << bit;
            }
            std::cout << std::endl;
        }
    }

    std::vector<int> convert_str_to_byte(std::string byte) {
        std::vector<int> returner;
        if (byte.size() != 8) {
            std::cerr << "[ERROR!] Byte Size is Not 8 [ERROR!]\n";
            return {0, 0, 0, 0, 0, 0, 0, 0};
        }
        for (char c : byte) {
            if (c == '0') {
                returner.push_back(0);
            } else if (c == '1') {
                returner.push_back(1);
            } else {
                std::cerr << "[ERROR!] Bit is Not Binary [ERROR!]\n";
                return {0, 0, 0, 0, 0, 0, 0, 0};
            }
        }
        return returner;
    }

}

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
        return {};
    }

    std::vector<std::vector<int>> from_t1x1s(std::vector<std::vector<int>> encrypted, std::vector<int> key) {
        return {};
    }
}
