/******************************************************************************
 * Copyright (c) 2025 Calypso Networks Association https://calypsonet.org/    *
 *                                                                            *
 * See the NOTICE file(s) distributed with this work for additional           *
 * information regarding copyright ownership.                                 *
 *                                                                            *
 * This program and the accompanying materials are made available under the   *
 * terms of the MIT License which is available at                             *
 * https://opensource.org/licenses/MIT                                        *
 *                                                                            *
 * SPDX-License-Identifier: MIT                                               *
 ******************************************************************************/

#pragma once

#include <string>

namespace keypop {
namespace reader {
namespace selection {
namespace spi {

/**
 * Basic smart card with which communication has been established after a
 * selection process and which is ready to receive APDUs.
 *
 * <p>The power-on data that could be collected by the selection process are
 * made available.
 *
 * <p>Must be implemented and possibly extended by a card extension to meet its
 * specific needs.
 *
 * @since 1.0.0
 */
class SmartCard {
public:
    /**
     *
     */
    virtual ~SmartCard() = default;

    /**
     * Basic smart card with which communication has been established after a
     * selection process and which is ready to receive APDUs.
     *
     * <p>The power-on data that could be collected by the selection process are
     * made available.
     *
     * <p>Must be implemented and possibly extended by a card extension to meet
     * its specific needs.
     *
     * @since 1.0.0
     */
    virtual const std::string& getPowerOnData() const = 0;
};

} /* namespace spi */
} /* namespace selection */
} /* namespace reader */
} /* namespace keypop */
