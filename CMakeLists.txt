# CMakeList de Invisible Spirit 0.1-110123-1
# Editez le fichier CMakeCache.txt pour sp�cifier les chemins vers les
# biblioth�ques Irrlicht et Newton
# Voir "include_directories" et "link_directories" ci-dessous

# La compilation sur un syst�me Macintosh n'a pas �t�
# test�e, si vous souhaitez contribuer en proposant une version
# Mac OS, n'h�sitez pas � me contacter : http://www.is06.com/contact.php

cmake_minimum_required(VERSION 2.6)

project(Invisible-Spirit)

set(EXECUTABLE_OUTPUT_PATH bin/${CMAKE_BUILD_TYPE})

include_directories(
  ${irrlicht_include_dir}
  ${newton_include_dir}
  ${fmodex_include_dir}
)
link_directories(
  ${irrlicht_lib_dir}
  ${newton_lib_dir}
  ${fmodex_lib_dir}
)

file(
  GLOB_RECURSE
  source_files
  src/*.cpp
)

add_executable(
  Invisible-Spirit
  ${source_files}
)

IF(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
  target_link_libraries(
    Invisible-Spirit
    Irrlicht
    Newton
    fmodex
  )
ELSE(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
  IF(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    target_link_libraries(
      Invisible-Spirit
      GL
      Xxf86vm
      Irrlicht
      Newton
      fmodex
    )
  ENDIF(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
ENDIF(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
