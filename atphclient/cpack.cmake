set(CPACK_PACKAGE_CONTACT             "Aqua Tracker")
set(CPACK_PACKAGE_NAME                "atphclient")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Aqua Tracker Ph Reader")
set(CPACK_PACKAGE_VENDOR              "Aqua Tracker")
set(CPACK_PACKAGE_FILE_NAME           "atphclient_1.0.0")
set(CPACK_DEBIAN_PACKAGE_SECTION      "non-free")
set(CPACK_DEBIAN_PACKAGE_DEPENDS      "sqlite3, libsqlite3-dev, qt5-default")
find_program(DPKG NAMES dpkg)
set(CPACK_GENERATOR "DEB")
include(CPack)