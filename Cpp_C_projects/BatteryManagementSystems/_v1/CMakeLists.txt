cmake_minimum_required(VERSION 3.10)
project(BMS_Project C)
set(CMAKE_C_STANDARD 99)

add_executable(BMS_Project
    BMS/BMS.c
    APP/main.c
)

target_include_directories(BMS_Project PRIVATE BMS)