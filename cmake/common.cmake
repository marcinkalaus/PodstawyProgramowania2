function(zip_all_work)
    get_filename_component(directoryBasename ${CMAKE_CURRENT_SOURCE_DIR} NAME)
    get_filename_component(directory2Zip "${CMAKE_CURRENT_SOURCE_DIR}" ABSOLUTE)
    set(archiveFullPath ${PROJECT_BINARY_DIR}/${directoryBasename}.zip)

    message("Creating ZIP from path: ${directory2Zip} into ${archiveFullPath}")
    file(ARCHIVE_CREATE OUTPUT ${archiveFullPath}
        PATHS ${directory2Zip}
        FORMAT zip
#        VERBOSE
    )
endfunction()


function(add_subdirectory_if_exists directory_to_add)
    if (IS_DIRECTORY "${directory_to_add}")
            add_subdirectory(${directory_to_add})
    endif ()
endfunction()


function(generate_pdf_if_possible cpp_sources)
    find_program(enscriptTool enscript)
    find_program(ps2pdfTool ps2pdf)
    if (enscriptTool AND ps2pdfTool)
        add_custom_target(pdf
            COMMAND cat ${cpp_sources} | enscript -Ecpp --color=1 -C  -fCourier8 -o - | ps2pdf - pdf.pdf
            DEPENDS ${PROJECT_NAME}
            WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
        )
    endif()
endfunction()


function(enable_cpp17)
    set(CMAKE_CXX_STANDARD 17)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
    set(CMAKE_CXX_EXTENSIONS OFF)
    set(CMAKE_C_STANDARD 11)
    set(CMAKE_C_STANDARD_REQUIRED 11)

    if (NOT CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
        set(COMPILER_FLAGS "--std=c++17")
        set(COMPILER_DEBUG_FLAGS "-D_DEBUG")
        set(COMPILER_RELEASE_FLAGS "-O3 -DNDEBUG")
        set(LINKER_FLAGS "--std=c++17")
    endif()
endfunction()


## source of function below: https://stackoverflow.com/a/33266748/1350091
include(CheckCXXCompilerFlag)

function(enable_cxx_compiler_flag_if_supported flag)
    string(FIND "${CMAKE_CXX_FLAGS}" "${flag}" flag_already_set)
    if(flag_already_set EQUAL -1)
        check_cxx_compiler_flag("${flag}" flag_supported)
        if(flag_supported)
            set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${flag}" PARENT_SCOPE)
        endif()
        unset(flag_supported CACHE)
    endif()
endfunction()


## ogarnac to: https://stackoverflow.com/a/9843594/1350091
