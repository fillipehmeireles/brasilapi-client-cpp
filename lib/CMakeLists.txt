cmake_minimum_required(VERSION 3.8)
project (BrasilApiClient)

add_library(BrasilApiClientLib src/HTTPService.cpp src/ApiProvider.cpp src/Utils.cpp)
target_compile_features(BrasilApiClientLib PUBLIC cxx_std_20)

target_link_libraries(BrasilApiClientLib PUBLIC cpr::cpr)