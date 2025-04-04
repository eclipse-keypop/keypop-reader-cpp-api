/**************************************************************************************************
 * Copyright (c) 2025 Calypso Networks Association https://calypsonet.org/                        *
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
namespace cpp {

/**
 * Base class for CardSelector manipulation.
 *
 * @since 2.0.0
 */
class CardSelectorBase {
public:
    /**
     * Virtual destructor.
     */
    virtual ~CardSelectorBase() = default;
};

} /* namespace cpp */
} /* namespace reader */
} /* namespace keypop */
