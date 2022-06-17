cmake_minimum_required(VERSION 3.14)
project(http_server LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(http_server upload.cc)

# target_link_libraries(notes_client_demo notes_client base libprotobuf crypto spdlog sqlite3 sqlpp11)
# include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../external/asio/include)