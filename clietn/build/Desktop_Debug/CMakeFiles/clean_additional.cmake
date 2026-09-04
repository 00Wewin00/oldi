# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/clietn_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/clietn_autogen.dir/ParseCache.txt"
  "clietn_autogen"
  )
endif()
