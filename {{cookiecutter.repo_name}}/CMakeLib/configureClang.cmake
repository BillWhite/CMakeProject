function (configureClang clangDir)
  set (SYSTEM_INCLUDES -nostdinc
                       -nostdinc++
 		       -isystem /usr/include
		       -isystem ${CLANG_DIR}/lib/clang/3.3/include
		       -isystem ${CLANG_DIR}/include/c++/v1)
  set (SYSTEM_LIBS -rpath ${CLANG_DIR}/lib -lc++ -lc++abi)
  set (CXXSTD c++11)
  set (DEPENDENCIES -MD)
  add_definitions(
endfunction(configureClang)
