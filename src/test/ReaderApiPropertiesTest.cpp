/******************************************************************************
 * Copyright (c) 2025 Calypso Networks Association https://calypsonet.org/    *
 *                                                                            *
 * This program and the accompanying materials are made available under the   *
 * terms of the MIT License which is available at                             *
 * https://opensource.org/licenses/MIT.                                       *
 *                                                                            *
 * SPDX-License-Identifier: MIT                                               *
 ******************************************************************************/

#include <regex>
#include <string>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "keypop/reader/ReaderApiProperties.hpp"

using keypop::reader::ReaderApiProperties_VERSION;

TEST(ReaderApiPropertiesTest, versionIsCorrectlyWritten)
{
    const std::string& apiVersion = ReaderApiProperties_VERSION;
    const std::regex r("\\d+\\.\\d+");

    ASSERT_TRUE(std::regex_match(apiVersion, r));
}
