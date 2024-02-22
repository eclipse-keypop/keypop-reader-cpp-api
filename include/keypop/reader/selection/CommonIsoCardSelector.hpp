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

#include <string>
#include <vector>

#include "keypop/reader/selection/CardSelector.hpp"
#include "keypop/reader/selection/FileControlInformation.hpp"
#include "keypop/reader/selection/FileOccurrence.hpp"

namespace keypop {
namespace reader {
namespace selection {

/**
 * Common ISO filters used to restrict the selection process to certain ISO
 * 7816-4 cards.
 *
 * <p>These filters are all optional but can also be combined.
 *
 * <p>If no filtering is specified, any card that responds when inserted in the
 * reader will be considered selected.
 *
 * <p>Conversely, if one or more filters have been defined, the card will not be
 * selected if one of them rejects the card.
 *
 * @param <T> The type of the lowest level child object.
 * @since 2.0.0
 */
template <typename T>
class CommonIsoCardSelector : public CardSelector<T> {
public:
    /**
     * Selects a card application DF by its name.
     *
     * <p>The DF is selected only if its name starts with the provided AID, as
     * defined by ISO7816-4 chapter 4.2.
     *
     * <p>The provided AID will be used as a parameter of the "Selection
     * Application" ISO card command.
     *
     * @param aid The AID as a byte array containing 5 to 16 bytes.
     * @return The current instance.
     * @throw IllegalArgumentException If the provided array is null or out of
     * range.
     * @since 2.0.0
     */
    virtual T& filterByDfName(const std::vector<uint8_t>& aid) = 0;

    /**
     * Selects a card application DF by its name.
     *
     * <p>The DF is selected only if its name starts with the provided AID, as
     * defined by ISO7816-4 chapter 4.2.
     *
     * <p>The provided AID will be used as a parameter of the "Selection
     * Application" ISO card command.
     *
     * @param aid The AID as a hexadecimal string of 5 to 16 bytes.
     * @return The current instance.
     * @throw IllegalArgumentException If the provided string is null, invalid
     * or out of range.
     * @since 2.0.0
     */
    virtual T& filterByDfName(const std::string& aid) = 0;

    /**
     * Sets the file occurrence mode (see ISO7816-4).
     *
     * <p>The default value is {@link FileOccurrence#FIRST}.
     *
     * @param fileOccurrence The {@link FileOccurrence}.
     * @return The current instance.
     * @throws IllegalArgumentException If fileOccurrence is null.
     * @since 2.0.0
     */
    virtual T& setFileOccurrence(FileOccurrence fileOccurrence) = 0;

    /**
     * Sets the file control mode (see ISO7816-4).
     *
     * <p>The default value is {@link FileControlInformation#FCI}.
     *
     * @param fileControlInformation The {@link FileControlInformation}.
     * @return The current instance.
     * @throws IllegalArgumentException If fileControlInformation is null.
     * @since 2.0.0
     */
    virtual T&
    setFileControlInformation(FileControlInformation fileControlInformation)
        = 0;
};

} /* namespace selection */
} /* namespace reader */
} /* namespace keypop */
