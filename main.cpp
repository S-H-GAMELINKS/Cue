#include <filesystem>
#include <iostream>
#include <string>
#include <vector>

namespace fs = std::filesystem;

void CreateCue(const std::string& argv) {
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

void StaticCue(const std::string& components_path, const std::string& dir_name, const std::vector<std::string>& arg) {

    std::string cue_path = std::getenv("CUE");
    std::string dir = "\\static\\Static.vue";

    fs::create_directories(components_path + dir_name);

    for(auto&& a : arg) {
        fs::path path = components_path + dir_name + "/" + a + ".vue";
        fs::path scaffold = cue_path + dir;

        fs::copy(scaffold, path, fs::copy_options::recursive);

        std::cout << "Static " << a << " Template!" << std::endl;
    }
}

void ShowCommand() {
    std::array<std::pair<std::string, std::string>, 4> command = {{{"new", "Create New Cue App"},
                                                                {"scaffold", "Create CRUD for Cue"},
                                                                {"static", "Create Static file for Vue Components"},
                                                                {"help", "Show Command Help"}}};

    for(auto&& c : command)
        std::cout << c.first << " : " << c.second << std::endl;
}

int main(int argc, char* argv[]) {

    std::string cmd = argv[1];

    if (cmd == "new") {
        CreateCue(argv[2]);
    } else if (cmd == "scaffold") {
        ScaffoldCue("assets/components/", argv[2]);
    } else if (cmd == "static") {

        std::vector<std::string> arg;

        for(std::size_t i = 3; i < argc; i++)
            arg.emplace_back(std::move(argv[i]));

        StaticCue("assets/components/", argv[2], arg);
    } else if (cmd == "help") {
        ShowCommand();
    }

    return 0;
}