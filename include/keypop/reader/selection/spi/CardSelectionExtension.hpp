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

namespace keypop {
namespace reader {
namespace selection {
namespace spi {

/**
 * SPI provided by a card extension, allowing to enrich a selection case with
 * additional commands if required, and to interpret the return to selection in
 * order to build and fill the specific SmartCard which acts as an image of the
 * targeted card.
 *
 * @since 2.0.0
 */
class CardSelectionExtension {
public:
    /**
     * Virtual destructor.
     */
    virtual ~CardSelectionExtension() = default;
};

} /* namespace spi */
} /* namespace selection */
} /* namespace reader */
} /* namespace keypop */
