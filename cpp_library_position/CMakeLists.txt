file(GLOB_RECURSE PYXMOLPP_SOURCES
        Portfolio/**.cpp
        Portfolio/**.h
)
pybind11_add_module(Portfolio ${PYXMOLPP_SOURCES})
target_include_directories(Portfolio PRIVATE ${CMAKE_CURRENT_LIST_DIR}/Portfolio)
target_link_libraries(Portfolio PRIVATE cpp_library)