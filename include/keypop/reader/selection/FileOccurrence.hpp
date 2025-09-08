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

#include <iostream>

namespace keypop {
namespace reader {
namespace selection {

/**
 * Navigation options through the different applications contained in the card
 * according to the ISO7816-4 standard.
 *
 * @since 2.0.0
 */
enum class FileOccurrence {
    /**
     * First occurrence.
     *
     * @since 2.0.0
     */
    FIRST,

    /**
     * Last occurrence.
     *
     * @since 2.0.0
     */
    LAST,

    /**
     * Next occurrence.
     *
     * @since 2.0.0
     */
    NEXT,

    /**
     * Previous occurrence.
     *
     * @since 2.0.0
     */
    PREVIOUS
};

static inline std::ostream&
operator<<(std::ostream& os, const FileOccurrence fo)
{
    os << "FILE_OCCURENCE: ";
    switch (fo) {
    case FileOccurrence::FIRST:
        os << "FIRST";
        break;
    case FileOccurrence::LAST:
        os << "LAST";
        break;
    case FileOccurrence::NEXT:
        os << "NEXT";
        break;
    case FileOccurrence::PREVIOUS:
        os << "PREVIOUS";
        break;
    default:
        os << "UNKNOWN";
        break;
    }

    return os;
}

} /* namespace selection */
} /* namespace reader */
} /* namespace keypop */
