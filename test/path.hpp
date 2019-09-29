#pragma once
#include <fstream>
#if defined(__cpp_lib_filesystem)
    #include <filesystem>
    namespace fs = std::filesystem;
#else
    #include <experimental/filesystem>
    namespace fs = std::experimental::filesystem;
#endif


class path
{
public:
    static bool exists(const char *fname) {
        std::ifstream f (fname);
        return f.good();
    }


    static int remove(const char *fname) {
        return ::remove(fname);
    }

    static std::string cwd() {
        return fs::current_path().string();
    }


    static std::string abspath(const char *fname) {
        return path::cwd() + "/" + fname;
    }
};
