set (MANTIS_TEST_LIBS gtest_main gmock_main)

FILE(GLOB_RECURSE TESTS . *.cpp)
foreach(testCpp ${TESTS})
    get_filename_component(testName ${testCpp} NAME_WE)
    add_executable (${testName} ${testCpp})
    target_link_libraries (${testName} ${MANTIS_TEST_LIBS})
    add_test(${testName} ${testName})
endforeach(testCpp)
