#pragma once
#include <fstream>
#include <string>
#if defined(__cpp_lib_filesystem) && !defined(__APPLE__)
    #include <filesystem>
    namespace fs = std::filesystem;
#else
#  include <unistd.h>

   namespace fs {

   class current_path
   {
   public:
       std::string string() const {
           char *cwd = getcwd(nullptr, 0);
           std::string s (cwd);
           free(cwd);
           return s;
       }
   };
   }
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
