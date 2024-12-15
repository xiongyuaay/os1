cmake_minimum_required(VERSION 3.5)

project(spinlock)
set(
    SOURCES
    ./spinlock.c
)

add_executable(${PROJECT_NAME} ${SOURCES})