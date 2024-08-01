# CMakeList.txt: проект CMake для ServerSS; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#

# Добавьте источник в исполняемый файл этого проекта.
add_executable (ServerSS "ServerSS.cpp" "ServerSS.h" "inputCheck.h" "inputCheck.cpp" "buffer.h" "bufferProcessing.cpp" "bufferProcessing.h" "heart.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ServerSS PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
