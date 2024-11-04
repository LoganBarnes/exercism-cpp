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

#add_subdirectory(gigasecond) # requires boost
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
add_subdirectory(rna-transcription)
add_subdirectory(sieve)
add_subdirectory(robot-name)
add_subdirectory(allergies)
add_subdirectory(protein-translation)
add_subdirectory(secret-handshake)
add_subdirectory(isbn-verifier)
add_subdirectory(say)
add_subdirectory(log-levels)
add_subdirectory(sum-of-multiples)
add_subdirectory(prime-factors)
add_subdirectory(clock)
add_subdirectory(meetup)
add_subdirectory(beer-song)
add_subdirectory(atbash-cipher)
add_subdirectory(trinary)
add_subdirectory(luhn)
add_subdirectory(armstrong-numbers)
add_subdirectory(bob)
add_subdirectory(hexadecimal)
add_subdirectory(high-scores)
add_subdirectory(phone-number)
add_subdirectory(series)
add_subdirectory(complex-numbers)
add_subdirectory(food-chain)
add_subdirectory(simple-linked-list)
add_subdirectory(binary)
add_subdirectory(perfect-numbers)
add_subdirectory(roman-numerals)
add_subdirectory(scrabble-score)
add_subdirectory(pascals-triangle)
add_subdirectory(etl)
add_subdirectory(word-count)
add_subdirectory(crypto-square)
add_subdirectory(acronym)
add_subdirectory(anagram)
add_subdirectory(isogram)
add_subdirectory(troll-the-trolls)
add_subdirectory(doctor-data)
add_subdirectory(pop-count)
add_subdirectory(lasagna-master)
add_subdirectory(linked-list)
add_subdirectory(diamond)
add_subdirectory(run-length-encoding)
