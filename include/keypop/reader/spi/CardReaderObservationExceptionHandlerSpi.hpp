/**************************************************************************************************
 * Copyright (c) 2024 Calypso Networks Association https://calypsonet.org/                        *
 *                                                                                                *
 * This program and the accompanying materials are made available under the                       *
 * terms of the MIT License which is available at https://opensource.org/licenses/MIT.            *
 *                                                                                                *
 * SPDX-License-Identifier: MIT                                                                   *
 **************************************************************************************************/

#pragma once

#include <memory>
#include <stdexcept>
#include <string>

namespace keypop {
namespace reader {
namespace spi {

/**
 * Reader observation error handler to implement in order to be notified of errors that may occur
 * during operations carried out by the card monitoring process.
 *
 * @since 1.0.0
 */
class CardReaderObservationExceptionHandlerSpi {
public:
    /**
     * Called when an error occurs in the observed reader.
     *
     * <p>When an error occurs, the observation process is stopped.
     *
     * @param contextInfo The context information.
     * @param readerName The reader name.
     * @param e The original exception.
     * @since 1.0.0
     */
    virtual void onReaderObservationError(
        const std::string& contextInfo,
        const std::string& readerName,
        const std::shared_ptr<std::exception> e)
        = 0;
};

} /* namespace spi */
} /* namespace reader */
} /* namespace keypop */
