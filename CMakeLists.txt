#基本配置-------------------------------------------------------
cmake_minimum_required(VERSION 3.5)

#设置C++标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#设置C++编译器 默认g++ 
# set(CMAKE_CXX_COMPILER clang++)
# set(CMAKE_CXX_COMPILER icc)
# coc.nvim 设置 lsp（clangd）生成 compile_commands.json 文件 这样 clangd 就可以找到头文件目录
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
#设置编译类型默认 Debug 可被覆盖
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif(NOT CMAKE_BUILD_TYPE)
message(STATUS 编译类型:  ${CMAKE_BUILD_TYPE})

# 解决 CUDA 报错: Policy CMP0104 is not set: CMAKE_CUDA_ARCHITECTURES now detected for NVCC, empty CUDA_ARCHITECTURES not allowed. 
# https://cmake.org/cmake/help/latest/prop_tgt/CUDA_ARCHITECTURES.html?highlight=cuda_architectures
set(CMAKE_CUDA_ARCHITECTURES OFF)

#构建 C++ 项目 -----------------------------------------------------
# project(main LANGUAGES CUDA)
project(main LANGUAGES CXX)
#显示详细的编译信息 包括编译器选项等
#set(CMAKE_VERBOSE_MAKEFILE 1)

aux_source_directory(${PROJECT_SOURCE_DIR}/src FILES)
add_executable(${PROJECT_NAME} ${FILES})
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)

#外部库链接--------------------------------------------------
# sudo apt install 方式安装的库 可以直接链接
# make 编译安装 root 权限下  ./configure && make && make install 可以直接链接

#find_package 用于支持 cmake 的库中 如 QT 安装目录中有 Qt/6.2.3/gcc_64/lib/cmake 说明
#支持 cmake 所以可以用 find_package

# math.h ------------------------------------------------------ 
#target_link_libraries(${PROJECT_NAME} -lm)

# intel oneMKL -------------------------------------------------------
# target_link_libraries(${PROJECT_NAME}  -lmkl_intel_lp64 -lmkl_intel_thread -lmkl_core -liomp5 -lpthread -lm -ldl)

# GSL ---------------------------------------------------------
#target_link_libraries(${PROJECT_NAME}  -lgsl -lgslcblas -lm)

#openMP ----------------------------------------------------------
# 注意 手动添加 -fopenmp 直接链接会出错！
# https://stackoverflow.com/questions/17633513/cmake-cannot-find-openmp
# https://cliutils.gitlab.io/modern-cmake/chapters/packages/OpenMP.html

#find_package(OpenMP REQUIRED)
#if(OpenMP_FOUND)
#    target_link_libraries(${PROJECT_NAME} OpenMP::OpenMP_CXX)
#else()
#    message(FATAL_ERROR "openmp not found!")
#endif()

# matplotlib-cpp ---------------------------------------------
#find_package(Python3 COMPONENTS Development NumPy)
#target_link_libraries(${PROJECT_NAME} Python3::Python Python3::NumPy)

