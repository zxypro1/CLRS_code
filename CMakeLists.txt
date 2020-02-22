# lib
add_library(common common.cpp)

# exec
add_executable(c02-big_num_add c02-big_num_add.cpp)

add_executable(c02-find_sum_using_set c02-find_sum_using_set.cpp)

add_executable(c02-find_sum_using_sort c02-find_sum_using_sort.cpp)

add_executable(c02-insert_sort c02-insert_sort.cpp)
target_link_libraries(c02-insert_sort PUBLIC common)

add_executable(c02-merge_sort c02-merge_sort.cpp)
target_link_libraries(c02-merge_sort PUBLIC common)

add_executable(c04-find_max_subarray c04-find_max_subarray.cpp)

add_executable(c06-heap_sort c06-heap_sort.cpp)
target_link_libraries(c06-heap_sort PUBLIC common)

add_library(c06-priority_queue c06-priority_queue.cpp)
