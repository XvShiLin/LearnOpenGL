project(HelloWindow)

aux_source_directory(src SRC_DIR)
file(GLOB_RECURSE SRC_LIST ${SRC_DIR})
add_executable(${PROJECT_NAME} ${SRC_LIST})
target_link_libraries(${PROJECT_NAME} -lglfw -ldl)
# -lm -lGL -lXrandr -lXi -lX11 -lXxf86vm -lpthread -lXinerama -lXcursor

# OS:Ubuntu
# complier:GCC
# linkoptions:-lGLEW -lglfw3 -lGL -lX11 -lpthread -lXrandr -lXi