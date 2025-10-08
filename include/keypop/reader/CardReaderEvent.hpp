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
#include <ostream>
#include <string>

#include "keypop/reader/selection/ScheduledCardSelectionsResponse.hpp"

namespace keypop {
namespace reader {

using keypop::reader::selection::ScheduledCardSelectionsResponse;

/**
 * Card event data container indicating a change of state.
 *
 * <p>Contains the event origin (reader name), the event type and possibly the
 * card selection response (when available).
 *
 * @since 1.0.0
 */
class CardReaderEvent {
public:
    /**
     * Possible card events.
     *
     * @since 1.0.0
     */
    enum Type {
        /**
         * A card has been inserted with or without specific selection.
         *
         * @since 1.0.0
         */
        CARD_INSERTED,

        /**
         * A card has been inserted that matches the selection.
         *
         * @since 1.0.0
         */
        CARD_MATCHED,

        /**
         * The card has been removed from the reader.
         *
         * @since 1.0.0
         */
        CARD_REMOVED,

        /**
         * The reader has become unavailable.
         *
         * @since 1.0.0
         */
        UNAVAILABLE
    };

    /**
     * Returns the name of the reader that generated the event.
     *
     * @return A non-empty string.
     * @since 1.0.0
     */
    virtual const std::string& getReaderName() const = 0;

    /**
     * Returns the reader event type.
     *
     * @return A non-null value.
     * @since 1.0.0
     */
    virtual Type getType() const = 0;

    /**
     * Returns the card selection responses when it is available and null in all
     * other cases. It may be available when the event type is {@link
     * Type#CARD_INSERTED} and always present when the event type is {@link
     * Type#CARD_MATCHED}.
     *
     * <p>It is necessary to use the method
     * keypop::reader::selection::CardSelectionManager
     * ::parseScheduledCardSelectionsResponse(ScheduledCardSelectionsResponse)
     * to analyze the result.
     *
     * @return Null if the event is not carrying a
     * ScheduledCardSelectionsResponse.
     * @since 1.0.0
     */
    virtual const std::shared_ptr<ScheduledCardSelectionsResponse>
    getScheduledCardSelectionsResponse() const = 0;
};

/**
 * Operator << for CardReaderEvent::Type enum to enable readable logging.
 *
 * @param os The output stream.
 * @param type The event type.
 * @return The output stream.
 */
inline std::ostream&
operator<<(std::ostream& os, const CardReaderEvent::Type type)
{
    switch (type) {
    case CardReaderEvent::Type::CARD_INSERTED:
        os << "CARD_INSERTED";
        break;
    case CardReaderEvent::Type::CARD_MATCHED:
        os << "CARD_MATCHED";
        break;
    case CardReaderEvent::Type::CARD_REMOVED:
        os << "CARD_REMOVED";
        break;
    case CardReaderEvent::Type::UNAVAILABLE:
        os << "UNAVAILABLE";
        break;
    default:
        os << "UNKNOWN_TYPE(" << static_cast<int>(type) << ")";
        break;
    }
    return os;
}

} /* namespace reader */
} /* namespace keypop */
