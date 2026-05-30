#pragma once

#include <vector>
#include <fstream>

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

            if (byte.size() != 8) {
                std::cout << " <- Not 8 Size Byte (" << byte.size() << ')';
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
