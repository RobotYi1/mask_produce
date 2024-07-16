cmake_minimum_required(VERSION 3.10)
project(MaskBoundingBox)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 寻找 OpenCV 包
find_package(OpenCV REQUIRED)

# 包含头文件目录
include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(${CMAKE_SOURCE_DIR}/include)

# 添加可执行文件
add_executable(MaskBoundingBox src/main.cpp src/mask_bounding.cpp src/mask_generation.cpp)

# 链接 OpenCV 库
target_link_libraries(MaskBoundingBox ${OpenCV_LIBS})
