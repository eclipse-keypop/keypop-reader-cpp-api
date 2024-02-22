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
#include <string>

#include "keypop/reader/selection/BasicCardSelector.hpp"
#include "keypop/reader/selection/CardSelectionManager.hpp"
#include "keypop/reader/selection/IsoCardSelector.hpp"

namespace keypop {
namespace reader {

using keypop::reader::selection::BasicCardSelector;
using keypop::reader::selection::CardSelectionManager;
using keypop::reader::selection::IsoCardSelector;

/**
 * Reader API Factory.
 *
 * @since 2.0.0
 */
class ReaderApiFactory {
public:
    /**
     *
     */
    virtual ~ReaderApiFactory() = default;

    /**
     * Returns a new instance of CardSelectionManager.
     *
     * @return A new instance of CardSelectionManager.
     * @since 2.0.0
     */
    virtual std::shared_ptr<CardSelectionManager> createCardSelectionManager()
        = 0;

    /**
     * Returns a new instance of BasicCardSelector.
     *
     * @return A new instance of BasicCardSelector.
     * @since 2.0.0
     */
    virtual std::shared_ptr<BasicCardSelector> createBasicCardSelector() = 0;

    /**
     * Returns a new instance of IsoCardSelector.
     *
     * @return A new instance of IsoCardSelector.
     * @since 2.0.0
     */
    virtual std::shared_ptr<IsoCardSelector> createIsoCardSelector() = 0;
};

} /* namespace reader */
} /* namespace keypop */
