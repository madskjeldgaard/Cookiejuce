# Dependencies that are downloaded using the CPM package manager
include("${CMAKE_CURRENT_LIST_DIR}/CPM.cmake")

option(USE_RUST "Use Rust" ON)
if(USE_RUST)

  # Define USING_RUST to be used in C++ code
  add_definitions(-DUSING_RUST)

  # Install corrosion – a Rust to C++ bridge
  cpmaddpackage(NAME Corrosion GITHUB_REPOSITORY corrosion-rs/corrosion GIT_TAG
                v0.4.7)

  # Rust directory: rust in root dir
  set(RUST_DIR "${CMAKE_CURRENT_SOURCE_DIR}/rust")

  # Add a rust library After this, all you need to do is link to the rust
  # library in your C++ like this: target_link_libraries(SharedCode INTERFACE
  # myrustlib)
  corrosion_import_crate(MANIFEST_PATH "${RUST_DIR}/{{ cookiecutter.__rust_lib_name }}/Cargo.toml")

  corrosion_add_cxxbridge(
    {{ cookiecutter.__rust_lib_name }}
    CRATE
    {{ cookiecutter.__rust_crate_name }}
    MANIFEST_PATH
    "${RUST_DIR}/{{ cookiecutter.__rust_lib_name }}"
    # NOTE: These file paths are relative to the root of the rust crate's src
    # dir eg rust/{{ cookiecutter.__rust_lib_name }}/src.
    FILES
    "lib.rs")

  if(MSVC)
    # Note: This is required because we use `cxx` which uses `cc` to compile and
    # link C++ code.
    corrosion_set_env_vars({{ cookiecutter.__rust_crate_name }} "CFLAGS=-MDd" "CXXFLAGS=-MDd")
  endif()

endif()
