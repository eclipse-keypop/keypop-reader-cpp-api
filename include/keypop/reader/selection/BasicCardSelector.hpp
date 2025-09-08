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

#include "keypop/reader/selection/CardSelector.hpp"

namespace keypop {
namespace reader {
namespace selection {

/**
 * Basic filters used to restrict the selection process to certain cards.
 *
 * <p>These filters are all optional but can also be combined.
 *
 * <p>If no filtering is specified, any card that responds when inserted in the
 * reader will be considered selected.
 *
 * <p>Conversely, if one or more filters have been defined, the card will not be
 * selected if one of them rejects the card.
 *
 * <p>An instance of this interface can be obtained via the method {@link
 * ReaderApiFactory#createBasicCardSelector()}.
 *
 * @since 2.0.0
 */
class BasicCardSelector : public CardSelector<BasicCardSelector> {
public:
    /**
     * Virtual destructor.
     */
    virtual ~BasicCardSelector() = default;
};

} /* namespace selection */
} /* namespace reader */
} /* namespace keypop */
