# TDEBUG
debug tools...



### assert

```c++
#include <tdebug.hpp>

int main() {
    TDEBUG::setDPrint((void *)printf); // init debug env
    
    // compiles check
    STATIC_ASSERT("static assert" == "dynamic assert");
    
    int a = 3;
    int b = 4;
    
    // run-time check
    ASSERT(a == 3);
    ASSERT(a == b);
    
}
```

