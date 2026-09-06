set_project("FPSGame")
set_languages("cxx17")

add_requires("libsdl2", "libsdl2_image", "libsdl2_mixer", "libsdl2_ttf")

target("main")
    set_kind("binary")
    set_rundir("$(projectdir)")
    add_files("src/*.cpp")
    add_packages("libsdl2", "libsdl2_image", "libsdl2_mixer", "libsdl2_ttf")