/**************************************************************************************************
 * Copyright (c) 2024 Calypso Networks Association https://calypsonet.org/                        *
 *                                                                                                *
 * This program and the accompanying materials are made available under the                       *
 * terms of the MIT License which is available at https://opensource.org/licenses/MIT.            *
 *                                                                                                *
 * SPDX-License-Identifier: MIT                                                                   *
 **************************************************************************************************/

#pragma once

#include <memory>
#include <stdexcept>
#include <string>

namespace keypop {
namespace reader {

/**
 * Indicates that the communication with the reader failed.
 *
 * <p>The most likely reason is a physical disconnection of the reader, but other technical problems
 * may also be the origin of the failure.
 *
 * @since 1.0.0
 */
class ReaderCommunicationException final : public std::runtime_error {
public:
    /**
     * @param message The message to identify the exception context.
     * @since 1.0.0
     */
    explicit ReaderCommunicationException(const std::string& message)
    : std::runtime_error(message) {
    }

    /**
     * @param message The message to identify the exception context.
     * @param cause The cause.
     * @since 1.0.0
     */
    ReaderCommunicationException(
        const std::string& message, const std::shared_ptr<std::exception> cause)
    : std::runtime_error(message) {
        (void)cause;
    }
};

} /* namespace reader */
} /* namespace keypop */
