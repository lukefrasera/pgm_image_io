cmake_minimum_required(VERSION 2.8.4)


project(pgm_image_io)

include_directories(include)

add_executable(pgm_image_io.cc
  src/pgm_image_io.cc
)
