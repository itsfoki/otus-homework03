cmake_minimum_required(VERSION 3.5)
project(guess_number)

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set(CMAKE_EXE_LINKER_FLAGS "-static") # для того чтобы можно было запускать приложение в Windows двойным
    #кликом и из командной строки без прописывания в PATH путей к бинарникам libstdc++
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "CLANG")
    set(CMAKE_EXE_LINKER_FLAGS "-static") # для того чтобы можно было запускать приложение в Windows двойным
    #кликом и из командной строки без прописывания в PATH путей к бинарникам libstdc++
elseif(...)

endif()

set(CMAKE_CXX_STANDARD 17)

add_executable(guess_number
        main.cpp
        game.cpp game.h
        getRandomNumber.cpp 
        getRandomNumber.h
        inputCheck.cpp 
        inputCheck.h
        fileTable.cpp 
        fileTable.h 
        print.cpp 
        print.h)