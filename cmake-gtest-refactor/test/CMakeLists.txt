add_executable(runTest
    PersonData.cpp
    Employee.cpp
    Database.cpp
    Report.cpp
    work.cpp
    main.cpp)

target_link_libraries(runTest libcompany libgtest libgmock)

add_test(allTests runTest)
