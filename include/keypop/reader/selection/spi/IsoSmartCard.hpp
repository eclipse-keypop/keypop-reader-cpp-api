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

#include <cstdint>
#include <vector>

#include "keypop/reader/selection/spi/SmartCard.hpp"

namespace keypop {
namespace reader {
namespace selection {
namespace spi {

/**
 * ISO 7816-4 smart card with which communication has been established after a
 * selection process and which is ready to receive APDUs.
 *
 * <p>The information that could be collected by the selection process, i.e. the
 * power-on data or the response to the "Select Application" command are made
 * available.<br> Both are optional but cannot be null at the same time.
 *
 * <p>Must be implemented and possibly extended by a ISO card extension to meet
 * its specific needs.
 *
 * @since 2.0.0
 */
class IsoSmartCard : public SmartCard {
public:
    /**
     * Gets the card data received in response to the "Select Application"
     * command (including the status word).
     *
     * @return Null if no selection application has been performed.
     * @since 1.0.0
     */
    virtual const std::vector<uint8_t>&
    getSelectApplicationResponse() const = 0;
};

} /* namespace spi */
} /* namespace selection */
} /* namespace reader */
} /* namespace keypop */
