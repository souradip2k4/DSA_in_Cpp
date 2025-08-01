cmake_minimum_required(VERSION 3.29)
project(DSA)

set(CMAKE_CXX_STANDARD 14)

add_executable(product_except_self leetcode/product_except_self.cpp)
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
add_executable(majority_element leetcode/majority_element.cpp)
add_executable(sort_colors leetcode/sort_colors.cpp)
add_executable(pascals_triangle leetcode/pascals_triangle.cpp)
add_executable(2_sum.cpp leetcode/2_sum.cpp)
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
add_executable(middle_elem_LL leetcode/linked-list/middle_elem_LL.cpp)
add_executable(deletion_in_LL leetcode/linked-list/deletion_in_LL.cpp)
add_executable(reverse_LL leetcode/linked-list/reverse_LL.cpp)
add_executable(LL_cycle leetcode/linked-list/LL_cycle.cpp)
add_executable(LL_cycle2_approach1 leetcode/linked-list/LL_cycle2_approach1.cpp)
add_executable(LL_cycle2_approach2 leetcode/linked-list/LL_cycle2_approach2.cpp)
add_executable(palindrome_LL leetcode/linked-list/palindrome_LL.cpp)
add_executable(odd_even_LL leetcode/linked-list/odd_even_LL.cpp)
add_executable(delete_node_from_end_approach1 leetcode/linked-list/delete_node_from_end_approach1.cpp)
add_executable(delete_mid_node_LL leetcode/linked-list/delete_mid_node_LL.cpp)
add_executable(merge_interval leetcode/linked-list/merge_interval.cpp)
add_executable(sort_LL leetcode/linked-list/sort_LL.cpp)
add_executable(add_two_nos.cpp leetcode/linked-list/add_two_nos.cpp)
add_executable(reverse_LL_in_K_groups.cpp leetcode/linked-list/reverse_LL_in_K_groups.cpp)


# String problems
add_executable(longest_repeat_char_replacement.cpp leetcode/string/longest_repeat_char_replacement.cpp)
add_executable(substr_all_3_chars.cpp leetcode/string/substr_all_3_chars.cpp)
add_executable(remove_outer_parenthesis.cpp leetcode/string/remove_outer_parenthesis.cpp)
add_executable(reverse_words_in_string.cpp leetcode/string/reverse_words_in_string.cpp)
add_executable(maxOddSubstr.cpp leetcode/string/maxOddSubstr.cpp)
add_executable(longest_common_prefix.cpp leetcode/string/longest_common_prefix.cpp)
add_executable(isomorphic_string.cpp leetcode/string/isomorphic_string.cpp)
add_executable(anagram.cpp leetcode/string/anagram.cpp)
add_executable(rotate_string.cpp leetcode/string/rotate_string.cpp)
add_executable(sort_by_freq.cpp leetcode/string/sort_by_freq.cpp)
add_executable(max_nesting_depth.cpp leetcode/string/max_nesting_depth.cpp)
add_executable(string_to_int.cpp leetcode/string/string_to_int.cpp)
add_executable(longest_palindromic_substr.cpp leetcode/string/longest_palindromic_substr.cpp)
add_executable(sum_beauty_strings.cpp leetcode/string/sum_beauty_strings.cpp)
add_executable(min_parenthesis_valid_add.cpp leetcode/string/min_parenthesis_valid_add.cpp)
add_executable(count_and_stay.cpp leetcode/string/count_and_stay.cpp)
add_executable(shortest_palindrome.cpp leetcode/string/shortest_palindrome.cpp)
add_executable(repeated_string_match.cpp leetcode/string/repeated_string_match.cpp)
add_executable(first_occurance_string.cpp leetcode/string/first_occurance_string.cpp)
add_executable(shortest-palindrome leetcode/string/shortest-palindrome.cpp)
add_executable(roman-no leetcode/string/roman-no.cpp)
add_executable(longest-prefix-also-suffix leetcode/string/longest-prefix-also-suffix.cpp)

# Sliding window
add_executable(max-binary-subArrays.cpp leetcode/sliding-window/max-binary-subArrays.cpp)
add_executable(fruits_into_basket leetcode/sliding-window/fruits_into_basket.cpp)
add_executable(count-nice-subarrays leetcode/sliding-window/count-nice-subarrays.cpp)
add_executable(longest-substr-without-repeat-chars leetcode/sliding-window/longest-substr-without-repeat-chars.cpp)
add_executable(max-points-from-card leetcode/sliding-window/max-points-from-card.cpp)
add_executable(subArrays-distinct-integers leetcode/sliding-window/subArrays-distinct-integers.cpp)
add_executable(min-window-substring leetcode/sliding-window/min-window-substring.cpp)
add_executable(max-cons-1s-k-replacement leetcode/sliding-window/max-cons-1s-k-replacement.cpp)

# Recursion problems
add_executable(generate_parenthesis.cpp leetcode/recursion/generate_parenthesis.cpp)
add_executable(generate_all_subsets leetcode/recursion/generate_all_subsets.cpp)
add_executable(count-good-numbers leetcode/recursion/count-good-numbers.cpp)
add_executable(pow leetcode/recursion/pow.cpp)

# Stacks and queues
add_executable(next-greater-elem-in-array leetcode/stacks-and-queues/stacks/next-greater-elem-in-array.cpp)
add_executable(next-greater-elem-in-array2 leetcode/stacks-and-queues/stacks/next-greater-elem-in-array2.cpp)
add_executable(get-min leetcode/stacks-and-queues/stacks/get-min-stack.cpp)
add_executable(largest-reactngle-histogram-approach1 leetcode/stacks-and-queues/stacks/largest-reactngle-histogram-approach1.cpp)
add_executable(largest-reactngle-histogram-approach2 leetcode/stacks-and-queues/stacks/largest-reactngle-histogram-approach2.cpp)
add_executable(subarray-min-sum leetcode/stacks-and-queues/stacks/subarray-min-sum.cpp)
add_executable(asteroid-collision leetcode/stacks-and-queues/stacks/asteroid-collision.cpp)
add_executable(sum-subarray-ranges leetcode/stacks-and-queues/stacks/sum-subarray-ranges.cpp)
add_executable(valid-parenthesis leetcode/stacks-and-queues/stacks/valid-parenthesis.cpp)
add_executable(online-stock-plan leetcode/stacks-and-queues/stacks/online-stock-plan.cpp)
add_executable(remove-k-digits leetcode/stacks-and-queues/stacks/remove-k-digits.cpp)

add_executable(stack-using-queue leetcode/stacks-and-queues/queues/stack-using-queue.cpp)
add_executable(LRU leetcode/stacks-and-queues/queues/LRU.cpp)
add_executable(LFU-cache leetcode/stacks-and-queues/queues/LFU-cache.cpp)


add_executable(trapping-rainwater.cpp leetcode/trapping-rainwater.cpp)


#Bit Manipulation
add_executable(check_power_of_two.cpp leetcode/bit_manipulation/check_power_of_two.cpp)
add_executable(divide_two_integers.cpp leetcode/bit_manipulation/divide_two_integers.cpp)
add_executable(minBitsFlip leetcode/bit_manipulation/minBitsFlip.cpp)
add_executable(single_number_1 leetcode/bit_manipulation/single_number_1.cpp)
add_executable(no_of_subsets leetcode/bit_manipulation/no_of_subsets.cpp)
add_executable(findXorRange leetcode/bit_manipulation/findXorRange.cpp)
add_executable(single_number_3 leetcode/bit_manipulation/single_number_3.cpp)
add_executable(reverse_bits_unsigned_int leetcode/bit_manipulation/reverse_bits.cpp)
add_executable(count_no_of_bits leetcode/bit_manipulation/count_no_of_bits.cpp)

# Linked List coding ninja
add_executable(count_loop_nodes_in_LL coding_ninja/count_loop_nodes_in_LL.cpp)

# Double linked list coding ninja
add_executable(reverse_double_linked_list coding_ninja/reverse_double_linked_list.cpp)
add_executable(deleting_end_node_DLL coding_ninja/deleting_end_node_DLL.cpp)

# Double linked list gfg
add_executable(insert_in_DLL gfg/linked-list/insert_in_DLL.cpp)

# recursion
add_executable(sort-stack gfg/recursion/sort-stack.cpp)

add_executable(linked_list1 linked_list/linked_list1.cpp)

add_executable(binary_search search/binary_search.cpp)