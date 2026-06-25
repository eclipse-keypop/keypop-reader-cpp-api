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

#include <memory>
#include <stdexcept>
#include <string>

namespace keypop {
namespace reader {

/**
 * Indicates that the communication with the card failed.
 *
 * @since 1.0.0
 */
class CardCommunicationException final : public std::runtime_error {
public:
    /**
     * @param message The message to identify the exception context.
     * @since 1.0.0
     */
    explicit CardCommunicationException(const std::string& message)
    : std::runtime_error(message)
    {
    }

    /**
     * @param message The message to identify the exception context.
     * @param cause The cause.
     * @since 1.0.0
     */
    CardCommunicationException(
        const std::string& message, const std::exception& /*cause*/)
    : std::runtime_error(message)
    {
    }
};

} /* namespace reader */
} /* namespace keypop */
