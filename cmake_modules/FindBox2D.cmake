IF(BOX2D_INCLUDE_DIR)
    SET(BOX2D_FIND_QUIETLY TRUE)
ENDIF(BOX2D_INCLUDE_DIR)

FIND_PATH(BOX2D_INCLUDE_DIR Box2D.h PATH_SUFFIXES include/Box2D include)

SET(BOX2D_NAMES box2d Box2d BOX2D Box2D)
FIND_LIBRARY(BOX2D_LIBRARY NAMES ${BOX2D_NAMES})
MARK_AS_ADVANCED(BOX2D_LIBRARY BOX2D_INCLUDE_DIR)

SET(Box2D_INCLUDE_DIRS "${BOX2D_INCLUDE_DIR}")
SET(Box2D_LIBRARIES    "${BOX2D_LIBRARY}")

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(Box2D DEFAULT_MSG Box2D_LIBRARIES Box2D_INCLUDE_DIRS)