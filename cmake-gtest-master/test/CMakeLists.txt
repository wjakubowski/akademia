add_executable(test
    example.cpp
    main.cpp
    list.cpp
    binsearchtree.cpp)

target_link_libraries(test libstuff libgtest)
