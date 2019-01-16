#include <iostream>

#include <cpp-httlib/httplib.h>
#include <fstream>
#include <sstream>
#include <string>
#include <array>

const std::string LoadAssets(const std::string& path) {

    std::ifstream file(path.c_str(), std::ios::in);
    
    std::stringstream stream;

    stream << file.rdbuf();

    file.close();

    std::string assets(stream.str());

    return assets;
}

int main() {

    httplib::Server svr;

    std::array<std::string, 3> routes = {"/", "/about", "/contact"};

    std::string body = LoadAssets("./assets/index.html");

    std::string indexjs = LoadAssets("./assets/index.js");

    for (auto&& route : routes) {
        svr.Get(route.c_str(), [&](const httplib::Request& req, httplib::Response& res) {
            res.set_content(body, "text/html");
        });
    }

    svr.Get("/index.js", [&](const httplib::Request& req, httplib::Response& res) {
        res.set_content(indexjs, "text/html");
    });

    svr.listen("localhost", 3000);

    return 0;
}