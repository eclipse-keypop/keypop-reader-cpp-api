/**************************************************************************************************
 * Copyright (c) 2024 Calypso Networks Association https://calypsonet.org/                        *
 *                                                                                                *
 * This program and the accompanying materials are made available under the                       *
 * terms of the MIT License which is available at https://opensource.org/licenses/MIT.            *
 *                                                                                                *
 * SPDX-License-Identifier: MIT                                                                   *
 **************************************************************************************************/

#pragma once

#include <string>

namespace keypop {
namespace reader {

/**
 * Card reader driving the underlying hardware to manage the card detection.
 *
 * @since 1.0.0
 */
class CardReader {
public:
    /**
     *
     */
    virtual ~CardReader() = default;

    /**
     * Returns the name of the reader.
     *
     * @return A non-empty string containing the name of the reader.
     * @since 1.0.0
     */
    virtual const std::string& getName() const = 0;

    /**
     * Checks if the card communication mode is contactless.
     *
     * C++ note: this function cannot be set 'const' as some derived classes will set internal
     *           flags accordingly.
     *
     * @return <b>true</b> if the communication mode is contactless else <b>false</b>
     * @since 1.0.0
     */
    virtual bool isContactless() = 0;

    /**
     * Checks if the card is present.
     *
     * @return <b>true</b> if a card is inserted in the reader else <b>false</b>.
     * @throw ReaderCommunicationException If the communication with the reader has failed.
     * @since 1.0.0
     */
    virtual bool isCardPresent() = 0;
};

} /* namespace reader */
} /* namespace keypop */
