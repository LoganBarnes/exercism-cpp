cmake_minimum_required(VERSION 3.21)
project(Exercism CXX)

set(CMAKE_CXX_STANDARD 17)

add_compile_options(
        # Strict warnings/errors with gcc and clang
        $<$<COMPILE_LANG_AND_ID:CXX,GNU,Clang,AppleClang>:-Wall>
        $<$<COMPILE_LANG_AND_ID:CXX,GNU,Clang,AppleClang>:-Wextra>
        $<$<COMPILE_LANG_AND_ID:CXX,GNU,Clang,AppleClang>:-Werror>
        $<$<COMPILE_LANG_AND_ID:CXX,GNU,Clang,AppleClang>:-Wpedantic>
        $<$<COMPILE_LANG_AND_ID:CXX,GNU,Clang,AppleClang>:-Wunused>
        $<$<COMPILE_LANG_AND_ID:CXX,GNU,Clang,AppleClang>:-pedantic-errors>
        $<$<COMPILE_LANG_AND_ID:CXX,GNU,Clang,AppleClang>:-Winit-self>
        $<$<COMPILE_LANG_AND_ID:CXX,GNU,Clang,AppleClang>:-Wold-style-cast>
        $<$<COMPILE_LANG_AND_ID:CXX,GNU,Clang,AppleClang>:-Woverloaded-virtual>
        $<$<COMPILE_LANG_AND_ID:CXX,GNU,Clang,AppleClang>:-Wsign-conversion>
        $<$<COMPILE_LANG_AND_ID:CXX,GNU,Clang,AppleClang>:-Wshadow>
        $<$<COMPILE_LANG_AND_ID:CXX,GNU,Clang,AppleClang>:-Wmissing-declarations>
        $<$<COMPILE_LANG_AND_ID:CXX,GNU,Clang,AppleClang>:-Wmissing-include-dirs>
        $<$<COMPILE_LANG_AND_ID:CXX,GNU,Clang,AppleClang>:-Wno-unknown-pragmas>
        $<$<COMPILE_LANG_AND_ID:CXX,Clang,AppleClang>:-Wimplicit-float-conversion>
        $<$<COMPILE_LANG_AND_ID:CXX,GNU>:-Wfloat-conversion>
        # Strict warnings/errors with msvc
        $<$<COMPILE_LANG_AND_ID:CXX,MSVC>:/external:W0>
        # Ignore any headers using angle brackets on windows
        $<$<COMPILE_LANG_AND_ID:CXX,MSVC>:/experimental:external>
        $<$<COMPILE_LANG_AND_ID:CXX,MSVC>:/external:anglebrackets>
        $<$<COMPILE_LANG_AND_ID:CXX,MSVC>:/external:W0>
)

add_compile_definitions(EXERCISM_RUN_ALL_TESTS)

add_subdirectory(leap)
add_subdirectory(reverse-string)
add_subdirectory(space-age)
add_subdirectory(bank-account)
add_subdirectory(binary-search-tree)
add_subdirectory(robot-simulator)
add_subdirectory(queen-attack)
add_subdirectory(all-your-base)
add_subdirectory(triangle)
add_subdirectory(grains)
add_subdirectory(raindrops)
add_subdirectory(binary-search)
add_subdirectory(darts)
add_subdirectory(largest-series-product)
add_subdirectory(matching-brackets)
add_subdirectory(circular-buffer)
add_subdirectory(pangram)
add_subdirectory(collatz-conjecture)
add_subdirectory(difference-of-squares)
add_subdirectory(hamming)
add_subdirectory(grade-school)
add_subdirectory(nth-prime)
add_subdirectory(nucleotide-count)
