function (configureClang clangDir CXXSTD CXXLIB CXXABI)
  set (SYSTEM_INCLUDES /usr/include
		       ${clangDir}/lib/clang/3.3/include
		       ${clangDir}/include/c++/v1)
  set (SYSTEM_FLAGS "-nostdinc -nostdinc++")
  set (SYSTEM_LIBS -rpath ${clangDir}/lib -l${CXXLIB} -l${CXXABI})
  set (DEPENDENCIES -MD)

  include_directories(SYSTEM ${SYSTEM_INCLUDES})
endfunction(configureClang)

function (configureTargetForCompilation target sources)
  message("Configuring ${target}")
  set_target_properties(${target}
                        PROPERTIES
                        LINK_FLAGS "${SYSTEM_LIBS}")
  set_source_files_properties("${sources}"
			      PROPERTIES
			      COMPILE_FLAGS "${SYSTEM_FLAGS}")
endfunction(configureTargetForCompilation)
