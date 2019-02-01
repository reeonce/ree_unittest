# ree_unittest

## how to use

1. clone the code to your code folder.

2. add the following lines to your CMakeLists.txt

```cmake
add_subdirectory(ree_unittest)
target_link_libraries(test PRIVATE ree_unittest)
```

3. add following code to the main.cc

```cpp
#include <ree/unittest.h>

int main(int argc, char const *argv[]) {
    R_TEST_INIT(argc, argv);
    R_RUN_TESTS();
    return 0;
}
```

4. write your test cases