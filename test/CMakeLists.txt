include(FetchContent)
FetchContent_Declare(doctesth
    URL https://raw.githubusercontent.com/onqtam/doctest/2.3.5/doctest/doctest.h
    DOWNLOAD_NO_EXTRACT ON
    DOWNLOAD_DIR doctest
    SUBBUILD_DIR .
)
FetchContent_GetProperties(doctesth)
FetchContent_Populate(doctesth)
include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_executable(doctests
    doctests.cpp
    test_path.cpp
    test_hdf5.cpp
)
target_link_libraries(doctests minih5)
target_compile_features(doctests PUBLIC cxx_std_17)

if (MSVC)
    add_compile_definitions(-D_CRT_SECURE_NO_WARNINGS)
elseif (CMAKE_COMPILER_IS_GNUCC AND CMAKE_CXX_COMPILER_VERSION VERSION_LESS 8.0)
    message("-- stdc++fs")
    target_link_libraries(doctests stdc++fs)
endif()
