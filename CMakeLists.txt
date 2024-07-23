# To build and run
# mkdir build
# cd build
# cmake ..
# make
# pdfgen hello.pdf

cmake_minimum_required( VERSION 3.10 )

project( MyPDFGenerator )

set( CMAKE_MODULE_PATH ${CMAKE_CURRENT_BINARY_DIR}
	${CMAKE_CURRENT_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH})

set( CMAKE_CXX_STANDARD 17 )

add_compile_options(-fsanitize=address)
add_link_options(-fsanitize=address)

set( PODOFO_BUILD_LIB_ONLY ON CACHE INTERNAL "" FORCE )
set( PODOFO_SHARED ON CACHE INTERNAL "" FORCE )
add_subdirectory( 3rdparty/podofo )

add_definitions( -DPODOFO_SHARED )

set( SRC main.cpp PDFGenerator.h PDFGenerator.cpp )

include_directories( ${CMAKE_CURRENT_SOURCE_DIR}
	${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/podofo/src
	${CMAKE_CURRENT_BINARY_DIR}/3rdparty/podofo/src/podofo )

link_directories( ${CMAKE_CURRENT_BINARY_DIR}/3rdparty/podofo/src/podofo )
link_directories( ${CMAKE_CURRENT_BINARY_DIR}/3rdparty/podofo/src )

add_executable( pdfgen.out ${SRC} )

target_link_libraries( pdfgen.out podofo_shared )

message("Output path: ${CMAKE_CURRENT_BINARY_DIR}")
