cmake_minimum_required(VERSION 3.10)
project(FisheyeMaskGenerator)

# 设置C++标准为C++11或更高
set(CMAKE_CXX_STANDARD 11)

# 查找OpenCV库
find_package(OpenCV REQUIRED)

# 包含OpenCV头文件
include_directories(${OpenCV_INCLUDE_DIRS})

# 添加可执行文件
add_executable(FisheyeMaskGenerator main.cpp)

# 链接OpenCV库
target_link_libraries(FisheyeMaskGenerator ${OpenCV_LIBS})
