SET(CMAKE_FIND_FRAMEWORK LAST)

find_path(OPENAL_INCLUDE_DIR al.h
        HINTS
        ENV OPENALDIR
        PATHS
        /opt
        /opt/homebrew/opt/openal-soft
        /usr/local/opt/openal-soft
        ~/Library/Frameworks
        /Library/Frameworks
        [HKEY_LOCAL_MACHINE\\SOFTWARE\\Creative\ Labs\\OpenAL\ 1.1\ Software\ Development\ Kit\\1.00.0000;InstallDir]
        PATH_SUFFIXES include/AL include/OpenAL include AL OpenAL
        )

if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(_OpenAL_ARCH_DIR libs/Win64)
else()
    set(_OpenAL_ARCH_DIR libs/Win32)
endif()

find_library(OPENAL_LIBRARY
        NAMES OpenAL al openal OpenAL32
        HINTS
        ENV OPENALDIR
        PATHS
        /opt
        /opt/homebrew/opt/openal-soft
        /usr/local/opt/openal-soft
        ~/Library/Frameworks
        /Library/Frameworks
        [HKEY_LOCAL_MACHINE\\SOFTWARE\\Creative\ Labs\\OpenAL\ 1.1\ Software\ Development\ Kit\\1.00.0000;InstallDir]
        PATH_SUFFIXES libx32 lib64 lib libs64 libs ${_OpenAL_ARCH_DIR}
        )

unset(_OpenAL_ARCH_DIR)

find_package_handle_standard_args(
        OpenAL
        REQUIRED_VARS OPENAL_LIBRARY OPENAL_INCLUDE_DIR
        VERSION_VAR OPENAL_VERSION_STRING
)

mark_as_advanced(OPENAL_LIBRARY OPENAL_INCLUDE_DIR)
