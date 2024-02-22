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
#include <string>

#include "keypop/reader/CardReader.hpp"
#include "keypop/reader/ObservableCardReader.hpp"
#include "keypop/reader/selection/CardSelectionResult.hpp"
#include "keypop/reader/selection/CardSelector.hpp"
#include "keypop/reader/selection/spi/CardSelectionExtension.hpp"

namespace keypop {
namespace reader {
namespace selection {

using keypop::reader::CardReader;
using keypop::reader::ObservableCardReader;
using keypop::reader::selection::CardSelectionResult;
using keypop::reader::selection::CardSelector;
using keypop::reader::selection::spi::CardSelectionExtension;

/**
 * Service dedicated to card selection, based on the preparation of a card selection scenario.
 *
 * <p>A card selection scenario consists of one or more selection cases based on a {@link
 * CardSelectionExtension}.<br>
 * A card selection case targets a specific card. <br>
 * Optionally, additional commands can be defined to be executed after the successful selection of
 * the card. <br>
 *
 * <p>If a card selection case fails, the service will try with the next card selection case defined
 * in the scenario, until there are no further card selection cases available.
 *
 * <p>If a card selection case succeeds:
 *
 * <ul>
 *   <li>By default, the service stops at the first successful card selection.
 *   <li>If the multiple selection mode is set (disabled by default), the service will execute the
 *       next selection. This multiple selection mode force the execution of all card selection
 *       cases defined in the scenario. This method can be enabled using the {@link
 *       CardSelectionManager#setMultipleSelectionMode()} method
 * </ul>
 *
 * <p>The logical channel established with the card can be left open (default) or closed after card
 * selection (by using the {@link CardSelectionManager#prepareReleaseChannel()} method).
 *
 * <p>This service allows to:
 *
 * <ul>
 *   <li>Prepare the card selection scenario.
 *   <li>Make an explicit selection of a card (when the card is already present).
 *   <li>Schedule the execution of the selection as soon as a card is presented to an observable
 *       reader.
 * </ul>
 *
 * An instance of this interface can be obtained via the method {@link
 * ReaderApiFactory#createCardSelectionManager()}.
 *
 * @since 1.0.0
 */
class CardSelectionManager {
public:
    /**
     * Virtual destructor.
     */
    virtual ~CardSelectionManager() = default;

    /**
     * Sets the multiple selection mode to process all selection cases even in case of a successful
     * selection.
     *
     * <p>The multiple selection mode is disabled by default.
     *
     * @since 1.0.0
     */
    virtual void setMultipleSelectionMode() = 0;

    /**
     * Appends a card selection case to the card selection scenario.
     *
     * <p>The method returns the index giving the current position of the selection in the selection
     * scenario (0 for the first application, 1 for the second, etc.). This index will be used to
     * retrieve the corresponding result in the {@link CardSelectionResult} object.
     *
     * @param cardSelector The card selector containing the filters to be used to select the card.
     * @param cardSelectionExtension The card selection extension to be used to parse the card
     *        selection response.
     * @return A non-negative int.
     * @throws IllegalArgumentException If the provided card selector or card selection extension is
     *         null.
     * @since 2.0.0
     */
    virtual int prepareSelection(
        const std::shared_ptr<CardSelector> cardSelector,
        const std::shared_ptr<spi::CardSelectionExtension> cardSelectionExtension)
        = 0;

    /**
     * Requests the closing of the physical channel at the end of the execution of the card
     * selection request.
     *
     * <p>It is thus possible to chain several selections on the same card selection scenario by
     * restarting the card connection sequence.
     *
     * @since 1.0.0
     */
    virtual void prepareReleaseChannel() = 0;

    /**
     * Exports the current prepared card selection scenario to a string in string format.
     *
     * <p>This string can be imported into the same or another card selection manager via the method
     * importCardSelectionScenario(const std::string&).
     *
     * @return A non-null string.
     * @see importCardSelectionScenario(const std::string&)
     * @since 1.1.0
     */
    virtual const std::string exportCardSelectionScenario() const = 0;

    /**
     * Imports a card selection scenario provided as a string in string format.
     *
     * <p>The string must have been exported from a card selection manager via the method
     * exportCardSelectionScenario().
     *
     * @param cardSelectionScenario The string containing the exported card selection scenario.
     * @return The index of the last imported selection in the card selection scenario.
     * @throws IllegalArgumentException If the string is null or malformed.
     * @see exportCardSelectionScenario()
     * @since 1.1.0
     */
    virtual int importCardSelectionScenario(const std::string& cardSelectionScenario) = 0;

    /**
     * Explicitely executes a previously prepared card selection scenario and returns the card
     * selection result.
     *
     * @param reader The reader to communicate with the card.
     * @return A non-null reference.
     * @throw IllegalArgumentException If the provided reader is null.
     * @throw ReaderCommunicationException If the communication with the reader has failed.
     * @throw CardCommunicationException If communication with the card has failed or if the status
     *        word check is enabled in the card request and the card has returned an unexpected
     *        code.
     * @throw InvalidCardResponseException If the card returned invalid data during the selection
     *        process.
     * @since 1.0.0
     */
    virtual const std::shared_ptr<CardSelectionResult>
    processCardSelectionScenario(std::shared_ptr<CardReader> reader) = 0;

    /**
     * Schedules the execution of the prepared card selection scenario as soon as a card is
     * presented to the provided ObservableCardReader.
     *
     * <p>calypsonet::terminal::reader::CardReaderEvent are pushed to the observer according to the
     * specified notification mode.
     *
     * <p>The result of the scenario execution will be analyzed by
     * parseScheduledCardSelectionsResponse(ScheduledCardSelectionsResponse).
     *
     * @param observableCardReader The reader with which the card communication is carried out.
     * @param notificationMode The card notification mode to use when a card is detected.
     * @throw IllegalArgumentException If one of the parameters is null.
     * @since 1.0.0
     */
    virtual void scheduleCardSelectionScenario(
        std::shared_ptr<ObservableCardReader> observableCardReader,
        const ObservableCardReader::NotificationMode notificationMode)
        = 0;

    /**
     * Analyzes the responses provided by a calypsonet::terminal::reader::CardReaderEvent
     * following the insertion of a card and the execution of the card selection scenario.
     *
     * @param scheduledCardSelectionsResponse The card selection scenario execution response.
     * @return A non-null reference.
     * @throw IllegalArgumentException If the provided card selection response is null.
     * @throw InvalidCardResponseException If the data returned by the card could not be
     * interpreted.
     * @since 1.0.0
     */
    virtual std::shared_ptr<calypsonet::reader::selection::CardSelectionResult>
    parseScheduledCardSelectionsResponse(const std::shared_ptr<ScheduledCardSelectionsResponse>
                                             scheduledCardSelectionsResponse) const
        = 0;

    /**
     * Exports the content of the previously processed card selection scenario in string format.
     *
     * <p>This string can be imported into the same or another card selection manager via the method
     * importProcessedCardSelectionScenario(const std::string&).
     *
     * <p>Prerequisite: the card selection scenario must first have been processed via the
     * processCardSelectionScenario(const std::shared_ptr<CardReader>) or
     * parseScheduledCardSelectionsResponse(const std::shared_ptr<ScheduledCardSelectionsResponse>)
     * method.
     *
     * <p>Caution: if the local environment does not have the card extensions involved in the
     * selection scenario, then methods processCardSelectionScenario(const
     * std::shared_ptr<CardReader>) and parseScheduledCardSelectionsResponse(const
     * std::shared_ptr<ScheduledCardSelectionsResponse>) will not be able to
     * interpret the content of the result, and consequently, the content of the result object
     * CardSelectionResult will not contain any active selection. It will then be necessary to
     * export the processed scenario in order to import it and interpret it correctly by a card
     * selection manager that has all the card extensions involved in the selection scenario.
     *
     * @return A non-null string.
     * @throw IllegalStateException If the card selection scenario has not yet been processed or has
     *        failed.
     * @see importProcessedCardSelectionScenario(const std::string&)
     * @since 1.3.0
     */
    virtual const std::string& exportProcessedCardSelectionScenario() const = 0;

    /**
     * Imports a previously exported processed card selection scenario in string format and returns
     * the card selection result.
     *
     * <p>Prerequisites:
     *
     * <ul>
     *   <li>the string must have been exported from a card selection manager via the method
     *       exportProcessedCardSelectionScenario(),
     *   <li>the local environment must have the card extensions involved in the card selection
     *       scenario,
     *   <li>the current manager must first be configured with the same card selection scenario as
     *       the manager that was used to export the processed card selection scenario.
     * </ul>
     *
     * @param processedCardSelectionScenario The string containing the exported processed card
     *        selection scenario.
     * @return A non-null reference.
     * @throw IllegalArgumentException If the string is null, malformed or contains more card
     *        selection cases than the current card selection scenario.
     * @throw InvalidCardResponseException If the data returned by the card could not be
     *        interpreted.
     * @see exportProcessedCardSelectionScenario()
     * @since 1.3.0
     */
    virtual const std::shared_ptr<CardSelectionResult>
    importProcessedCardSelectionScenario(const std::string& processedCardSelectionScenario) const
        = 0;
};

} /* namespace selection */
} /* namespace reader */
} /* namespace keypop */
