# *************************************************************************************************
# Copyright (c) 2024 Calypso Networks Association https://calypsonet.org/                         *
#                                                                                                 *
# This program and the accompanying materials are made available under the                        *
# terms of the MIT License which is available at https://opensource.org/licenses/MIT.             *
#                                                                                                 *
# SPDX-License-Identifier: MIT                                                                    *
# *************************************************************************************************/

SET(EXECTUABLE_NAME keypopreader_ut)

INCLUDE_DIRECTORIES(
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/../../include
)

ADD_EXECUTABLE(
    ${EXECTUABLE_NAME}

    ${CMAKE_CURRENT_SOURCE_DIR}/MainTest.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/ReaderApiPropertiesTest.cpp
)

# Add Google Test
SET(GOOGLETEST_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
INCLUDE(CMakeLists.txt.googletest)

TARGET_LINK_LIBRARIES(${EXECTUABLE_NAME} gtest gmock)
