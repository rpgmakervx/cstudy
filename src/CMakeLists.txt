cmake_minimum_required(VERSION 3.6.3)
project(pointertest C)
set(CMAKE_CXX_STANDARD 17)

add_executable(main main.c mystrlen.c mystrlen.h mystrcpy.c mystrcpy.h mystringcmp.c mystringcmp.h)
add_executable(arraypointer arraypointer.c mystrlen.c mystrlen.h)
add_executable(stringtest stringtest.c mystringcmp.c mystringcmp.h)
add_executable(structtest structtest.c)
add_executable(datastruct datastruct.c linkedlist.c linkedlist.h)
add_executable(treemain treemain.c mybinarytree.c mybinarytree.h)

