#include "../lib/mainprocess.h"

int main(int argc, char **argv)
{
    std::string path_file = "";
    if (argc > 1)
        path_file = std::string(argv[1]);
    else
        path_file = "input.txt";

    MainProcess *mp = new MainProcess();
    if (!mp->run(path_file)) {
        std::cout << "Successful exiting from program!";
    }
    else {
        std::cout << "Program execution failed!";
    }
    return 0;
}