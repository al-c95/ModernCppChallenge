cmake_minimum_required(VERSION 3.14)
project(modern_Cpp_challenge)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Boost 1.82.0)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include_directories(${Boost_INCLUDE_DIRS})  # Include Boost headers
include_directories(${PROJECT_SOURCE_DIR}/src/StringsAndRegex)
include_directories(${PROJECT_SOURCE_DIR}/test/StringsAndRegex)
include_directories(${PROJECT_SOURCE_DIR}/src/Cryptography)
include_directories(${PROJECT_SOURCE_DIR}/test/Cryptography)

enable_testing()

# Create an executable for StringsAndRegex
add_executable(StringsAndRegex_Test
  src/StringsAndRegex/license_plates.cpp
  test/StringsAndRegex/license_plates_test.cpp
  src/StringsAndRegex/article_title_capitaliser.cpp
  test/StringsAndRegex/article_title_capitaliser_test.cpp
  src/StringsAndRegex/joining_strings.cpp
  test/StringsAndRegex/joining_strings_test.cpp
)

target_link_libraries(StringsAndRegex_Test GTest::gtest_main ${Boost_LIBRARIES})
include(GoogleTest)
gtest_discover_tests(StringsAndRegex_Test)

# Create an executable for Cryptography
add_executable(Cryptography_Test
  src/Cryptography/caesar_cipher.cpp
  test/Cryptography/caesar_cipher_test.cpp
  src/Cryptography/validating_user_credentials.cpp
  test/Cryptography/validating_user_credentials_tests.cpp
)

target_link_libraries(Cryptography_Test GTest::gtest_main ${Boost_LIBRARIES})
include(GoogleTest)
gtest_discover_tests(Cryptography_Test)