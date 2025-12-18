
cmake_minimum_required(VERSION 3.15)
project(EdgeAIInferenceEngine VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Add library
add_library(EdgeAIInferenceEngine
    EdgeAIInferenceEngine.cpp
    EdgeAIInferenceEngine.h
)

# Configure install targets
install(TARGETS EdgeAIInferenceEngine
    EXPORT EdgeAIInferenceEngineTargets
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include
)

# Add example executable
add_executable(example
    main.cpp
)
target_link_libraries(example PRIVATE EdgeAIInferenceEngine)

# Add install target for example
install(TARGETS example
    RUNTIME DESTINATION bin
)
