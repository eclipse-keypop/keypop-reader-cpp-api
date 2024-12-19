/**************************************************************************************************
 * Copyright (c) 2024 Calypso Networks Association https://calypsonet.org/                        *
 *                                                                                                *
 * This program and the accompanying materials are made available under the                       *
 * terms of the MIT License which is available at https://opensource.org/licenses/MIT.            *
 *                                                                                                *
 * SPDX-License-Identifier: MIT                                                                   *
 **************************************************************************************************/

#pragma once

namespace keypop {
namespace reader {
namespace selection {

/**
 * Navigation options through the different applications contained in the card according to the
 * ISO7816-4 standard.
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

} /* namespace selection */
} /* namespace reader */
} /* namespace keypop */
