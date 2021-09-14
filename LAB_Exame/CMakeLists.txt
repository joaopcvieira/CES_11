cmake_minimum_required(VERSION 3.19)
project(LAB_Exame C)

set(CMAKE_C_STANDARD 99)

add_executable(CES_11
        main.c
        binTree.c
        binTree.h
        adt_stack.h
        adt_stack.c
        list.h
        list.c
        atomSet.c
        atomSet.h
        PolishExpr.c
        PolishExpr.h)