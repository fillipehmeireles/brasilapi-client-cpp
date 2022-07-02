cmake_minimum_required(VERSION 3.8)
project (BrasilApiClient)

add_subdirectory(lib)
add_executable(BrasilApiClient examples/usage.cpp)

target_link_libraries(BrasilApiClient PUBLIC BrasilApiClientLib)

target_include_directories(BrasilApiClient PUBLIC ${PROJECT_BINARY_DIR} ${PROJECT_SOURCE_DIR}/lib/include)

include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git
                         GIT_TAG db351ffbbadc6c4e9239daaa26e9aefa9f0ec82d) # The commit hash for 1.8.3.
FetchContent_MakeAvailable(cpr)

include(FetchContent)

FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.10.5/json.tar.xz)
FetchContent_MakeAvailable(json)

target_link_libraries(BrasilApiClient PRIVATE nlohmann_json::nlohmann_json)