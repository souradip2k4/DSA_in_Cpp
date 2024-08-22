cmake_minimum_required(VERSION 3.29)
project(DSA)

set(CMAKE_CXX_STANDARD 14)

add_executable(product_except_self leetcode/product_except_self.cpp)
add_executable(merge_interval leetcode/merge_interval.cpp)
add_executable(array_mountain leetcode/array_mountain.cpp)
add_executable(pivotIndex_apr1 leetcode/pivotIndex_apr1.cpp)
add_executable(pivotIndex_apr2 leetcode/pivotIndex_apr2.cpp)
add_executable(buy_sell_stock leetcode/buy_sell_stock.cpp)
add_executable(binary_search_index leetcode/binary_search_index.cpp)

add_executable(01 coding_ninja/01.cpp)
add_executable(square_root coding_ninja/square_root.cpp)
add_executable(max_subarray coding_ninja/max_subarray.cpp)
add_executable(min_dishes coding_ninja/min_dishes.cpp)

add_executable(binary_search sorting/binary_search.cpp)
add_executable(quick_sort sorting/quick_sort.cpp)
