cmake_minimum_required(VERSION 3.6)

project(Test_Unit LANGUAGES C)

add_executable (${PROJECT_NAME} "")

target_sources(${PROJECT_NAME} PRIVATE test1.c)
target_link_libraries(${PROJECT_NAME} PRIVATE cunit)
if (APPLE)
target_include_directories(${PROJECT_NAME} PUBLIC /usr/local/include)
target_link_directories(${PROJECT_NAME} PUBLIC /usr/local/lib)
endif()             

# target_compile_options(${PROJECT_NAME} PRIVATE --coverage -g -O0)
# target_link_options(${PROJECT_NAME} PUBLIC --coverage -g -O0)

enable_testing()

add_test(NAME test_one_cmake COMMAND ${PROJECT_NAME})

