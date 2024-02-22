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

/**
 * Response of the execution of a scheduled selection scenario provided by a
 * calypsonet::terminal::reader::CardReaderEvent.
 *
 * <p>Contains the card's responses to one or more of the scenario's selection
 * cases, i.e. the data from the selection step itself and any responses to
 * commands that may have been executed afterwards.
 *
 * <p>It is necessary to use the method
 * CardSelectionManager#parseScheduledCardSelectionsResponse(ScheduledCardSelectionsResponse)
 * to analyze the result.
 *
 * @since 1.0.0
 */
class ScheduledCardSelectionsResponse {
public:
    /**
     *
     */
    virtual ~ScheduledCardSelectionsResponse() = default;
};

} /* namespace selection */
} /* namespace reader */
} /* namespace keypop */
