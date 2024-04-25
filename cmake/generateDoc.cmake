# Doxygen Build

if (BUILD_DOC)
    message("DOCUMENTATION SWITCHED ON")
    find_package(Doxygen)
    if(DOXYGEN_FOUND)
        set(BUILD_DOC_DIR ${CMAKE_BINARY_DIR}/docs)
        if(NOT EXISTS ${BUILD_DOC_DIR})
            file(MAKE_DIRECTORY ${BUILD_DOC_DIR})
        endif()

        set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile)
        set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)
        configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)

        message("Doxygen build started")
        add_custom_target(Doxygen ALL
                COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
                WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
                COMMENT "Generating API documentation with Doxygen"
                VERBATIM)
    else(DOXYGEN_FOUND)
        message("Doxygen needs to be installed to generate the documentation.")
    endif(DOXYGEN_FOUND)
else (BUILD_DOC)
    message("DOCUMENTATION SWITCHED OFF")
endif (BUILD_DOC)
