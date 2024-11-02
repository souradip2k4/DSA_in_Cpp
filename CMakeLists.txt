cmake_minimum_required(VERSION 3.29)
project(DSA)

set(CMAKE_CXX_STANDARD 14)

add_executable(product_except_self leetcode/product_except_self.cpp)
add_executable(merge_interval leetcode/merge_interval.cpp)
add_executable(pivotIndex_apr1 leetcode/pivotIndex_apr1.cpp)
add_executable(pivotIndex_apr2 leetcode/pivotIndex_apr2.cpp)
add_executable(buy_sell_stock leetcode/buy_sell_stock.cpp)

# Binary search
add_executable(array_mountain leetcode/array_mountain.cpp)
add_executable(binary_search_index leetcode/binary_search_index.cpp)
add_executable(rotated_sorted_arr1 leetcode/rotated_sorted_arr1.cpp)
add_executable(rotated_sorted_arr2 leetcode/rotated_sorted_arr2.cpp)
add_executable(first_last_pos leetcode/first_last_pos.cpp)
add_executable(koko_eating_bananas leetcode/koko_eating_bananas.cpp)
add_executable(min_days_m_bouquets leetcode/min_days_m_bouquets.cpp)
add_executable(ship_package_capacity leetcode/ship_package_capacity.cpp)

add_executable(pos_neg_pair_arr leetcode/pos_neg_pair_arr.cpp)
add_executable(max_consecutive_arr leetcode/max_consecutive_arr.cpp)
add_executable(single_number leetcode/single_number.cpp)
add_executable(3_cons_int_sum leetcode/3_cons_int_sum.cpp)
add_executable(fruits_into_basket leetcode/fruits_into_basket.cpp)
add_executable(majority_element leetcode/majority_element.cpp)
add_executable(sort_colors leetcode/sort_colors.cpp)
add_executable(pascals_triangle leetcode/pascals_triangle.cpp)
add_executable(3_sum1 leetcode/3_sum1.cpp)
add_executable(3_sum2 leetcode/3_sum2.cpp)
add_executable(4_sum leetcode/4_sum.cpp)
add_executable(rotate_array leetcode/rotate_array.cpp)

# merge sort
add_executable(reverse_pair leetcode/reverse_pair.cpp)

# Binary search
add_executable(square_root coding_ninja/square_root.cpp)
add_executable(book_allocation coding_ninja/book_allocation.cpp)
add_executable(no_of_inversions coding_ninja/no_of_inversions.cpp)

add_executable(max_subarray coding_ninja/max_subarray.cpp)
add_executable(min_dishes coding_ninja/min_dishes.cpp)
add_executable(quick_sort coding_ninja/quick_sort.cpp)
add_executable(merge_sort coding_ninja/merge_sort.cpp)
add_executable(arr_pair_sum coding_ninja/arr_pair_sum.cpp)
add_executable(longest_subarr_sum_k coding_ninja/longest_subarr_sum_k.cpp)
add_executable(longest_subarr_sum_k_signed coding_ninja/longest_subarr_sum_k_signed.cpp)
add_executable(union coding_ninja/union.cpp)
add_executable(ceil_the_floor coding_ninja/ceil_the_floor.cpp)

# Linked List leetcode
add_executable(middle_elem_LL leetcode/middle_elem_LL.cpp)
add_executable(deletion_in_LL leetcode/deletion_in_LL.cpp)
add_executable(reverse_LL leetcode/reverse_LL.cpp)
add_executable(LL_cycle leetcode/LL_cycle.cpp)
add_executable(LL_cycle2_approach1 leetcode/LL_cycle2_approach1.cpp)
add_executable(palindrome_LL leetcode/palindrome_LL.cpp)
add_executable(odd_even_LL leetcode/odd_even_LL.cpp)
add_executable(delete_node_from_end_approach1 leetcode/delete_node_from_end_approach1.cpp)
add_executable(delete_mid_node_LL leetcode/delete_mid_node_LL.cpp)

# Linked List coding ninja
add_executable(count_loop_nodes_in_LL coding_ninja/count_loop_nodes_in_LL.cpp)

# Double linked list coding ninja
add_executable(reverse_double_linked_list coding_ninja/reverse_double_linked_list.cpp)
add_executable(deleting_end_node_DLL coding_ninja/deleting_end_node_DLL.cpp)

# Double linked list gfg
add_executable(insert_in_DLL gfg/insert_in_DLL.cpp)

add_executable(linked_list1 linked_list/linked_list1.cpp)

add_executable(binary_search search/binary_search.cpp)
