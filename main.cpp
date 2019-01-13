#include <filesystem>
#include <iostream>
#include <string>

namespace fs = std::filesystem;

void CreateCue(const char* argv) {
    fs::path path = argv;
    fs::path cue = "./cue/cue";

    fs::copy(cue, path, fs::copy_options::recursive);

    std::cout << "Create Cue Template!" << std::endl;
}

int main(int argc, char* argv[]) {

    std::string cmd = argv[1];

    if (cmd == "new") {
        CreateCue(argv[2]);
    }

    return 0;
}