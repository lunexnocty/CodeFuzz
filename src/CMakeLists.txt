file(GLOB SOURCES "*.cpp")

# 创建静态库
add_library(${PROJECT_NAME} STATIC ${SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE ../include/project)

# 创建动态库
# add_library(${PROJECT_NAME} SHARED ${SOURCES})
# target_include_directories(${PROJECT_NAME} PRIVATE ../include/project)