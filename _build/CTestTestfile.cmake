# CMake generated Testfile for 
# Source directory: /home/vita/Vita927/workspace/homework/banking
# Build directory: /home/vita/Vita927/workspace/homework/banking/_build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(check "/home/vita/Vita927/workspace/homework/banking/_build/check")
set_tests_properties(check PROPERTIES  _BACKTRACE_TRIPLES "/home/vita/Vita927/workspace/homework/banking/CMakeLists.txt;18;add_test;/home/vita/Vita927/workspace/homework/banking/CMakeLists.txt;0;")
subdirs("third-party/gtest")
