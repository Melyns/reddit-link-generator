#include <iostream>
#include <random>
#include <string>

std::string generateRandomText(int length, int mode) {
    static const char charset[] = "abcdefghijklmnopqrstuvwxyz";
    static const char numberset[] = "0123456789";
    const int charsetSize = sizeof(charset) - 1;
    const int numbersetSize = sizeof(numberset) - 1;
    std::string result;
    result.reserve(length);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> charDist(0, charsetSize - 1);
    std::uniform_int_distribution<> numDist(0, numbersetSize - 1);

    if (mode == 1) {
        for (int i = 0; i < length; ++i) {
            result += charset[charDist(gen)];
        }
    }
    else if (mode == 2) {
        result += numberset[numDist(gen)];
        for (int i = 1; i < length; ++i) {
            result += charset[charDist(gen)];
        }
    }
    else if (mode == 3) {
        if (length >= 2) {
            result += std::to_string(10 + gen() % 2); // Generate 10 or 11
            for (int i = 2; i < length; ++i) {
                result += charset[charDist(gen)];
            }
        }
    }
    else if (mode == 4) {
        for (int i = 0; i < length; ++i) {
            result += numberset[numDist(gen)];
        }
    }

    return result;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " <number of links to generate> [-m<mode>]" << std::endl;
        return 1;
    }

    int numLinks = std::atoi(argv[1]);
    if (numLinks <= 0) {
        std::cout << "Please provide a valid number of links to generate." << std::endl;
        return 1;
    }

    int mode = 1;
    for (int i = 2; i < argc; ++i) {
        if (argv[i][0] == '-' && argv[i][1] == 'm') {
            mode = std::atoi(&argv[i][2]);
        }
    }

    for (int i = 0; i < numLinks; ++i) {
        std::string randomText = generateRandomText(6, mode);
        std::cout << "https://reddit.com/" << randomText << std::endl;
    }

    return 0;
}
