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
 * Types of templates available in return for the Select Application command, according to the
 * ISO7816-4 standard.
 *
 * @since 2.0.0
 */
enum class FileControlInformation {
    /**
     * File control information.
     *
     * @since 2.0.0
     */
    FCI,

    /**
     * File control parameters.
     *
     * @since 2.0.0
     */
    FCP,

    /**
     * File management data.
     *
     * @since 2.0.0
     */
    FMD,

    /**
     * No response expected.
     *
     * @since 2.0.0
     */
    NO_RESPONSE
};

} /* namespace selection */
} /* namespace reader */
} /* namespace keypop */
