#include <filesystem>
#include <iostream>
#include <string>

namespace fs = std::filesystem;

void CreateCue(const char* argv) {
    fs::path path = argv;

    std::string cue_path = std::getenv("CUE");
    std::string dir = "\\cue";
    fs::path cue = cue_path + dir;

    fs::copy(cue, path, fs::copy_options::recursive);

    std::cout << "Create Cue Template!" << std::endl;
}

void ScaffoldCue(const std::string& components_path, const std::string& scaffold_name) {

    std::string cue_path = std::getenv("CUE");
    std::string dir = "\\scaffold";

    fs::path path = components_path + scaffold_name;
    fs::path scaffold = cue_path + dir;

    fs::copy(scaffold, path, fs::copy_options::recursive);

    std::cout << "Scaffold " << scaffold_name << " Template!" << std::endl;
}

void StaticCue(const std::string& components_path, const std::string& scaffold_name) {

    std::string cue_path = std::getenv("CUE");
    std::string dir = "\\static";

    fs::path path = components_path + scaffold_name;
    fs::path scaffold = cue_path + dir;

    fs::copy(scaffold, path, fs::copy_options::recursive);

    std::cout << "Static " << scaffold_name << " Template!" << std::endl;
}

int main(int argc, char* argv[]) {

    std::string cmd = argv[1];

    if (cmd == "new") {
        CreateCue(argv[2]);
    } else if (cmd == "scaffold") {
        ScaffoldCue("assets/components/", argv[2]);
    } else if (cmd == "static") {
        StaticCue("assets/components/", argv[2]);
    }

    return 0;
}