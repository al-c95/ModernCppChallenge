cmake_minimum_required(VERSION 3.14)
project(modern_Cpp_challenge)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include_directories(${PROJECT_SOURCE_DIR}/src/StringsAndRegex)
include_directories(${PROJECT_SOURCE_DIR}/test/StringsAndRegex)

enable_testing()

add_executable(
  StringsAndRegex_Test
  src/StringsAndRegex/license_plates.cpp
  test/StringsAndRegex/license_plates_test.cpp
  src/Cryptography/caesar_cipher.cpp
  test/Cryptography/caesar_cipher_test.cpp
  src/Cryptography/validating_user_credentials.cpp
  test/Cryptography/validating_user_credentials_tests.cpp
)
target_link_libraries(
  StringsAndRegex_Test
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(StringsAndRegex_Test)