#ifdef __unix__
#include <doctest/doctest.h>
#include <string>
#include <unistd.h>


TEST_CASE("getcwd")
{
    char *cwd = getcwd(nullptr, 0);
    std::string s (cwd);
    free(cwd);
    CHECK(s.size() > 5);
}

#endif
