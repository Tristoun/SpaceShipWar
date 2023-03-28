cmake_minimum_required(VERSION 3.24)
project(spatial C)

set(CMAKE_C_STANDARD 99)

add_executable(spatial main.c vaisseau.c vaisseau.h color.c star.c star.h enemy.c enemy.h text.c text.h shot.c shot.h)
target_link_libraries(spatial -lmingw32 -lallegro-5.0.10-monolith-md-debug)
