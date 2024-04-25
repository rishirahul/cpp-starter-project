macro(generateVerHeader outpath)
    configure_file(${CMAKE_SOURCE_DIR}/cmake/config.h.in ${outpath}/version.h)
    include_directories(${outpath})
endmacro()