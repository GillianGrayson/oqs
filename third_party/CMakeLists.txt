# Distributed under the MIT License (See accompanying file /LICENSE )

# CMake build : third party

# configure directories
set (THIRD_PARTY_MODULE_PATH "${PROJECT_SOURCE_DIR}/third_party")

# -------------------------------------------------------------------------
# catch
# -------------------------------------------------------------------------

# configure directories
set (CATCH_MODULE_PATH "${THIRD_PARTY_MODULE_PATH}/Catch2")
set (CATCH_INCLUDE_PATH "${CATCH_MODULE_PATH}/single_include/catch2")

#include custom cmake function
include ("${CATCH_MODULE_PATH}/contrib/ParseAndAddCatchTests.cmake")

# -------------------------------------------------------------------------
# spdlog
# -------------------------------------------------------------------------

# configure directories
set (SPDLOG_MODULE_PATH "${THIRD_PARTY_MODULE_PATH}/spdlog")
set (SPDLOG_INCLUDE_PATH "${SPDLOG_MODULE_PATH}/include")

# -------------------------------------------------------------------------
# eigen-git-mirror
# -------------------------------------------------------------------------

# configure directories
set (EIGEN_MODULE_PATH "${THIRD_PARTY_MODULE_PATH}/eigen-git-mirror")
set (EIGEN_INCLUDE_PATH "${EIGEN_MODULE_PATH}")

# -------------------------------------------------------------------------
# export vars
# -------------------------------------------------------------------------
set (SPDLOG_INCLUDE_PATH  ${SPDLOG_INCLUDE_PATH} PARENT_SCOPE)
set (CATCH_INCLUDE_PATH  ${CATCH_INCLUDE_PATH} PARENT_SCOPE)
set (EIGEN_INCLUDE_PATH  ${EIGEN_INCLUDE_PATH} PARENT_SCOPE)
