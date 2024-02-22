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

#include <memory>

#include "keypop/reader/CardReaderEvent.hpp"

namespace keypop {
namespace reader {
namespace spi {

/**
 * Reader observer to implement in order to receive CardReaderEvent from a
 * keypop::reader::ObservableCardReader.
 *
 * @since 1.0.0
 */
class CardReaderObserverSpi {
public:
    /**
     * Called when a reader event occurs.
     *
     * <p>The event notification should be done <b>sequentially</b> and <b>synchronously</b> but
     * this may depend on the implementation used.
     *
     * @param readerEvent The not null CardReaderEvent containing the event
     * data.
     * @since 1.0.0
     */
    virtual void
    onReaderEvent(const std::shared_ptr<CardReaderEvent> readerEvent)
        = 0;
};

} /* namespace spi */
} /* namespace reader */
} /* namespace keypop */
