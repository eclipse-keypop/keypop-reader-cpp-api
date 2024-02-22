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
namespace selection {

/**
 * Common filters used to restrict the selection process to certain cards.
 *
 * <p>These filters are all optional but can also be combined.
 *
 * <p>If no filtering is specified, any card that responds when inserted in the reader will be
 * considered selected.
 *
 * <p>Conversely, if one or more filters have been defined, the card will not be selected if one of
 * them rejects the card.
 *
 * @param <T> The type of the lowest level child object.
 * @since 2.0.0
 */
template <typename T>
class CardSelector<T> {
public:
    /**
     * Restricts the selection process to cards communicating with the reader according to a
     * specific protocol, corresponding to the underlying technology: ISO14443-A, ISO14443-B or any
     * other proprietary or standardized communication technology.
     *
     * <p>The protocol is identified by its <b>logical name</b>.
     *
     * <p><b>Prerequisites</b>: the reader must be of type keypop::reader::ConfigurableCardReader
     * and the targeted card protocol(s) must be activated via the
     * keypop::reader::ConfigurableCardReader#activateProtocol(const std::string&,
     * const std::string&) method and associated with the logical name used as a filter.
     *
     * @param logicalProtocolName The logical name of the protocol to use as filter.
     * @return The current instance.
     * @throw IllegalArgumentException If the provided logical protocol name is null or empty.
     * @since 2.0.0
     */
    virtual T& filterByCardProtocol(const std::string& logicalProtocolName) = 0;

    /**
     * Restricts the selection process to cards whose power-on data provided by the reader matches a
     * specific regular expression.
     *
     * @param powerOnDataRegex The regular expression to use as filter.
     * @return The current instance.
     * @throw IllegalArgumentException If the provided regular expression is null, empty or invalid.
     * @since 2.0.0
     */
    virtual T& filterByPowerOnData(const std::string& powerOnDataRegex) = 0;
};

} /* namespace selection */
} /* namespace reader */
} /* namespace keypop */
