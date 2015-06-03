include(ExternalProject)
macro (getExternalProject name url)
  message("getExternalProject(${name} ${url})")
  ExternalProject_Add(${name}
      URL ${url}
      PREFIX ${CMAKE_CURRENT_BINARY_DIR}/${name}
      UPDATE_COMMAND ""
      INSTALL_COMMAND ""
  )

  ExternalProject_Get_Property(${name} source_dir)
  string(TOUPPER ${name} bigname)

  ExternalProject_Get_Property(${name} source_dir)
  set(${bigname}_INCLUDE_DIR ${source_dir}/include)

  ExternalProject_Get_Property(${name} binary_dir)
  set(${bigname}_LIB_DIR ${binary_dir})

endmacro(getExternalProject)
