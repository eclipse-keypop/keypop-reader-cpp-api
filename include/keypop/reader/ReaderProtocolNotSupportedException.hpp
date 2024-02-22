/******************************************************************************
 * Copyright (c) 2025 Calypso Networks Association https://calypsonet.org/    *
 *                                                                            *
 * This program and the accompanying materials are made available under the   *
 * terms of the MIT License which is available at                             *
 * https://opensource.org/licenses/MIT.                                       *
 *                                                                            *
 * SPDX-License-Identifier: MIT                                               *
 ******************************************************************************/

#pragma once

#include <stdexcept>
#include <string>

namespace keypop {
namespace reader {

/**
 * Indicates that the current card protocol is not supported by the reader.
 *
 * @since 1.0.0
 */
class ReaderProtocolNotSupportedException final : public std::runtime_error {
public:
    /**
     * @param cardProtocol The identification data used to identify the card.
     * @since 1.0.0
     */
    explicit ReaderProtocolNotSupportedException(
        const std::string& cardProtocol)
    : std::runtime_error(
        "The card protocol " + cardProtocol + " is not supported.")
    {
    }
};

} /* namespace reader */
} /* namespace keypop */
