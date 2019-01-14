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

void ScaffoldCue(const char* argv) {
    fs::path path = "assets/components/" + argv;
    fs::path scaffold = "./cue/scaffold";

    fs::copy(scaffold, path, fs::copy_options::recursive);

    std::cout << "Scaffold " << argv << " Template!" << std::endl;
}

int main(int argc, char* argv[]) {

    std::string cmd = argv[1];

    if (cmd == "new") {
        CreateCue(argv[2]);
    } else if (cmd == "scaffold") {
        ScaffoldCue(argv[2]);
    }

    return 0;
}