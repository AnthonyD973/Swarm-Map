set(HEADERS
    swarmmap.h
    sminclude.h)
set(TRANSLATION_UNITS
    swarmmap.c)
set(SOURCES ${TRANSLATION_UNITS} ${HEADERS})

configure_file(smconfig.h.in "${CMAKE_CURRENT_BINARY_DIR}/smconfig.h" @ONLY)
include_directories("{CMAKE_CURRENT_BINARY_DIR}")

add_library(swarmmap ${SOURCES})

install(TARGETS swarmmap
        LIBRARY DESTINATION lib/
        ARCHIVE DESTINATION lib/)
install(DIRECTORY ./ DESTINATION include/
        FILES_MATCHING PATTERN "*.h")
