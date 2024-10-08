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

#include "keypop/reader/CardReader.hpp"

namespace keypop {
namespace reader {

/**
 * Configurable card reader providing the methods to manage the card protocols.
 *
 * @since 1.0.0
 */
class ConfigurableCardReader : virtual public CardReader {
public:
    /**
     *
     */
    virtual ~ConfigurableCardReader() = default;

    /**
     * Activates the reader communication protocol by associating the provided physical
     * communication protocol name and the logical communication protocol name defined by the
     * application.
     *
     * <ul>
     *   <li>Activates the detection of cards using the provided reader communication protocol.
     *   <li>Internally associates the two strings provided as arguments.
     * </ul>
     *
     * <p>The association between the communication protocol name known by the reader and the
     * communication protocol name defined by the application is intended to manage non-ISO cards.
     * It allows a unique protocol name to be set when constructing a card selector as defined by
     * the <b>Keypop Card API</b> regardless of the type of reader that will be used.
     *
     * @param physicalProtocolName The name of the physical communication protocol as known by the
     *        reader. See the reader documentation for the list of supported communication
     *        protocols.
     * @param logicalProtocolName The name of the logical protocol associated with the cards
     *        detected with the physical protocol also provided. This name can be used by the
     *        application to perform filtering at the time of selection.
     * @throw IllegalArgumentException If one of the provided communication protocols is null or
     *        empty.
     * @throw ReaderProtocolNotSupportedException If the reader communication protocol is not
     *        supported.
     * @since 1.0.0
     */
    virtual void activateProtocol(
        const std::string& physicalProtocolName, const std::string& logicalProtocolName)
        = 0;

    /**
     * Deactivates the provided reader communication protocol. Inhibits the detection of cards using
     * this reader communication protocol.
     *
     * @param physicalProtocolName The name of the physical communication protocol as known by the
     *        reader. See the reader documentation for the list of supported communication
     *        protocols.
     * @throw IllegalArgumentException If the provided reader communication protocol is null or
     *        empty.
     * @throw ReaderProtocolNotSupportedException If the reader communication protocol is not
     *        supported.
     * @since 1.0.0
     */
    virtual void deactivateProtocol(const std::string& physicalProtocolName) = 0;

    /**
     * Returns the name of the physical protocol currently used by the reader.
     *
     * @return Null if no selection has been made yet or if no protocol has been activated.
     * @see #activateProtocol(const std::string&, const std::string&)
     * @since 1.2.0
     */
    virtual const std::string& getCurrentProtocol() const = 0;
};

} /* namespace reader */
} /* namespace keypop */
