if(EXISTS "/Users/andrebrahin/Computing_Science/SortingAlgorithms/build/SortingAlgorithms_test[1]_tests.cmake")
  include("/Users/andrebrahin/Computing_Science/SortingAlgorithms/build/SortingAlgorithms_test[1]_tests.cmake")
else()
  add_test(SortingAlgorithms_test_NOT_BUILT SortingAlgorithms_test_NOT_BUILT)
endif()