# CMake 最低版本号要求
cmake_minimum_required (VERSION 2.8)
# 项目信息
project (demo)
# 指定生成目标
add_executable(factory_method factory_method.cc)
add_executable(factory_method_shareptr factory_method_shareptr.cc)
add_executable(simple_factory simple_factory.cc)
