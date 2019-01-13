#include <filesystem>

namespace fs = std::filesystem;

int main(int argc, char* argv[]) {

    fs::create_directories(argv[1]);

    fs::copy("cue", argv[1]);

    return 0;
}