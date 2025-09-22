cmake_minimum_required(VERSION 3.10)
project(GeometryProject VERSION 1.0.0 LANGUAGES CXX)

# Configuration du compilateur C++
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Options de compilation
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")
endif()

# Définition des fichiers sources pour chaque exécutable
set(TD3_3_SOURCES 
    main_vecteur.cpp
    Vecteur.cpp
    Point2D.cpp
    Point3D.cpp
)

set(TD3_2_SOURCES 
    main.cpp 
    Point2D.cpp 
    Point3D.cpp 
    Shape.cpp 
    Circle.cpp 
    Triangle.cpp 
    Rectangle.cpp 
    Trajectory.cpp
    Vecteur.cpp
)

# Nouvel exécutable pour Polygon
set(TD3_4_SOURCES
    main_polygon.cpp
    Polygon.cpp
    Point2D.cpp
)

# Définition des fichiers d'en-tête
set(HEADERS
    Point2D.hpp
    Point3D.hpp
    Shape.hpp
    Circle.hpp
    Triangle.hpp
    Rectangle.hpp
    Trajectory.hpp
    Vecteur.hpp
    Polygon.hpp  # ← Ajouter cette ligne
)

# Création des exécutables
add_executable(TD3_3 ${TD3_3_SOURCES} ${HEADERS} "TD3_5.cpp")
add_executable(TD3_2 ${TD3_2_SOURCES} ${HEADERS} "TD3_5.cpp")
add_executable(TD3_4 ${TD3_4_SOURCES} ${HEADERS} "TD3_5.cpp")  # ← Ajouter cette ligne
add_executable(TD3_5 TD3_5.cpp)

# Définition des répertoires d'inclusion
target_include_directories(TD3_3 PRIVATE .)
target_include_directories(TD3_2 PRIVATE .)
target_include_directories(TD3_4 PRIVATE .)  # ← Ajouter cette ligne

# Options de compilation spécifiques
target_compile_options(TD3_3 PRIVATE ${CMAKE_CXX_FLAGS})
target_compile_options(TD3_2 PRIVATE ${CMAKE_CXX_FLAGS})
target_compile_options(TD3_4 PRIVATE ${CMAKE_CXX_FLAGS})  # ← Ajouter cette ligne

# Configuration pour les builds de type Debug
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_definitions(TD3_3 PRIVATE DEBUG)
    target_compile_definitions(TD3_2 PRIVATE DEBUG)
    target_compile_definitions(TD3_4 PRIVATE DEBUG)  # ← Ajouter cette ligne
    if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
        target_compile_options(TD3_3 PRIVATE -g -O0)
        target_compile_options(TD3_2 PRIVATE -g -O0)
        target_compile_options(TD3_4 PRIVATE -g -O0)  # ← Ajouter cette ligne
    endif()
endif()

# Configuration pour les builds de type Release
if(CMAKE_BUILD_TYPE STREQUAL "Release")
    if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
        target_compile_options(TD3_3 PRIVATE -O3 -DNDEBUG)
        target_compile_options(TD3_2 PRIVATE -O3 -DNDEBUG)
        target_compile_options(TD3_4 PRIVATE -O3 -DNDEBUG)  # ← Ajouter cette ligne
    endif()
endif()

# Installation (optionnel)
install(TARGETS TD3_3 TD3_2 TD3_4 DESTINATION bin)  # ← Ajouter TD3_4

# Cibles pour l'exécution rapide
add_custom_target(run_TD3_3
    COMMAND ./TD3_3
    DEPENDS TD3_3
    COMMENT "Running TD3_3"
)

add_custom_target(run_TD3_2
    COMMAND ./TD3_2
    DEPENDS TD3_2
    COMMENT "Running TD3_2"
)

add_custom_target(run_TD3_4  # ← Ajouter cette ligne
    COMMAND ./TD3_4
    DEPENDS TD3_4
    COMMENT "Running TD3_4"
)

# Cible pour le nettoyage
add_custom_target(clean-all
    COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target clean
    COMMENT "Cleaning all build files"
)

# Affichage des informations du projet
message(STATUS "Project: ${PROJECT_NAME}")
message(STATUS "C++ compiler: ${CMAKE_CXX_COMPILER}")
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
message(STATUS "Targets created: TD3_2, TD3_3, TD3_4")  # ← Ajouter TD3_4