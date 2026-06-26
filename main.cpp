#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "bits_manipulation.hpp"
#include "cryptography.hpp"

void press_enter() {
    std::string null_poniter;
    std::cout << "Press Enter to Continue...";
    std::cin >> null_poniter;
}

int main() {
    std::vector<std::vector<int>> input_file;
    std::vector<std::vector<int>> output_file;
    std::vector<int> code;
    std::string input_file_name;
    std::string output_file_name;
    std::string code_str;
    int opt;
    int type;
    bool exit_key;
    exit_key = false;

    while (1) {
        system("clear");
        std::cout << "_______________File to Bits_______________\n";
        std::cout << "(1) -> Read File Bits\n";
        std::cout << "(2) -> Read Bits to Txt\n";
        std::cout << "(3) -> Invert File Bits\n";
        std::cout << "(4) -> Encrypt to T1x1\n";
        std::cout << "(5) -> Decrypt from T1x1\n";
        std::cout << "(6) -> Encrypt to T1x1 + Invert Bits\n";
        std::cout << "(7) -> Decrypt from T1x1 + Invert Bits\n";
        std::cout << "(8) -> Encrypt to T1x1s\n";
        std::cout << "(9) -> Decrypt from T1x1s\n";
        std::cout << "(10) -> Encrypt to T1x1s + Invert Bits\n";
        std::cout << "(11) -> Decrypt from T1x1s + Invert Bits\n";
        std::cout << "(12) -> Encrypt to Twisted\n";
        std::cout << "(13) -> Decrypt from Twisted\n";
        std::cout << "(14) -> Encrypt to T8x8\n";
        std::cout << "(15) -> Decrypt from T8x8\n";
        std::cout << "(16) -> Encrypt to T8x8s\n";
        std::cout << "(17) -> Decrypt from T8x8s\n";
        std::cout << "(0) -> Close Program\n";

        std::cout << ">>> ";
        std::cin >> opt;

        switch (opt) {
            case 1:
            std::cout << "Input File Name >>> ";
            std::cin >> input_file_name;

            input_file = bits_manipulation::txt_to_bits(input_file_name);

            bits_manipulation::display_bits(input_file);

            std::cout << input_file.size() << " Bytes\n";

            press_enter();

            break;
            case 2:
            // Read Bits to Txt
            std::cerr << "WIP\n";

            press_enter();

            break;
            case 3:
            std::cout << "Input File Name >>> ";
            std::cin >> input_file_name;
            std::cout << "Output File Name >>> ";
            std::cin >> output_file_name;

            input_file = bits_manipulation::txt_to_bits(input_file_name);
            output_file = bits_manipulation::invert_bits(input_file);
            bits_manipulation::bits_to_txt(output_file_name, output_file);

            press_enter();

            break;
            case 4:
            std::cout << "Input File Name >>> ";
            std::cin >> input_file_name;
            std::cout << "Output File Name >>> ";
            std::cin >> output_file_name;
            std::cout << "Code (8 bits) >>> ";
            std::cin >> code_str;
            code = bits_manipulation::convert_str_to_byte(code_str);

            input_file = bits_manipulation::txt_to_bits(input_file_name);
            output_file = cryptography::to_t1x1(input_file, code);

            bits_manipulation::bits_to_txt(output_file_name, output_file);

            press_enter();

            break;
            case 5:
            std::cout << "Input File Name >>> ";
            std::cin >> input_file_name;
            std::cout << "Output File Name >>> ";
            std::cin >> output_file_name;

            input_file = bits_manipulation::txt_to_bits(input_file_name);
            output_file = cryptography::from_t1x1(input_file);

            bits_manipulation::bits_to_txt(output_file_name, output_file);

            press_enter();

            break;
            case 6:
            std::cout << "Input File Name >>> ";
            std::cin >> input_file_name;
            std::cout << "Output File Name >>> ";
            std::cin >> output_file_name;
            std::cout << "Code (8 Bits) >>> ";
            std::cin >> code_str;

            code = bits_manipulation::convert_str_to_byte(code_str);

            input_file = bits_manipulation::txt_to_bits(input_file_name);
            output_file = bits_manipulation::invert_bits(cryptography::to_t1x1(input_file, code));
            bits_manipulation::bits_to_txt(output_file_name, output_file);

            press_enter();

            break;
            case 7:
            std::cout << "Input File Name >>> ";
            std::cin >> input_file_name;
            std::cout << "Output File Name >>> ";
            std::cin >> output_file_name;

            input_file = bits_manipulation::txt_to_bits(input_file_name);
            output_file = cryptography::from_t1x1(bits_manipulation::invert_bits(input_file));
            bits_manipulation::bits_to_txt(output_file_name, output_file);

            press_enter();

            break;
            case 8:
            std::cout << "Input File Name >>> ";
            std::cin >> input_file_name;
            std::cout << "Output File Name >>> ";
            std::cin >> output_file_name;
            std::cout << "Code (8 Bits) >>> ";
            std::cin >> code_str;
            code = bits_manipulation::convert_str_to_byte(code_str);
            
            input_file = bits_manipulation::txt_to_bits(input_file_name);
            output_file = cryptography::to_t1x1s(input_file, code);
            bits_manipulation::bits_to_txt(output_file_name, output_file);

            press_enter();

            break;
            case 9:
            std::cout << "Input File Name >>> ";
            std::cin >> input_file_name;
            std::cout << "Output File Name >>> ";
            std::cin >> output_file_name;
            std::cout << "Code (8 Bits) >>> ";
            std::cin >> code_str;
            code = bits_manipulation::convert_str_to_byte(code_str);

            input_file = bits_manipulation::txt_to_bits(input_file_name);
            output_file = cryptography::from_t1x1s(input_file, code);
            bits_manipulation::bits_to_txt(output_file_name, output_file);

            press_enter();

            break;
            case 10:
            std::cout << "Input File Name >>> ";
            std::cin >> input_file_name;
            std::cout << "Output File Name >>> ";
            std::cin >> output_file_name;
            std::cout << "Code (8 Bits) >>> ";
            std::cin >> code_str;
            code = bits_manipulation::convert_str_to_byte(code_str);

            input_file = bits_manipulation::txt_to_bits(input_file_name);
            output_file = cryptography::to_t1x1s_invert(input_file, code);
            bits_manipulation::bits_to_txt(output_file_name, output_file);

            press_enter();

            break;
            case 11:
            std::cout << "Input File Name >>> ";
            std::cin >> input_file_name;
            std::cout << "Output File Name >>> ";
            std::cin >> output_file_name;
            std::cout << "Code (8 Bits) >>> ";
            std::cin >> code_str;
            code = bits_manipulation::convert_str_to_byte(code_str);

            input_file = bits_manipulation::txt_to_bits(input_file_name);
            output_file = cryptography::from_t1x1s_invert(input_file, code);
            bits_manipulation::bits_to_txt(output_file_name, output_file);

            press_enter();

            break;
            case 12:
            std::cout << "Input File Name >>> ";
            std::cin >> input_file_name;
            std::cout << "Output File Name >>> ";
            std::cin >> output_file_name;
            std::cout << "Code (8 Bits) >>> ";
            std::cin >> code_str;
            std::cout << "Type (0/1) >>> ";
            std::cin >> type;
            code = bits_manipulation::convert_str_to_byte(code_str);

            input_file = bits_manipulation::txt_to_bits(input_file_name);
            output_file = cryptography::to_twisted(input_file, code, type);
            bits_manipulation::bits_to_txt(output_file_name, output_file);

            press_enter();

            break;
            case 13:
            std::cout << "Input File Name >>> ";
            std::cin >> input_file_name;
            std::cout << "Output File Name >>> ";
            std::cin >> output_file_name;
            std::cout << "Code (8 Bits) >>> ";
            std::cin >> code_str;
            std::cout << "Type (0/1) >>> ";
            std::cin >> type;
            code = bits_manipulation::convert_str_to_byte(code_str);

            input_file = bits_manipulation::txt_to_bits(input_file_name);
            output_file = cryptography::from_twisted(input_file, code, type);
            bits_manipulation::bits_to_txt(output_file_name, output_file);

            press_enter();
            
            break;
            case 14:
            std::cout << "Input File Name >>> ";
            std::cin >> input_file_name;
            std::cout << "Output File Name >>> ";
            std::cin >> output_file_name;
            std::cout << "Code (8 Bits) >>> ";
            std::cin >> code_str;
            code = bits_manipulation::convert_str_to_byte(code_str);

            input_file = bits_manipulation::txt_to_bits(input_file_name);
            output_file = cryptography::to_t8x8(input_file, code);
            bits_manipulation::bits_to_txt(output_file_name, output_file);

            press_enter();

            break;
            case 15:
            std::cout << "Input File Name >>> ";
            std::cin >> input_file_name;
            std::cout << "Output File Name >>> ";
            std::cin >> output_file_name;

            input_file = bits_manipulation::txt_to_bits(input_file_name);
            output_file = cryptography::from_t8x8(input_file);
            bits_manipulation::bits_to_txt(output_file_name, output_file);

            press_enter();

            break;
            case 16:
            std::cout << "Input File Name >>> ";
            std::cin >> input_file_name;
            std::cout << "Output File Name >>> ";
            std::cin >> output_file_name;
            std::cout << "Code (8 Bits) >>> ";
            std::cin >> code_str;
            code = bits_manipulation::convert_str_to_byte(code_str);

            input_file = bits_manipulation::txt_to_bits(input_file_name);
            output_file = cryptography::to_t8x8s(input_file, code);
            bits_manipulation::bits_to_txt(output_file_name, output_file);

            press_enter();

            break;
            case 17:
            std::cout << "Input File Name >>> ";
            std::cin >> input_file_name;
            std::cout << "Output File Name >>> ";
            std::cin >> output_file_name;
            std::cout << "Code (8 Bits) >>> ";
            std::cin >> code_str;
            code = bits_manipulation::convert_str_to_byte(code_str);

            input_file = bits_manipulation::txt_to_bits(input_file_name);
            output_file = cryptography::from_t8x8s(input_file, code);
            bits_manipulation::bits_to_txt(output_file_name, output_file);

            press_enter();

            break;
            case 0:
            exit_key = true;

            break;
            default:
            std::cerr << "Invalid Option\n";
            break;
        }

        if (exit_key) break;
    }


    return 0;
}
