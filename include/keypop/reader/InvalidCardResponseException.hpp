/******************************************************************************
 * Copyright (c) 2025 Calypso Networks Association https://calypsonet.org/    *
 *                                                                            *
 * See the NOTICE file(s) distributed with this work for additional           *
 * information regarding copyright ownership.                                 *
 *                                                                            *
 * This program and the accompanying materials are made available under the   *
 * terms of the MIT License which is available at                             *
 * https://opensource.org/licenses/MIT                                        *
 *                                                                            *
 * SPDX-License-Identifier: MIT                                               *
 ******************************************************************************/

#pragma once

#include <stdexcept>
#include <string>

namespace keypop {
namespace reader {

/**
 * Indicates that a response received from the card during the command
 * processing was invalid.
 *
 * @since 2.1.0
 */
class InvalidCardResponseException : public std::runtime_error {
public:
    /**
     * @param message The message to identify the exception context.
     * @since 2.1.0
     */
    explicit InvalidCardResponseException(const std::string& message)
    : std::runtime_error(message)
    {
    }

    /**
     * @param message The message to identify the exception context.
     * @param cause The cause.
     * @since 2.1.0
     */
    InvalidCardResponseException(
        const std::string& message, const std::exception& /*cause*/)
    : std::runtime_error(message)
    {
    }
};

} /* namespace reader */
} /* namespace keypop */
