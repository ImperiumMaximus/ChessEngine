#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "check" for configuration "Release"
set_property(TARGET check APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(check PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "C"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/check.lib"
  )

list(APPEND _IMPORT_CHECK_TARGETS check )
list(APPEND _IMPORT_CHECK_FILES_FOR_check "${_IMPORT_PREFIX}/lib/check.lib" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
